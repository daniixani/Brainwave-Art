#ifndef Brain_h
#define Brain_h

#include "Arduino.h"
#include <Stream.h>

class Brain {
public:
    // Constructor
    Brain(Stream& _brainStream);

    // Methods
    void init();
    boolean update();
    char* readErrors();
    char* readCSV();
    void printCSV();
    void printDebug();
    uint8_t readSignalQuality();
    uint8_t readAttention();
    uint8_t readMeditation();
    uint32_t* readPowerArray();
    uint32_t readDelta();
    uint32_t readTheta();
    uint32_t readLowAlpha();
    uint32_t readHighAlpha();
    uint32_t readLowBeta();
    uint32_t readHighBeta();
    uint32_t readLowGamma();
    uint32_t readMidGamma();

private:
    // Constants
    static const uint8_t MAX_PACKET_LENGTH = 32;
    static const uint8_t EEG_POWER_BANDS = 8;

    // Properties
    Stream* brainStream;
    boolean freshPacket;
    boolean inPacket;
    uint8_t packetIndex;
    uint8_t packetLength;
    uint8_t eegPowerLength;
    boolean hasPower;
    uint8_t checksum;
    uint8_t checksumAccumulator;
    uint8_t latestByte;
    uint8_t lastByte;
    uint8_t signalQuality;
    uint8_t attention;
    uint8_t meditation;
    uint32_t eegPower[EEG_POWER_BANDS];
    char latestError[64];
    char csvBuffer[128];

    // Methods
    void clearPacket();
    void clearEegPower();
    boolean parsePacket();
    void handleInPacket();
    void handleFirstByte();
    void handleDataByte();
    void handleEndOfPacket();
    boolean detectStartOfPacket();
    void startOfPacket();
    void handlePacketLengthError();
    void handleParseError();
    void handleChecksumError();
    void handleEEGPower(uint8_t& index);
};

#endif
