
#include <SPI.h>
#include <Adafruit_BMP085.h>
#include <ESP8266WiFi.h>
// #include <Arduino.h>
#include <PubSubClient.h>


const char* ssid = "raspi-webgui";
const char* password =  "ChangeMe";
const char* mqttServer = "10.3.141.1";
const int mqttPort = 1883;
const char* mqttUser = "";
const char* mqttPassword = "";

unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE	(50)
char msg[MSG_BUFFER_SIZE];
int value = 0;

Adafruit_BMP085 bmp;
WiFiClient espClient;
PubSubClient client(espClient);


void setup() {
  Serial.begin(115200);

  Wire.begin(D4,D5);
  while (!bmp.begin(0x77)) {
	  Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    delay(1000);
  }

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");

  client.setServer(mqttServer, mqttPort);

  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");

    if (client.connect("Potager01")) {

      Serial.println("connected");

    } else {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void loop() {
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    ++value;
    snprintf (msg, MSG_BUFFER_SIZE, "%f", bmp.readTemperature());
    client.publish("potager01/temperature", msg);
  }
}



