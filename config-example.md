# Configuration Example

Before uploading the firmware, replace every placeholder value with your own project credentials and settings. Do not commit real credentials, passwords, API keys, phone numbers, or personal tokens to a public repository.

## ESP8266 Gas Monitor

File: `firmware/esp8266-gas-monitor/esp8266_gas_monitor.ino`

Update the following values:

```cpp
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

unsigned long myChannelNumber = YOUR_THINGSPEAK_CHANNEL_ID;
const char * myWriteAPIKey = "YOUR_THINGSPEAK_WRITE_API_KEY";

Serial.println("AT+CMGS=\"YOUR_PHONE_NUMBER\"");
```

Replace them as follows:

| Placeholder | Description |
| --- | --- |
| `YOUR_WIFI_SSID` | Name of your Wi-Fi network |
| `YOUR_WIFI_PASSWORD` | Password for your Wi-Fi network |
| `YOUR_THINGSPEAK_CHANNEL_ID` | Numeric ThingSpeak channel ID |
| `YOUR_THINGSPEAK_WRITE_API_KEY` | ThingSpeak Write API Key |
| `YOUR_PHONE_NUMBER` | GSM recipient phone number in the format required by your SIM/network |

## ESP32-CAM Human Detection

File: `firmware/esp32cam-human-detection/esp32cam_human_detection.ino`

Update the following values:

```cpp
const char* ssid     = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

const char* apssid = "YOUR_AP_SSID";
const char* appassword = "YOUR_AP_PASSWORD";
```

Replace them as follows:

| Placeholder | Description |
| --- | --- |
| `YOUR_WIFI_SSID` | Name of the Wi-Fi network used by the ESP32-CAM |
| `YOUR_WIFI_PASSWORD` | Password for the Wi-Fi network used by the ESP32-CAM |
| `YOUR_AP_SSID` | Access point SSID broadcast by the ESP32-CAM |
| `YOUR_AP_PASSWORD` | Access point password broadcast by the ESP32-CAM |

## Optional Line Notify Credentials

The ESP32-CAM sketch includes functions for Line Notify commands. If you enable or use this feature, provide the token at runtime or replace any token placeholder with:

```text
YOUR_LINE_NOTIFY_TOKEN
```

Do not commit a real Line Notify token to the repository.

## Security Checklist

- Keep real credentials only on your local machine.
- Do not upload screenshots that expose API keys, tokens, Wi-Fi passwords, or phone numbers.
- Rotate any credential that was previously committed to a public repository.
- Use placeholders in examples and documentation.
