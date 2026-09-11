#include <Arduino.h>
#include "init.h"
#include "kinematics_joystick.h"

#ifndef definitions_h
#define definitions_h


void Chassis::motion(int motor, int lpwm, int rpwm){          // definition
    analogWrite(m_pins[motor*2], lpwm);
    analogWrite(m_pins[motor*2+1], rpwm);
    //Serial.println("Monitoring...");
}

void cal_pwm();


void forward(){
    motor.motion(0, PWM[0], 0);
    motor.motion(1, 0, PWM[1]);
    motor.motion(2, PWM[2], 0);
    motor.motion(3, 0, PWM[3]);
}

void backward(){
    motor.motion(0, 0, PWM[0]);
    motor.motion(1, PWM[1], 0);
    motor.motion(2, 0, PWM[2]);
    motor.motion(3, PWM[3], 0);
}

void left(){
    motor.motion(0, PWM[0], 0);
    motor.motion(1, PWM[1], 0);
    motor.motion(2, PWM[2], 0);
    motor.motion(3, PWM[3], 0);
}

void right(){
    motor.motion(0, 0, PWM[0]);
    motor.motion(1, 0, PWM[1]);
    motor.motion(2, 0, PWM[2]);
    motor.motion(3, 0, PWM[3]);
}

void clockwise(){
    motor.motion(0, 0, PWM[0]);
    motor.motion(1, 0, PWM[1]);
    motor.motion(2, PWM[2], 0);
    motor.motion(3, PWM[3], 0);
}

void anti_clockwise(){
    motor.motion(0, PWM[0], 0);
    motor.motion(1, PWM[1], 0);
    motor.motion(2, 0, PWM[2]);
    motor.motion(3, 0, PWM[3]);
}

void chassis_on_joystick(){
    motor.motion(0, PWM[0], 0);
    motor.motion(1, PWM[1], 0);
    motor.motion(2, 0, PWM[2]);
    motor.motion(3, 0, PWM[3]);
}

void stop(){
    motor.motion(0, 0, 0);
    motor.motion(1, 0, 0);
    motor.motion(2, 0, 0);
    motor.motion(3, 0, 0);
}


#endif