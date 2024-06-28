#ifndef PongConsoleClient_H
#define PongConsoleClient_H

#include <string>

#include "ConsoleClientDisplay.h"

#include "../../common/Color.h"
#include "../../common/BasicDisplay.h"
#include "../../common/Timer.h"

#include "../../utils/UserInput.h"

#include "../sockets/SocketAddress.h"
#include "../sockets/SocketUDP.h"
#include "../sockets/PacketCounterUDP.h"

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
    /**
     * Init connection with server.
    */
    void connect();

    /**
     * display and handle connection error.
    */
    void connectionError(std::string message, int time);

    /**
     * display and handle connection info.
    */
    void connectionInfo(std::string message, int time);

    /**
     * display and handle summary after loss/victory.
    */
    void gameSummary(std::string message, Color color, int time);

    /**
     * Receive the state of the game from the server by UDP.
    */
    void receiveState();

    /**
     * Send player move to the server.
    */
    void sendMove(int val);

    /**
     * Handle the messages received from the server by TCP.
     * If a new game state is received it is drawn on the screen
    */
    void handleMessagesFromServer();

    std::string serverIPv4Str;

    int serverPort;

    // network properties ----------------------
    SocketAddress* clientIPv4;

    SocketAddress* serverIPv4;

    PongSocketTCP* clientSocketTCP;

    SocketUDP* clientSocketUDP;

    PacketCounterUDP* packetCounterUDP;
    // network properties ----------------------

    // game variables ---------------------------------
    Timer* frameTimer;

    Score* clientOneScore;

    Score* clientTwoScore;

    Ball* ball;

    Paddle* clientOnePaddle;

    Paddle* clientTwoPaddle;

    int centralX = Table::WIDTH/2;

    int centralY = Table::SCORE_HEIGHT + (Table::HEIGHT - Table::SCORE_HEIGHT)/2;
    // game variables ---------------------------------

    // for console service ------------------
    UserInput* userInput = UserInput::getInstance();

    ConsoleClientDisplay* display;

    BasicDisplay* basicDisplay;
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