#include "arduino_secrets.h"
#include "thingProperties.h"
#include <DHT.h>

#define DHTPIN 2      // Pin where the DHT22 is connected
#define DHTTYPE DHT22 // DHT22 type

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  initProperties();  // Initialize Arduino Cloud properties
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  dht.begin();
}

void loop() {
  ArduinoCloud.update();  // Update Arduino Cloud data
  float currentTemperature = dht.readTemperature();
  
  // Handle alarming conditions
  if (currentTemperature > 10.0) { // Set threshold value for temperature
    alarmTriggered = true;
  } else {
    alarmTriggered = false;
  }

  temperature = currentTemperature;
  delay(1000);  // Wait for 1 second before next loop
}

void onTemperatureChange() {
  // Handle temperature change
}

void onAlarmTriggeredChange() {
  // Handle alarm triggered change
}
