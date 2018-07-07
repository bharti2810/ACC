#include <math.h>
#include <iostream>
#include <string>
#include "ACC.h"
#include "Speed_sensor.cpp"
class BCM : public ACC {
  bool Break_Switch1;
  bool Break_Switch2;
  int Vehicle_Speed;

 public:
  BCM(bool i, bool y, bool z, int s)
      : ACC(i), Break_Switch1(y), Break_Switch2(z), Vehicle_Speed(s) {}
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
  ~BCM() { std::cout << "BCM destructor \n"; }
};

class Cruise_Switches : public BCM {
  std::string ACC_state;

 public:
  Cruise_Switches(bool i, bool y, bool z, int s, std::string x)
      : BCM(i, y, z, s), ACC_state(x) {}
  void control() {
    if (ACC_state == "ON") {
      std::cout << "ACC is in standby mode"
                << "\n";

      if (get_Switch1status() == 1 && get_Switch2status() == 1 &&
          Vehicle_Speed_status() == 1) {
        std::cout << "ACC is in active mode"
                  << "\n";
      } else {
        std::cout << "ACC is not in active mode"
                  << "\n";
      }
    }
  }
};
