/*
 * Radar.cpp
 *
 *  Created on: 07-Jul-2018
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
  void control() {
    int speed;  // Obstacle at distance greater than 300cm
    if (calculateDistance() >=
        300)  // 300cm as Ultrasonic sensor has max range of 300cm
    {
      std::cout << "Speed is: " << Cruise_speed << "kmph\n";
    }

    // Obstacle at distance 300cm and 250cm
    else if ((calculateDistance() < 300) && (calculateDistance() >= 250)) {
      speed = Cruise_speed - (Cruise_speed / 6);  // speed reduction calculation
      std::cout << "Speed is: " << speed << "kmph\n";
    }

    // Obstacle at distance 250cm and 200cm
    else if ((calculateDistance() < 250) && (calculateDistance() >= 200)) {
      speed = Cruise_speed -
              (2 * (Cruise_speed / 6));  // speed reduction calculation
      std::cout << "Speed is: " << speed << "kmph\n";
    }

    // Obstacle at distance 200cm and 150cm
    else if ((calculateDistance() < 200) && (calculateDistance() >= 150)) {
      speed = Cruise_speed -
              (3 * (Cruise_speed / 6));  // speed reduction calculation
      std::cout << "Speed is: " << speed << "kmph\n";
    }

    // Obstacle at distance 150cm and 100cm
    else if ((calculateDistance() < 150) && (calculateDistance() >= 100)) {
      speed = Cruise_speed -
              (4 * (Cruise_speed / 6));  // speed reduction calculation
      std::cout << "Speed is: " << speed << "kmph\n";
    }

    // Obstacle at distance 1speed00cm and 50cm
    else if ((calculateDistance() < 100) && (calculateDistance() >= 50)) {
      speed = Cruise_speed -
              (5 * (Cruise_speed / 6));  // speed reduction calculation
      std::cout << "Speed is: " << speed << "kmph\n";
    }

    // Obstacle at distance below 50cm
    else if (calculateDistance() < 50) {
      speed = Cruise_speed -
              (6 * (Cruise_speed / 6));  // speed reduction calculation
      std::cout << "Speed is: " << speed << "kmph\n";
    }
  }
};
int main() {
  // Radar R1(2);
  // R1.control();
  Sensors *ptr1;
  ptr1 = new Radar(1, 1, 3);
  ptr1->control();
}

/* """Adaptive Cruise Control
speed: Current car speed (m/s)
acceleration: Current car acceleration (m/s^2)
brake: last signal sent. Real number.
distance: distance in meters to the car in front. (m)
gap: maximum distance to the car in front (m)
cruise_speed: desired speed, set via the cruise control buttons. (m/s)
ACC_state: a convenience dictionary to keep state of ACC.
*/
