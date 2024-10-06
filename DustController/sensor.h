#ifndef custom_sensor
#define custom_sensor


const int OBSERVATIONS_COUNT = 3;
const int OBSERVATION_INTERVAL_MS = 50;
const int CALIBRATION_OBSERVATIONS_COUNT = 20;

class Sensor {
  public:
    Sensor(const int sensor, const int led);

    bool currentDetected();
    void observe();
    void stopObserve();

  private:
    int sensor_pin;
    int led_pin;
    bool observing;
    
    int passive_max;
    int passive_min;

};

#endif