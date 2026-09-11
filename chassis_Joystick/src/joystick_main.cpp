#include <Arduino.h>
#include <PS4Controller.h>

#include "init.h"
#include "definitions.h"
#include "kinematics_joystick.h"



void setup() {
  Serial.begin(115200);
  PS4.begin("1a:2b:3c:00:00:00");
}

void loop() {
  cal_joystick();
  cal_pwm();
  if(PS4.isConnected()) {
    if (PS4.Triangle()) {
      forward();
      Serial.printf("Forward %d %d %d %d %d \n", PWM[0], PWM[1], PWM[2], PWM[3]);
    } 
    else if (PS4.Cross()) {
      backward();
      Serial.printf("Backward %d %d %d %d %d \n", PWM[0], PWM[1], PWM[2], PWM[3]);
    } 
    else if (PS4.Square()) {
      left();
      Serial.println("Left");
    } 
    else if (PS4.Circle()) {
     right();
      Serial.println("Right");
    } 
    else if (PS4.L2()) {
      clockwise();
      Serial.println("Clockwise");
    } 
    else if (PS4.R2()) {
      anti_clockwise();
      Serial.println("Anti-Clockwise");
    } 
    else if (PS4.LStickY() || PS4.LStickX()){
      chassis_on_joystick();
      Serial.printf("PWM : %d %d %d %d %d \n", PWM[0], PWM[1], PWM[2], PWM[3]);
    }
    else{
      stop();
      Serial.println("Stop");
    } 
  }
  else {
     stop();
  }
}