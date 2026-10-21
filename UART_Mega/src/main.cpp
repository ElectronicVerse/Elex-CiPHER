#include <Arduino.h>

unsigned long receivedTime;
unsigned long data;

void setup()
{
    Serial.begin(115200);
    Serial1.begin(115200);

    Serial.println("Mega Ready");
}

void loop()
{
    if (Serial1.available() > 0)
    {
        receivedTime = Serial1.parseInt();

        data = millis() - receivedTime;

        Serial.print("Received timestamp: ");
        Serial.println(receivedTime);

        Serial.print("Time difference: ");
        Serial.print(data);
        Serial.println(" ms");
    }
}