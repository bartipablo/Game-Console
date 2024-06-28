#include "PacketCounterUDP.h"

bool PacketCounterUDP::isPacketNewer() {
    if (counter > lastCounter) {
        return true;
    }
    else if (lastCounter - 1000 > counter) {
        return true;
    }
    return false;
}

void PacketCounterUDP::incrementCounter() {
    counter++;
}

void PacketCounterUDP::updateLastCounter() {
    lastCounter = counter;
}

void PacketCounterUDP::write(OutputMemoryStream &stream) {
    stream.write(&counter, sizeof(counter));
}

void PacketCounterUDP::read(InputMemoryStream &stream) {
    stream.read(&counter, sizeof(counter));
}

void PacketCounterUDP::reset() {
    counter = 0;
    lastCounter = 0;
}