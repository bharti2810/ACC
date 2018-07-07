/*
 * Speed_sensor.cpp
 *
 *  Created on: 07-Jul-2018
 *      Author: kpit
 */
#include "Sensors.cpp"
class Speed_sensor : public Sensors {
  float rpm;
  float speed;

 public:
  Speed_sensor() : Sensors(0, 0), rpm(0), speed(0) {}

  Speed_sensor(bool i, bool j, float r, float s)
      : Sensors(i, j), rpm(r), speed(s) {}
  Speed_sensor(const Speed_sensor& ref)
      : Sensors(ref), rpm(ref.rpm), speed(ref.speed) {}
  float wheelSpeedSensor() {
    float wheelspeed = rpm * circumference;
    return wheelspeed;
  }
};
