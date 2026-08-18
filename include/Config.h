#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

#define can1_Cs 5             //CAN 1 CS PIN
#define can1_Int 4            //CAN 1 INTERRUPT POIN

#define can2_Cs 15            //CAN 2 cs PIN
#define can2_Int 16           //CAN 2 INTERRUPT PIN

#define buzzerPin 19        //BUZZER PIN FOR PURPLE PCB
#define MAX_SPEED 8000      //maximum is 16000, 
#define LIFT_POWER 7000     // Lift Speed

const int SDA_PIN = 32;
const int SCL_PIN = 33;

const float kP = 0.5;  
const float kI = 0.01; 
const float kD = 0.05;  


#endif 
