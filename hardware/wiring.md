# Wiring

## ESP8266 Connections

| ESP8266 Pin | Connected Module | Module Pin / Signal | Purpose |
| --- | --- | --- | --- |
| `A0` | MQ Gas Sensor | Analog Output | Reads gas concentration |
| `D6` | ESP32-CAM | Human detection output | Reads human detection status |
| `SDA` | 16x2 I2C LCD | SDA | LCD data line |
| `SCL` | 16x2 I2C LCD | SCL | LCD clock line |
| `TX/RX` | GSM Module | RX/TX | GSM AT command communication |
| `GND` | All modules | GND | Common ground |

## ESP32-CAM Connections

| ESP32-CAM Pin | Connected Module | Purpose |
| --- | --- | --- |
| `IO2` | ESP8266 `D6` | Human detection output signal |
| `5V` | Power Supply | ESP32-CAM power input |
| `GND` | Common Ground | Shared reference ground |

## Important Wiring Notes

- Connect all module grounds together.
- Use a stable external power supply for the GSM module because SMS transmission can require high current.
- Confirm the LCD I2C address before uploading the ESP8266 sketch. The current firmware uses `0x27`.
- Confirm the ESP32-CAM output pin and ESP8266 input pin match the uploaded firmware.
- Avoid powering the full system only from a laptop USB port during GSM transmission.
