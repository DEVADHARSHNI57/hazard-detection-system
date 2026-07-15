# Flowchart

```text
Start
  |
  v
Initialize ESP32-CAM and ESP8266
  |
  v
Connect Wi-Fi
  |
  v
Start ESP32-CAM Web Interface
  |
  v
Run Human Detection
  |
  v
Send Human Status to ESP8266
  |
  v
Read Gas Sensor Value
  |
  v
Is Gas Value Above Threshold?
  |
  +-- No --> Display System Safe
  |          Upload Safe Status to ThingSpeak
  |          Repeat Monitoring
  |
  +-- Yes --> Is Human Detected?
               |
               +-- No --> Display Gas Alert
               |          Upload Gas Alert Status to ThingSpeak
               |          Repeat Monitoring
               |
               +-- Yes --> Display Human + Gas Alert
                          Send SMS via GSM
                          Upload Critical Alert Status to ThingSpeak
                          Repeat Monitoring
```

## Alert Status Values

| Alert Status | Meaning |
| --- | --- |
| `0` | System safe |
| `1` | Gas detected |
| `2` | Gas and human detected |
