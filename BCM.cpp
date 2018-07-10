#include "BCM.h"
#include <math.h>
#include <iostream>
#include <string>

BCM::BCM(bool i, bool y, bool z, int s, int n)
    : ACC(i),
      Break_Switch1(y),
      Break_Switch2(z),
      Vehicle_Speed(s),
      faulty_wheel(n) {}

int BCM::get_Switch1status() {
  bool x = Break_Switch1;
  return x;
}
int BCM::get_Switch2status() {
  bool y = Break_Switch2;
  return y;
}
int BCM::Vehicle_Speed_status() {
  int z = Vehicle_Speed;
  return z;
}

void BCM::control() {
  // std::cout << faulty_wheel;
  switch (faulty_wheel) {
    case 1:
      if (Vehicle_Speed < 25)
        std::cout << "Accelerate front-left wheel by reducing breaking power\n";

      break;
    case 2:
      if (Vehicle_Speed < 25)
        std::cout
            << "Accelerate front-right wheel by reducing breaking power\n";

      break;
    case 3:
      if (Vehicle_Speed < 25)
        std::cout << "Accelerate rear-left wheel by reducing breaking power\n";

      break;
    case 4:
      if (Vehicle_Speed < 25)
        std::cout << "Accelerate rear-right wheel by reducing breaking power\n";

      break;
    default:
      std::cout << "default called";
  }
}
