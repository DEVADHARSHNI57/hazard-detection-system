# Industrial Safety Monitor

An IoT-based Industrial Safety Monitoring System that combines harmful gas sensing, human detection, LCD status display, GSM alerting, and ThingSpeak cloud monitoring. The project uses an ESP8266 as the gas monitoring and alert controller, while an ESP32-CAM performs real-time human detection through a web interface powered by TensorFlow.js COCO-SSD.

## Features

- Harmful gas detection using an MQ gas sensor
- Human detection using ESP32-CAM
- GSM SMS alerts for safety notifications
- ThingSpeak cloud monitoring
- 16x2 I2C LCD status display
- Real-time monitoring through ESP32-CAM web interface
- Alert decision based on gas and human presence status

## Hardware Used

- ESP8266
- ESP32-CAM
- MQ Gas Sensor
- GSM Module
- 16x2 I2C LCD
- Power Supply

## Project Workflow

```text
ESP32-CAM
    |
    v
Human Detection
    |
    v
ESP8266
    |
    v
Gas Detection
    |
    v
If Gas == TRUE AND Human == TRUE
    |
    v
Send SMS via GSM
    |
    v
Upload data to ThingSpeak
```

## Repository Structure

```text
industrial-safety-monitor/
|-- README.md
|-- config-example.md
|-- LICENSE
|-- .gitignore
|-- docs/
|   |-- system-architecture.md
|   |-- flowchart.md
|   `-- circuit-diagram.md
|-- hardware/
|   |-- components.md
|   `-- wiring.md
|-- firmware/
|   |-- esp8266-gas-monitor/
|   |   `-- esp8266_gas_monitor.ino
|   `-- esp32cam-human-detection/
|       `-- esp32cam_human_detection.ino
|-- images/
|-- results/
`-- requirements.md
```

## Folder Description

- `docs/` contains architecture, flowchart, and circuit documentation.
- `hardware/` lists the components and wiring connections.
- `firmware/esp8266-gas-monitor/` contains the ESP8266 gas monitoring, LCD, ThingSpeak, and GSM alert firmware.
- `firmware/esp32cam-human-detection/` contains the ESP32-CAM human detection and web interface firmware.
- `images/` is reserved for project photos, diagrams, and screenshots.
- `results/` is reserved for testing output, ThingSpeak screenshots, LCD photos, and demonstration evidence.
- `requirements.md` lists hardware, software, library, and cloud requirements.


## Configuration

Before running this project, replace all placeholder values in the firmware with your own credentials. The public repository intentionally uses safe placeholder values instead of real passwords, API keys, tokens, phone numbers, or personal information.

Use [config-example.md](config-example.md) as the configuration guide for:

- Wi-Fi SSID and password
- ESP32-CAM access point SSID and password
- ThingSpeak channel ID
- ThingSpeak Write API Key
- GSM recipient phone number
- Optional Line Notify token, if that feature is used

Do not commit real credentials to this repository. If any real credential was previously committed or pushed, rotate it before using the project publicly.

## Installation

1. Install the Arduino IDE.
2. Add ESP8266 and ESP32 board support through Arduino Boards Manager.
3. Install the required Arduino libraries:
   - `ESP8266WiFi`
   - `ThingSpeak`
   - `Wire`
   - `LiquidCrystal_I2C`
   - `WiFi`
   - `WiFiClientSecure`
   - `esp_camera`
4. Open `firmware/esp8266-gas-monitor/esp8266_gas_monitor.ino` and update:
   - Wi-Fi SSID and password
   - ThingSpeak channel number
   - ThingSpeak write API key
   - GSM recipient phone number
   - Gas threshold value, if required
5. Open `firmware/esp32cam-human-detection/esp32cam_human_detection.ino` and update:
   - Wi-Fi SSID and password
   - Access point SSID and password, if required
6. Upload the ESP8266 firmware to the ESP8266 board.
7. Upload the ESP32-CAM firmware to the ESP32-CAM board.
8. Connect the ESP32-CAM human detection output to the ESP8266 human detection input.
9. Power the system and monitor LCD, SMS, web interface, and ThingSpeak updates.

## Future Improvements

- Mobile application
- Buzzer alert
- Email alerts
- Multiple gas sensors
- Dashboard for historical safety analytics

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.


