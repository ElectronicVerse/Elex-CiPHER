#include <Arduino.h>
#include <PS4Controller.h>
#include "Setup.h"

int basespeed = 80;


void Chassis::motion(int lpwm, int rpwm){          // definition
    analogWrite(m_pin1, lpwm);
    analogWrite(m_pin2, rpwm);
    //Serial.println("Monitoring...");
}

/*
void Chassis::forward(int speed){          // definition
    analogWrite(m_pin1, speed);
    analogWrite(m_pin2, 0);
    Serial.println("motion");
}

void Chassis::backward(int speed){
    analogWrite(m_pin1, 0);
    analogWrite(m_pin2, speed);
    Serial.println("motion");
} 

void Chassis::left(int speed){
    analogWrite(m_pin1, speed);
    analogWrite(m_pin2, 0);
    Serial.println("motion"); 
} 

void Chassis::right(int speed){
    analogWrite(m_pin1, 0);
    analogWrite(m_pin2, speed);
    Serial.println("motion");
}

void Chassis::rotate(int rpwm,int lpwm)   // Optimization for motion
{
  analogWrite(m_pin1, rpwm);
  analogWrite(m_pin2, lpwm);
}

void Chassis::kill(int speed){
    analogWrite(m_pin1, speed);
    analogWrite(m_pin2, 0);
    Serial.println("Stop");
}
*/



Chassis m1(18, 5), m2(26, 25), m3(14, 27), m4(32, 33);

void setup() {
  Serial.begin(115200);
  PS4.begin("1a:2b:3c:00:00:00");
}

void loop() {
  if(PS4.isConnected()) {
    if (PS4.Triangle()) {
      m1.motion(basespeed, 0);         // call
      m2.motion(0, basespeed);
      m3.motion(basespeed, 0);
      m4.motion(0, basespeed);
      Serial.println("Forward");
    } 
    else if (PS4.Cross()) {
      m1.motion(0, basespeed);
      m2.motion(basespeed, 0);
      m3.motion(0, basespeed);
      m4.motion(basespeed, 0);
      Serial.println("Backward");
    } 
    else if (PS4.Square()) {
      m1.motion(basespeed, 0);
      m2.motion(basespeed, 0);
      m3.motion(basespeed, 0);
      m4.motion(basespeed, 0);
      Serial.println("Left");
    } 
    else if (PS4.Circle()) {
      m1.motion(0, basespeed);
      m2.motion(0, basespeed);
      m3.motion(0, basespeed);
      m4.motion(0, basespeed);
      Serial.println("Right");
    } 
    else if (PS4.L2()) {
      m1.motion(0, basespeed);
      m2.motion(0, basespeed);
      m3.motion(basespeed, 0);
      m4.motion(basespeed, 0);
      Serial.println("Clockwise");
    } 
    else if (PS4.R2()) {
      m1.motion(basespeed, 0);
      m2.motion(basespeed, 0);
      m3.motion(0, basespeed);
      m4.motion(0, basespeed);
      Serial.println("Anti-Clockwise");
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