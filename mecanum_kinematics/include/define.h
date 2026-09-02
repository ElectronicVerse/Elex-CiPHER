#ifndef define_h
#define define_h
#include "declare.h"    


void Chassis::motion(int lpwm, int rpwm){          // definition
    analogWrite(m_pin1, lpwm);
    analogWrite(m_pin2, rpwm);
    //Serial.println("Monitoring...");
}


#endif