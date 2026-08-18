#include "Config.h"
#include "MotorRPMReader.h"

extern MCP_CAN CAN_Driver1;

MotorRPM motorRPMData = {0, 0, 0, 0, 0, 0, 0, 0};

void updateMotorRPM() {
    unsigned long rxId;
    unsigned char len = 0;
    unsigned char rxBuf[8];

    if (!digitalRead(can1_Int)) {
        CAN_Driver1.readMsgBuf(&rxId, &len, rxBuf);

        short rpm = (rxBuf[2] << 8) | rxBuf[3];

        switch (rxId) {
            case 0x201: motorRPMData.M1 = rpm; break;
            case 0x202: motorRPMData.M2 = rpm; break;
            case 0x203: motorRPMData.M3 = rpm; break;
            case 0x204: motorRPMData.M4 = rpm; break;
            case 0x205: motorRPMData.M5 = rpm; break;
            case 0x206: motorRPMData.M6 = rpm; break;
            case 0x207: motorRPMData.M7 = rpm; break; // Motor 7 feedback!
            case 0x208: motorRPMData.M8 = rpm; break;
            default: break;
        }
    }
}