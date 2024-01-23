#include <Brain.h>

// Set up the brain parser, pass it the hardware serial object you want to listen on.
Brain brain(Serial);

void setup() {
    // Start the hardware serial.
    Serial.begin(9600);
}

void loop() {
    // Expect packets about once per second.
    if (brain.update()) {
        // Print errors if any
        Serial.println(brain.readErrors());

        // Print CSV format of brain data
        Serial.println(brain.readCSV());

        // Access specific values
        Serial.print("Signal Quality: ");
        Serial.println(brain.readSignalQuality());

        Serial.print("Attention: ");
        Serial.println(brain.readAttention());

        Serial.print("Meditation: ");
        Serial.println(brain.readMeditation());

        // Access EEG power bands
        Serial.print("Delta: ");
        Serial.println(brain.readDelta());

        Serial.print("Theta: ");
        Serial.println(brain.readTheta());

        // Add more print statements for other values as needed

        // Print a separator line
        Serial.println("-------------------------");
    }
}
