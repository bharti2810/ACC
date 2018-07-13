/*
 * ACC.h
 *
 *  Created on: 13-Jul-2018
 *      Author: kpit
 */

#ifndef ACC_H_
#define ACC_H_
#include <math.h>
#include <iostream>
#include <string>
#include "BCM.h"

class ACC : public ECU {
  std::string ACC_state;

 public:
  ACC(bool i, std::string x);
  void Cruise_switches(BCM& ref_bcm, ECM& ref_ecm);
  void control();
  virtual ~ACC() { std::cout << " ACC destructor called"; }
};
#endif /* ACC_H_ */
