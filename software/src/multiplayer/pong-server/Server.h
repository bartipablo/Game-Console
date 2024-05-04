
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

    EXIT_STATUS e;

    char nativeBuffer[1024];

    static const int nativeBufferSize = 1024;

    void initServerSockets();

    void connectionsService();

    void gameSession();

    void receiveClientsMoves();

    void sendGameStateToClients();

    void resetGameStates();

    void resetGameVariables();

    void handleMessagesFromClients();

    // scheduled tasks
    int loopCounter = 0;

    const int loopCountToNextTour = 300;

    void nextTourHandler();

    void runNextTour();

};

}


#endif //EXAMPLE_SERVER_H
