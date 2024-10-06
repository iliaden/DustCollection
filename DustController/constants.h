
#ifndef custom_constants
#define custom_constants

#include <Hashtable.h>

const int sensor0 = A0;
const int sensor1 = A1;
const int sensor2 = A2;
const int sensor3 = A3;
const int sensor4 = A4;
const int sensor5 = A5;
const int sensor6 = A6;
const int sensor7 = A7;
const int sensor8 = A8;
const int sensor9 = A9;
const int sensor10 = A10;
const int sensor11 = A11;

const int sensorPins[] = {
  sensor0,
  sensor1,
  sensor2,
  sensor3,
  sensor4,
  sensor5,
  sensor6,
  sensor7,
  sensor8,
  sensor9,
  sensor10,
  sensor11
};

const int sensor_LED0 = 40;
const int sensor_LED1 = 41;
const int sensor_LED2 = 42;
const int sensor_LED3 = 43;
const int sensor_LED4 = 44;
const int sensor_LED5 = 45;
const int sensor_LED6 = 46;
const int sensor_LED7 = 47;
const int sensor_LED8 = 48;
const int sensor_LED9 = 49;
const int sensor_LED10 = 50;
const int sensor_LED11 = 51;

const int sensorLedPins[] = {
  sensor_LED0,
  sensor_LED1,
  sensor_LED2,
  sensor_LED3,
  sensor_LED4,
  sensor_LED5,
  sensor_LED6,
  sensor_LED7,
  sensor_LED8,
  sensor_LED9,
  sensor_LED10,
  sensor_LED11
};

const int servo0 = 2;
const int servo1 = 3;
const int servo2 = 4;
const int servo3 = 5;
const int servo4 = 6;
const int servo5 = 7;
const int servo6 = 8;
const int servo7 = 9;
const int servo8 = 10;
const int servo9 = 11;
const int servo10 = 12;
const int servo11 = 13;

const int servoPins[] = {
  servo0,
  servo1,
  servo2,
  servo3,
  servo4,
  servo5,
  servo6,
  servo7,
  servo8,
  servo9,
  servo10,
  servo11
};

const int servo_LED0 = 16;
const int servo_LED1 = 17;
const int servo_LED2 = 18;
const int servo_LED3 = 19;
const int servo_LED4 = 22;
const int servo_LED5 = 23;
const int servo_LED6 = 24;
const int servo_LED7 = 25;
const int servo_LED8 = 26;
const int servo_LED9 = 27;
const int servo_LED10 = 28;
const int servo_LED11 = 29;

const int servoLedPins[] = {
  servo_LED0,
  servo_LED1,
  servo_LED2,
  servo_LED3,
  servo_LED4,
  servo_LED5,
  servo_LED6,
  servo_LED7,
  servo_LED8,
  servo_LED9,
  servo_LED10,
  servo_LED11
};

const int servo0_min = 22;
const int servo1_min = 14;
const int servo2_min = 13;
const int servo3_min = 90;
const int servo4_min = 14;
const int servo5_min = 10;

const int servoMinValues[] = {
  servo0_min,
  servo1_min,
  servo2_min,
  servo3_min,
  servo4_min,
  servo5_min
};

const int servo0_max = 86;
const int servo1_max = 77;
const int servo2_max = 74;
const int servo3_max = 152;
const int servo4_max = 80;
const int servo5_max = 73;

const int servoMaxValues[] = {
  servo0_max,
  servo1_max,
  servo2_max,
  servo3_max,
  servo4_max,
  servo5_max
};

const int extractor1 = 30;
const int extractor2 = 38;
const int extractor3 = 39;

const int LCD_E = 15;
const int LCD_RS = 31;
const int LCD_D4 = 32;
const int LCD_D5 = 33;
const int LCD_D6 = 34;
const int LCD_D7 = 35;

const int lcd_brightness_ud = 36;
const int lcd_brightness_cs = 37;

const int device0_open_gates[] = {0};
const int device1_open_gates[] = { 0,1 };
const int device2_open_gates[] = { 0,2 };
const int device3_open_gates[] = { 0,3 };
const int device4_open_gates[] = { 1,3 };
const int device5_open_gates[] = { 1,4 };

#endif