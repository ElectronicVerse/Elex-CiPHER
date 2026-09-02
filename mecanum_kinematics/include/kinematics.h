#ifndef kinematics_h
#define kinematics_h
#include <Arduino.h>  // Just for Maths Library



float Vx = 2;  // linear forward  velocity 2m/s
float Vy = 0;
float Wz = 0;
float L  = 0;  // Lx + Ly (distance of wheel from centre of chassis)

   
float ang_vel[4];   // array to store calculated individual wheel velocity
float RPM[4];      // array to store calculated individual wheel velocity
int PWM[4];       // array to store the pwm required for individual wheel

void cal_angular_velocity(){
    float  w[4], r = 0.05;         // array for 4 wheels

   w[0] = (1/r)*(Vx - Vy - L*Wz);
   w[1] = (1/r)*(Vx + Vy + L*Wz);
   w[2] = (1/r)*(Vx + Vy - L*Wz);
   w[3] = (1/r)*(Vx - Vy + L*Wz);

    for(int i = 0; i < 4; i++){
        ang_vel[i] = w[i]; 
    }
}

void cal_wheel_RPM(){
    cal_angular_velocity();
    float rpm[4];
    rpm[0] = ang_vel[0]*(30/PI);      // w(60/2Pi)
    rpm[1] = ang_vel[1]*(30/PI);     
    rpm[2] = ang_vel[2]*(30/PI);     
    rpm[3] = ang_vel[3]*(30/PI);       

    for(int i = 0; i < 4; i++){
        RPM[i] = rpm[i];
    }
}

void cal_pwm(){
    cal_wheel_RPM();
    int max_rpm = 1100, pwm[4];
    pwm[0] = (RPM[0]*255)/max_rpm;
    pwm[1] = (RPM[1]*255)/max_rpm;
    pwm[2] = (RPM[2]*255)/max_rpm;
    pwm[3] = (RPM[3]*255)/max_rpm;

    for(int i = 0; i < 4; i++){
        PWM[i] = pwm[i];
    }
}

#endif