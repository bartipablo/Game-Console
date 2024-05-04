#ifdef ARDUINO
 // to ignore by arduino compiler.
#else


#include "DesktopClient.h"


int main(int argc, char* argv[]) {

    if (argc != 3) {
        std::cerr << "Invalid argument number." << std::endl;
        std::cout << "expected arguments: [server IPv4] [server port]" << std::endl;
        exit(1);
    }

    std::string serverIPv4 = argv[1];

    for (char* p = argv[2]; *p; ++p) {
        if (!std::isdigit(*p)) {
            std::cerr << "Server port must be an integer." << std::endl;
            std::cout << "expected arguments: [server IPv4] [server port]" << std::endl;
            exit(2);
        }
    }

    int serverPort = std::atoi(argv[2]);

    pong::DesktopClient desktopClient(serverIPv4, serverPort);

    desktopClient.start();

    return 0;
}


namespace pong {

DesktopClient::DesktopClient(std::string serverIPv4, int serverPort) : serverIPv4str(std::move(serverIPv4)), serverPort(serverPort)  {}


void DesktopClient::start() {
    initNetworkVariables();

    connect();

    initGameVariables();

    SetTraceLogLevel(LOG_WARNING);

    InitWindow(screenWidth, screenHeight, "PONG DESKTOP");
    SetTargetFPS(40);


    while (!WindowShouldClose() && running)
    {
        BeginDrawing();

        ClearBackground(BLACK);

        drawBall();
        drawPaddles();
        drawLine();
        drawScore();

        EndDrawing();

        if (IsKeyDown(KEY_UP)) {
            sendMove(3);
        }
        else if (IsKeyDown(KEY_DOWN)) {
            sendMove(-3);
        }

        receiveState();

        handleMessagesFromServer();


    }
    CloseWindow();

    if (running) clientSocketTCP->sendCommunicate(Communicates::Disconnect);

    closeResources();
}

void DesktopClient::drawBall() {
    DrawRectangle(ball->getX(), ball->getY(), ball->LENGTH, ball->LENGTH, WHITE);
}


void DesktopClient::drawPaddles() {
    DrawRectangle(clientOnePaddle->getX(), clientOnePaddle->getY(), clientOnePaddle->WIDTH, clientOnePaddle->HEIGHT, WHITE);
    DrawRectangle(clientTwoPaddle->getX(), clientTwoPaddle->getY(), clientTwoPaddle->WIDTH, clientTwoPaddle->HEIGHT, WHITE);
}

void DesktopClient::drawLine() {
    DrawRectangle(0, 20, 320, 1, WHITE);
}

void DesktopClient::drawScore() {
    std::ostringstream oss;
    oss << clientOneScore->getScore() << "  :  " << clientTwoScore->getScore();
    DrawText(oss.str().c_str(), 150, 5, 12, WHITE);
}


void DesktopClient::connect() {
    std::cout << "Connection..." << std::endl;

    // UDP ------------------------------------------------------
    e = clientSocketUDP->init_();
    if (e == ERROR) {
        connectionError("Cannot create UDP socket.");
    }

    e = clientSocketUDP->bind_(clientIPv4.get());
    if (e == ERROR) {
        connectionError("Cannot create UDP socket.");
    }

    e = clientSocketUDP->getSocketName_(clientIPv4.get());
    if (e == ERROR) {
        connectionError("Cannot bind UDP address.");
    }

    clientSocketUDP->setNonBlocking(true);
    clientSocketTCP->setNonBlocking(false);

    // TCP ------------------------------------------------------
    e = clientSocketTCP->init_();
    if (e == ERROR) {
        connectionError("Cannot create TCP socket.");
    }

    e = clientSocketTCP->connect_(*serverIPv4);
    if (e == ERROR) {
        connectionError("Cannot connect to server TCP socket.");
    }

    std::cout << "Waiting for new game..." << std::endl;

    Communicates firstCommunicate = clientSocketTCP->receiveCommunicate();

    if (firstCommunicate != Communicates::SendPortUDP) {
        connectionError("Unexpected message from server.");
    }

    clientSocketTCP->sendPortUDP(clientIPv4->getPort());

    Communicates secondCommunicate = clientSocketTCP->receiveCommunicate();

    switch (secondCommunicate) {
        case Communicates::SuccessfulConnected:
            std::cout << "Connection successfully established!" << std::endl;
            break;
        case Communicates::InternalServerError:
            connectionError("Internal server error.");
        case Communicates::SecondPlayerLeftTheGame:
            connectionError("Second player left the game.");
        default:
            connectionError("Unexpected message from server.");
    }

    clientSocketTCP->setNonBlocking(true);
}

void DesktopClient::initNetworkVariables() {
    serverIPv4 = std::make_shared<SocketAddress>(serverIPv4str, serverPort);
    clientIPv4 = std::make_shared<SocketAddress>();
    clientSocketTCP = std::make_shared<PongSocketTCP>();
    clientSocketUDP = std::make_shared<SocketUDP>();
    clientSocketUDP->setNonBlocking(true);
}


void DesktopClient::initGameVariables() {
    clientOneScore = std::make_shared<Score>();
    clientTwoScore = std::make_shared<Score>();

    ball = std::make_shared<Ball>(centralX - Ball::LENGTH/2, centralY - Ball::LENGTH/2);

    clientOnePaddle = std::make_shared<Paddle>(0, centralY + Paddle::HEIGHT);
    clientTwoPaddle = std::make_shared<Paddle>(Table::WIDTH - Paddle::WIDTH, centralY + Paddle::HEIGHT);
}


void DesktopClient::connectionError(const std::string& errorMessage) {
    clientSocketTCP->close_();
    clientSocketUDP->close_();
    std::cout << errorMessage << std::endl;
    exit(3);
}


void DesktopClient::sendMove(int val) {
    Move move(val);
    OutputMemoryStream out;
    move.write(out);
    clientSocketUDP->sendTo_(out.getBufferPtr(), (int) out.getLength(), *serverIPv4);
}


void DesktopClient::receiveState() {
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

void DesktopClient::handleMessagesFromServer() {
    Communicates receivedMessage = clientSocketTCP->receiveCommunicate();

    switch (receivedMessage) {
        case Communicates::None:
            break;
        case Communicates::Disconnect:
            std::cout << "The server requested that the communication be terminated." << std::endl;
            running = false;
            break;
        case Communicates::SecondPlayerLeftTheGame:
            std::cout << "Second player left the game." << std::endl;
            running = false;
            break;
        case Communicates::YouLost:
            std::cout << "You lost!" << std::endl;
            running = false;
            break;
        case Communicates::YouWon:
            std::cout << "Congratulates! You won!" << std::endl;
            running = false;
            break;
        case Communicates::StillLiveRequest:
            clientSocketTCP->sendCommunicate(Communicates::StillLiveReply);
            break;
        default:
            std::cout << "Unexpected message from server." << std::endl;
    }
}

void DesktopClient::closeResources() {
    e = clientSocketTCP->close_();
    if (e == ERROR) {
        std::cout <<"ERROR: cannot close clientSocketTCP" << std::endl;
    }

    e = clientSocketUDP->close_();
    if (e == ERROR) {
        std::cout <<"ERROR: cannot close clientSocketUDP" << std::endl;
    }


}

}


#endif