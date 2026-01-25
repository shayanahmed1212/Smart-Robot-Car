# Smart Robot Car (Arduino)

A smart Arduino-based robot car designed with multiple control modes, including
Bluetooth-controlled manual driving, autonomous obstacle avoidance, and voice
command navigation. This project demonstrates core embedded systems concepts,
real-time decision making, and seamless hardware–software integration.

---

## 📌 Project Overview

The Smart Robot Car is built to operate in different environments using multiple
control strategies. It can be manually controlled via Bluetooth, autonomously
navigate by detecting and avoiding obstacles, or respond to voice commands.
An ultrasonic sensor mounted on a servo motor allows the robot to scan its
surroundings and choose the safest direction to move.

This project was developed to strengthen understanding of:
- Microcontroller programming
- Sensor integration
- Motor control
- Embedded logic and system design

---

## ⚙️ Features

- 🔹 **Bluetooth Control Mode**
  - Manual control using serial Bluetooth commands
  - Supports forward, backward, left, right, and stop movements

- 🔹 **Obstacle Avoidance Mode**
  - Autonomous navigation using an ultrasonic sensor
  - Servo motor scans left and right to determine the safest path
  - Real-time decision making for movement

- 🔹 **Voice Control Mode**
  - Robot responds to predefined voice commands
  - Movement decisions validated using sensor feedback

- 🔹 **Multi-Mode Switching**
  - Easily switch between control modes using serial commands

---

## 🧠 Control Modes

| Mode Number | Mode Name              | Description                                   |
|------------|------------------------|-----------------------------------------------|
| 0          | Bluetooth Control      | Manual control via Bluetooth commands         |
| 1          | Obstacle Avoidance     | Autonomous navigation using ultrasonic sensor |
| 2          | Voice Control          | Control using voice-based serial commands     |

---

## 🛠️ Hardware Components Used

- Arduino Uno
- L293D Motor Driver Shield
- DC Motors & Robot Chassis
- Ultrasonic Sensor (HC-SR04)
- Servo Motor
- Bluetooth Module (HC-05 / HC-06)
- Connecting wires and power supply

---

## 💻 Software & Libraries

- Arduino IDE
- **Servo.h**
- **AFMotor.h**

---

## 🔄 How It Works

1. The robot starts in Bluetooth control mode by default.
2. Commands received via serial communication determine the active control mode.
3. In obstacle avoidance mode, the ultrasonic sensor measures distance ahead.
4. The servo motor rotates the sensor to scan left and right.
5. The robot compares distances and turns toward the safer direction.
6. Motor speed and direction are controlled through the motor driver shield.

---

## 📚 Learning Outcomes

- Understanding embedded systems fundamentals
- Implementing multi-mode control logic
- Working with sensors and actuators
- Integrating hardware with software logic
- Designing structured and maintainable Arduino code

---

## 🚀 Future Improvements

- Add LCD or OLED display for live status
- Implement speed control using PWM
- Add line-following capability
- Integrate ESP32 for Wi-Fi / IoT features
- Improve obstacle detection accuracy

---

## 📷 Demo & Documentation

- Demo videos and images can be added here
- Wiring diagrams can be included in a `/docs` folder

---

## 👤 Author

**Shayan Ahmed**  
Full-Stack Developer | Flutter Developer | Embedded Systems Enthusiast

---

## 📜 License

This project is open for learning and educational purposes.

<img width="978" height="537" alt="image" src="https://github.com/user-attachments/assets/ced73e3b-ad42-4f2c-bd33-ff35ba8c858d" />

