# Welcome to CEAZA-M1!
Wireless communication and memory backup expansion board for CEAZA MEGA.
![alt text](/Images/M1_Front.jpg?raw=true "CEAZA M1 Board")

## What is the CEAZA M1?

This design is an expansion board for CEAZA MEGA datalogger, which add the local wireless comumunication capability to the system.
The board Design integrates:
* An Ra-02 Ai-Thinker for 410-525MHz or Ra-01SH for 803MHz~930MHz LoRa Radio module.
* An ATGM336H-5N-31 GNSS GPS BDS positioning and navigation module.
* An ESP-12E WiFi module.
* A W25N01GVZEIG 1G-bit serial nand flash memory for redundant data storage.

All modules integratred are equiped with its respective power switch and power supply controlled by firmware for energy save when low power consumtions are required.
An on board jumper is included, ready to solder when the backup power source is required for GNSS module from permanent 3.3V available from CEAZA MEGA board, which increases 10uA the system power consumption.

The GNSS and WiFi modules share the same MCU UART2 thought an 74HC4052D analog multiplexer, which is controlled by firmware.

This board is pin compatible and should be connected to the CEAZA MEGA system to proper work.

## Documentation
A comprehensive documentation for well undertand, use or modify the CEAZA M1 board is available in our Wiki. In adition, we share with you the schematics diagrams, adns Arduino example codes.

## Quickstart guide
Install the M1 board in the CEAZA MEGA's bottom, make certain connection throuhg the boards by three 2 x 10 pin header terminals is rigth. 
Attach GNSS and LoRa antennas to the board, connect the power source 7 to 14 Vdc to the system.
Connect the CEAZA MEGA main board system to the host PC by mini-USB connector, open the Arduino ide software, select the Arduino Mega board and the correspondign COM port.

Open any of examples scketches and upload to the board.

# Contact and support
For all kinds of inquiries, please contact me to my e-mail address: adrian.gallardo@ceaza.cl

# Contributing
You are welcome to contribute to the development or improvement of M1 hardware design or example application codes. Feel free to submit a new pull request via github.

# Academic Context

# Licensing

# Disclaimer
Use M1 board and examples code at your own risk. We do not encourage any malicious use of our board.

