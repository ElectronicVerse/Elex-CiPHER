#ifndef init_h
#define init_h

#include <Arduino.h>

class Chassis{
public:
    Chassis(int pins[8]){
        for(int i = 0; i < 8; i++){
            m_pins[i] = pins[i];
            pinMode(m_pins[i], OUTPUT);
        }
       
    } 

    void motion(int motor, int lpwm, int rpwm);       // declaration

private:
    int m_pins[8];
};

int pins[8] = {18, 5, 26, 25, 14, 27, 32, 33};
Chassis motor(pins);

#endif