#ifdef ARDUINO
 // to ignore by arduino compiler.
#else


#ifndef DESKTOP_CLIENT_H
#define DESKTOP_CLIENT_H

#include "raylib.h"

#include "PongSocketTCP.h"
#include "Communicates.h"
#include "PongScore.h"
#include "Paddle.h"
#include "Ball.h"
#include "Move.h"

#include "SocketUDP.h"
#include "PacketCounterUDP.h"

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
    std::shared_ptr<sockets::SocketAddress> clientIPv4;

    std::shared_ptr<sockets::SocketAddress> serverIPv4;

    int serverPort;

    std::shared_ptr<pong::PongSocketTCP> clientSocketTCP;

    std::shared_ptr<sockets::SocketUDP> clientSocketUDP;

    std::shared_ptr<sockets::PacketCounterUDP> packetCounterUDP;
    // network properties ----------------------

    // game variables ---------------------------------
    std::shared_ptr<pong::Score> clientOneScore;

    std::shared_ptr<pong::Score> clientTwoScore;

    std::shared_ptr<pong::Ball> ball;

    std::shared_ptr<pong::Paddle> clientOnePaddle;

    std::shared_ptr<pong::Paddle> clientTwoPaddle;

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

    sockets::EXIT_STATUS e;

    char nativeBuffer[1024];

    static const int nativeBufferSize = 1024;
};

}

#endif

#endif
