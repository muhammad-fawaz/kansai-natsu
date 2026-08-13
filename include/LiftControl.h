#ifndef LIFT_CONTROL_H
#define LIFT_CONTROL_H

#include <mcp_can.h>
#include <SPI.h>

// Controls main lift (Motors 5 & 6)
void driveMainLift(int upPressed, int downPressed, int liftPower);

// Controls back lift (Motor 7)
void driveBackLift(int upPressed, int downPressed, int liftPower);

// Sends data to CAN bus
void sendLiftFrame();

#endif