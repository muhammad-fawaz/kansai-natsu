#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <mcp_can.h>
#include <SPI.h>

bool initCAN();
void driveMecanum(int forward, int sideways, int turn, int maxCurrent);

#endif