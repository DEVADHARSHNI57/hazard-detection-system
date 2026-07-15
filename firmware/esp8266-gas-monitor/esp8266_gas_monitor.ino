#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

WiFiClient client;

unsigned long myChannelNumber = YOUR_THINGSPEAK_CHANNEL_ID;   // Replace with your ThingSpeak channel ID
const char * myWriteAPIKey = "YOUR_THINGSPEAK_WRITE_API_KEY";

int gasPin = A0;
int humanPin = D6;
int threshold = 400;

bool smsSentGas = false;
bool smsSentBoth = false;

void sendSMS(String message)
{
  Serial.println("AT");
  delay(1000);
  Serial.println("AT+CMGF=1");
  delay(1000);
  Serial.println("AT+CMGS=\"YOUR_PHONE_NUMBER\"");
  delay(1000);
  Serial.print(message);
  delay(500);
  Serial.write(26);
  delay(5000);
}

void setup()
{
  Serial.begin(9600);
  delay(5000);

  pinMode(humanPin, INPUT);

  lcd.begin();
  lcd.backlight();

  WiFi.begin(ssid, password);
  lcd.print("Connecting WiFi");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    lcd.print(".");
  }

  lcd.clear();
  lcd.print("WiFi Connected");
  delay(2000);
  lcd.clear();

  ThingSpeak.begin(client);
}

void loop()
{
  int gasValue = analogRead(gasPin);
  int humanStatus = digitalRead(humanPin);

  int alertStatus = 0;

  lcd.setCursor(0, 0);
  lcd.print("Gas:");
  lcd.print(gasValue);
  lcd.print("   ");

  lcd.setCursor(0, 1);

  // GAS + HUMAN
  if (gasValue > threshold && humanStatus == HIGH)
  {
    lcd.print("HUMAN+GAS!  ");
    alertStatus = 2;

    if (!smsSentBoth)
    {
      sendSMS("Danger! Human detected with Gas Leakage!");
      smsSentBoth = true;
      smsSentGas = true;
    }
  }

  // ONLY GAS
  else if (gasValue > threshold)
  {
    lcd.print("GAS ALERT!  ");
    alertStatus = 1;

    if (!smsSentGas)
    {
      sendSMS("Alert! Gas Leakage Detected!");
      smsSentGas = true;
    }
  }

  else
  {
    lcd.print("System Safe  ");
    smsSentGas = false;
    smsSentBoth = false;
    alertStatus = 0;
  }

  // Upload to ThingSpeak
  ThingSpeak.setField(1, gasValue);
  ThingSpeak.setField(2, humanStatus);
  ThingSpeak.setField(3, alertStatus);

  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

  delay(20000);   // ThingSpeak requires 15 sec minimum
}

