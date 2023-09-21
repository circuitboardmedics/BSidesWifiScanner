# BSidesWifiScanner

## Overview
BSidesWifiScanner is a Wi-Fi scanner project designed for embedded systems. It features modular button handling, a timer for fields, and a page manager for different UI screens.

## Prerequisites
- Arduino IDE or PlatformIO
- ESP8266 or compatible board
- Required libraries (e.g., ESP8266WiFi)

## Setup Environment
1. **Download and Install IDE**: Download and install the Arduino IDE or PlatformIO.
2. **Install Board Support**: Go to `Tools > Board > Boards Manager` and install support for ESP8266.
3. **Install Libraries**: Install required libraries via `Sketch > Include Library > Manage Libraries`.

## Flashing the Code
1. **Clone the Repository**: Clone this repository to your local machine.
2. **Open the Project**: Open the `.ino` or `.cpp` file in your IDE.
3. **Configure Settings**: Update Wi-Fi credentials or other settings in the code if necessary.
4. **Select Board and Port**: Go to `Tools > Board` to select your board and `Tools > Port` to select the COM port.
5. **Compile and Upload**: Click on the `Upload` button to compile and flash the code to your board.

## Usage
After flashing, the device will start scanning for Wi-Fi networks and display them on the screen. Use the buttons to navigate through different pages.
