#include "Config.h"
#include "MotorAngleReader.h"

extern MCP_CAN CAN_Driver1;

MotorAngle motorAngleData = {0, 0, 0, 0, 0, 0, 0, 0};

void updateMotorAngle() {
    unsigned long rxId;
    unsigned char len = 0;
    unsigned char rxBuf[8];

    if (!digitalRead(can1_Int)) {
        CAN_Driver1.readMsgBuf(&rxId, &len, rxBuf);

        short angle = (rxBuf[0] << 8) | rxBuf[1];

        switch (rxId) {
            case 0x201: motorAngleData.M1 = angle; break;
            case 0x202: motorAngleData.M2 = angle; break;
            case 0x203: motorAngleData.M3 = angle; break;
            case 0x204: motorAngleData.M4 = angle; break;
            case 0x205: motorAngleData.M5 = angle; break;
            case 0x206: motorAngleData.M6 = angle; break;
            case 0x207: motorAngleData.M7 = angle; break; // Motor 7 feedback!
            case 0x208: motorAngleData.M8 = angle; break;
            default: break;
        }
    }
}