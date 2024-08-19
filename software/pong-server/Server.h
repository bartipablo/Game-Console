#ifdef ARDUINO
 // to ignore by arduino compiler.
#else


#ifndef PONG_SERVER_H
#define PONG_SERVER_H


#include "Communicates.h"
#include "SocketUDP.h"
#include "PacketCounterUDP.h"
#include "PongSocketTCP.h"
#include "InputMemoryStream.h"
#include "OutputMemoryStream.h"

#include "PongScore.h"
#include "Ball.h"
#include "Table.h"
#include "Paddle.h"
#include "Move.h"

#include "Timer.h"

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
    std::shared_ptr<pong::PongSocketTCP> serverTCPSocket;

    std::shared_ptr<sockets::SocketUDP> serverUDPSocket;

    std::shared_ptr<sockets::SocketAddress> serverAddress;

    std::shared_ptr<Timer> frameTimer;


    // client one variables--------------------------
    std::shared_ptr<sockets::SocketAddress> clientOneAddress;

    std::shared_ptr<pong::PongSocketTCP> clientOneTCPSocket;
    // client one variables--------------------------


    // client two variables--------------------------
    std::shared_ptr<sockets::SocketAddress> clientTwoAddress;

    std::shared_ptr<pong::PongSocketTCP> clientTwoTCPSocket;
    // client two variables--------------------------


    // game states -----------------------------------
    bool running;

    bool waitForNextTour;
    // game states ------------------------------------


    // game variables ---------------------------------
    std::shared_ptr<pong::Score> clientOneScore;

    std::shared_ptr<pong::Score> clientTwoScore;

    std::shared_ptr<pong::Ball> ball;

    std::shared_ptr<pong::Paddle> clientOnePaddle;

    std::shared_ptr<pong::Paddle> clientTwoPaddle;

    std::shared_ptr<sockets::PacketCounterUDP> packetCounterUDP;
    // game variables ---------------------------------


    // game properties --------------------------------
    int roundNumber = 10;

    int centralX = Table::WIDTH/2;

    int centralY = Table::SCORE_HEIGHT + (Table::HEIGHT - Table::SCORE_HEIGHT)/2;
    // game properties --------------------------------

    // others -----------------------------------------
    sockets::EXIT_STATUS e;

    static constexpr int nativeBufferSize = 1024;

    char nativeBuffer[nativeBufferSize];

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

    const int loopCountToNextTour = 200;
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

#endif

#endif //EXAMPLE_SERVER_H
