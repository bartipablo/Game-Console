#ifndef PackageCounterUDP_H
#define PackageCounterUDP_H

#include "../streams/Serializable.h"

/**
 * This class is used to keep track of the number of packets received by the UDP socket.
 * Server should for each packet increment the counter and send this counter to the client.
 * The client should check if the counter is newer than the last counter and if so update the last counter.
 */
class PacketCounterUDP : public Serializable {

public:
    PacketCounterUDP() = default;

/**
 * Check if the packet is newer than the last one.
 */
    bool isPacketNewer();

/**
 * Increment the counter.
 * Should execute server side.
 */
    void incrementCounter();

/**
 * Update the last counter to the current counter.
 * Should execture client side.
 */
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