/*
 * BCM.h
 *
 *  Created on: 08-Jul-2018
 *      Author: kpit
 */

#ifndef BCM_H_
#define BCM_H_
#include "ECM.cpp"
using namespace std;
class BCM : public ECU {
  bool Break_Switch1;
  bool Break_Switch2;
  int faulty_wheel;

 public:
  BCM(bool i, bool y, bool z, int n);
  int getSpeed(ECM& ref_ecm);
  bool get_Switch1status();
  bool get_Switch2status();
  void control();

  ~BCM() { std::cout << "BCM destructor \n"; }
};

#endif /* BCM_H_ */
