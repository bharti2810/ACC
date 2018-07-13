/*
 * main.cpp
 *
 *  Created on: 13-Jul-2018
 *      Author: kpit
 */
#include "ACC.h"
#include "BCM.h"
#include "ECM.h"
#include "ECU.h"
//#include "Radar.cpp"
int main() {
  ECM e(1, 5, 0.6);
  BCM b(1, 0, 0, 3);
  b.getSpeed(e);
  ACC a1(1, "OFF");
  a1.Cruise_switches(b, e);
}
