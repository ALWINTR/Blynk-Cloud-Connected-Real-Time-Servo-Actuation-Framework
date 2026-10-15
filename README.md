# Blynk Cloud Connected Real Time Servo Actuation Framework

<div align="center">

[![GitHub Repository](https://img.shields.io/badge/GitHub-Repository-00f0ff?style=for-the-badge&logo=github&logoColor=white)](https://github.com/ALWINTR/Blynk-Cloud-Connected-Real-Time-Servo-Actuation-Framework)
[![Developer](https://img.shields.io/badge/Developer-Alwin_T_R-0284c7?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/alwintr)
[![Portfolio](https://img.shields.io/badge/Portfolio-alwintr.github.io-00f0ff?style=for-the-badge&logo=googlechrome&logoColor=black)](https://alwintr.github.io)
[![License](https://img.shields.io/badge/License-MIT-10b981?style=for-the-badge)](LICENSE)

</div>

> Cloud IoT actuator framework connecting ESP32 to Blynk 2.0 Cloud Platform, featuring bidirectional Virtual Pin telemetry, auto-reconnection state machines, and angle telemetry sync.

---

## 📌 Executive Overview

Cloud IoT actuator framework connecting ESP32 to Blynk 2.0 Cloud Platform, featuring bidirectional Virtual Pin telemetry, auto-reconnection state machines, and angle telemetry sync. This repository contains production-ready firmware implementations, hardware wiring pinouts, signal conditioning routines, and real-time telemetry pipelines engineered for reliable physical operation.

- **Primary Domain**: IoT & Telemetry
- **Microcontroller & Hardware Core**: ESP32 / Blynk
- **Specialization**: Cloud IoT
- **Live Specs & BOM Viewer**: [alwintr.github.io](https://alwintr.github.io)

---

## 📐 System Architecture & Signal Flow

```
+--------------------------------------------------------------+
|                 Blynk 2.0 Mobile / Web App                   |
|    - Cloud Dashboard          - Virtual Pin V0 Slider Widget |
+--------------------------------------------------------------+
        |
        | SSL / TLS Encrypted WebSocket Link
        v
+--------------------------------------------------------------+
|                     Blynk IoT Cloud Server                   |
+--------------------------------------------------------------+
        |
        | Bidirectional Virtual Pin Protocol
        v
+--------------------------------------------------------------+
|                    ESP32 / ESP8266 Firmware                  |
|  - BLYNK_WRITE(V0) Handler    - Non-Blocking State Loop      |
|  - Wi-Fi Reconnect Watchdog   - Brownout Safety Protocol     |
+--------------------------------------------------------------+
                                |
                                v Hardware LEDC PWM
                   +--------------------------+
                   |   Servo Actuator (MG996R)|
                   +--------------------------+
```

---

## 📋 Hardware Bill of Materials (BOM)

| Component Name | Operating Voltage | Interface / Functionality |
| :--- | :--- | :--- |
| **ESP32 DevKit V1** | `5V DC` | 240MHz Dual-Core Wi-Fi SoC |
| **MG996R Metal Gear Servo** | `5V - 6V DC` | High-torque industrial actuator |
| **External 5V / 2A Power Supply** | `5V DC` | Actuator power rail |
| **Status Indicator LEDs** | `5V DC` | Cloud Connection Status |

---

## 🔌 Circuit Pinout & Microcontroller Interconnect

| MCU Pin / Channel | Peripheral Pin | Signal Function / Bus |
| :--- | :--- | :--- |
| `ESP32 GPIO 18` | `Servo Signal Line` | LEDC Hardware PWM Channel 0 |
| `ESP32 GPIO 2` | `Onboard LED` | Wi-Fi & Cloud Connection Heartbeat |
| `ESP32 VIN / GND` | `5V Power Supply` | Common Ground |

---

## ⚙️ Firmware Architecture & Control Logic

Blynk 2.0 Virtual Pin handlers with non-blocking reconnection algorithms, connection state fallback timers, and software brownout safety.

### Key Firmware Capabilities:
- **Zero-Blocking Architecture**: Real-time non-blocking scheduling eliminating delay() deadlocks.
- **Hardware Interrupt Servicing**: Microsecond-precision edge-triggered pulse detection and safety shutoffs.
- **Diagnostic Telemetry**: Continuous serial datastreaming and state-machine transition logging.

---

## 📁 Repository Structure

```
Blynk-Cloud-Connected-Real-Time-Servo-Actuation-Framework/
├── .gitignore
├── blynk_servo_controller.ino
├── LICENSE
└── README.md
```

---

## 🚀 Build & Deployment Instructions

### 1. Hardware Assembly
- Verify common system ground across all microcontrollers, drivers, and peripheral sensor boards.
- Ensure dedicated power supply rails match the operating voltage specified in the Hardware Bill of Materials.

### 2. Firmware Compilation & Flashing
```bash
# Clone the repository
git clone https://github.com/ALWINTR/Blynk-Cloud-Connected-Real-Time-Servo-Actuation-Framework.git

# Navigate to the project directory
cd Blynk-Cloud-Connected-Real-Time-Servo-Actuation-Framework
```

- Open the project in **Arduino IDE**, **PlatformIO**, or **ESP-IDF**.
- Select the target board configuration and COM port.
- Compile and upload firmware directly to the microcontroller.

---

## 👨‍💻 Author

**Alwin T R** — Robotics & Automation Engineer  
- 💼 **LinkedIn**: [linkedin.com/in/alwintr](https://www.linkedin.com/in/alwintr)  
- 🌐 **Interactive Portfolio**: [alwintr.github.io](https://alwintr.github.io)  
- 🐙 **GitHub**: [github.com/ALWINTR](https://github.com/ALWINTR)  
- ✉️ **Direct Email**: [alwintr2003@gmail.com](mailto:alwintr2003@gmail.com)

---

## 📄 License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.
