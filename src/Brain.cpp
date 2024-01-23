#include "Brain.h"

//This program will read brain waves from Mindflex

Brain::Brain(Stream& _brainStream) : brainStream(&_brainStream) {
    init();
}

void Brain::init() {
    freshPacket = false;
    inPacket = false;
    packetIndex = 0;
    packetLength = 0;
    eegPowerLength = 0;
    hasPower = false;
    checksum = 0;
    checksumAccumulator = 0;

    signalQuality = 200;
    attention = 0;
    meditation = 0;

    clearEegPower();
}

boolean Brain::update() {
    if (brainStream->available()) {
        latestByte = brainStream->read();

        if (inPacket) {
            handleInPacket();
        } else if (detectStartOfPacket()) {
            startOfPacket();
        }

        lastByte = latestByte;
    }

    return freshPacket;
}

// Other methods remain unchanged...
