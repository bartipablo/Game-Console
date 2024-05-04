
#ifndef PONG_SERVER_H
#define PONG_SERVER_H

#include "../pong-game/Communicates.h"
#include "../sockets/SocketUDP.h"
#include "../pong-game/PongSocketTCP.h"
#include "../streams/InputMemoryStream.h"
#include "../streams/OutputMemoryStream.h"

#include "../pong-game/Score.h"
#include "../pong-game/Ball.h"
#include "../pong-game/Table.h"
#include "../pong-game/Paddle.h"
#include "../pong-game/Move.h"

#include <memory>
#include <iostream>
#include <thread>
#include <chrono>
#include <csignal>


namespace pong {

class Server {

public:
    Server();

    /**
     * Start the server loop.
    */
    void start();

    static const int PORT = 12345;

private:
    std::shared_ptr<PongSocketTCP> serverTCPSocket;

    std::shared_ptr<SocketUDP> serverUDPSocket;

    std::shared_ptr<SocketAddress> serverAddress;


    // client one variables--------------------------
    std::shared_ptr<SocketAddress> clientOneAddress;

    std::shared_ptr<PongSocketTCP> clientOneTCPSocket;
    // client one variables--------------------------


    // client two variables--------------------------
    std::shared_ptr<SocketAddress> clientTwoAddress;

    std::shared_ptr<PongSocketTCP> clientTwoTCPSocket;
    // client two variables--------------------------


    // game states -----------------------------------
    bool running;

    bool waitForNextTour;
    // game states ------------------------------------


    // game variables ---------------------------------
    std::shared_ptr<Score> clientOneScore;

    std::shared_ptr<Score> clientTwoScore;

    std::shared_ptr<Ball> ball;

    std::shared_ptr<Paddle> clientOnePaddle;

    std::shared_ptr<Paddle> clientTwoPaddle;
    // game variables ---------------------------------


    // game properties --------------------------------
    int roundNumber = 21;

    int centralX = Table::WIDTH/2;

    int centralY = Table::SCORE_HEIGHT + (Table::HEIGHT - Table::SCORE_HEIGHT)/2;
    // game properties --------------------------------

    // others -----------------------------------------
    EXIT_STATUS e;

    char nativeBuffer[1024];

    static const int nativeBufferSize = 1024;
    // others -----------------------------------------

    /**
     * Initialize server TCP, UDP sockets and bind address.
     * If any error occurs, the program will exit.
    */
    void initServerSockets();

    /**
     * This method initializes server loop to handle connections and game session.
     * This loop will run as long as connections to two clients are not established.
    */
    void connectionsService();

    /**
     * This method initializes the game session loop.
     * This loop will run as long as the game is running or clients are connected.
    */
    void gameSession();

    /**
     * This method receives the paddle moves from clients using UDP.
    */
    void receiveClientsMoves();

    /**
     * This method sends the game state to clients using UDP.
    */
    void sendGameStateToClients();

    /**
     * This message receives messages from clients using TCP.
    */
    void handleMessagesFromClients();

    void resetGameStates();

    void resetGameVariables();

    // scheduled tasks --------------------------------
    // variables used to delay the next tour.
    int loopCounter = 0;

    const int loopCountToNextTour = 300;
    // scheduled tasks --------------------------------

    /**
     * This method is called when client gets a score.
    */
    void nextTourHandler();

    /**
     * This method is called when next tour should be run.
    */
    void runNextTour();

};

}


#endif //EXAMPLE_SERVER_H
