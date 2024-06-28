#ifdef ARDUINO
 // to ignore by arduino compiler.
#else


#include "Server.h"


void SIGPIPEhandler(int signal) {
    // ignore signal...
}

int main() {
    signal(SIGPIPE, SIGPIPEhandler);
    pong::Server server;
    server.start();
    return 0;
}

namespace pong {

Server::Server() : serverAddress(new SocketAddress(PORT)) {
    clientOneScore = std::make_shared<Score>();
    clientTwoScore = std::make_shared<Score>();

    ball = std::make_shared<Ball>(centralX - Ball::LENGTH/2, centralY - Ball::LENGTH/2);

    frameTimer = std::make_shared<Timer>(30);

    clientOnePaddle = std::make_shared<Paddle>(0, centralY + Paddle::HEIGHT);
    clientTwoPaddle = std::make_shared<Paddle>(Table::WIDTH - Paddle::WIDTH, centralY + Paddle::HEIGHT);
    packetCounterUDP = std::make_shared<PacketCounterUDP>();

    initServerSockets();
}

void Server::initServerSockets() {
    serverTCPSocket = std::make_shared<PongSocketTCP>();
    serverUDPSocket = std::make_shared<SocketUDP>();

    e = serverTCPSocket->init_();
    if (e == ERROR) {
        std::cout << "ERROR: cannot create server socket TCP." << std::endl;
        exit(1);
    }
    std::cout << "Successfully init server TCP socket." << std::endl;

    e = serverTCPSocket->bind_(serverAddress.get());
    if (e == ERROR) {
        std::cout << "ERROR: cannot bind address to TCP socket." << std::endl;
        exit(2);
    }
    std::cout << "Successfully bind address to server TCP socket." << std::endl;

    e = serverUDPSocket->init_();
    if (e == ERROR) {
        std::cout << "ERROR: cannot create UDP socket.";
        exit(3);
    }
    std::cout << "Successfully init server UDP socket." << std::endl;

    e = serverUDPSocket->bind_(serverAddress.get());
    serverUDPSocket->setNonBlocking(true);
    if (e == ERROR) {
        std::cout << "ERROR: cannot bind address to UDP socket." << std::endl;
        exit(4);
    }
    std::cout << "Successfully bind address to server UDP socket." << std::endl;
}


void Server::start() {
    std::cout << "Server running on port: " << PORT << std::endl;

    while (true) {
        connectionsService();
        gameSession();
        std::cout << "Session finished." << std::endl;
    }
}

void Server::connectionsService() {

    std::cout << "New connection initializer run..." << std::endl;

    while (true) {

        e = serverTCPSocket->listen_(10);
        if (e == ERROR) {
            std::cout << "ERROR: cannot call listen." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(10));
            continue;
        }
        std::cout << "Successfully listen on server TCP socket." << std::endl;

        clientOneAddress = std::make_shared<SocketAddress>();
        clientTwoAddress =  std::make_shared<SocketAddress>();

        serverTCPSocket->setNonBlocking(false);
        SOCKET nativeSocketTCPOne = serverTCPSocket->accept_(*clientOneAddress);
        if (nativeSocketTCPOne == ERROR) {
            std::cout << "ERROR: cannot accept client one." << std::endl;
            continue;
        }
        std::cout << "Client one connected. Waiting for client two..." << std::endl;

        SOCKET nativeSocketTCPTwo = serverTCPSocket->accept_(*clientTwoAddress);
        if (nativeSocketTCPTwo == ERROR) {
            std::cout << "ERROR: cannot accept client two." << std::endl;
            continue;
        }
        std::cout << "Client two connected." << std::endl;


        clientOneTCPSocket = std::make_shared<PongSocketTCP>(nativeSocketTCPOne);
        clientTwoTCPSocket = std::make_shared<PongSocketTCP>(nativeSocketTCPTwo);

        clientOneTCPSocket->setNonBlocking(true);
        clientTwoTCPSocket->setNonBlocking(true);

        clientOneTCPSocket->sendCommunicate(Communicates::SendPortUDP);
        clientTwoTCPSocket->sendCommunicate(Communicates::SendPortUDP);

        bool receivedAddressOne = clientOneTCPSocket->receivePortUDP(clientOneAddress.get(), 300);
        bool receivedAddressTwo = clientTwoTCPSocket->receivePortUDP(clientTwoAddress.get(), 300);

        if (!receivedAddressOne || !receivedAddressTwo) {
            std::cout << "ERROR: cannot received address to UDP socket." << std::endl;
            clientOneTCPSocket->sendCommunicate(Communicates::SecondPlayerLeftTheGame);
            clientTwoTCPSocket->sendCommunicate(Communicates::SecondPlayerLeftTheGame);
            continue;
        }

        clientOneTCPSocket->sendCommunicate(Communicates::SuccessfulConnected);
        clientTwoTCPSocket->sendCommunicate(Communicates::SuccessfulConnected);

        std::cout << "Connections have been successfully established!" << std::endl;
        return;
    }
}

void Server::gameSession() {
    resetGameStates();
    resetGameVariables();

    /* **************************************************************
                    Main game loop.
    *************************************************************** */
    while(running) {

        handleMessagesFromClients();

        if (!running) return;

        receiveClientsMoves();

        if (frameTimer->isExpired()) {
            frameTimer->reset();

            if (ball->isCollisionWithWall()) {
                ball->bouncesOffWall();
            }
            else if (ball->isCollisionWithPaddle(*clientOnePaddle)) {
                ball->bouncesOffPaddle(*clientOnePaddle);
            }
            else if (ball->isCollisionWithPaddle(*clientTwoPaddle)) {
                ball->bouncesOffPaddle(*clientTwoPaddle);
            }
            else if (ball->isBehindPaddle(*clientOnePaddle)) {
                clientTwoScore->giveScore();
                nextTourHandler();
            }
            else if (ball->isBehindPaddle(*clientTwoPaddle)) {
                clientOneScore->giveScore();
                nextTourHandler();
            }
        
            if (!waitForNextTour) {
                ball->update();
            }
            else {
                if (loopCounter >= loopCountToNextTour) {
                runNextTour();
                } else {
                    loopCounter++;
                }
            }
            sendGameStateToClients();
        }
    }
}


void Server::handleMessagesFromClients() {
    Communicates receivedCommunicateFromClientOne = clientOneTCPSocket->receiveCommunicate();
    Communicates receivedCommunicateFromClientTwo = clientTwoTCPSocket->receiveCommunicate();

    switch(receivedCommunicateFromClientOne) {
        case Communicates::None:
            break;
        case Communicates::Disconnect:
            std::cout << "Client one left the game." << std::endl;
            clientTwoTCPSocket->sendCommunicate(Communicates::SecondPlayerLeftTheGame);
            running = false;
            break;
        default:
            std::cout << "Unexpected message from client one." << std::endl;
    }

    switch (receivedCommunicateFromClientTwo) {
        case Communicates::None:
            break;
        case Communicates::Disconnect:
            std::cout << "Client two left the game." << std::endl;
            clientOneTCPSocket->sendCommunicate(Communicates::SecondPlayerLeftTheGame);
            running = false;
            break;
        default:
            std::cout << "Unexpected message from client one." << std::endl;
    }
}


void Server::resetGameStates() {
    running = true;
    waitForNextTour = true;
}


void Server::resetGameVariables() {
    clientOneScore->reset();
    clientTwoScore->reset();

    ball->reset();

    clientOnePaddle->reset();
    clientTwoPaddle->reset();

    packetCounterUDP->reset();
}


void Server::receiveClientsMoves() {
    SocketAddress receivedAddress;
    const int maxReceivedMovesQuantity = 10;
    int receivedMoves = 0;

    serverUDPSocket->setNonBlocking(true);
    while (receivedMoves < maxReceivedMovesQuantity) {
        int readBytes = serverUDPSocket->receiveFrom_(nativeBuffer, nativeBufferSize, receivedAddress);
        if (readBytes <= 0) {
            return;
        }

        InputMemoryStream in = InputMemoryStream(nativeBuffer, readBytes);
        Move move;
        move.read(in);
        if (receivedAddress == *clientOneAddress) {
            clientOnePaddle->move(move.getY());
        }
        else if (receivedAddress == *clientTwoAddress) {
            clientTwoPaddle->move(move.getY());
        }
        receivedMoves++;
    }
}


void Server::sendGameStateToClients() {
    std::shared_ptr<OutputMemoryStream> out = std::make_shared<OutputMemoryStream>();

    packetCounterUDP->write(*out);
    clientOnePaddle->write(*out);
    clientTwoPaddle->write(*out);
    ball->write(*out);
    clientOneScore->write(*out);
    clientTwoScore->write(*out);

    serverUDPSocket->sendTo_(out->getBufferPtr(), (int) out->getLength(), *clientOneAddress);
    serverUDPSocket->sendTo_(out->getBufferPtr(), (int) out->getLength(), *clientTwoAddress);

    packetCounterUDP->incrementCounter();
}


void Server::nextTourHandler() {
    if (clientOneScore->getScore() == roundNumber) {
        clientOneTCPSocket->sendCommunicate(Communicates::YouWon);
        clientTwoTCPSocket->sendCommunicate(Communicates::YouLost);
        running = false;
    }
    else if (clientTwoScore->getScore() == roundNumber) {
        clientOneTCPSocket->sendCommunicate(Communicates::YouLost);
        clientTwoTCPSocket->sendCommunicate(Communicates::YouWon);
        running = false;
    }

    waitForNextTour = true;
    loopCounter = 0;
    ball->reset();
}


void Server::runNextTour() {
    waitForNextTour = false;
    ball->launch();
}

}

#endif