/*
 * Cruise_Switches.h
 *
 *  Created on: 08-Jul-2018
 *      Author: kpit
 */

#ifndef CRUISE_SWITCHES_H_
#define CRUISE_SWITCHES_H_
#include "BCM.h"

class Cruise_Switches : public BCM {
  std::string ACC_state;

 public:
  Cruise_Switches(bool i, bool m, bool n, int s, int q, std::string x);

  void control();
};

/*int main() {
  BCM *ptr1;
  ptr1 = new Cruise_Switches(1, 0, 0, 4, 3, "ON");
  ptr1->control();
  BCM B1(1, 0, 0, 4, 2);
  B1.control();
}
*/

#endif /* CRUISE_SWITCHES_H_ */
