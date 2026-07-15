# Circuit Diagram

This page documents the circuit layout for the Industrial Safety Monitoring System. Add the final circuit image inside the `images/` folder and reference it here after hardware assembly.

## Suggested Diagram Contents

- ESP8266 connected to MQ gas sensor analog output
- ESP8266 connected to 16x2 I2C LCD through SDA and SCL
- ESP8266 connected to GSM module through serial communication
- ESP32-CAM digital output connected to ESP8266 human detection input
- Common ground between ESP8266, ESP32-CAM, GSM module, gas sensor, and LCD
- Stable external power supply for GSM and ESP32-CAM modules

## Block-Level Circuit

```text
MQ Gas Sensor  ---> ESP8266 A0
ESP32-CAM IO2  ---> ESP8266 D6
16x2 I2C LCD   ---> ESP8266 SDA/SCL
GSM Module     ---> ESP8266 Serial
ESP8266        ---> ThingSpeak
GSM Module     ---> SMS Receiver
```

## Notes

- Use a common ground across all modules.
- Ensure the GSM module receives sufficient current from a stable supply.
- Verify voltage compatibility before connecting ESP32-CAM output to ESP8266 input.
- Calibrate the MQ gas sensor threshold based on the target environment.
