#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>

#define SB_r 28              // Following Pins on mega are digtalpins  
#define SB_l 29              // So use digitalWrite for these pins 
#define SBrot_r 24           // analogWrite won't work
#define SBrot_l 25
#define EB_r 8
#define EB_l 9
#define must_r 30
#define must_l 31 
#define mosfet1 45
#define mosfet2 47

Servo servo_ball, servo2_skyblock;

int basepwm = 25;

volatile char cmd;

void setMotor(int rpwm, int lpwm, int pwm_r, int pwm_l) {
  digitalWrite(rpwm, pwm_r);   // Pins on mega are digtalpins 
  digitalWrite(lpwm, pwm_l);
}


void receiveEvent(int bytes) {      // Registering the callback does not receive any data by itself.
                                    // It establishes what should happen when data arrives.
  while(Wire.available()) {
    cmd = Wire.read();
    //Serial.print("Received :"); 
    
    switch(cmd){
    case 'u' :
      setMotor(SB_r, SB_l, 0, basepwm);
      //Serial.print(cmd);
      Serial.println(": SkyBlock Grip");
      break;

    case 'd' :
      setMotor(SB_r, SB_l, basepwm, 0);
      //Serial.print(cmd);
      Serial.println(": SkyBlock UnGrip");
      break;

    case 'U' :
      setMotor(EB_r, EB_l, 0, basepwm);
      //Serial.print(cmd);
      Serial.println(": Earthblock Gripper UP");
      break;

    case 'D' :
      setMotor(EB_r, EB_l, basepwm, 0);
      //Serial.print(cmd);
      Serial.println(": Earthblock Gripper Down");
      break;
 

    case 'A' :
      setMotor(SBrot_r, SBrot_l, 0, basepwm);
      //Serial.print(cmd);
      Serial.println(": Rotate Gripper Clockwise");
      break; 

    case 'C' :
      setMotor(SBrot_r, SBrot_l, basepwm, 0);
      //Serial.print(cmd);
      Serial.println(": Rotate Gripper Anti-Clockwise");
      break;  

    case 'f' :
      setMotor(must_r, must_l, basepwm, 0);
      //Serial.print(cmd);
      Serial.println(": SkyBlock Gripper Up");
      break;  

    case 'b' :
      setMotor(must_r, must_l, 0, basepwm);
      //Serial.print(cmd);
      Serial.println(": SkyBlock Gripper Down");
      break;  

    case '0' :
      servo_ball.write(60);
      //Serial.print(cmd);
      Serial.println(": Servo 60");
      break;  

    case '1' :
      servo_ball.write(120);
      //Serial.print(cmd);
      Serial.println(": Servo 90");
      break; 

    case 'O' :
      servo2_skyblock.write(50);
      //Serial.print(cmd);
      Serial.println(": Servo2 60");
      break;  

    case 'X' :
      servo2_skyblock.write(100);
      //Serial.print(cmd);
      Serial.println(": Servo2 90");
      break;

    case 'G' :
      digitalWrite(mosfet1, HIGH);
      digitalWrite(mosfet2, LOW);
      Serial.print(cmd);
      Serial.println(": EarthBlock Grip");
      break;

    case 'g' :
      digitalWrite(mosfet1, LOW);
      digitalWrite(mosfet2, HIGH);
      Serial.print(cmd);
      Serial.println(": EarthBlock UnGrip");
      break;  

    case 'x' :
      setMotor(EB_r, EB_l, 0, 0);
      setMotor(SB_r, SB_l, 0, 0);
      setMotor(SBrot_r, SBrot_l, 0, 0);
      setMotor(must_r, must_l, 0, 0);
      //Serial.print(cmd);
      //Serial.println(": Kill...");
      break;      

    default : 
      // Ignore unknown commands 
      break;
  }
 }
}

void setup() {
  Serial.begin(115200);

  int pins[] = {28,29,24,25,8,9,30,31,45,47};
  for(int i=0;i<10;i++){  
    pinMode(pins[i], OUTPUT);
  }
  servo_ball.attach(5);
  servo2_skyblock.attach(7);
  
  Wire.begin(0x05);
  Wire.onReceive(receiveEvent); // This passes the function to the library so it can call it later. 
                                // The 'receiveEvent()' attempts to call the function immediately, which is not what we want.
}

void loop() {
  //Nothing to do here
}