#include "PongApplication.h"


void PongApplication::start() {
    servermetadatain::ServerMetadataInput serverMetadataInput {};
    serverMetadataInput.start();

    std::string serverIPv4 = serverMetadataInput.getServerIPv4();
    int serverPort = serverMetadataInput.getServerPort();
    bool correctInputProvided = serverMetadataInput.isCorrectInputProvided();

    if (correctInputProvided) {
        pong::ConsoleClient client = { pong::ConsoleClient(serverIPv4, serverPort)  };
        client.start();
    }
}


void PongApplication::display() {
    using namespace mainmenudisplay;
    using basicdisplay::clearScreen;

    PongIcon pongIcon {};

    clearScreen();
    drawIcon(pongIcon);
    drawTitle(title);
    drawButtonInfo();
}