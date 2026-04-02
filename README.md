# Voice-Controlled-Smart-Car

A smart robotic car capable of **voice-controlled navigation**, **Bluetooth-based remote control**, and **autonomous obstacle avoidance**, built using Arduino and integrated hardware modules.

---

## 🚀 Project Overview

This project focuses on developing a **voice-controlled smart car** that enhances user interaction through hands-free operation while maintaining autonomous navigation capabilities.

The system allows users to:

* Control the car using **voice commands 🎤**
* Operate it remotely via **Bluetooth 📡**
* Enable **automatic obstacle detection and avoidance 🚧**

It integrates concepts from **robotics, IoT, and embedded systems** into a practical real-world application.

---

## 🎯 Objectives

* Implement **voice-controlled movement**
* Enable **Bluetooth-based remote operation**
* Integrate **ultrasonic sensors** for obstacle detection
* Provide smooth and responsive navigation
* Combine manual and autonomous control systems

---

## ⚙️ Tech Stack

### 💻 Software

* Arduino IDE
* Embedded C (Arduino Programming)

### 🔌 Hardware

* Arduino UNO R3
* HC-05 Bluetooth Module
* HC-SR04 Ultrasonic Sensor
* SG90 Servo Motor
* L293D Motor Driver
* DC Gear Motors
* Battery Power Supply

---

## 🧠 Working Principle

### 🎤 Voice Control (Primary Feature)

* User gives voice commands
* Commands are processed and sent to Arduino
* Car moves accordingly

### 📡 Bluetooth Control

* Mobile device sends control signals
* Arduino interprets commands for movement

### 🚧 Obstacle Avoidance

* Ultrasonic sensor detects nearby objects
* Car automatically avoids collisions

---

## 🏗️ System Design

### 🔩 Hardware Design

* Chassis with DC motors for movement
* Ultrasonic sensor mounted on servo for scanning
* Bluetooth module for wireless communication
* Arduino as the central controller

### 💻 Software Design

The system is modular:

* `VoiceControl()` – handles voice input
* `BluetoothControl()` – processes remote commands
* `ObstacleAvoidance()` – manages autonomous navigation

---

## 🧪 Testing

### ✅ Unit Testing

* Tested individual components:

  * Sensors
  * Motors
  * Bluetooth module
  * Voice control system

### 🔗 Integration Testing

* Verified smooth interaction between all modules

### 📊 Test Cases

#### 🚧 Obstacle Avoidance

* Obstacle detected → Stops, reverses, turns
* No obstacle → Moves forward

#### 📡 Bluetooth Commands

* `F` → Forward
* `B` → Backward
* `L` → Left
* `R` → Right
* `S` → Stop

#### 🎤 Voice Commands

* `^` → Forward
* `-` → Backward
* `<` → Left
* `>` → Right
* `*` → Stop

---

## 📷  Component Images

Microcontroller: Aurdino uno

<img width="300" height="200" alt="image" src="https://github.com/user-attachments/assets/1cdd3f4a-372f-4675-b6f6-5a78ff7585cd" />

---

Blutooth Module: HC05

<img width="550" height="392" alt="HC-05-Bluetooth-Module-Pinout" src="https://github.com/user-attachments/assets/f34eb932-058a-460b-8fdb-0c2518e58e44" />

---
Ultrasonic Sensor: HC-SR04

<img width="627" height="519" alt="image" src="https://github.com/user-attachments/assets/525e8bb5-fc60-4df0-9a75-0f8f91cffcf4" />

---
Servo Motor: SG90 

<img width="500" height="364" alt="image" src="https://github.com/user-attachments/assets/6c8810ee-4cf8-4c33-bab0-79797ff5c6f3" />

---
Motor Driver Shield: L293D

<img width="659" height="659" alt="image" src="https://github.com/user-attachments/assets/b914eb6e-61df-4102-89a9-58bf22cb4ff9" />

---
DC Gear Motors

<img width="225" height="225" alt="image" src="https://github.com/user-attachments/assets/2a566766-d2f1-44a5-9f9d-d377f7db53d3" />

---
65 mm Robot Wheels

<img width="224" height="224" alt="image" src="https://github.com/user-attachments/assets/d0a3174f-dad4-4313-b224-da23ef697498" />


---











## 📈 Results

* Successfully implemented **voice-controlled navigation**
* Reliable **Bluetooth communication**
* Efficient **obstacle detection and avoidance**
* Fast and responsive system performance

---

## 🔮 Future Enhancements

* 📱 Dedicated mobile application
* 📷 Camera integration for live streaming
* 🌍 GPS-based navigation
* 🤖 AI-based obstacle recognition
* 📡 Extended communication range
* 🎤 Improved voice recognition accuracy

---

## 📚 References

* Arduino Official Documentation
* HC-SR04 Datasheet
* HC-05 Bluetooth Module Documentation
* Servo & Motor Driver Libraries

---

## 👨‍💻 Authors

* **R Haricharan**
* **Sampati Rajesh Anvekar**

---

## 🏫 Institution

**B.M.S. College of Engineering**
Department of Computer Applications

---

## 📜 License

This project is for educational purposes.

---

## 📹 Videos

https://github.com/user-attachments/assets/e8f39534-7811-4fca-ae4e-5d633672a4d3

---

