#include "ConsoleClient.h"

namespace pong {



ConsoleClient::ConsoleClient(std::string serverIPv4Str, int serverPort) {
    this->serverIPv4Str = serverIPv4Str;
    this->serverPort = serverPort;

    inputBlocking = new InputBlocking();

    //network variables.
    serverIPv4 = new SocketAddress(serverIPv4Str, serverPort);
    clientIPv4 = new SocketAddress();
    clientSocketTCP = new PongSocketTCP();
    clientSocketUDP = new SocketUDP();
    clientSocketUDP->setNonBlocking(true);

    //game variables.
    clientOneScore = new Score();
    clientTwoScore = new Score();
    ball = new Ball(centralX - Ball::LENGTH/2, centralY - Ball::LENGTH/2);
    clientOnePaddle = new Paddle(0, centralY + Paddle::HEIGHT);
    clientTwoPaddle = new Paddle(Table::WIDTH - Paddle::WIDTH, centralY + Paddle::HEIGHT);

    display = new ConsoleClientDisplay(clientOneScore, clientTwoScore, ball, clientOnePaddle, clientTwoPaddle);
}

ConsoleClient::~ConsoleClient() {
    delete inputBlocking;
    delete display;

    delete serverIPv4;
    delete clientIPv4;
    delete clientSocketTCP;
    delete clientSocketUDP;

    delete clientOneScore;
    delete clientTwoScore;
    delete ball;
    delete clientOnePaddle;
    delete clientTwoPaddle;
}


void ConsoleClient::start() {
    connect();

    if (!successfullyConnected) return;

    display->clearScreen();
    display->drawLine();

    while (running) {
        display->drawBall();
        display->drawPaddles();
        display->drawScoreBoard();

        if (inputBlocking->isBlocked()) {
            if (userInput->isPressedJoysticUp()) {
                sendMove(-3);
                inputBlocking->startBlocking(20);
            }
            else if (userInput->isPressedJoysticDown()) {
                sendMove(3);
                inputBlocking->startBlocking(20);
            } else if (userInput->isPressedRightButton()) {
                clientSocketTCP->sendCommunicate(Communicates::Disconnect);
                return;
            }
        }

        delay(25);
        inputBlocking->decrement();

        receiveState();

        handleMessagesFromServer();
    }
}


void ConsoleClient::connect() {
    connectionInfo("Conection...", 0);

    // UDP ------------------------------------------------------
    e = clientSocketUDP->init_();
    if (e == ERROR) {
        connectionError("Cannot create UDP socket.", 5000);
        return;
    }

    e = clientSocketUDP->bind_(clientIPv4);
    if (e == ERROR) {
        connectionError("Cannot create UDP socket.", 5000);
        return;
    }

    e = clientSocketUDP->getSocketName_(clientIPv4);
    if (e == ERROR) {
        connectionError("Cannot bind UDP address.", 5000);
        return;
    }

    clientSocketUDP->setNonBlocking(true);
    clientSocketTCP->setNonBlocking(false);

    // TCP ------------------------------------------------------
    e = clientSocketTCP->init_();
    if (e == ERROR) {
        connectionError("Cannot create TCP socket.", 5000);
        return;
    }

    e = clientSocketTCP->connect_(*serverIPv4);
    if (e == ERROR) {
        connectionError("Cannot connect to server TCP socket.", 5000);
        return;
    }

    connectionInfo("Waiting for a new game...", 0);

    Communicates firstCommunicate = clientSocketTCP->receiveCommunicate();

    if (firstCommunicate != Communicates::SendPortUDP) {
        connectionError("Unexpected message from server.", 5000);
        return;
    }

    clientSocketTCP->sendPortUDP(clientIPv4->getPort());

    Communicates secondCommunicate = clientSocketTCP->receiveCommunicate();

    switch (secondCommunicate) {
        case Communicates::SuccessfulConnected:
            connectionInfo("Successfuly connection established.", 0);
            break;
        case Communicates::InternalServerError:
            connectionError("Internal server error.", 5000);
            return;
        case Communicates::SecondPlayerLeftTheGame:
            connectionError("Second player left the game.", 5000);
            return;
        default:
            connectionError("Unexpected message from server.", 5000);
            return;
    }

    clientSocketTCP->setNonBlocking(true);
    successfullyConnected = true;
    running = true;

}


void ConsoleClient::connectionError(std::string message, int time) {
    display->clearScreen();
    display->drawInfo(message, "ERROR");
    successfullyConnected = false;
    delay(time);
}


void ConsoleClient::connectionInfo(std::string message, int time) {
    display->clearScreen();
    display->drawInfo(message, "INFO");
    delay(time);
}


void ConsoleClient::gameSummary(std::string message, Color color, int time) {
    display->clearScreen();
    display->drawSummary(message, color);
    running = false;
    delay(time);    
}


void ConsoleClient::receiveState() {
    SocketAddress _;
    const int maxReceivedStates = 10;
    int receivedStates = 0;

    while (receivedStates < maxReceivedStates) {
        int readBytes = clientSocketUDP->receiveFrom_(nativeBuffer, nativeBufferSize, _);
        if (readBytes <= 0) {
            return;
        }
        InputMemoryStream in = InputMemoryStream(nativeBuffer, readBytes);
        clientOnePaddle->read(in);
        clientTwoPaddle->read(in);
        ball->read(in);
        clientOneScore->read(in);
        clientTwoScore->read(in);

        receivedStates++;
    }
}


void ConsoleClient::sendMove(int val) {
    Move move(val);
    OutputMemoryStream out;
    move.write(out);
    clientSocketUDP->sendTo_(out.getBufferPtr(), (int) out.getLength(), *serverIPv4);
}


void ConsoleClient::handleMessagesFromServer() {
    Communicates receivedMessage = clientSocketTCP->receiveCommunicate();

    switch (receivedMessage) {
        case Communicates::None:
            break;
        case Communicates::Disconnect:
            gameSummary("The server requested that the communication be terminated.", Color::YELLOW_, 5000);
            break;
        case Communicates::SecondPlayerLeftTheGame:
            gameSummary("Second player left the game.", Color::YELLOW_, 5000);
            break;
        case Communicates::YouLost:
            gameSummary("You lost!", Color::RED_, 5000);
            break;
        case Communicates::YouWon:
            gameSummary("You won!", Color::GREEN_, 5000);
            break;
        case Communicates::StillLiveRequest:
            clientSocketTCP->sendCommunicate(Communicates::StillLiveReply);
            break;
    }
}




}
