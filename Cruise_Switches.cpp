/*
 * Cruise_Switches.cpp
 *
 *  Created on: 08-Jul-2018
 *      Author: kpit
 */
#include "Cruise_Switches.h"
#include <math.h>
#include <iostream>
#include <string>

Cruise_Switches::Cruise_Switches(bool i, bool m, bool n, int s, int q,
                                 std::string x)
    : BCM(i, m, n, s, q), ACC_state(x) {}
void Cruise_Switches::control() {
  if (ACC_state == "ON") {
    std::cout << "ACC is in standby mode"
              << "\n";

    if (get_Switch1status() == 0 && get_Switch2status() == 0 &&
        Vehicle_Speed_status() > 1) {
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
  BCM::control();
}
