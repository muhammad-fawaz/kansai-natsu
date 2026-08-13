#include "Config.h"
#include "MotorControl.h"

// MCP2515 CAN Driver using CS pin defined in config.h
MCP_CAN CAN_Driver(canCs);


bool initCAN() {

    if (CAN_Driver.begin(MCP_ANY, CAN_1000KBPS, MCP_8MHZ) == CAN_OK) {
        CAN_Driver.setMode(MCP_NORMAL);
        Serial.println("MCP2515 CAN Bus Initialized Successfully!");
        return true;
    } else {
        Serial.println("Error Initializing MCP2515...");
        return false;
    }
}

void driveMecanum(int forward, int sideways, int turn, int maxCurrent) {

    // Kinematic equations for Mecanum chassis (FL, FR, BL, BR)
    float m1 =  forward + sideways + turn; // M1: Front Left
    float m2 =  forward - sideways - turn; // M2: Front Right
    float m3 =  forward - sideways + turn; // M3: Back Left
    float m4 =  forward + sideways - turn; // M4: Back Right

    // Map outputs to target motor currents
    int16_t c1 = constrain(map(m1, -256, 256, -maxCurrent, maxCurrent), -maxCurrent, maxCurrent);
    int16_t c2 = constrain(map(m2, -256, 256, -maxCurrent, maxCurrent), -maxCurrent, maxCurrent);
    int16_t c3 = constrain(map(m3, -256, 256, -maxCurrent, maxCurrent), -maxCurrent, maxCurrent);
    int16_t c4 = constrain(map(m4, -256, 256, -maxCurrent, maxCurrent), -maxCurrent, maxCurrent);

    // Build the 8-byte CAN payload for ESCs 1-4 (ID 0x200)
    byte frame[8];
    frame[0] = (c1 >> 8) & 0xFF;
    frame[1] = c1 & 0xFF;
    frame[2] = (c2 >> 8) & 0xFF;
    frame[3] = c2 & 0xFF;
    frame[4] = (c3 >> 8) & 0xFF;
    frame[5] = c3 & 0xFF;
    frame[6] = (c4 >> 8) & 0xFF;
    frame[7] = c4 & 0xFF;

    CAN_Driver.sendMsgBuf(0x200, 0, 8, frame);
}