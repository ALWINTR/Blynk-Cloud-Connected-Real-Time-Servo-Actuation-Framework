# Blynk Cloud Connected Real Time Servo Actuation Framework

[![GitHub Repository](https://img.shields.io/badge/GitHub-Repository-00f0ff?style=for-the-badge&logo=github&logoColor=white)](https://github.com/ALWINTR/blynk-servo-controller)
[![Developer](https://img.shields.io/badge/Developer-Alwin_T_R-0284c7?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/alwintr)
[![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)](LICENSE)

A production-ready enterprise IoT actuator framework connecting ESP8266 and ESP32 microcontrollers to the **Blynk 2.0 Cloud** platform, featuring bidirectional Virtual Pin (V0) angle streaming, zero-downtime auto-reconnection state machines, and hardware timer brownout protection.

---

## Cloud Architecture and Datastream Mapping

- **Blynk Template Authentication**: Connects securely via TLS / token authentication.
- **Virtual Pin V0**: Mapped to an integer range of 0 to 180 degrees for smooth angle control from mobile or web dashboard.
- **Non-Blocking Architecture**: Utilizes `BlynkTimer` event scheduling to ensure steady 50Hz PWM output without blocking network keep-alive packets.
- **Auto-Reconnect State Machine**: Automatically recovers Wi-Fi and cloud connectivity during network dropouts without resetting the hardware position.

---

## Circuit Pinout Table

| Module / Pin | NodeMCU ESP8266 | ESP32 DevKit | Description |
| :--- | :--- | :--- | :--- |
| **Servo Signal** | GPIO 2 (D4) | GPIO 18 | 50Hz PWM Servo Angle Pulse |
| **Servo Power (5V)** | External 5V 2A Rail | External 5V 2A Rail | Isolated DC power supply |
| **Ground (GND)** | Common GND | Common GND | Shared common ground reference |

---

## Author

**Alwin T R** - Robotics and Automation Engineer  
- LinkedIn: [linkedin.com/in/alwintr](https://www.linkedin.com/in/alwintr)  
- Portfolio: [alwintr.github.io](https://alwintr.github.io)  
- GitHub: [github.com/ALWINTR](https://github.com/ALWINTR)

---

## License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.
