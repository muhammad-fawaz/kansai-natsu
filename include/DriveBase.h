#ifndef DRIVE_BASE_H
#define DRIVE_BASE_H

#include <mcp_can.h>
#include <SPI.h>

void driveMecanum(int forward, int sideways, int turn, int maxCurrent);

#endif