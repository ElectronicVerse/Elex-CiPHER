#ifndef Setup_h
#define Setup_h

#include <Arduino.h>
// #include <PS4Controller.h>

class Chassis{
public:
    Chassis(int lpwm, int rpwm){
        m_pin1 = lpwm;
        m_pin2 = rpwm;
        pinMode(lpwm, OUTPUT);
        pinMode(rpwm, OUTPUT);
    } 

    Chassis(int relay_pin){
        m_pin1 = relay_pin;
        pinMode(relay_pin, OUTPUT);
    }

    void motion(int lpwm, int rpwm);       // declaration
   
  
    // void joystick();

    // void switch_relay();

private:
    int m_pin1, m_pin2;
};

void Chassis::motion(int lpwm, int rpwm){          // definition
    analogWrite(m_pin1, lpwm);
    analogWrite(m_pin2, rpwm);
}

// void Chassis::joystick(){          // definition
//     //int x_pos = map(PS4.LStickX(),-127,127, 0, 0);
//     int y_pos = map(PS4.LStickY(),-126,127,-200,200);

//     if(y_pos > 30){  // x & y both -ve
//         analogWrite(m_pin1, y_pos);
//         analogWrite(m_pin2, 0);
//         //Serial.println(m_pin1, m_pin2);
//         Serial.print("Gripper Up :");  
//         Serial.println(y_pos);
//     }else if(y_pos < -30){
//         analogWrite(m_pin1, 0);
//         analogWrite(m_pin2, abs(y_pos));
//         Serial.print("Gripper Down :");  
//         Serial.println(-y_pos);  
//     }else{
//         analogWrite(m_pin1, 0);
//         analogWrite(m_pin2, 0);
//        // Serial.println("Stop");
//     }
// }

// void Chassis::switch_relay(){          // definition
//     if (PS4.R1()){
//         digitalWrite(m_pin1, HIGH);
//         Serial.println("Relay ON");
//     }else if(PS4.L1()){
//         digitalWrite(m_pin1, LOW);
//         Serial.println("Relay OFF"); 
//     }
// }


#endif 