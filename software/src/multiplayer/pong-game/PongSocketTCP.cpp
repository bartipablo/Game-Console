
#include "PongSocketTCP.h"

namespace pong {

PongSocketTCP::PongSocketTCP() {}

PongSocketTCP::PongSocketTCP(SOCKET inSocket) {
    mSocket = inSocket;
}


Communicates PongSocketTCP::receiveCommunicate() {
    Communicates reply = Communicates::None;

    char* nativeBuff = static_cast<char *>(malloc(sizeof(reply)));
    int readByes = receive_(nativeBuff, sizeof(reply));

    if (readByes == sizeof(reply)) {
        InputMemoryStream* in = new InputMemoryStream(nativeBuff, sizeof(reply));
        in->read((void*) &reply, sizeof (reply));
        delete in;
    }

    free(nativeBuff);

    return reply;
}


void PongSocketTCP::sendCommunicate(Communicates request) {
    OutputMemoryStream* out = new OutputMemoryStream;

    out->write((void*) &request, sizeof(request));
    send_(out->getBufferPtr(), out->getLength());

    delete out;
}


bool PongSocketTCP::receivePortUDP(SocketAddress *socketAddress, int timeout) {
    bool receivedPort = false;
    int port = -1;

    char* nativeBuff = static_cast<char *>(malloc(sizeof(int)));

    for (int i = 0; i < timeout; i++) {
        int readByes = receive_(nativeBuff, sizeof(int));

        if (readByes == sizeof(port)) {
            InputMemoryStream* in = new InputMemoryStream(nativeBuff, sizeof(port));
            in->read((void*) &port, sizeof (port));
            socketAddress->setPort(port);
            receivedPort = true;
            delete in;
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    free(nativeBuff);

    return receivedPort;
}


void PongSocketTCP::sendPortUDP(int port) {
    OutputMemoryStream* out = new OutputMemoryStream;

    out->write( (void*) &port, sizeof(port));
    send_(out->getBufferPtr(), out->getLength());

    delete out;
}

}