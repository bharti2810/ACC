/*
 * Instrument_cluster.h
 *
 *  Created on: 07-Jul-2018
 *      Author: kpit
 */

#ifndef INSTRUMENT_CLUSTER_H_
#define INSTRUMENT_CLUSTER_H_
#include <ACC.h>
#include <iostream>
#include <string>
class Instrument_Cluster : public ACC {
  void display() {}
};
class Cruise_Switches : public Instrument_Cluster {
  std::string ACC_state;
  // BCM::Break_Switch1;
  // BCM::Break_Switch2;
  // BCM::Vehicle_Speed;

 public:
  Cruise_Switches(std::string x) : ACC_state(x) {
    if (x == "ON") {
      std::cout << "ACC is in standby mode"
                << "\n";
      if (Break_Switch1 == 1 && Break_Switch2 == 1 && Vehicle_Speed == 1) {
        std::cout << "ACC is in active mode"
                  << "\n";
      } else {
        std::cout << "ACC is not in active mode"
                  << "\n";
      }
    } else if (x == "OFF") {
    }
  }
};

#endif /* CLASS_ACC_H_ */

#endif /* INSTRUMENT_CLUSTER_H_ */
