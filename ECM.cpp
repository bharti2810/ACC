/*
 * ECM.cpp
 *
 *  Created on: 08-Jul-2018
 *      Author: kpit
 */

#include <math.h>
#include <iostream>
#include <string>
#include "Radar.cpp"
float fraction_of_Throttle_opening;
class ECM : public Radar {
 public:
  ECM(bool i, bool j, int x) : Radar(i, j, x) {}
  float get_Rpm() {
    // float x;
    float rpm = THROTTLE_MAX * fraction_of_Throttle_opening;

    return rpm;
  }
  void control() {
    int speed;  // Obstacle at distance greater than 300cm

    if (calculateDistance() >= 300)  // 300cm as max range of sensor.
    {
      // fraction_of_Throttle_opening = 0.2;
      std::cout << "Throttle angle is: " << 80 << "°\n";
      std::cout << "Speed is: " << Cruise_speed << "kmph\n";
    }

    // Obstacle at distance 300cm and 250cm
    else if ((calculateDistance() < 300) && (calculateDistance() >= 250)) {
      fraction_of_Throttle_opening = 0.3;

      speed =
          Cruise_speed - (get_Rpm() / 6);  // speed reduction calculation//54
      std::cout << "Speed is: " << speed << "kmph\n";
    }

    // Obstacle at distance 250cm and 200cm
    else if ((calculateDistance() < 250) && (calculateDistance() >= 200)) {
      fraction_of_Throttle_opening = 0.4;
      speed = Cruise_speed -
              (2 * (get_Rpm() / 6));  // speed reduction calculation//49
      std::cout << "Speed is: " << speed << "kmph\n";
    }

    // Obstacle at distance 200cm and 150cm
    else if ((calculateDistance() < 200) && (calculateDistance() >= 150)) {
      fraction_of_Throttle_opening = 0.5;
      std::cout << "Throttle angle is: " << 50 << "°\n";
      speed = Cruise_speed -
              (3 * (get_Rpm() / 6));  // speed reduction calculation//36
      std::cout << "Speed is: " << speed << "kmph\n";
    }

    // Obstacle at distance 150cm and 100cm
    else if ((calculateDistance() < 150) && (calculateDistance() >= 100)) {
      fraction_of_Throttle_opening = 0.6;
      std::cout << "Throttle angle is: " << 40 << "°\n";
      speed = Cruise_speed -
              (4 * (get_Rpm() / 6));  // speed reduction calculation//17.33
      std::cout << "Speed is: " << speed << "kmph\n";
    }

    // Obstacle at distance 1speed00cm and 50cm
    else if ((calculateDistance() < 100) && (calculateDistance() >= 50)) {
      fraction_of_Throttle_opening = 0.7;
      speed =
          Cruise_speed - (5 * (get_Rpm() / 6));  // speed reduction calculation
      std::cout << "Speed is: " << speed << "kmph\n";
    }

    // Obstacle at distance below 50cm
    else if (calculateDistance() < 50) {
      fraction_of_Throttle_opening = 0.8;
      std::cout << "Throttle angle is: " << 20 << "°\n";
      speed =
          Cruise_speed - (6 * (get_Rpm() / 6));  // speed reduction calculation
      std::cout << "Speed is: " << speed << "kmph\n";
    }
  }
};

/*int main() {
  Radar *ptr1;
  ptr1 = new ECM(1, 1, 10);
  ptr1->control();
}*/
