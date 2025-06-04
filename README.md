# RFID Door Lock with Arduino Uno R3

This GitHub repository presents a project focused on implementing a door lock system using Radio-Frequency Identification (RFID) technology.

### Project Overview

This project aims to enhance security by allowing access through authorized RFID cards or tags. The system utilizes an RFID reader to scan tags and control a locking mechanism accordingly.

* **Hardware Components**:

  * Arduino Uno R3: Mircrocontroller. Contains digital pins(1-12 and ground), analog pins(A0-A5), 3.3V PIN , two 5V pins and two ground pins.
  * Servo: Motor with gears for precise movement. Contains 5V pin, ground pin and control pin.
  * RFID RC522: Radio Frequency Identification, used to identify the tag attached to the object. Contains the VCC pin, RST pin, GRD pin, IRQ pin, MISO / SCL / Tx pin , MOSI pin, SCK pin and SS / SDA / Rx pin.
  * Jumper Wires: to connect the components to each other.
  * USB cable: used to connect the CPU to the Arduino UNO board.


* **Software Components**:

  * Arduino code to read RFID tags and control the lock
  * Libraries such as `MFRC522` for RFID communication
