#include "BCM.h"
#include <math.h>
#include <iostream>
#include <string>

BCM::BCM(bool i, bool y, bool z, int n)
    : ECU(i), Break_Switch1(y), Break_Switch2(z), faulty_wheel(n) {}

bool BCM::get_Switch1status() {
  bool x = Break_Switch1;
  return x;
}
bool BCM::get_Switch2status() {
  bool y = Break_Switch2;
  return y;
}
int BCM::getSpeed(ECM& ref_ecm) {
  int d = ref_ecm.giveSpeed();
  switch (faulty_wheel) {
    case 1:
      if (d < 25)
        std::cout << "Accelerate front-left wheel by reducing breaking power\n";

      break;
    case 2:
      if (d < 25)
        std::cout
            << "Accelerate front-right wheel by reducing breaking power\n";

      break;
    case 3:
      if (d < 25)
        std::cout << "Accelerate rear-left wheel by reducing breaking power\n";

      break;
    case 4:
      if (d < 25)
        std::cout << "Accelerate rear-right wheel by reducing breaking power\n";

      break;
    default:
      std::cout << "default called";
  }
  return d;
}
/*int BCM::getSpeed() {
  ECM r;
  int Vehicle_speed = r.giveSpeed();
  return Vehicle_speed;
}*/

void BCM::control() { std::cout << "BCM Controller"; }
/*
int main() {
  ECM e(1, 5, 0.6);
  BCM b(1, 0, 0, 3);
  b.getSpeed(e);
}*/
