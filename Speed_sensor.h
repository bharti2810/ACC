/*
 * Speed_sensor.h
 *
 *  Created on: 08-Jul-2018
 *      Author: kpit
 */

#ifndef SPEED_SENSOR_H_
#define SPEED_SENSOR_H_
#include "Sensors.cpp"

class Speed_sensor : public Sensors {
  float rpm;

 public:
  Speed_sensor();
  Speed_sensor(bool i, bool j, float r);
  Speed_sensor(const Speed_sensor& ref);
  float wheelSpeedSensor();
};

#endif /* SPEED_SENSOR_H_ */
