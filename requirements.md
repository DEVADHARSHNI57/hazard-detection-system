# Requirements

## Hardware Requirements

| Component | Purpose |
| --- | --- |
| ESP8266 | Main controller for gas sensing, LCD display, ThingSpeak upload, and GSM alert logic |
| ESP32-CAM | Camera module for real-time human detection and web interface hosting |
| MQ Gas Sensor | Detects harmful gas concentration |
| GSM Module | Sends SMS alerts during unsafe conditions |
| 16x2 I2C LCD | Displays gas value and safety status |
| Jumper Wires | Connects modules and signal lines |
| Breadboard or PCB | Circuit assembly |
| External Power Supply | Stable power for ESP8266, ESP32-CAM, and GSM module |

## Software Requirements

- Arduino IDE
- ESP8266 board package
- ESP32 board package
- ThingSpeak account and channel
- Wi-Fi network
- Browser with JavaScript support for ESP32-CAM web interface

## Arduino Libraries

- `ESP8266WiFi`
- `ThingSpeak`
- `Wire`
- `LiquidCrystal_I2C`
- `WiFi`
- `WiFiClientSecure`
- `esp_camera`

## Cloud Requirements

- ThingSpeak channel number
- ThingSpeak Write API Key
- Fields configured for:
  - Gas value
  - Human detection status
  - Alert status
