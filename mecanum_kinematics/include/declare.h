#ifndef declare_h
#define declare_h

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
    
private:
    int m_pin1, m_pin2;
};


#endif 