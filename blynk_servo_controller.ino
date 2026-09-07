/*************************************************************
  Blynk 2.0 IoT Servo Controller (0° - 180°)
  With Wi-Fi Network Scanner & Connection Diagnostics
 *************************************************************/

#define BLYNK_TEMPLATE_ID   "TMPL3a9ba58EB"
#define BLYNK_TEMPLATE_NAME "food dispenser"
#define BLYNK_AUTH_TOKEN    "k-y1yy8vbnQchvAre17-YEXLeWT-7-qr"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

// --- WiFi Credentials ---
char ssid[] = "MATHA ELECTRONICS_ Dwan";
char pass[] = "qwerty09";

// --- Servo Configuration ---
const int SERVO_PIN = 18; // GPIO 18
Servo myServo;

int currentAngle = 0;
const int ANGLE_OFF = 0;    // 0° (Closed/Home)
const int ANGLE_ON  = 180;  // 180° (Dispense/Open)

void moveServo(int targetAngle) {
  targetAngle = constrain(targetAngle, 0, 180);
  Serial.print("[SERVO] Rotating to ");
  Serial.print(targetAngle);
  Serial.println("°");
  myServo.write(targetAngle);
  currentAngle = targetAngle;
}

// Blynk Switch Widget Handler
BLYNK_WRITE(V0) {
  int switchState = param.asInt();
  Serial.print("[BLYNK] V0 Switch received: ");
  Serial.println(switchState);

  if (switchState == 1) {
    moveServo(ANGLE_ON);
  } else {
    moveServo(ANGLE_OFF);
  }
}

BLYNK_CONNECTED() {
  Serial.println("[BLYNK] >>> Successfully Connected to Blynk Cloud! <<<");
  Blynk.syncVirtual(V0);
}

void scanWiFiNetworks() {
  Serial.println("\n[WIFI SCAN] Scanning nearby 2.4GHz Wi-Fi networks...");
  int n = WiFi.scanNetworks();
  if (n == 0) {
    Serial.println("[WIFI SCAN] No networks found! (Check ESP32 antenna)");
  } else {
    Serial.print("[WIFI SCAN] Found ");
    Serial.print(n);
    Serial.println(" networks:");
    for (int i = 0; i < n; ++i) {
      Serial.print("   ");
      Serial.print(i + 1);
      Serial.print(": \"");
      Serial.print(WiFi.SSID(i));
      Serial.print("\" (Signal: ");
      Serial.print(WiFi.RSSI(i));
      Serial.print(" dBm, ");
      Serial.print((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "Open" : "Encrypted");
      Serial.println(")");
    }
  }
  Serial.println("----------------------------------------");
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n========================================");
  Serial.println("    Blynk 2.0 180° Servo Controller     ");
  Serial.println("========================================");

  // Initialize Servo
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myServo.setPeriodHertz(50);
  myServo.attach(SERVO_PIN, 500, 2400);
  
  // Test servo movement on startup (quick 0 -> 90 -> 0 test)
  Serial.println("[SERVO] Testing servo on GPIO 18...");
  myServo.write(0);
  delay(500);
  myServo.write(90);
  delay(500);
  myServo.write(0);
  currentAngle = 0;
  Serial.println("[SERVO] Servo Test Complete! Position set to 0°");

  // Scan WiFi to verify SSID visibility
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  scanWiFiNetworks();

  // Connect to WiFi
  Serial.print("[WIFI] Connecting to \"");
  Serial.print(ssid);
  Serial.println("\"...");
  
  WiFi.begin(ssid, pass);
  
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 40) {
    delay(500);
    Serial.print(".");
    attempts++;
    if (attempts % 20 == 0) {
      Serial.println();
    }
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n[WIFI] Connected Successfully!");
    Serial.print("[WIFI] IP Address: ");
    Serial.println(WiFi.localIP());
    Serial.print("[WIFI] Signal Strength (RSSI): ");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBm");

    // Connect to Blynk
    Serial.println("[BLYNK] Connecting to Blynk Cloud server...");
    Blynk.config(BLYNK_AUTH_TOKEN, "blynk.cloud", 80);
    Blynk.connect();
  } else {
    Serial.println("\n[WIFI] FAILED to connect!");
    Serial.print("[WIFI] Status Code: ");
    Serial.println(WiFi.status());
    Serial.println("Possible causes: Incorrect password, 5GHz-only network, or weak signal.");
  }
}

void loop() {
  Blynk.run();
}
