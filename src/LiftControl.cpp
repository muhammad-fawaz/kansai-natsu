#include "LiftControl.h"
#include "Config.h"

// Reference the single CAN_Driver initialized in MotorControl.cpp
extern MCP_CAN CAN_Driver;

int16_t targetCurrent56 = 0;
int16_t targetCurrent78 = 0;


void driveMainLift(int upPressed, int downPressed, int liftPower) {

    if (upPressed) {
        targetCurrent56 = liftPower;      // Move Up
    } else if (downPressed) {
        targetCurrent56 = -liftPower;     // Move Down
    } else {
        targetCurrent56 = 0;              // Idle
    }

}


void driveBackLift(int upPressed, int downPressed, int liftPower) {
    
    if (upPressed) {
        targetCurrent78 = liftPower;      // Move Up
    } else if (downPressed) {
        targetCurrent78 = -liftPower;     // Move Down
    } else {
        targetCurrent78 = 0;              // Idle
    }

}


void sendLiftFrame() {
    
    // Build the 8-byte CAN payload for ESCs 5-8 (ID 0x204)
    byte frame[8] = {0};
    
    // Motor 5 (Bytes 0 & 1)
    frame[0] = (targetCurrent56 >> 8) & 0xFF;
    frame[1] = targetCurrent56 & 0xFF;

    // Motor 6 (Bytes 2 & 3)
        frame[2] = (targetCurrent56 >> 8) & 0xFF;
        frame[3] = targetCurrent56 & 0xFF;

        // Motor 7 (Bytes 4 & 5)
        frame[4] = (targetCurrent78 >> 8) & 0xFF;
        frame[5] = targetCurrent78 & 0xFF;
    
        // Bytes 0-3 and 6-8 are 0 (Motors 5, 6 and 8 sit idle)
        CAN_Driver.sendMsgBuf(0x204, 0, 8, frame);
    }