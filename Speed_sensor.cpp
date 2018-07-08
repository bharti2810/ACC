/*
 * Speed_sensor.cpp
 *
 *  Created on: 07-Jul-2018
 *      Author: kpit
 */
#include <math.h>
#include <iostream>
#include <string>
#include "Sensors.cpp"
class Speed_sensor : public Sensors {
  float rpm;

 public:
  Speed_sensor() : Sensors(0, 0), rpm(0) {}

  Speed_sensor(bool i, bool j, float r) : Sensors(i, j), rpm(r) {}
  Speed_sensor(const Speed_sensor& ref) : Sensors(ref), rpm(ref.rpm) {}
  // void control() { std::cout << "inside Speed sensor"; }
  float wheelSpeedSensor() {
    float wheelspeed = rpm * circumference;
    return wheelspeed;
  }
};

/*int main() {
  Sensors* ptr1;
  ptr1 = new Speed_sensor(1, 1, 500);
  std::cout << ptr1->wheelSpeedSensor() << "\n";
  std::cout << "bhupp";
}*/
