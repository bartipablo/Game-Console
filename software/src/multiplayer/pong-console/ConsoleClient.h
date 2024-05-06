#ifndef PongConsoleClient_H
#define PongConsoleClient_H

#include <string>

#include "ConsoleClientDisplay.h"

#include "../../common/Color.h"

#include "../../utils/UserInput.h"
#include "../../utils/InputBlocking.h"

#include "../sockets/SocketAddress.h"
#include "../sockets/SocketUDP.h"
#include "../pong-game/PongSocketTCP.h"
#include "../pong-game/Score.h"
#include "../pong-game/Ball.h"
#include "../pong-game/Paddle.h"
#include "../pong-game/Communicates.h"
#include "../pong-game/Move.h"

namespace pong {

class ConsoleClient {

public:
    ConsoleClient(std::string serverIPv4Str, int serverPort);

    ~ConsoleClient();

    void start();

private:
    void connect();

    void connectionError(std::string message, int time);

    void connectionInfo(std::string message, int time);

    void gameSummary(std::string message, Color color, int time);

    void receiveState();

    void sendMove(int val);

    void handleMessagesFromServer();

    std::string serverIPv4Str;

    int serverPort;

    // network properties ----------------------
    SocketAddress* clientIPv4;

    SocketAddress* serverIPv4;

    PongSocketTCP* clientSocketTCP;

    SocketUDP* clientSocketUDP;

    // network properties ----------------------

    // game variables ---------------------------------
    Score* clientOneScore;

    Score* clientTwoScore;

    Ball* ball;

    Paddle* clientOnePaddle;

    Paddle* clientTwoPaddle;

    int centralX = Table::WIDTH/2;

    int centralY = Table::SCORE_HEIGHT + (Table::HEIGHT - Table::SCORE_HEIGHT)/2;
    // game variables ---------------------------------

    // for console service ------------------
    InputBlocking* inputBlocking;

    UserInput* userInput = UserInput::getInstance();

    ConsoleClientDisplay* display;
    // for console service ------------------

    // game state 
    bool successfullyConnected = false;

    bool running = false;

    EXIT_STATUS e;

    char nativeBuffer[1024];

    static const int nativeBufferSize = 1024;

};


}

#endif