#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

#define canInt 4            // CAN INTERRUPT POIN
#define canCs 5             //CHIP SELECT FOR PURPLE PCB
#define buzzerPin 15        //BUZZER PIN FOR PURPLE PCB
#define MAX_SPEED 8000      //maximum is 16000, 
#define LIFT_POWER 2000     // Lift Speed

const float kP = 0.5;  
const float kI = 0.01; 
const float kD = 0.05;  


#endif 
