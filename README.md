# Kansai Natsu 2026 — ESP32 Robot Controller

This is the code for the KUAS Robotics Team's 2026 robot. It runs on an ESP32 using PlatformIO. 

The ESP32 connects to a PS4 controller over Bluetooth to drive the robot, read motor speeds, move the front and back lift mechanisms.

More features will be added as the progress continues.

---

## Features

* **4-Wheel Drive**: Controls a 4-wheel omni/mecanum drive system with speed feedback from the motors via CAN bus (`0x201–0x204`).
* **PS4 Controller**: Wireless control over Bluetooth.
* **CAN Bus**: Uses an MCP2515 module (1 Mbps, 8 MHz crystal) to talk to motor controllers.

---

## Folder Structure

```text
kiseki-main/
├─ platformio.ini      # ESP32 project settings
├─ partitions.csv      # ESP32 memory setup
├─ include/            # Header files and settings
├─ src/                # Main code files
└─ test/               # Code testing folder