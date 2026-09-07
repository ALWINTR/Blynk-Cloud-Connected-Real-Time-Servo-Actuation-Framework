# 🤖 Blynk 2.0 IoT 180° Servo Controller

This project allows you to control a standard servo motor (SG90, MG90S, MG995, MG996R, etc.) remotely from anywhere in the world using **Blynk 2.0 IoT**. When you toggle a switch widget in the Blynk App / Web Dashboard, the servo instantly rotates to **180°**, and when toggled off, it returns to **0°**.

---

## 📋 Table of Contents
1. [Components Required](#-components-required)
2. [Circuit Diagram & Pinout](#-circuit-diagram--pinout)
3. [Blynk 2.0 Cloud Configuration](#-blynk-20-cloud-configuration)
4. [Arduino IDE Setup & Libraries](#-arduino-ide-setup--libraries)
5. [Code Configuration](#-code-configuration)
6. [Testing & Operation](#-testing--operation)
7. [Troubleshooting & Power Tips](#-troubleshooting--power-tips)

---

## 🛠 Components Required

| Component | Quantity | Description |
| :--- | :--- | :--- |
| **Microcontroller** | 1 | **ESP8266** (NodeMCU / D1 Mini) OR **ESP32** (DevKit) |
| **Servo Motor** | 1 | SG90 / MG90S / MG995 / MG996R (180° Positional Servo) |
| **Power Supply / USB** | 1 | 5V 2A USB power adapter or external 5V power supply |
| **Jumper Wires** | Several | Male-to-Female / Male-to-Male |
| **Breadboard** (Optional) | 1 | For easy wiring |

---

## 🔌 Circuit Diagram & Pinout

### Standard Servo Wire Color Code:
* **Brown / Black**: Ground (`GND`)
* **Red**: Power (`VCC` / `5V`)
* **Orange / Yellow**: PWM Signal (`SIG`)

---

### Option A: ESP8266 (NodeMCU / Wemos D1 Mini)

```
        +-------------------------+
        |   ESP8266 (NodeMCU)     |
        |                         |
        |  GND ------------------------> Servo Brown/Black (GND)
        |  VIN (5V) -------------------> Servo Red (VCC)
        |  D4 (GPIO 2) ----------------> Servo Orange/Yellow (Signal)
        +-------------------------+
```

| Servo Wire | NodeMCU Pin | Wemos D1 Mini Pin | Notes |
| :--- | :--- | :--- | :--- |
| **Orange (Signal)** | `D4` (GPIO 2) | `D4` (GPIO 2) | PWM Signal |
| **Red (VCC)** | `VIN` or `5V` | `5V` | Powered from 5V USB |
| **Brown (GND)** | `GND` | `GND` | Common Ground |

---

### Option B: ESP32 (30-pin / 38-pin DevKit)

```
        +-------------------------+
        |     ESP32 DevKit        |
        |                         |
        |  GND ------------------------> Servo Brown/Black (GND)
        |  VIN / 5V -------------------> Servo Red (VCC)
        |  GPIO 18 --------------------> Servo Orange/Yellow (Signal)
        +-------------------------+
```

| Servo Wire | ESP32 Pin | Notes |
| :--- | :--- | :--- |
| **Orange (Signal)** | `GPIO 18` | PWM Signal |
| **Red (VCC)** | `VIN` / `5V` | Powered from 5V USB |
| **Brown (GND)** | `GND` | Common Ground |

> [!CAUTION]
> **Power Warning for Heavy Servos (MG995 / MG996R):**
> High-torque servos draw up to 1.5A when moving. Powering them directly from the microcontroller's 3.3V pin will cause the board to crash or brown out. Always connect the servo's Red wire to **5V / VIN** or use an **external 5V 2A power supply** (ensure the external power supply GND is connected to the ESP GND).

---

## ☁️ Blynk 2.0 Cloud Configuration

Follow these steps to set up Blynk Cloud (Web Console & Mobile App):

### Step 1: Create a Template
1. Go to [blynk.cloud](https://blynk.cloud/) and log into your account.
2. Navigate to **Developer Zone** $\rightarrow$ **Templates** $\rightarrow$ Click **+ New Template**.
3. Name: `Servo Controller`
4. Hardware: Select `ESP8266` or `ESP32` (depending on your board).
5. Connection Type: `WiFi`.
6. Click **Done**.

### Step 2: Create Datastream
1. In your Template, click the **Datastreams** tab $\rightarrow$ Click **+ New Datastream** $\rightarrow$ Select **Virtual Pin**.
2. Configure the datastream:
   - **Name**: `Servo Switch`
   - **Pin**: `V0`
   - **Data Type**: `Integer`
   - **Min**: `0`
   - **Max**: `1`
   - **Default Value**: `0`
3. Click **Create** $\rightarrow$ Click **Save** in the top right.

### Step 3: Configure Web Dashboard
1. Click the **Web Dashboard** tab in your template.
2. Drag and drop a **Switch** widget onto the canvas.
3. Click the gear icon on the Switch widget:
   - Title: `Servo 180° Toggle`
   - Datastream: Select `Servo Switch (V0)`
4. Click **Save and Apply**.

### Step 4: Add New Device
1. Go to the **Devices** section (Magnifying glass icon) $\rightarrow$ Click **+ New Device**.
2. Select **From Template** $\rightarrow$ Choose `Servo Controller`.
3. Copy the generated **Template ID**, **Template Name**, and **Auth Token** from the top right info card.

### Step 5: Configure Mobile App (Android / iOS)
1. Open the **Blynk IoT** app on your phone.
2. Open the `Servo Controller` device.
3. Tap the wrench/edit icon $\rightarrow$ Tap `+` to add a widget.
4. Add a **Button / Switch** widget.
5. Tap the switch widget:
   - Mode: **SWITCH** (or PUSH if you prefer a pulse trigger)
   - Datastream: `Servo Switch (V0)`

---

## 💻 Arduino IDE Setup & Libraries

### 1. Install Board Package:
- **ESP8266**: `Tools` $\rightarrow$ `Board` $\rightarrow$ `Boards Manager...` $\rightarrow$ Search for `ESP8266` by *ESP8266 Community* and install.
- **ESP32**: `Tools` $\rightarrow$ `Board` $\rightarrow$ `Boards Manager...` $\rightarrow$ Search for `ESP32` by *Espressif Systems* and install.

### 2. Install Required Libraries:
Go to `Sketch` $\rightarrow$ `Include Library` $\rightarrow$ `Manage Libraries...` and install:
1. **`Blynk`** (by Volodymyr Shymanskyy)
2. **`ESP32Servo`** (by Kevin Harrington) — *Required only if using ESP32*

---

## ⚙️ Code Configuration

Open [`blynk_servo_controller.ino`](file:///C:/Users/matha/.gemini/Developer Logs/scratch/blynk_servo_controller/blynk_servo_controller.ino) and update the configuration section:

```cpp
// 1. Paste your Blynk credentials here:
#define BLYNK_TEMPLATE_ID   "TMPLxxxxxx"
#define BLYNK_TEMPLATE_NAME "Servo Controller"
#define BLYNK_AUTH_TOKEN    "YourAuthTokenHere"

// 2. WiFi credentials:
char ssid[] = "Your_WiFi_Name";
char pass[] = "Your_WiFi_Password";
```

### Optional Customizations:
- **Smooth Sweep Movement**: Change `const bool SMOOTH_MOVEMENT = true;` to enable gradual degree-by-degree servo rotation instead of sudden jumps.
- **Change Angles**: Modify `ANGLE_OFF = 0;` and `ANGLE_ON = 180;` to customize the movement range (e.g., 45° to 135°).

---

## 🚀 Testing & Operation

1. Connect your ESP board to your computer via USB.
2. Select the correct **Board** and **COM Port** in Arduino IDE.
3. Click **Upload**.
4. Open the **Serial Monitor** at **115200 baud**.
5. You should see:
   ```
   ========================================
       Blynk 2.0 180° Servo Controller     
   ========================================
   [SERVO] Initialized at Pin: GPIO 18 (Position: 0°)
   [WIFI] Connecting to WiFi and Blynk...
   [BLYNK] Connected to Blynk Cloud!
   ```
6. Open your Blynk App or Web Dashboard:
   - Flip the switch to **ON (1)**: The servo rotates to **180°**.
   - Flip the switch to **OFF (0)**: The servo returns to **0°**.

---

## 💡 Troubleshooting & Power Tips

1. **Servo Jitters or Board Resets on Movement:**
   - Cause: Current surge caused by the servo motor.
   - Solution: Add a `100µF` to `470µF` electrolytic capacitor across the Servo's VCC and GND pins, or use a separate 5V power supply.
2. **Servo doesn't reach exact 180°:**
   - Some budget SG90 servos have slightly narrower pulse widths (~600µs to 2300µs). You can fine-tune the pulse range in `myServo.attach(SERVO_PIN, minMicros, maxMicros)`.
3. **Blynk Device is Offline:**
   - Ensure your 2.4GHz Wi-Fi SSID and password are correct (ESP8266/ESP32 do not connect to 5GHz-only networks).
