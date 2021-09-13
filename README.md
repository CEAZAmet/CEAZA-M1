# WELLCOME TO CEAZA-M1
Wireless communication and memory backup expansion board for CEAZA MEGA.

#What is the CEAZA M1?

This design is an expansion board for CEAZA MEGA datalogger, which add the local wireless comumunication capability to the system.
Design integrates an XL1278-SMT 433MHz LoRa Radio module, an ATGM336H-5N-31 GNSS GPS BDS positioning and navigation module, an ESP-12E WiFi module, and a W25N01GVZEIG 1G-bit serial nand flash memory for redundant data storage.

All components are equiped with its respective power switch and power supply controlled by firmware for energy save when low power consumtions are required.
An on board jumper is included, ready to solder when the backup power source is required for GNSS module from permanent 3.3V available from CEAZA MEGA board, which increases 10uA the system power consumption.

The GNSS and WiFi modules share the same UART2 thought an 74HC4052D analog multiplexer, which is controlled by firmware.

This board is pin compatible and should be connected to the CEAZA MEGA system to proper work.
