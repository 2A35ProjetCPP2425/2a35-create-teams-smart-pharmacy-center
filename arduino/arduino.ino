#include <OneWire.h>
#include <DallasTemperature.h>
#include "arduino.h"
// Broche de connexion du capteur DS18B20 (modifiez selon votre configuration)
#define ONE_WIRE_BUS 2

// Initialisation de l'objet OneWire et du capteur de température
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  // Démarrage de la communication série
  Serial.begin(9600);
  Serial.println("Demarrage du capteur DS18B20...");

  // Démarrage du capteur DS18B20
  sensors.begin();
}

void loop() {
  // Demander la lecture des températures
  sensors.requestTemperatures();
  
  // Lire la température en Celsius
  float temperatureC = sensors.getTempCByIndex(0);

  // Vérifier si le capteur renvoie une valeur valide
  if (temperatureC != DEVICE_DISCONNECTED_C) {
    Serial.print("Temperature: ");
    Serial.print(temperatureC);
    Serial.println(" °C");
  } else {
    Serial.println("Erreur: Capteur deconnecté !");
  }

  // Pause de 1 seconde avant la prochaine lecture
  delay(1000);
}
