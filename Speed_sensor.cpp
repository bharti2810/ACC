/*
 * Speed_sensor.cpp
 *
 *  Created on: 08-Jul-2018
 *      Author: kpit
 */
#include "Speed_sensor.h"
#include <math.h>
#include <iostream>
#include <string>
Speed_sensor::Speed_sensor() : Sensors(0, 0), rpm(0) {}

Speed_sensor::Speed_sensor(bool i, bool j, float r) : Sensors(i, j), rpm(r) {}
Speed_sensor::Speed_sensor(const Speed_sensor& ref)
    : Sensors(ref), rpm(ref.rpm) {}
// void control() { std::cout << "inside Speed sensor"; }
float Speed_sensor::wheelSpeedSensor() {
  float wheelspeed = rpm * circumference;
  return wheelspeed;
}
/*int main() {
  Sensors* ptr1;
  ptr1 = new Speed_sensor(1, 1, 500);
  std::cout << ptr1->wheelSpeedSensor() << "\n";
  std::cout << "bhupp";
}*/
