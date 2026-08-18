#include "Config.h"
#include "Display.h"
#include "DriveBase.h"
#include "LiftControl.h"
#include "InitializeCAN.h"
#include "MotorRPMReader.h"
#include "BluetoothUtils.h"
#include "PS4ControllerHandler.h"

void setup() {
    Serial.begin(115200);
    
    // Set CAN interrupt pin mode
    pinMode(can1_Int, INPUT_PULLUP);
    pinMode(can2_Int, INPUT_PULLUP);

    // Initialize the Oled
    initDisplay();
    showMessage("Initializing Display...");

    // Initialize CAN bus and PS4 Controller
    showMessage("Initializing CAN Bus...");
    initCAN1();
    initCAN2();

    showMessage("Initializing Controller...");
    PS4.begin();

    // Print MAC Address to terminal
    Serial.print("ESP32 Bluetooth MAC Address: ");
    printDeviceAddress();

    Serial.println("System Ready. Connect PS4 Controller...");
    showMessage("Connect Controller...");
}

void loop() {

  // updateMotorRPM();
  
  if (PS4.isConnected()) {

    // Logging button press for debugging purposes
    checkPS4();

    // Read left stick for movement, right stick X for rotation
    int forward  = PS4.LStickY(); // -128 to 127
    int sideways = PS4.LStickX(); // -128 to 127
    int turn     = PS4.RStickX(); // -128 to 127

    // Apply deadzone to ignore stick drift near center
    if (abs(forward) < 10) forward = 0;
    if (abs(sideways) < 10) sideways = 0;
    if (abs(turn) < 10) turn = 0;

    // Drive chassis
    driveMecanum(forward, sideways, turn, MAX_SPEED);

    // Drive lift
    driveMainLift(PS4.Up(), PS4.Down(), LIFT_POWER);
    driveBackLift(PS4.Triangle(), PS4.Cross(), LIFT_POWER);
    sendLiftFrame();
    
  } else {
    // Stop all motors if controller disconnects
    driveMecanum(0, 0, 0, 0);
    driveMainLift(0, 0, 0);
    driveBackLift(0, 0, 0);
    sendLiftFrame();
}

  delay(10); // 100Hz loop rate
}