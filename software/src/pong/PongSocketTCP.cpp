
#include "PongSocketTCP.h"

namespace pong {

PongSocketTCP::PongSocketTCP() {}

PongSocketTCP::PongSocketTCP(sockets::SOCKET inSocket) {
    mSocket = inSocket;
}


Communicates PongSocketTCP::receiveCommunicate() {
    Communicates reply = Communicates::None;

    char* nativeBuff = static_cast<char *>(malloc(sizeof(reply)));
    int readByes = receive_(nativeBuff, sizeof(reply));

    if (readByes == sizeof(reply)) {
        streams::InputMemoryStream* in = new streams::InputMemoryStream(nativeBuff, sizeof(reply));
        in->read((void*) &reply, sizeof (reply));
        delete in;
    }

    free(nativeBuff);

    return reply;
}


void PongSocketTCP::sendCommunicate(Communicates request) {
    streams::OutputMemoryStream* out = new streams::OutputMemoryStream;

    out->write((void*) &request, sizeof(request));
    send_(out->getBufferPtr(), out->getLength());

    delete out;
}


bool PongSocketTCP::receivePortUDP(sockets::SocketAddress *socketAddress, int timeout) {
    bool receivedPort = false;
    int port = -1;

    char* nativeBuff = static_cast<char *>(malloc(sizeof(int)));

    for (int i = 0; i < timeout; i++) {
        int readByes = receive_(nativeBuff, sizeof(int));

        if (readByes == sizeof(port)) {
            streams::InputMemoryStream* in = new streams::InputMemoryStream(nativeBuff, sizeof(port));
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
    streams::OutputMemoryStream* out = new streams::OutputMemoryStream;

    out->write( (void*) &port, sizeof(port));
    send_(out->getBufferPtr(), out->getLength());

    delete out;
}

}