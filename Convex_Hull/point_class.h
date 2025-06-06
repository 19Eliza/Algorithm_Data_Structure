#pragma once

#include <cmath>
#include <iostream>

class Point {
private:
  double x;
  double y;
  static int count_points;

public:
  Point();
  Point(double, double);
  Point(const Point &);
  Point &operator=(const Point &);

  double getX() const;
  double getY() const;

  bool setX(const double &x1);
  bool setY(const double &y1);

  double module() const;

  ~Point();

  friend double distance(const Point &, const Point &);

  friend std::ostream &operator<<(std::ostream &os, const Point &);
  friend std::istream &operator>>(std::istream &is, Point &);

  static int How_many();
};