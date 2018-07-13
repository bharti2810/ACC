/*
 * ECU.h
 *
 *  Created on: 11-Jul-2018
 *      Author: kpit
 */

#ifndef ECU_H_
#define ECU_H_

#include <math.h>
#include <iostream>
#include <string>

class ECU {
 public:
  bool ignition;
  ECU(bool i) : ignition(i) {}
  const static float THROTTLE_MAX = 80;
  const static float Cruise_speed = 60;
  const static float circumference = 209.6;  // cm
  virtual void control() = 0;
  // virtual double() = 0;
  virtual ~ECU() { std::cout << " ECU destructor called"; }
};

#endif /* ECU_H_ */
