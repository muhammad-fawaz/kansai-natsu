#include "Config.h"
#include "Display.h"
#include "LiftControl.h"

extern MCP_CAN CAN_Driver;

int16_t targetCurrent1 = 0;
int16_t targetCurrent2 = 0;

void driveMainLift(int upPressed, int downPressed, int liftPower) {
    if (upPressed) {
        targetCurrent1 = liftPower;
    } else if (downPressed) {
        targetCurrent1 = -liftPower;
    } else {
        targetCurrent1 = 0;
    }
}

void driveBackLift(int upPressed, int downPressed, int liftPower) {
    if (upPressed) {
        targetCurrent2 = -liftPower;     // Triangle button -> Up
    } else if (downPressed) {
        targetCurrent2 = liftPower;    // Cross button -> Down
    } else {
        targetCurrent2 = 0;             // Idle
    }
}

void sendLiftFrame() {
    byte frame[8] = {0};

    // Motor 1 (Bytes 0 & 1) - Controlled by targetCurrent1
    frame[0] = (targetCurrent1 >> 8) & 0xFF;
    frame[1] = targetCurrent1 & 0xFF;
    
    // Motor 2 (Bytes 2 & 3) - Controlled by targetCurrent2
    frame[2] = (targetCurrent2 >> 8) & 0xFF;
    frame[3] = targetCurrent2 & 0xFF;
    
    // Motor 3 (Bytes 4 & 5) - Idle
    frame[4] = 0;
    frame[5] = 0;

    // Motor 4 (Bytes 6 & 7) - Idle
    frame[6] = 0;
    frame[7] = 0;

    // Send frame to ID 0x200 (Controls ESCs 1-4)
    CAN_Driver.sendMsgBuf(0x200, 0, 8, frame);
    if (targetCurrent1 != 0 || targetCurrent2 != 0) {
        showMessage("Lift Moving");
        Serial.printf("Front Lift: %d | Back Lift: %d\n", targetCurrent1, targetCurrent2);
    }
}