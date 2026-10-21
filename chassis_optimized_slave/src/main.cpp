#include <Arduino.h>
#include <Servo.h>
#include "Setup.h"

char cmd;

Chassis m1(24, 25), m2(8, 9), m3(28, 29), m4(30, 31);
Servo myservo, myservo2;

void setup() {
  myservo.attach(11);
  myservo2.attach(12);
  Serial.begin(9600);
  Serial1.begin(115200);

  Serial.println("Mega Slave Ready...");
}

void loop() {
   while (Serial1.available() > 0) {
  
    cmd = Serial1.read();

    if (cmd == 'U') {
      m1.motion(150, 0);
      Serial.println("Skyblock-Gripper rotate_CW");
    }
    else if (cmd == 'D') {
      m1.motion(0, 150);
      Serial.println("Skyblock-Gripper rotate_CCW"); ///////////////////////////
    }
    else if (cmd == 'u') {
      m2.motion(200, 0);
      Serial.println("Mustika-Gripper DOWN");
    }
    else if (cmd == 'd') {
      m2.motion(0, 200);
      Serial.println("Mustika-Gripper UP");  ///////////////////////////
    }
    else if (cmd == 'o') {
      m3.motion(0, 200);
      Serial.println("Earth Block down");
    }
    else if (cmd == 'c') {
      m3.motion(200, 0);
      Serial.println("Earth Block UP");  ///////////////////////////
    }
    else if (cmd == '1') {
      m4.motion(0, 200);
      Serial.println("Skyblock-Gripper UP");
    }
    else if (cmd == '0') {
      m4.motion(200, 0);
      Serial.println("Skyblock-Gripper Down");   ///////////////////////////
    }
    else if(cmd == 'S'){
      myservo.write(130);
      Serial.println("Servo 130");
    }
    else if(cmd == 's'){
      myservo.write(60);
      Serial.println("Servo 60");  ///////////////////////////
    }
    else if(cmd == 'O'){
      myservo.write(120);
    }
     else if(cmd == 'C'){
      myservo.write(60);
    }
    else {
      m1.motion(0, 0);
      m2.motion(0, 0);
      m3.motion(0, 0);  
       m4.motion(0, 0); 
    }
  }
}