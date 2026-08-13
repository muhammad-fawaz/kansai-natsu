#include "BluetoothUtils.h"

void removePairedDevices() {
    int count = esp_bt_gap_get_bond_device_num();
    if (count > 0) {
        esp_bd_addr_t dev_list[count];
        esp_bt_gap_get_bond_device_list(&count, dev_list);
        for (int i = 0; i < count; i++) {
            esp_bt_gap_remove_bond_device(dev_list[i]);
        }
    }
}

void printDeviceAddress() {
    const uint8_t* point = esp_bt_dev_get_address();
    if (point != NULL) {
        for (int i = 0; i < 6; i++) {
            char str[3];
            sprintf(str, "%02X", (int)point[i]);
            Serial.print(str);
            if (i < 5) Serial.print(":");
        }
        Serial.println(); // Added newline for clean output formatting
    } else {
        Serial.println("UNKNOWN (BT stack not initialized)");
    }
}