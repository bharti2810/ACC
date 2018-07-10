/*
 * Sensors.h
 *
 *  Created on: 08-Jul-2018
 *      Author: kpit
 */

#ifndef SENSORS_H_
#define SENSORS_H_
#include "ACC.h"

class Sensors : public ACC {
  bool sensor_state;

 public:
  const static float THROTTLE_MAX = 80;
  Sensors(bool i, bool j);
  virtual float wheelSpeedSensor();
  void control();
  ~Sensors() { std::cout << " Sensors destructor called"; }
};

#endif /* SENSORS_H_ */
