#include "sensor.h"
#include <Arduino.h>

Sensor::Sensor(const int sensor, const int led){
  sensor_pin = sensor;
  led_pin = led;
  pinMode(sensor_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  observing = false;
};

void Sensor::observe(){
  observing = true;
  
  passive_max = 0;
  passive_min = 1024;
  // spend 1s getting measurements to establish passive_max and passive_min
  int observation_count = 0;
  while (observation_count < CALIBRATION_OBSERVATIONS_COUNT){
    int observation = analogRead(sensor_pin);
    if (observation > passive_max){
      passive_max =  observation;
    }
    if (observation < passive_min){
      passive_min = observation;
    }
    delay(OBSERVATION_INTERVAL_MS);
    observation_count++;
  }
}

void Sensor::stopObserve(){
  observing = false;
  passive_max = 0;
  passive_min = 1024;
}

bool Sensor::currentDetected(){
  
  if (!observing){
    return false;
  }
  int observation_count = 0;
  while (observation_count < OBSERVATIONS_COUNT){
    int observation = analogRead(sensor_pin);
    if (observation > passive_max || observation < passive_min){
      digitalWrite(led_pin, HIGH);
      return true;
    }
    delay(OBSERVATION_INTERVAL_MS);
    observation_count++;
  }
  digitalWrite(led_pin, LOW);
  return false;
}
