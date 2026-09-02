#include <Arduino.h>
#include <PS4Controller.h>

#include "declare.h"
#include "define.h"
#include "kinematics.h"

//int basespeed = 80;


Chassis m1(18, 5), m2(26, 25), m3(14, 27), m4(32, 33);

void setup() {
  Serial.begin(115200);
  PS4.begin("1a:2b:3c:00:00:00");
}

void loop() {
  if(PS4.isConnected()) {
    cal_pwm();
    if (PS4.Triangle()) {
      m1.motion(0, PWM[0]);
      m2.motion(0, PWM[1]);
      m3.motion(0, PWM[2]);
      m4.motion(0, PWM[3]);
      Serial.printf("Forward : %d %d %d %d \n", PWM[0], PWM[1], PWM[2], PWM[3]);
    } 
    else if (PS4.Cross()) {
      m1.motion(PWM[0], 0);
      m2.motion(PWM[1], 0);
      m3.motion(PWM[2], 0);
      m4.motion(PWM[3], 0);
      Serial.printf("Backward : %d %d %d %d \n", PWM[0], PWM[1], PWM[2], PWM[3]);
    } 
    else if (PS4.Square()) {
      m1.motion(PWM[0], 0);         // calling
      m2.motion(0, PWM[1]);
      m3.motion(PWM[2], 0);
      m4.motion(0, PWM[3]);
      Serial.printf("Left : %d %d %d %d \n", PWM[0], PWM[1], PWM[2], PWM[3]);
    } 
    else if (PS4.Circle()) {
      m1.motion(0, PWM[0]);
      m2.motion(PWM[1], 0);
      m3.motion(0, PWM[2]);
      m4.motion(PWM[3], 0);
      Serial.printf("Right : %d %d %d %d \n", PWM[0], PWM[1], PWM[2], PWM[3]);
    } 
    else if (PS4.L2()) {
      m1.motion(0, PWM[0]);
      m2.motion(0, PWM[1]);
      m3.motion(PWM[2], 0);
      m4.motion(PWM[3], 0);
      Serial.printf("Clockwise : %d %d %d %d \n", PWM[0], PWM[1], PWM[2], PWM[3]);
    } 
    else if (PS4.R2()) {
      m1.motion(PWM[0], 0);
      m2.motion(PWM[1], 0);
      m3.motion(0, PWM[2]);
      m4.motion(0, PWM[3]);
      Serial.printf("Anti-Clockwise : %d %d %d %d \n", PWM[0], PWM[1], PWM[2], PWM[3]);
    } 
    else {
      m1.motion(0, 0);
      m2.motion(0, 0);
      m3.motion(0, 0);
      m4.motion(0, 0);
      Serial.println("Stop");
    } 
  }
}