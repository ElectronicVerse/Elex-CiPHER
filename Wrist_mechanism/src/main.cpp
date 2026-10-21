#include <Arduino.h>
#include <PS4Controller.h>

#define stepPin 25
#define dirPin 26 
#define stepPin_m2 14
#define dirPin_m2 27

#define stepsPerRevolution 200

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin_m2, OUTPUT);
  pinMode(dirPin_m2, OUTPUT);
  Serial.begin(115200);
  PS4.begin("1a:2b:3c:00:00:00");
}

void rotate_forward(){
  digitalWrite(dirPin, LOW);
  delay(10);

  for (int i = 0; i < stepsPerRevolution; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);

    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
}

void rotate_backward(){
  digitalWrite(dirPin, HIGH);
  delay(10);

  for (int i = 0; i < stepsPerRevolution; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);

    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
}

void twist_CW(){
  digitalWrite(dirPin, LOW);
  digitalWrite(dirPin_m2, LOW);
  delay(10);

  for (int i = 0; i < stepsPerRevolution; i++) {
    digitalWrite(stepPin, HIGH);
    digitalWrite(stepPin_m2, HIGH);  
    delayMicroseconds(500);

    digitalWrite(stepPin, LOW);
    digitalWrite(stepPin_m2, LOW);  
    delayMicroseconds(500);
  }
}

void twist_CCW(){
  digitalWrite(dirPin, HIGH);
  digitalWrite(dirPin_m2, HIGH);
  delay(10);

  for (int i = 0; i < stepsPerRevolution; i++) {
    digitalWrite(stepPin, HIGH);
    digitalWrite(stepPin_m2, HIGH);  
    delayMicroseconds(500);

    digitalWrite(stepPin, LOW);
    digitalWrite(stepPin_m2, LOW);  
    delayMicroseconds(500);
  }
}



void loop() {
  if (PS4.isConnected()) {
    if(PS4.Up()) {
      rotate_forward();
      Serial.println("rotating forward");
    }
    else if (PS4.Down()) {
      rotate_backward();
      Serial.println("rotating backward");
    }
    else if (PS4.Left()) {
      twist_CW();
      Serial.println("rotating clockwise");
    }
    else if (PS4.Right()) {
      twist_CCW();
      Serial.println("rotating anti-clockwise");
    }
    // else if (PS4.R1()) {
    //   rotate_forward();
    //   rotate_forward();
    //   delay(2000);
    //   twist_CW();
    //   twist_CW();
    //   Serial.println("rotating forward");
    // }
    // else {
    //   kill();
    // }
  }
}
