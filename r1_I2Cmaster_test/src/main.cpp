#include <Arduino.h>
#include <PS4Controller.h>
#include <Wire.h>

#define m1_r 5
#define m1_l 18
#define m2_r 25
#define m2_l 26
#define m3_r 14
#define m3_l 27
#define m4_r 32
#define m4_l 33

#define slave_adrss 0x05

int basepwm = 100;


bool prevShareState = 0;
bool prevOptionsState = 0;
bool prevtouchpadState = 0;
bool servo1State = 0;
bool servo2State = 0;
bool mosfetState = 0;


void setMotor(int rpwm, int lpwm, uint8_t pwm_r, uint8_t pwm_l) {
  analogWrite(rpwm, pwm_r);
  analogWrite(lpwm, pwm_l);
}

void backward(){
  setMotor(m1_r, m1_l, basepwm, 0);
  setMotor(m2_r, m2_l, basepwm, 0);
  setMotor(m3_r, m3_l, 0, basepwm);
  setMotor(m4_r, m4_l, 0, basepwm);
}

void forward(){
  setMotor(m1_r, m1_l, 0, basepwm);
  setMotor(m2_r, m2_l, 0, basepwm);
  setMotor(m3_r, m3_l, basepwm, 0);
  setMotor(m4_r, m4_l, basepwm, 0);
}

void right(){
  setMotor(m1_r, m1_l, 0, basepwm);
  setMotor(m2_r, m2_l, basepwm, 0);
  setMotor(m3_r, m3_l, basepwm, 0);
  setMotor(m4_r, m4_l, 0, basepwm);
}

void left(){
  setMotor(m1_r, m1_l, basepwm, 0);
  setMotor(m2_r, m2_l, 0, basepwm);
  setMotor(m3_r, m3_l, 0, basepwm);
  setMotor(m4_r, m4_l, basepwm, 0);
}

void anticlockwise(){
  setMotor(m1_r, m1_l, basepwm, 0);
  setMotor(m2_r, m2_l, basepwm, 0);
  setMotor(m3_r, m3_l, basepwm, 0);
  setMotor(m4_r, m4_l, basepwm, 0);
}

void clockwise(){
  setMotor(m1_r, m1_l, 0, basepwm);
  setMotor(m2_r, m2_l, 0, basepwm);
  setMotor(m3_r, m3_l, 0, basepwm);
  setMotor(m4_r, m4_l, 0, basepwm);
}

void stopAll(){
  setMotor(m1_r, m1_l, 0, 0);
  setMotor(m2_r, m2_l, 0, 0);
  setMotor(m3_r, m3_l, 0, 0);
  setMotor(m4_r, m4_l, 0, 0);
}



void setup() {
  Serial.begin(115200);
  PS4.begin("1a:2b:3c:00:00:00");

  int pins[] = {18,5,14,27,25,26,32,33};
  for(int i=0;i<8;i++){  
    pinMode(pins[i], OUTPUT);
  }
  
  Wire.begin();
}



void loop() {  
  bool shareState = PS4.Share();
  bool optionsState = PS4.Options();
  bool touchpadState = PS4.Touchpad();
  
  char cmd = 'x'; 
   if(PS4.isConnected()){
    if(PS4.Right()) cmd = 'u';        // Mustika Up/Down
    else if(PS4.Left()) cmd = 'd';  
    else if(PS4.Up()) cmd = 'U';      // EarthBlock Up/Down
    else if(PS4.Down()) cmd = 'D';  
    else if(PS4.R1()) cmd = 'C';      // SkyBlock Rotate
    else if(PS4.L1()) cmd = 'A'; 
    else if(PS4.R3()) cmd = 'f';     // SkyBlock Grip/UnGrip 
    else if(PS4.L3()) cmd = 'b';
    else if(PS4.Share() && (shareState != prevShareState)){
      cmd = servo1State ? '1' : '0';  // Servo_Mustika
      servo1State = !servo1State;
    }
    else if(PS4.Options() && (optionsState != prevOptionsState)){
      cmd = servo2State ? 'X' : 'O';  // Servo_SkyBlock
      servo2State = !servo2State;
    }
    else if(PS4.Touchpad() && (touchpadState != prevtouchpadState)){
      cmd = mosfetState ? 'G' : 'g';  // Servo_SkyBlock
      mosfetState = !mosfetState;
    } 
    else cmd = 'x';

    prevShareState = shareState;
    prevOptionsState = optionsState;
    prevtouchpadState = touchpadState;
  }

  Wire.beginTransmission(slave_adrss);  //Start Communication with (Slave)Arduino Mega
  Wire.write(cmd);                      //Sending data to I2C Slave 
  Wire.endTransmission();


  if(PS4.isConnected()){
    
    if(PS4.Triangle()){
       forward();
       Serial.println("Forward");
    }
    else if(PS4.Cross()){
       backward();
       Serial.println("Backward");
    }
    else if(PS4.Square()){
       left();
       Serial.println("Left");
    }
    else if(PS4.Circle()){
       right();
       Serial.println("Right");
    }
    else if(PS4.R2()){
       clockwise();
       Serial.println("Clockwise");
    }
    else if(PS4.L2()){
       anticlockwise();
       Serial.println("Anti-Clockwise");
    }
    else{
       stopAll();
       Serial.println("Stopped");
    }  
  }
}