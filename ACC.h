/*
 * ACC.h
 *
 *  Created on: 07-Jul-2018
 *      Author: kpit
 */

#ifndef ACC_H_
#define ACC_H_
#include <math.h>
#include <iostream>
#include <string>

class ACC {
 public:
  const static float MIN_SPEED = 3.14;
  virtual double Infotainment_msgs() = 0;
  virtual double() = 0;
  virtual ~ACC() { std::cout << " ACC destructor called"; }
};

///////////////////////////////////////////////////////////////////////
/*class Polygon : public Shape {
  int n_sides;

 public:
  // double area();this will create error because if we write a function is
  // without definition,either remove it or add a definition

  Polygon(int j) : n_sides(j) {}
  virtual ~Polygon() { std::cout << " Polygon destructor called"; }
};
/////////////////////////////////////////////////////////////////////////////////
class Circle : public Shape {
  int radius;

 public:
  Circle(int n) : radius(n) {}
  double area() {
    double a = PI * radius * radius;
    return a;
  }
  double circumference() {
    double c = 2 * PI * radius;
    return c;
  }

  virtual ~Circle() { std::cout << " Circle destructor called"; }
};
///////////////////////////////////////////////////////////////////////////////////
class Square : public Polygon {
  int side_length;

 public:
  Square(int l) : Polygon(4), side_length(l) {}
  double area() {
    double a = side_length * side_length;
    return a;
  }
  double circumference() {
    double c = 4 * side_length;
    return c;
  }
  virtual ~Square() { std::cout << " Square destructor called"; };
};
/////////////////////////////////////////////////////////////////////////////////////
class Triangle : public Polygon {
  int a;
  int b;
  int c;

 public:
  Triangle(int m, int n, int o) : Polygon(3), a(m), b(n), c(o) {}
  double area() {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
  }
  double circumference() {
    double d = a + b + c;
    return d;
  }
  virtual ~Triangle() { std::cout << " Triangle destructor called"; };
};
}
*/

#endif /* ACC_H_ */
