#ifdef ARDUINO
 // to ignore by arduino compiler.
#else


#ifndef DESKTOP_CLIENT_H
#define DESKTOP_CLIENT_H

#include "raylib.h"

#include "../pong-game/PongSocketTCP.h"
#include "../pong-game/Communicates.h"
#include "../pong-game/Score.h"
#include "../pong-game/Paddle.h"
#include "../pong-game/Ball.h"
#include "../pong-game/Move.h"

#include "../sockets/SocketUDP.h"
#include "../sockets/PacketCounterUDP.h"

#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <utility>
#include <memory>
#include <sstream>

namespace pong {

class DesktopClient {

public:
    DesktopClient(std::string serverIPv4, int serverPort);

    void start();

private:
    /**
     * Init connection with server.
    */
    void connect();

    /**
     * Function called when an error occurs during the connection.
    */
    void connectionError(const std::string& errorMessage);

    void initNetworkVariables();

    void initGameVariables();

    /**
     * Draw the ball on the screen.
    */
    void drawBall();

    /**
     * Draw the paddles on the screen.
    */
    void drawPaddles();

    /**
     * Draw the line in the separator of the screen.
    */
    void drawLine();

    /**
     * Draw the score of the players on the screen.
    */
    void drawScore();

    /**
     * Send player move to the server.
    */
    void sendMove(int val);

    /**
     * Receive the state of the game from the server by UDP.
    */
    void receiveState();

    /**
     * Handle the messages received from the server by TCP.
    */
    void handleMessagesFromServer();

    void closeResources();

    std::string serverIPv4str;


    // network properties ----------------------
    std::shared_ptr<SocketAddress> clientIPv4;

    std::shared_ptr<SocketAddress> serverIPv4;

    int serverPort;

    std::shared_ptr<PongSocketTCP> clientSocketTCP;

    std::shared_ptr<SocketUDP> clientSocketUDP;

    std::shared_ptr<PacketCounterUDP> packetCounterUDP;
    // network properties ----------------------

    // game variables ---------------------------------
    std::shared_ptr<Score> clientOneScore;

    std::shared_ptr<Score> clientTwoScore;

    std::shared_ptr<Ball> ball;

    std::shared_ptr<Paddle> clientOnePaddle;

    std::shared_ptr<Paddle> clientTwoPaddle;

    int centralX = Table::WIDTH/2;

    int centralY = Table::SCORE_HEIGHT + (Table::HEIGHT - Table::SCORE_HEIGHT)/2;
    // game variables ---------------------------------


    // states properties  ----------------------
    bool running = true;

    // states properties  ----------------------

    // screen properties -----------------------
    std::string startText;

    const int screenWidth = 320;

    const int screenHeight = 240;

    // screen properties -----------------------

    EXIT_STATUS e;

    char nativeBuffer[1024];

    static const int nativeBufferSize = 1024;
};

}

#endif

#endif
