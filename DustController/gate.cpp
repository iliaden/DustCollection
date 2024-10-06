#include "gate.h"
#include <Arduino.h>

Gate::Gate(const int servoPin, const int ledPin, const int closedValue, const int openValue){
  servo_pin = servoPin;
  led_pin = ledPin;
  closed_value = closedValue;
  open_value = openValue;
  pinMode(led_pin, OUTPUT);
  pinMode(servo_pin, OUTPUT);
  servo.attach(servo_pin);
}

void Gate::close(){
  servo.write(closed_value);
  digitalWrite(led_pin, LOW);

}
void Gate::open(){
  servo.write(open_value);
  digitalWrite(led_pin, HIGH);
}

void Gate::disconnect(){
  if(servo.attached()) {
    servo.detach();
  }
}
void Gate::connect(){
  if (!servo.attached()){
    servo.attach(servo_pin);
  }
  close();
}

