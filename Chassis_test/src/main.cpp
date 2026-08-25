#include <Arduino.h>
#include <PS4Controller.h>

int baseSpeed = 80;

class Chassis{
public:
    Chassis(int lpwm, int rpwm){
        m_pin1 = lpwm;
        m_pin2 = rpwm;
        pinMode(lpwm, OUTPUT);
        pinMode(rpwm, OUTPUT);
    } 


    void forward(int speed);       // declaration
    void backward(int speed);
    void right(int speed);
    void left(int speed);
    void rotate(int lpwm, int rpwm);
    void kill(int speed);

private:
    int m_pin1, m_pin2;
};

void Chassis::forward(int speed){          // definition
    analogWrite(m_pin1, speed);
    analogWrite(m_pin2, 0);
    Serial.println("Forward");
}

void Chassis::backward(int speed){
    analogWrite(m_pin1, 0);
    analogWrite(m_pin2, speed);
    Serial.println("Backward");
} 

void Chassis::right(int speed){
    analogWrite(m_pin1, speed);
    analogWrite(m_pin2, 0);
    Serial.println("Right"); 
} 

void Chassis::left(int speed){
    analogWrite(m_pin1, 0);
    analogWrite(m_pin2, speed);
    Serial.println("Left");
}

// void Chassis::rotate(int speed){
//   if(speed > 0){
//     analogWrite(m_pin1, speed);
//     analogWrite(m_pin2, 0);
//   } else {
//     analogWrite(m_pin1, 0);
//     analogWrite(m_pin2, -speed);
//   }
//     Serial.println("Rotate");
// }
void Chassis::rotate(int rpwm,int lpwm)   // Optimization for rotate
{
  analogWrite(m_pin1, rpwm);
  analogWrite(m_pin2, lpwm);
}

void Chassis::kill(int speed){
    analogWrite(m_pin1, speed);
    analogWrite(m_pin2, 0);
    Serial.println("Stop");
}


Chassis m1(18, 5), m2(26, 25), m3(14, 27), m4(32, 33);

void setup() {
  Serial.begin(115200);
  PS4.begin("1a:2b:3c:00:00:00");
}

void loop() {
  if(PS4.isConnected()) {
    if (PS4.Up()) {
      m1.forward(baseSpeed);         // call
      m2.forward(baseSpeed);
      m3.forward(baseSpeed);
      m4.forward(baseSpeed);
    } else if (PS4.Down()) {
      m1.backward(baseSpeed);
      m2.backward(baseSpeed);
      m3.backward(baseSpeed);
      m4.backward(baseSpeed);
    } else if (PS4.Left()) {
      m1.left(baseSpeed);
      m2.left(baseSpeed);
      m3.left(baseSpeed);
      m4.left(baseSpeed);
    } else if (PS4.Right()) {
      m1.right(baseSpeed);
      m2.right(baseSpeed);
      m3.right(baseSpeed);
      m4.right(baseSpeed);
    } else if (PS4.R2()) {
      m1.rotate(baseSpeed, -baseSpeed);
      m2.rotate(baseSpeed, -baseSpeed);
      m3.rotate(baseSpeed, -baseSpeed);
      m4.rotate(baseSpeed, -baseSpeed);
    } else if (PS4.L2()) {
      m1.rotate(-baseSpeed, baseSpeed);
      m2.rotate(-baseSpeed, baseSpeed);
      m3.rotate(-baseSpeed, baseSpeed);
      m4.rotate(-baseSpeed, baseSpeed);
    } else {
      m1.kill(0);
      m2.kill(0);
      m3.kill(0);
      m4.kill(0);
    } 
  }
}