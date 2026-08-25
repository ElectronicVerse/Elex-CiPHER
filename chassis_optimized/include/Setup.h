#ifndef Setup_h
#define Setup_h

#include <Arduino.h>

class Chassis{
public:
    Chassis(int lpwm, int rpwm){
        m_pin1 = lpwm;
        m_pin2 = rpwm;
        pinMode(lpwm, OUTPUT);
        pinMode(rpwm, OUTPUT);
    } 

    void motion(int lpwm, int rpwm);       // declaration
    // void backward(int speed);
    // void left(int speed);
    // void right(int speed);
    // void rotate(int lpwm, int rpwm);
    // void kill(int speed);

private:
    int m_pin1, m_pin2;
};

#endif 