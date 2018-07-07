/*
 * Sensors.cpp
 *
 *  Created on: 07-Jul-2018
 *      Author: kpit
 */

#include <math.h>
#include <iostream>
#include <string>
#include "ACC.h"
class Sensors : public ACC {
  bool sensor_state;

 public:
  Sensors(bool i, bool j) : ACC(i), sensor_state(j) {}
  virtual float wheelSpeedSensor() {
    float wheelspeed = Cruise_speed;
    return wheelspeed;
  }
  void control() { std::cout << "hello"; }
  ~Sensors() { std::cout << " Sensors destructor called"; }
};
