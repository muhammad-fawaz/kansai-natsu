#include "Config.h"
#include "Display.h"
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
        showMessage("Failed to Initialize CAN Bus...");
        delay(100);
        return false;
    }
}

void driveMecanum(int forward, int sideways, int turn, int maxCurrent) {

    // Kinematic equations for Mecanum (M5: FL, M6: FR, M7: BL, M8: BR)
    float m5 =  forward + sideways + turn; // M5: Front Left
    float m6 = -forward + sideways + turn; // M6: Front Right
    float m7 =  forward - sideways + turn; // M7: Back Left
    float m8 = -forward - sideways + turn; // M8: Back Right

    // Map outputs to target motor currents
    int16_t c5 = constrain(map(m5, -384, 384, -maxCurrent, maxCurrent), -maxCurrent, maxCurrent);
    int16_t c6 = constrain(map(m6, -384, 384, -maxCurrent, maxCurrent), -maxCurrent, maxCurrent);
    int16_t c7 = constrain(map(m7, -384, 384, -maxCurrent, maxCurrent), -maxCurrent, maxCurrent);
    int16_t c8 = constrain(map(m8, -384, 384, -maxCurrent, maxCurrent), -maxCurrent, maxCurrent);

    // Build the 8-byte CAN payload for ESCs 5-8
    byte frame[8];
    frame[0] = (c5 >> 8) & 0xFF;
    frame[1] = c5 & 0xFF;
    frame[2] = (c6 >> 8) & 0xFF;
    frame[3] = c6 & 0xFF;
    frame[4] = (c7 >> 8) & 0xFF;
    frame[5] = c7 & 0xFF;
    frame[6] = (c8 >> 8) & 0xFF;
    frame[7] = c8 & 0xFF;

    if (abs(c5) > 0 || abs(c6) > 0 || abs(c7) > 0 || abs(c8) > 0) {
        showMessage("Mecanum Moving");
        Serial.printf("Drive Currents - M5: %d | M6: %d | M7: %d | M8: %d\n", c5, c6, c7, c8);
    }

    // Sends command to Motor IDs 5-8
    CAN_Driver.sendMsgBuf(0x204, 0, 8, frame);
}