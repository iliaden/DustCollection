#ifndef gate_def
#define gate_def
#include <Servo.h>

class Gate {
  public:
    Gate(const int servoPin, const int ledPin, const int closedValue, const int openValue);

    void close();
    void open();
    void disconnect();
    void connect();

  private:
     int servo_pin;
     int led_pin;
     int closed_value;
     int open_value;
    Servo servo;
};

#endif