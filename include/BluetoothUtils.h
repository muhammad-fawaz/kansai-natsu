#ifndef BLUETOOTH_UTILS_H
#define BLUETOOTH_UTILS_H

#include <Arduino.h>
#include "esp_bt_main.h"
#include "esp_bt_device.h"
#include "esp_gap_bt_api.h"

// Prints the ESP32's Bluetooth MAC Address
void printDeviceAddress();

// Clears saved paired Bluetooth devices from ESP32 NVS memory
void removePairedDevices();

#endif