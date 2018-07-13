/*
 * ACC.cpp
 *
 *  Created on: 13-Jul-2018
 *      Author: kpit
 */

#include "ACC.h"

ACC::ACC(bool i, std::string x) : ECU(i), ACC_state(x) {}
void ACC::Cruise_switches(BCM& ref_bcm, ECM& ref_ecm) {
  bool s1 = ref_bcm.get_Switch1status();
  bool s2 = ref_bcm.get_Switch2status();
  int Vehiclespeed = ref_ecm.giveSpeed();

  if (ACC_state == "ON") {
    std::cout << "ACC is in standby mode"
              << "\n";

    if (s1 == 0 && s2 == 0 && Vehiclespeed > 1) {
      std::cout << "ACC is in active mode"
                << "\n";
    } else {
      std::cout << "ACC is not in active mode"
                << "\n";
    }
  } else {
    std::cout << "ACC is in OFF state"
              << "\n";
  }
}
void ACC::control() { std::cout << "ACC controller called\n"; }
