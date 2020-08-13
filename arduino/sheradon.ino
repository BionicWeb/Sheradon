#include <ArduinoMqttClient.h>

#ifdef ESP8266
  #include <ESP8266WiFi.h>
  #define outputPin D1
#endif
#ifdef ESP32
  #include <WiFi.h>
  #define outputPin 32
#endif


String readString;
int retries = 0;

#include "wifi_secrets.h"
// Please enter your sensitive data in wifi_secrets.h
char ssid[] = SECRET_SSID;                 // your network SSID (name)
char pass[] = SECRET_PASS;                 // your network password
char mqtt_user[] = MQTT_USERNAME;          // your MQTT username
char mqtt_pass[] = MQTT_PASS;              // your MQTT password
char open_command[] = MQTT_OPEN_COMMAND;   // This should be the same as MQTT_OPEN_COMMAND in config.py
char mqtt_broker[] = MQTT_BROKER;          // your MQTT broker
int  mqtt_port = MQTT_PORT;                // your MQTT port
char mqtt_topic[] = MQTT_TOPIC;            // your MQTT topic

// To connect with SSL/TLS:
// 1) Change WiFiClient to WiFiSSLClient.
// 2) Change port value from 1883 to 8883.
// 3) Change broker value to a server with a known SSL/TLS root certificate 
//    flashed in the WiFi module.

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

void setup() {
  Serial.begin(115200);
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(outputPin, OUTPUT);
  digitalWrite(outputPin, LOW);
  digitalWrite(LED_BUILTIN, HIGH);
  
  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to SSID: ");
  Serial.println(ssid);
 
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("You're connected to the network");
  Serial.println();

  // You can provide a unique client ID, if not set the library uses Arduino-millis()
  // Each client must have a unique client ID
  mqttClient.setId("gate1");

  // You can provide a username and password for authentication
  mqttClient.setUsernamePassword(mqtt_user,mqtt_pass);

  Serial.print("Attempting to connect to the MQTT broker: ");
  Serial.println(mqtt_broker);
 
  if (!mqttClient.connect(mqtt_broker, mqtt_port)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());

    while (1);
  }

  Serial.println("You're connected to the MQTT broker!");
  Serial.println();

  Serial.print("Subscribing to topic: ");
  Serial.println(mqtt_topic);
  Serial.println();

  // subscribe to a topic
  mqttClient.subscribe(mqtt_topic);

  Serial.print("Waiting for messages on topic: ");
  Serial.println(mqtt_topic);
  Serial.println();
}

void loop() {
  if (!mqttClient.connected()) {
    retries++;
    if(retries >= 5) {
      ESP.restart();
    }
    Serial.println("MQTT connection lost");
    mqttClient.setUsernamePassword(mqtt_user,mqtt_pass);
    if (!mqttClient.connect(mqtt_broker, mqtt_port)) {
      Serial.print("MQTT reconnection error ");
      Serial.println(mqttClient.connectError());
    }
  } else {
    retries = 0;
  }
  
  int messageSize = mqttClient.parseMessage();
  if (messageSize) {
    // we received a message, print out the topic and contents
    Serial.print("Received a message with topic '");
    Serial.print(mqttClient.messageTopic());
    Serial.print("', length ");
    Serial.print(messageSize);
    Serial.println(" bytes:");

    // use the Stream interface to print the contents
    while (mqttClient.available()) {
      char c = mqttClient.read();
      readString += c; 
    }
    readString.trim();
    Serial.println(readString);

    Serial.println();
    if (readString.length() > 0) {
      if (readString == open_command){
        Serial.println("Triggered ...");
        digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(outputPin, HIGH);
        delay(1000);
        digitalWrite(LED_BUILTIN, HIGH);
        digitalWrite(outputPin, LOW);
        delay(100);
      }
      readString = "";
    }
  }
}
