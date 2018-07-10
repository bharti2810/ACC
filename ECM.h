/*
 * ECM.h
 *
 *  Created on: 08-Jul-2018
 *      Author: kpit
 */

#ifndef ECM_H_
#define ECM_H_
#include "Radar.cpp"
float fraction_of_Throttle_opening;
class ECM : public Radar {
 public:
  ECM(bool i, bool j, int x);
  float get_Rpm();
  void control();
};

#endif /* ECM_H_ */
