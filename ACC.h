/*
 * ACC.h
 *
 *  Created on: 07-Jul-2018
 *      Author: kpit
 */

#ifndef ACC_H_
#define ACC_H_
#include <math.h>
#include <iostream>
#include <string>

class ACC {
  bool ignition;

 public:
  ACC(bool i) : ignition(i) {}
  const static float velocity_of_sound = 17;  // ms
  const static int Cruise_speed = 60;
  const static float circumference = 209.6;  // cm
  virtual void control() = 0;
  // virtual double() = 0;
  virtual ~ACC() { std::cout << " ACC destructor called"; }
};

#endif /* ACC_H_ */
