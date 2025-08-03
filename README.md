# 💧 Smart Water Tank Full Monitoring Alert System Using Rain Sensor

A smart IoT-based solution to monitor water levels in overhead tanks and automatically generate alerts when the tank is full—especially during rain—helping conserve water and prevent overflow.

---

## 🚩 Problem Statement

In many households and institutions, water tanks overflow due to lack of real-time monitoring, leading to water wastage. Additionally, during rainy seasons, the rainwater harvesting systems are not effectively managed, causing missed opportunities to conserve water or prevent overflow.

Key issues:

- Manual monitoring is inefficient and unreliable.
- Overflow during rain leads to both water wastage and structural damage.
- No alert system to notify users of full tanks in real time.

**Smart Water Tank Full Monitoring Alert System** solves this with real-time tank level tracking and automated alert notifications, integrating a rain sensor for contextual decision-making.

---

## 🌟 Features

- 📊 **Real-Time Water Level Monitoring** using ultrasonic or float sensors.
- 🌧️ **Rain Detection** via rain sensor to prioritize rainwater harvesting logic.
- 🚨 **Alert System** via buzzer, LED, or mobile notification when tank is full.
- 📡 **IoT Integration** to send live data to the cloud or mobile device.
- 🔋 **Low Power Consumption** for energy efficiency.
- 💡 **Automatic Pump Control** (optional feature) to stop pumping when full.

---

## 🛠️ Tech Stack & Components

- **Microcontroller**: Arduino UNO 
- **Sensors**:
  - Rain Sensor (YL-83 / FC-37)
- **Actuators**:
  - Buzzer / LED for alerts
  - Relay module (for pump control)
- **Connectivity**:
  - Blynk / MQTT / Firebase (optional)
- **Power Source**: 5V adapter / battery pack

---

## 🚀 Getting Started

### 🔧 Hardware Setup

1. Connect ultrasonic sensor to measure tank level.
2. Attach rain sensor outside to detect rainfall.
3. Wire buzzer/LED to alert when tank is full.
4. Optionally, connect a relay to control water pump.
5. Upload Arduino/ESP code from `/firmware`.

### 💻 Software Setup

1. Install Arduino IDE
2. Add board support (NodeMCU/ESP32) via board manager.
3. Install necessary libraries (`NewPing`, `WiFi`, `Blynk`, etc.).
4. Flash the code to your microcontroller.

---

## 💾 Example Arduino Code Snippet

```cpp
#define TRIG_PIN D1
#define ECHO_PIN D2
#define RAIN_SENSOR A0
#define BUZZER D3

void setup() {
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int rain = analogRead(RAIN_SENSOR);
  int distance = getWaterLevel();

  if (distance < 5 && rain < 300) {
    digitalWrite(BUZZER, HIGH); // Alert
    Serial.println("Tank Full and it's Raining!");
  } else {
    digitalWrite(BUZZER, LOW);
  }

  delay(1000);
}
