/*
 * Radar.cpp
 *
 *  Created on: 08-Jul-2018
 *      Author: kpit
 */
#include <math.h>
#include <iostream>
#include <string>
#include "ACC.h"
#include "Sensors.cpp"
class Radar : public Sensors {
  int time_Radar;  // ms

 public:
  Radar(bool i, bool j, int x) : Sensors(i, j), time_Radar(x) {}
  int calculateDistance() {
    int distance = (time_Radar)*velocity_of_sound;  // 17cm/ms
    return distance;
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
