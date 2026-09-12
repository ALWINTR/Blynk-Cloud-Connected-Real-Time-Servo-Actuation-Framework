# 📱 Blynk 2.0 Cloud Servo Controller (ESP8266 / ESP32)

[![GitHub Repository](https://img.shields.io/badge/GitHub-Repository-00f0ff?style=for-the-badge&logo=github&logoColor=white)](https://github.com/ALWINTR/blynk-servo-controller)
[![Developer](https://img.shields.io/badge/Developer-Alwin_T_R-0284c7?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/alwintr)
[![Platform](https://img.shields.io/badge/Platform-Blynk_2.0_IoT-38bdf8?style=for-the-badge&logo=blynk&logoColor=white)](https://github.com/ALWINTR)
[![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)](LICENSE)

A production-ready enterprise IoT actuator framework connecting ESP8266 and ESP32 microcontrollers to the **Blynk 2.0 Cloud** platform, featuring bidirectional Virtual Pin (V0) angle streaming, zero-downtime auto-reconnection state machines, and hardware timer brownout protection.

---

## 📌 Cloud Architecture & Datastream Mapping

- **Blynk Template Authentication**: Connects securely via TLS / encrypted token auth.
- **Virtual Pin V0**: Mapped to an integer range of `0` to `180` for smooth angle control from the Blynk mobile app or web console.
- **Non-Blocking Execution**: Utilizes `BlynkTimer` event scheduling to ensure steady 50Hz PWM output without blocking network keep-alive packets.
- **Auto-Reconnect State Machine**: Automatically recovers Wi-Fi and cloud connectivity during network dropouts without resetting the hardware position.

---

## ⚙️ Hardware BOM & Pinout

| Module / Pin | NodeMCU ESP8266 | ESP32 DevKit | Description |
| :--- | :--- | :--- | :--- |
| **Servo Signal** | GPIO 2 (D4) | GPIO 18 | 50Hz PWM Servo Angle Pulse |
| **Servo Power (5V)** | External 5V 2A Rail | External 5V 2A Rail | Isolated DC power supply |
| **Ground (GND)** | Common GND | Common GND | Shared common ground |

---

## 🚀 Getting Started & Configuration

1. Clone repository:
   ```bash
   git clone https://github.com/ALWINTR/blynk-servo-controller.git
   ```
2. Open `blynk_servo_controller.ino` in Arduino IDE.
3. Configure your Blynk 2.0 credentials:
   ```cpp
   #define BLYNK_TEMPLATE_ID   "TMPLxxxxxx"
   #define BLYNK_DEVICE_NAME   "Servo Controller"
   #define BLYNK_AUTH_TOKEN    "YourAuthToken"
   char ssid[] = "YOUR_WIFI_SSID";
   char pass[] = "YOUR_WIFI_PASSWORD";
   ```
4. Install the **Blynk** library via Library Manager.
5. Upload firmware and control the servo in real time from the Blynk mobile app.

---

## 👨‍💻 Author

**Alwin T R** — Robotics & Automation Engineer  
- 💼 LinkedIn: [linkedin.com/in/alwintr](https://www.linkedin.com/in/alwintr)  
- 🌌 Portfolio: [alwintr.github.io](https://alwintr.github.io)  
- 💻 GitHub: [github.com/ALWINTR](https://github.com/ALWINTR)

---

## 📄 License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.
