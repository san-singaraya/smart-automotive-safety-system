# Smart Automotive Safety System Using IoT and Sensor Fusion

## Project Description

This project presents a Smart Automotive Safety System using ESP32, IoT concepts, sensor fusion, and multiple sensors for intelligent driver assistance.

The system monitors vehicle surroundings and detects potential hazardous conditions using an ultrasonic sensor and MPU6050 accelerometer and gyroscope.

## Hardware Components

* ESP32
* HC-SR04 Ultrasonic Sensor
* MPU6050 Accelerometer and Gyroscope
* 16×2 I2C LCD
* Buzzer
* LED
* Relay Module

## Software and Tools

* Arduino IDE
* ESP32 Arduino Core
* Wokwi Simulator
* C/C++
* GitHub

## System Features

* Obstacle detection
* Abnormal movement detection
* Real-time warning system
* Buzzer alert
* LED warning indication
* Relay activation
* LCD status display
* Sensor-based safety monitoring

## Wokwi Connections

| Component    | ESP32 Pin |
| ------------ | --------- |
| HC-SR04 TRIG | GPIO 5    |
| HC-SR04 ECHO | GPIO 18   |
| MPU6050 SDA  | GPIO 21   |
| MPU6050 SCL  | GPIO 22   |
| Buzzer       | GPIO 25   |
| LED          | GPIO 26   |
| Relay IN     | GPIO 27   |

## Working Principle

The HC-SR04 measures the distance between the vehicle and nearby obstacles. The MPU6050 monitors acceleration and movement.

If the measured distance is less than 50 cm or abnormal acceleration is detected, the ESP32 activates the buzzer, LED, and relay and displays "WARNING" on the LCD.

When no hazardous condition is detected, the system displays "SYSTEM SAFE".

## Project Simulation

The complete system is simulated using Wokwi with ESP32 and the connected sensors and output devices.

## Project Files

* `sketch.ino` – ESP32 program
* `diagram.json` – Wokwi circuit configuration
* `libraries.txt` – Required libraries
* `documentation/` – Project documentation

## Future Enhancements

* GPS-based vehicle tracking
* IoT cloud monitoring
* Mobile application integration
* GSM-based emergency alerts
* Advanced sensor fusion
* Accident detection and automatic emergency notification

