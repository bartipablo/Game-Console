/**
 * Enums for communication between server and client by TCP in the Pong game.
*/

#ifndef PONG_COMMUNICATES_H
#define PONG_COMMUNICATES_H

namespace pong {

enum class Communicates {
    None,
    StillLiveRequest,
    StillLiveReply,
    SendPortUDP,
    SuccessfulConnected,
    SecondPlayerLeftTheGame,
    InternalServerError,
    YouWon,
    YouLost,
    Disconnect
};

}

#endif //COMMUNICATES_H
