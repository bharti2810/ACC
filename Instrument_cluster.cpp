/*
 * Instrument_cluster.cpp
 *
 *  Created on: 07-Jul-2018
 *      Author: kpit
 *//*
#include <iostream>
#include <string>
#include "BCM.cpp"
class Instrument_Cluster : public ACC {
  int x;
  Instrument_Cluster(bool i, int y) : ACC(i), x(y) {}
};
void compute(ACC &ref) {
  std::cout << ref.control() << "\n";
  std::cout << ref.display() << "\n";
}
}
;/*
