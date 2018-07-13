/*
 * Radar.cpp
 *
 *  Created on: 08-Jul-2018
 *      Author: kpit
 */
#include <math.h>
#include <iostream>
#include <string>

#include "ECM.h"
class Radar {
 public:
  int time_Radar;                             // ms
  const static float velocity_of_sound = 17;  // ms
  Radar(int x) : time_Radar(x) {}
  int calculateDistance() {
    int distance = (time_Radar)*velocity_of_sound;  // 17cm/ms
    return distance;
  }
  ~Radar() {
    std::cout << "Radar Destructor called"
              << "\n";
  }
};
/*
int main() {
// Radar R1(2);
// R1.control();
Sensors *ptr1;
ptr1 = new Radar(1, 1, 3);
ptr1->control();
}*/
