<div align="center">

<br/>

<h1>
  <img src="https://img.shields.io/badge/🤖-Smart%20Robot%20Car%20%7C%20Arduino-00cfff?style=for-the-badge&labelColor=0a0f1e&color=00cfff" height="45"/>
</h1>

<p>
  <img src="https://img.shields.io/badge/🔵%20Bluetooth%20Control-0a1628?style=flat-square&color=0d2244"/>
  <img src="https://img.shields.io/badge/📡%20Obstacle%20Avoidance-0a1628?style=flat-square&color=0d2244"/>
  <img src="https://img.shields.io/badge/🎙️%20Voice%20Navigation-0a1628?style=flat-square&color=0d2244"/>
</p>

<br/>

![Arduino](https://img.shields.io/badge/Arduino-Uno-00cfff?style=for-the-badge&logo=arduino&logoColor=white&labelColor=0a0f1e)
![Language](https://img.shields.io/badge/Language-C%2FC%2B%2B-00cfff?style=for-the-badge&logo=cplusplus&logoColor=white&labelColor=0a0f1e)
![Bluetooth](https://img.shields.io/badge/Bluetooth-HC--05%2F06-00cfff?style=for-the-badge&logo=bluetooth&logoColor=white&labelColor=0a0f1e)
![Sensor](https://img.shields.io/badge/Sensor-HC--SR04-00cfff?style=for-the-badge&labelColor=0a0f1e)
![License](https://img.shields.io/badge/License-Educational-00cfff?style=for-the-badge&labelColor=0a0f1e)

<br/>

> An Arduino-based robot car with **three control modes** — Bluetooth manual driving,
> autonomous obstacle avoidance, and voice command navigation.
> Built to demonstrate real-time embedded decision making and hardware–software integration.

<br/>

</div>

---

<br/>

## 📌 &nbsp;Project Overview

<table>
<tr>
<td width="55%" valign="top">

The Smart Robot Car operates across multiple environments using switchable control strategies. An **ultrasonic sensor mounted on a servo motor** continuously scans surroundings to measure distances, enabling autonomous real-time navigation decisions.

This project was built to deepen understanding of:

- ✅ Microcontroller programming
- ✅ Sensor &amp; actuator integration
- ✅ DC motor control via driver shield
- ✅ Embedded logic and multi-mode system design

</td>
<td width="45%" valign="top">

```
        ┌─────────────────┐
        │   Serial Input  │  ← Bluetooth / Voice
        └────────┬────────┘
                 │
        ┌────────▼────────┐
        │  Mode Selector  │
        └──┬──────┬───┬───┘
           │      │   │
      ┌────▼─┐ ┌──▼─┐ ┌▼──────┐
      │  BT  │ │Auto│ │ Voice │
      └────┬─┘ └──┬─┘ └┬──────┘
           └──────┴────┘
                  │
        ┌─────────▼────────┐
        │   Motor Driver   │
        │  (L293D Shield)  │
        └──────────────────┘
```

</td>
</tr>
</table>

<br/>

---

## ⚙️ &nbsp;Features

<br/>

<table>
<tr>
<td align="center" width="33%">

**🔵 Bluetooth Control**

Manual driving via serial
Bluetooth commands.
Supports F / B / L / R / Stop
with live mode switching.

</td>
<td align="center" width="33%">

**🚧 Obstacle Avoidance**

Autonomous navigation using
HC-SR04 + servo scan.
Compares left/right distances
and chooses the safest path.

</td>
<td align="center" width="33%">

**🎙️ Voice Control**

Predefined voice commands
sent over serial.
Movement validated against
live sensor feedback.

</td>
</tr>
</table>

<br/>

---

## 🧠 &nbsp;Control Modes

<br/>

| Mode | Name | Description |
|:---:|---|---|
| `0` | **Bluetooth Control** | Manual driving via Bluetooth serial commands |
| `1` | **Obstacle Avoidance** | Autonomous navigation using ultrasonic sensor |
| `2` | **Voice Control** | Movement via predefined voice-based serial commands |

> Switch between modes at any time using serial commands — no restart needed.

<br/>

---

## 🛠️ &nbsp;Hardware Components

<br/>

```
┌────────────────────────────────────────────────────────┐
│                    Hardware Stack                      │
├──────────────────────────┬─────────────────────────────┤
│  🧠  Microcontroller      │  Arduino Uno (ATmega328P)   │
│  ⚡  Motor Driver         │  L293D Motor Shield         │
│  🔄  Drive System         │  DC Motors + Robot Chassis  │
│  📏  Distance Sensor      │  Ultrasonic HC-SR04         │
│  🔁  Scanning Actuator    │  Servo Motor                │
│  📶  Wireless Module      │  HC-05 / HC-06 Bluetooth    │
│  🔌  Power                │  Battery Pack + Wires       │
└──────────────────────────┴─────────────────────────────┘
```

<br/>

---

## 💻 &nbsp;Software &amp; Libraries

| Library | Purpose |
|---|---|
| `Servo.h` | Controls servo motor angle for sensor scanning |
| `AFMotor.h` | Adafruit motor shield driver for DC motor control |
| Arduino IDE | Development and upload environment |

<br/>

---

## 🔄 &nbsp;How It Works

```
  1. Robot boots into Bluetooth Control Mode (default)
              │
              ▼
  2. Serial command received → Mode Selector evaluates
              │
      ┌───────┴──────────────────────┐
      │                              │
      ▼                              ▼
  Mode 1: Obstacle Avoidance     Mode 2: Voice Control
      │                              │
      ▼                              ▼
  HC-SR04 measures front        Voice command parsed
  distance continuously         via serial input
      │                              │
      ▼                              ▼
  Servo scans LEFT / RIGHT      Sensor validates path
      │                              │
      ▼                              ▼
  Compare distances →           Execute movement →
  Turn toward safer side        Confirm with sensor
              │
              ▼
  Motor Driver executes direction + speed via PWM
```

<br/>

---

## 📚 &nbsp;Learning Outcomes

- Embedded systems fundamentals and real-time control flow
- Multi-mode logic design and clean state switching
- Working with sensors, servo motors, and DC actuators
- Bluetooth serial communication on Arduino
- Structured, maintainable code for hardware projects

<br/>

---

## 🚀 &nbsp;Future Improvements

| Status | Task |
|---|---|
| 🔲 Planned | Add LCD / OLED display for live mode &amp; status |
| 🔲 Planned | Implement PWM-based speed control |
| 🔲 Planned | Add line-following capability |
| 🔲 Planned | Integrate ESP32 for Wi-Fi / IoT features |
| 🔲 Planned | Improve obstacle detection accuracy with IR sensors |

<br/>

---

## 📷 &nbsp;Demo &amp; Documentation

<div align="center">

<img width="1000" height="500" alt="Robot Car Demo" src="https://github.com/user-attachments/assets/2270ccef-4b2e-4e84-91cd-51c009b5cf40"/>

<br/><br/>

<img width="1000" height="800" alt="Robot Car Build" src="https://github.com/user-attachments/assets/6befe0e5-51a5-48b0-8933-a6a7ae43059b"/>

</div>

<br/>

---

## 👤 &nbsp;Author

<div align="center">

**Shayan Ahmed**

`Full-Stack Developer` &nbsp;·&nbsp; `Flutter Developer` &nbsp;·&nbsp; `Embedded Systems Enthusiast`

</div>

<br/>

---

## 📜 &nbsp;License

This project is open for **learning and educational purposes.**
Feel free to study, fork, and build upon it. 🔧

<br/>

<div align="center">

![divider](https://img.shields.io/badge/────────────────────────────────────────────────────-0a0f1e?style=for-the-badge)

<sub>Arduino Uno · L293D Shield · HC-SR04 · HC-05 · Servo Motor · C/C++</sub>

<br/><br/>

</div>
