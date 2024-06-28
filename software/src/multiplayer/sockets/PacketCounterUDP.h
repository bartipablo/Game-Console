#ifndef PackageCounterUDP_H
#define PackageCounterUDP_H

#include "../streams/Serializable.h"

class PacketCounterUDP : public Serializable {

public:
    PacketCounterUDP() = default;

    bool isPacketNewer();

    void incrementCounter();

    void updateLastCounter();

    void reset();

    void write(OutputMemoryStream &stream) override;

    void read(InputMemoryStream &stream) override;

    unsigned int getCounter() const {
        return counter;
    }

    unsigned int getLastCounter() const {
        return lastCounter;
    }


private:
    unsigned int counter = 0;

    unsigned int lastCounter = 0;

};

#endif