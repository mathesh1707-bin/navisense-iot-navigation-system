#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// WiFi
const char* ssid = "DEVICE_NAME";
const char* password = "PASSWORD";

// API Key
String apiKey = "YOUR_API_KEY";

// Coordinates
String start = "STARTING_POINT";   
String end   = "DESTINATION_POINT";   

// OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//  BUZZER PIN
#define BUZZER 25

// 🔊 BUZZER FUNCTION
void beep() {
  digitalWrite(BUZZER, HIGH);
  delay(120);
  digitalWrite(BUZZER, LOW);
}

void setup() {

  Serial.begin(115200);

  // 🔊 INIT BUZZER
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);

  // OLED INIT
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while(true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0,0);
  display.println("Starting...");
  display.display();

  // WiFi
  WiFi.begin(ssid, password);
  display.setCursor(0,20);
  display.println("Connecting WiFi");
  display.display();

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  display.clearDisplay();
  display.setCursor(0,0);
  display.println("WiFi Connected");
  display.display();
  delay(1000);

  WiFiClientSecure client;
  client.setInsecure();

  HTTPClient http;

  String url =
  "https://api.openrouteservice.org/v2/directions/driving-car?api_key=" +
  apiKey +
  "&start=" + start +
  "&end=" + end;

  http.begin(client, url);

  int httpCode = http.GET();

  if (httpCode > 0) {

    String payload = http.getString();

    DynamicJsonDocument doc(60000);
    deserializeJson(doc, payload);

    JsonArray steps =
    doc["features"][0]["properties"]["segments"][0]["steps"];

    for (JsonObject step : steps) {

      const char* instruction = step["instruction"];
      float distance = step["distance"];

      // SERIAL OUTPUT
      Serial.println(instruction);

      // OLED OUTPUT
      display.clearDisplay();

      display.setCursor(0,0);
      display.println("NAVIGATION");

      display.setCursor(0,15);
      display.println(instruction);

      display.setCursor(0,40);
      display.print(distance);
      display.println(" m");

      display.display();

      // 🔊 BUZZER SOUND ON EVERY STEP CHANGE
      beep();

      delay(3000);
    }

    // 🔊 FINAL DESTINATION SOUND (optional bonus)
    for(int i=0;i<5;i++){
      beep();
      delay(150);
    }

  } else {

    display.clearDisplay();
    display.setCursor(0,0);
    display.println("API FAILED");
    display.display();

    Serial.println("API request failed");
  }

  http.end();
}

void loop() {}
