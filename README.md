# BSidesWifiScanner

![BSidesKit](https://github.com/circuitboardmedics/BSidesWifiScanner/assets/5779011/e2b1d360-d259-46aa-b84c-78f1aae5670e)


# Overview
BSidesWifiScanner is a custom project commisioned by and designed for the [BSides 2023 Cybersecurity conference](https://www.bsidesgreenville.org/) in Greenville, SC. The device is capable of scanning for Wi-Fi networks, displaying the AP's MAC, the network's encryption type, as well as the current channel and RSSI.  It can also graphically display the signal strength of individual networks. The firmware features modular button handling, a timer for display fields, and a page manager for different UI screens.

## Assembly
[![Assembly Video](http://img.youtube.com/vi/cxqOrxhz6VQ/0.jpg)](http://www.youtube.com/watch?v=cxqOrxhz6VQ "Badge Assembly Video")

## Bill Of Materials:
- [WeMos D1 Mini microcontroller](https://www.amazon.com/s?k=wemos+d1+mini)
- [1.3 Inch IIC I2C OLED Display Module 128x64 Pixel SH1106 Screen Module](https://www.amazon.com/gp/product/B0C3L7N917/)
- [SPST Micro Switch](https://www.amazon.com/gp/product/B07BD1SPYG)
- ~100uF Electrolytic capacitor
- CR123 Battery

## PCB
KiCad design files for the PCB are included in the .zip.


# Programming 

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

# Usage
After flashing, the device will start scanning for Wi-Fi networks and display a graphical representation of the signal strength for individual networks. Use the buttons to navigate through different pages.

![bsides1](https://github.com/circuitboardmedics/BSidesWifiScanner/assets/39735406/03e90326-5ef2-4477-9201-dd1ca8c2671a)
![BSidesSelect](https://github.com/circuitboardmedics/BSidesWifiScanner/assets/5779011/e0134b6d-a24f-4a62-9546-30c748888c46)
![BSidesGraph](https://github.com/circuitboardmedics/BSidesWifiScanner/assets/5779011/b9c0b4c6-5811-4503-af9f-f0507ae3750a)


</div>
