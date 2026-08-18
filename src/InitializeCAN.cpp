#include "Config.h"
#include "Display.h"
#include "InitializeCAN.h"

// MCP2515 CAN Driver using CS pin defined in config.h
MCP_CAN CAN_Driver1(can1_Cs);
MCP_CAN CAN_Driver2(can2_Cs);

bool initCAN1() {

    if (CAN_Driver1.begin(MCP_ANY, CAN_1000KBPS, MCP_8MHZ) == CAN_OK) {
        CAN_Driver1.setMode(MCP_NORMAL);
        Serial.println("MCP2515 No. 1 CAN Bus Initialized Successfully!");
        showMessage("CAN Bus No. 1 Initialized Successfully!");
        return true;
    } else {
        Serial.println("Error Initializing MCP2515 No. 1...");
        showMessage("Failed to Initialize CAN Bus No. 1...");
        delay(100);
        return false;
    }

    delay(100);
}

bool initCAN2() {

    if (CAN_Driver2.begin(MCP_ANY, CAN_1000KBPS, MCP_8MHZ) == CAN_OK) {
        CAN_Driver2.setMode(MCP_NORMAL);
        Serial.println("MCP2515 No. 2 CAN Bus Initialized Successfully!");
        showMessage("CAN Bus No. 2 Initialized Successfully!");
        return true;
    } else {
        Serial.println("Error Initializing MCP2515 No. 2...");
        showMessage("Failed to Initialize CAN Bus No. 2...");
        delay(100);
        return false;
    }

    delay(100);
}