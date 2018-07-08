#include <math.h>
#include <iostream>
#include <string>
#include "ACC.h"

class BCM : public ACC {
  bool Break_Switch1;
  bool Break_Switch2;
  int Vehicle_Speed;
  int faulty_wheel;

 public:
  BCM(bool i, bool y, bool z, int s, int n)
      : ACC(i),
        Break_Switch1(y),
        Break_Switch2(z),
        Vehicle_Speed(s),
        faulty_wheel(n) {}

  int get_Switch1status() {
    bool x = Break_Switch1;
    return x;
  }
  int get_Switch2status() {
    bool y = Break_Switch2;
    return y;
  }
  int Vehicle_Speed_status() {
    int z = Vehicle_Speed;
    return z;
  }

  void control() {
    // std::cout << faulty_wheel;
    switch (faulty_wheel) {
      case 1:
        if (Vehicle_Speed < 25)
          std::cout
              << "Accelerate front-left wheel by reducing breaking power\n";

        break;
      case 2:
        if (Vehicle_Speed < 25)
          std::cout
              << "Accelerate front-right wheel by reducing breaking power\n";

        break;
      case 3:
        if (Vehicle_Speed < 25)
          std::cout
              << "Accelerate rear-left wheel by reducing breaking power\n";

        break;
      case 4:
        if (Vehicle_Speed < 25)
          std::cout
              << "Accelerate rear-right wheel by reducing breaking power\n";

        break;
      default:
        std::cout << "default called";
    }
  }

  ~BCM() { std::cout << "BCM destructor \n"; }
};
//////////////////////////////////////////////////////////

class Cruise_Switches : public BCM {
  std::string ACC_state;

 public:
  Cruise_Switches(bool i, bool m, bool n, int s, int q, std::string x)
      : BCM(i, m, n, s, q), ACC_state(x) {}
  void control() {
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
};
int main() {
  BCM *ptr1;
  ptr1 = new Cruise_Switches(1, 0, 0, 4, 3, "ON");
  ptr1->control();
  BCM B1(1, 0, 0, 4, 2);
  B1.control();
}
