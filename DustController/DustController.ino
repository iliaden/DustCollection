
#include "display.h"
#include "sensor.h"
#include "constants.h"
#include "gateController.h"
#include "routingMap.h"
#include <Servo.h>

Display display;
// Sensor s1 = Sensor(sensor0, sensor_LED0);
char mystr;


Servo myservo;


void setup() {
  // put your setup code here, to run once:
  // s1.observe();  
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(90);
  setRoutes();
}

void runCallibration(int servoNum){

}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() == 0) {} 
  String teststr = Serial.readString();
  teststr.trim();  

  int parsed = atoi(teststr.c_str());
  // for (const char c : teststr){
  Serial.write(String(parsed).c_str());
  myservo.write(parsed);
  // }
  Serial.write("\n");



}
