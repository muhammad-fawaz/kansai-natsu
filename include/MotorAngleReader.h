#ifndef MOTOR_ANGLE_READER_H
#define MOTOR_ANGLE_READER_H

#include <mcp_can.h>

// Structure holding RPM values for motors 1–8
struct MotorAngle
{
    short M1;
    short M2;
    short M3;
    short M4;
    short M5; // Yagura Lift (0x205)
    short M6; // Conveyor (0x206)
    short M7; // Lift (0x207)
    short M8;
    int   M7_angle; 
};

extern MotorAngle motorAngleData;

void updateMotorAngle();

#endif