/*
 * BCM.h
 *
 *  Created on: 08-Jul-2018
 *      Author: kpit
 */

#ifndef BCM_H_
#define BCM_H_
#include "ACC.h"

class BCM : public ACC {
  bool Break_Switch1;
  bool Break_Switch2;
  int Vehicle_Speed;
  int faulty_wheel;

 public:
  BCM(bool i, bool y, bool z, int s, int n);

  int get_Switch1status();
  int get_Switch2status();
  int Vehicle_Speed_status();
  void control();

  ~BCM() { std::cout << "BCM destructor \n"; }
};

#endif /* BCM_H_ */
