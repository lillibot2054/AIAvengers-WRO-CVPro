

# 🤖 AI Avengers – WRO Future Engineers 

## 📌 Project Overview

AI Avengers is a robotics project built for the **World Robot Olympiad (WRO) Future Engineers** category.
Our bot integrates **Computer Vision, AI-based decision making, and sensor fusion** to perform autonomous navigation, obstacle detection, and color-based decision tasks.

The design is based on the **CV Pro Competition Kit** with additional modules and custom programming.

---

## ⚙️ Hardware Setup

Our bot uses the following components:

* **ESP32 Dev Board** (Main Controller – Dual-core, Wi-Fi, Bluetooth support)
* **HC-SR04 Ultrasonic Sensors** (Distance and obstacle detection)

  * FUS (Front Ultrasonic Sensor)
  * FUS1 & FUS2 (Additional front sensors for precision)
  * RUS (Right Ultrasonic Sensor)
  * LUS (Left Ultrasonic Sensor)
* **Adafruit TCS34725 Color Sensor** (#1334 – I2C based, RGB detection for floor markers & decision-making)
* **Servo Motor** (for angle-based movement and actuation)
* **Lithium-Ion 3.7V 3200mAh battery** with charging circuit
* **Motor Driver** (for controlled wheel movement)
* **RGB LED Indicator**

📷 Reference Wiring:
![Wiring Diagram](./WRO%20SCHE.jpg)

---

## 💻 Software Setup

### Required Software:

* [Arduino IDE](https://www.arduino.cc/en/software)
* ESP32 Board Manager installed in Arduino IDE

### Required Libraries:

```cpp
#include <ESP32Servo.h>         // Servo motor control
#include <NewPing.h>            // Ultrasonic sensor distance calculation
#include <Wire.h>               // I2C communication
#include "Adafruit_TCS34725.h"  // Color sensor handling
#include <FastLED.h>            // RGB LED control
```

**Library Versions to Install:**

* `esp32` board: v2.0.17
* `NewPing`: v1.9.7
* `FastLED`: v3.7.0
* `ESP32Servo`: v1.2.1
* `Adafruit TCS34725`: v1.4.4

---

## 🚀 Features

* **Obstacle Avoidance** using ultrasonic sensors (360° awareness).
* **Color Detection & Path Decision** using TCS34725.
* **Servo-Controlled Mechanism** for flexible movement.
* **Autonomous Navigation** with AI-based decision-making.
* **Energy Efficient** with Li-ion power system (50 mins runtime).

---

## 🔧 How to Run

1. Connect the bot to your computer using a **USB Type-C cable**.
2. Open **Arduino IDE** and select the board: `Do It Yourself Devkit (ESP32)`
3. Select the correct **COM port**.
4. Open and upload your program (`.ino` file).
5. Switch on the bot.
6. Observe RGB LED status and bot behavior.

---

## 🧪 Testing

Preloaded test codes are available in the GitHub repository under `Firmware/Bot-TestCodes`:

* `ColorSensor_Test_Code` – test color detection.
* `Ultrasonic_Test_Code` – test obstacle detection.
* `Servo_Test_Code` – test motor movement.

---

## 🌍 Applications

* Autonomous Driving Research
* Color-based Sorting and Navigation
* AI-based Obstacle Avoidance
* Robotics Competitions & Education

---

## 👥 Team AI Avengers

We are passionate innovators exploring **AI, Robotics, and Computer Vision** to solve real-world challenges.
This project was built as part of our journey to the **WRO 2025 Finals** in Singapore.
