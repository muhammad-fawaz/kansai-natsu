#include "PS4ControllerHandler.h"
#include "Display.h"

int forwardSetpoint = 0;
int sidewaysSetpoint = 0;
int turnSetpoint = 0;

void checkPS4() {

    if (PS4.isConnected()) {
        // Shapes / Action Buttons
        if (PS4.Cross())    Serial.print(" [CROSS] ");
        if (PS4.Circle())   Serial.print(" [CIRCLE] ");
        if (PS4.Square())   Serial.print(" [SQUARE] ");
        if (PS4.Triangle()) Serial.print(" [TRIANGLE] ");

        // D-Pad
        if (PS4.Up())       Serial.print(" [DPAD UP] ");
        if (PS4.Down())     Serial.print(" [DPAD DOWN] ");
        if (PS4.Left())     Serial.print(" [DPAD LEFT] ");
        if (PS4.Right())    Serial.print(" [DPAD RIGHT] ");

        // Bumpers & Triggers
        if (PS4.L1())       Serial.print(" [L1] ");
        if (PS4.R1())       Serial.print(" [R1] ");
        if (PS4.L2())       Serial.printf(" [L2: %d] ", PS4.L2Value());
        if (PS4.R2())       Serial.printf(" [R2: %d] ", PS4.R2Value());

        // Stick Clicks & Special Buttons
        if (PS4.L3())       Serial.print(" [L3] ");
        if (PS4.R3())       Serial.print(" [R3] ");
        if (PS4.Share())    Serial.print(" [SHARE] ");
        if (PS4.Options())  Serial.print(" [OPTIONS] ");
        if (PS4.PSButton()) Serial.print(" [PS BUTTON] ");
        if (PS4.Touchpad()) Serial.print(" [TOUCHPAD] ");

        // Print a new line after printing active inputs
        Serial.println();
    } else {
        Serial.println("PS4 Controller Disconnected");
        delay(200);
    }
}
