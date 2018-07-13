/*
 * ECM.cpp
 *
 *  Created on: 08-Jul-2018
 *      Author: kpit
 */

#include <math.h>
#include <iostream>
#include <string>
#include "ECU.h"
static int speed;
//#include "Radar.cpp"

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

//////////////////////////////////////////////////////////////////////////////
class ECM : public ECU {
  float fraction_of_Throttle_opening;
  Radar R1;

 public:
  // ECM() : ECU(0), R1(2), fraction_of_Throttle_opening(0.3) {}
  ECM(bool i, int j, float k)
      : ECU(i), R1(j), fraction_of_Throttle_opening(k) {}
  ECM(const ECM& ref)
      : ECU(ref),
        R1(ref.R1),
        fraction_of_Throttle_opening(ref.fraction_of_Throttle_opening) {}
  float get_Rpm() {
    float rpm = THROTTLE_MAX * fraction_of_Throttle_opening;

    return rpm;
  }

  // int getSpeed() { return speed; }
  // storage class, allow initialization

  void control() {
    // Obstacle at distance greater than 300cm

    if (R1.calculateDistance() >= 300)  // 300cm as max range of sensor.
    {
      // fraction_of_Throttle_opening = 0.2;
      // std::cout << "Throttle angle is: " << 80 << "°\n";
      std::cout << "Speed is: " << Cruise_speed << "kmph\n";
    }

    // Obstacle at distance 300cm and 250cm
    else if ((R1.calculateDistance() < 300) &&
             (R1.calculateDistance() >= 250)) {
      speed =
          Cruise_speed - (get_Rpm() / 6);  // speed reduction calculation//54
      std::cout << "Speed is: " << speed << "kmph\n";
    }

    // Obstacle at distance 250cm and 200cm
    else if ((R1.calculateDistance() < 250) &&
             (R1.calculateDistance() >= 200)) {
      speed = Cruise_speed -
              (2 * (get_Rpm() / 6));  // speed reduction calculation//49
      std::cout << "Speed is: " << speed << "kmph\n";

      if (R1.calculateDistance() >= 300)  // 300cm as max range of sensor.
      {
        std::cout << "Throttle angle is: " << 80 << "°\n";
        std::cout << "Speed is: " << Cruise_speed << "kmph\n";
      }

      // Obstacle at distance 300cm and 250cm
      else if ((R1.calculateDistance() < 300) &&
               (R1.calculateDistance() >= 250)) {
        speed =
            Cruise_speed - (get_Rpm() / 6);  // speed reduction calculation//54
        std::cout << "Speed is: " << speed << "kmph\n";
      }

      // Obstacle at distance 250cm and 200cm
      else if ((R1.calculateDistance() < 250) &&
               (R1.calculateDistance() >= 200)) {
        fraction_of_Throttle_opening = 0.4;
        speed = Cruise_speed -
                (2 * (get_Rpm() / 6));  // speed reduction calculation//49
        std::cout << "Speed is: " << speed << "kmph\n";
      }

      // Obstacle at distance 200cm and 150cm
      else if ((R1.calculateDistance() < 200) &&
               (R1.calculateDistance() >= 150)) {
        std::cout << "Throttle angle is: " << 50 << "°\n";
        speed = Cruise_speed -
                (3 * (get_Rpm() / 6));  // speed reduction calculation//36
        std::cout << "Speed is: " << speed << "kmph\n";
      }

      // Obstacle at distance 150cm and 100cm
      else if ((R1.calculateDistance() < 150) &&
               (R1.calculateDistance() >= 100)) {
        std::cout << "Throttle angle is: " << 40 << "°\n";
        speed = Cruise_speed -
                (4 * (get_Rpm() / 6));  // speed reduction calculation//17.33
        std::cout << "Speed is: " << speed << "kmph\n";
      }

      // Obstacle at distance 1speed00cm and 50cm
      else if ((R1.calculateDistance() < 100) &&
               (R1.calculateDistance() >= 50)) {
        speed = Cruise_speed -
                (5 * (get_Rpm() / 6));  // speed reduction calculation
        std::cout << "Speed is: " << speed << "kmph\n";
      }

      // Obstacle at distance below 50cm
      else if (R1.calculateDistance() < 50) {
        // fraction_of_Throttle_opening = 0.8;
        std::cout << "Throttle angle is: " << 20 << "°\n";
        speed = Cruise_speed -
                (6 * (get_Rpm() / 6));  // speed reduction calculation
        std::cout << "Speed is: " << speed << "kmph\n";
      }

    }

    // Obstacle at distance 200cm and 150cm
    else if ((R1.calculateDistance() < 200) &&
             (R1.calculateDistance() >= 150)) {
      // fraction_of_Throttle_opening = 0.5;
      std::cout << "Throttle angle is: " << 50 << "°\n";
      speed = Cruise_speed -
              (3 * (get_Rpm() / 6));  // speed reduction calculation//36
      std::cout << "Speed is: " << speed << "kmph\n";
    }

    // Obstacle at distance 150cm and 100cm
    else if ((R1.calculateDistance() < 150) &&
             (R1.calculateDistance() >= 100)) {
      // fraction_of_Throttle_opening = 0.6;
      std::cout << "Throttle angle is: " << 40 << "°\n";
      speed = Cruise_speed -
              (4 * (get_Rpm() / 6));  // speed reduction calculation//17.33
      std::cout << "Speed is: " << speed << "kmph\n";
    }

    // Obstacle at distance 1speed00cm and 50cm
    else if ((R1.calculateDistance() < 100) && (R1.calculateDistance() >= 50)) {
      // fraction_of_Throttle_opening = 0.7;
      speed =
          Cruise_speed - (5 * (get_Rpm() / 6));  // speed reduction calculation
      std::cout << "Speed is: " << speed << "kmph\n";
    }

    // Obstacle at distance below 50cm
    else if (R1.calculateDistance() < 50) {
      // fraction_of_Throttle_opening = 0.8;
      std::cout << "Throttle angle is: " << 20 << "°\n";
      speed =
          Cruise_speed -
          (6 * (get_Rpm() /
                6));  // fraction_of_Throttle_openingspeed reduction calculation
      std::cout << "Speed is: " << speed << "kmph\n";
    }
  }

  int giveSpeed() {
    control();
    return speed;
  }
};
/*
int main() {
  EC e(1, 3, 0.4);
  // e.R1.time_Radar = 500;
  // e.ignition = 1;
  e.control();
  e.giveSpeed();
}*/
