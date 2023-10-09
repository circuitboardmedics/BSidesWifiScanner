# BSidesWifiScanner

![BSidesKit](https://github.com/circuitboardmedics/BSidesWifiScanner/assets/5779011/e2b1d360-d259-46aa-b84c-78f1aae5670e)


## Overview
BSidesWifiScanner is a specialized Wi-Fi scanner designed and commissioned for the BSides 2023 Cybersecurity conference in Greenville, SC. The device is capable of scanning for Wi-Fi networks and graphically displaying the signal strength of individual networks. It features modular button handling, a timer for fields, and a page manager for different UI screens.

## Prerequisites
- Visual Studio Code
- PlatformIO IDE extension
- ESP8266 or compatible board

## Setup Environment Using Visual Studio Code and PlatformIO

1. **Install Visual Studio Code**: Download and install [Visual Studio Code](https://code.visualstudio.com/).

2. **Install PlatformIO**: Open Visual Studio Code, go to Extensions and search for "PlatformIO IDE". Install it.

3. **Clone the Repository**: Clone this repository to your local machine using Git.

4. **Open the Project**: Open Visual Studio Code and navigate to `File > Open Folder` and select the cloned repository folder.

5. **PlatformIO Initialization**: The repository contains a [`platformio.ini`](https://github.com/circuitboardmedics/BSidesWifiScanner/blob/main/platformio.ini) file that specifies the board and dependencies. PlatformIO should automatically recognize this.

6. **Install Dependencies**: PlatformIO will automatically install the required libraries specified in `platformio.ini`.

## Flashing the Code

1. **Select Environment**: In PlatformIO Home, select the environment that matches your board. The default in `platformio.ini` is `d1_mini`.

2. **Build the Project**: Click on the "Build" button (checkmark icon) in the PlatformIO toolbar at the bottom.

3. **Upload the Code**: After a successful build, click on the "Upload" button (right arrow icon) in the PlatformIO toolbar to flash the code to your board.

4. **Monitor Serial Output**: Optionally, you can open the Serial Monitor by clicking on the "Serial Monitor" button (plug icon) in the PlatformIO toolbar to view debug output.

## Usage
After flashing, the device will start scanning for Wi-Fi networks and display a graphical representation of the signal strength for individual networks. Use the buttons to navigate through different pages.

![BSidesSplashScreen](https://github.com/circuitboardmedics/BSidesWifiScanner/assets/5779011/af4b3a4e-02b9-40b3-b173-609eae94fc86)
![BSidesSelect](https://github.com/circuitboardmedics/BSidesWifiScanner/assets/5779011/e0134b6d-a24f-4a62-9546-30c748888c46)
![BSidesGraph](https://github.com/circuitboardmedics/BSidesWifiScanner/assets/5779011/b9c0b4c6-5811-4503-af9f-f0507ae3750a)

