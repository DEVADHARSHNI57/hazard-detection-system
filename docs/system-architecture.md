# System Architecture

## Overview

The Industrial Safety Monitoring System uses two microcontrollers with separate responsibilities. The ESP32-CAM handles camera-based human detection and hosts the detection web interface. The ESP8266 reads gas sensor data, receives the human detection signal, displays the system state, uploads readings to ThingSpeak, and sends GSM alerts.

## Architecture Blocks

```text
+------------------+        Human Status Signal        +----------------------+
|    ESP32-CAM     | ---------------------------------> |       ESP8266        |
|                  |                                    |                      |
| Camera Capture   |                                    | Gas Sensor Reading   |
| Web Interface    |                                    | LCD Status Display   |
| COCO-SSD Model   |                                    | ThingSpeak Upload    |
| Human Detection  |                                    | GSM SMS Alert        |
+------------------+                                    +----------+-----------+
                                                                  |
                                                                  v
                                                        +----------------------+
                                                        |      ThingSpeak      |
                                                        | Cloud Monitoring     |
                                                        +----------------------+
                                                                  |
                                                                  v
                                                        +----------------------+
                                                        |     SMS Receiver     |
                                                        | Safety Notification  |
                                                        +----------------------+
```

## ESP32-CAM Role

- Captures images using the camera module.
- Hosts a browser-based interface.
- Uses TensorFlow.js COCO-SSD to detect people.
- Sends human detection status to the ESP8266 through a digital output signal.

## ESP8266 Role

- Reads harmful gas levels from the MQ gas sensor.
- Reads the ESP32-CAM human detection signal.
- Displays gas value and alert status on the 16x2 I2C LCD.
- Uploads gas value, human status, and alert status to ThingSpeak.
- Sends SMS alerts through the GSM module according to the firmware alert logic.

## Data Flow

1. ESP32-CAM detects whether a person is present.
2. ESP32-CAM outputs the human detection status to the ESP8266.
3. ESP8266 reads gas concentration from the MQ sensor.
4. ESP8266 evaluates gas and human status.
5. ESP8266 displays the result on the LCD.
6. ESP8266 uploads readings to ThingSpeak.
7. GSM SMS alert is triggered when the configured alert condition is met.
