#include <Arduino.h>

unsigned long prevTime = 0;

void setup()
{
    Serial.begin(115200);

    Serial1.begin(
        115200,
        SERIAL_8N1,
        16,   // RX
        17    // TX
    );

    Serial.println("ESP32 Ready");
}

void loop()
{
    unsigned long currentTime = millis();

    if (currentTime - prevTime >= 500)
    {
        Serial1.println(currentTime);  // Send timestamp to Mega

        Serial.print("Sent: ");
        Serial.println(currentTime);

        prevTime = currentTime;
    }
}