# 🚀 NaviSense – Smart IoT Navigation System

NaviSense is an ESP32-based smart navigation system that uses internet-based APIs to fetch real-time route data and display step-by-step directions on an OLED screen with audio alerts.

---

## 🧠 Overview
This project integrates IoT, embedded systems, and API-based navigation to create a compact and cost-effective alternative to traditional GPS navigation systems.

---

## ⚙️ Features
- 📡 WiFi-based route fetching
- 🗺️ Real-time navigation using OpenRouteService API
- 📺 OLED display for step-by-step instructions
- 🔊 Buzzer alerts for direction changes
- 🔋 Portable and low-cost design

---

## 🛠️ Tech Stack
- ESP32
- Arduino IDE (C++)
- OpenRouteService API
- JSON Parsing (ArduinoJson)
- OLED Display (SSD1306)
- HTTP & WiFi Libraries

---

## 🔌 Hardware Components
- ESP32 Development Board  
- OLED Display (SSD1306)  
- Buzzer  
- Breadboard & Jumper Wires  
- Power Supply  

---

## 🔗 Circuit Connections

### OLED Display
- VCC → 3.3V  
- GND → GND  
- SDA → GPIO 21  
- SCL → GPIO 22  

### Buzzer
- Positive → GPIO 25  
- Negative → GND  

---

## ⚡ How It Works
1. ESP32 connects to WiFi  
2. Sends request to OpenRouteService API  
3. Receives route data in JSON format  
4. Extracts navigation steps  
5. Displays instructions on OLED  
6. Buzzer alerts on each step  

---

## 📸 Demo
(Add your images/videos here)

---

## 📌 Future Improvements
- Add GPS module for offline tracking  
- Mobile app integration  
- Voice navigation output  
- Battery optimization  

---

## 🎯 Outcome
The system successfully retrieves and displays navigation instructions in real-time, demonstrating the integration of IoT, APIs, and embedded systems.

---

## 👨‍💻 Author
Mathesh S
