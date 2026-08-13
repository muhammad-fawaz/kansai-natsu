# Kansai Haru 2026 — ESP32 Robot Controller

ESP32-based robot control firmware for the KUAS Robotics Team Kansai Haru 2026 build. The main controller runs Arduino on ESP32 through PlatformIO, reads a PS4 controller over Bluetooth, drives RoboMaster/C620-style CAN ESCs with PID speed control, and controls the conveyor, lift, Yagura lift, servos, OLED status display, and an ESP-NOW flag signal.

---

## Highlights

- Drive: 4-motor holonomic drive with per-wheel PID using RPM feedback from CAN IDs `0x201–0x204`.
- Input: PS4 wireless controller over Bluetooth.
- CAN: MCP2515 at 1 Mbps with an 8 MHz crystal.
- Mechanisms: conveyor, lift, Yagura lift, and two servo outputs.
- Display: SSD1306 128×64 I²C OLED at address `0x3C`.
- Wireless link: ESP-NOW message for sending a simple open/close flag to another ESP32.

---

## Repo layout

```text
kiseki-main/
├─ platformio.ini              # ESP32 PlatformIO config
├─ partitions.csv              # custom ESP32 partition table
├─ include/                    # subsystem headers and shared config
├─ src/                        # implementations and main loop
└─ test/                       # PlatformIO test scaffold