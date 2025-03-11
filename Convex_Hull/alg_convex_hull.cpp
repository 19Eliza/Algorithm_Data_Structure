#include "alg_convex_hull.h"

namespace convex_hull {

bool cmp(Point p1, Point p2) {

  if (p1.getX() < p2.getX()) {
    return true;
  }
  if (p1.getX() > p2.getX()) {
    return false;
  }
  if (p1.getX() == p2.getX() && p1.getY() < p2.getY()) {
    return true;
  }
  if (p1.getX() == p2.getX() && p1.getY() > p2.getY()) {
    return false;
  }
}

bool Left_Rotation(Point p1, Point p2, Point p3) {

  double u_x = p2.getX() - p1.getX();
  double u_y = p2.getY() - p1.getY();
  double v_x = p3.getX() - p2.getX();
  double v_y = p3.getX() - p3.getX();

  if (u_x * v_y - u_y * v_x >= 0) {
    return true;
  } else {
    return false;
  }
}

std::vector<Point> Convex_Hull(std::vector<Point> &p) {
  sort(p.begin(), p.end(), cmp);
  std::vector<Point> L_upper;

  int n = p.size();

  L_upper.push_back(p[0]);
  L_upper.push_back(p[1]);

  int j = 1;

  for (int i = 2; i < n; i++) {
    L_upper.push_back(p[i]);

    while (L_upper.size() > 2 &&
           Left_Rotation(*(L_upper.end() - 3), *(L_upper.end() - 2),
                         *(L_upper.end() - 1))) {
      L_upper.erase(L_upper.end() - 2);
    }
  }

  std::vector<Point> L_lower;

  L_lower.push_back(p[n - 1]);
  L_lower.push_back(p[n - 2]);

  for (int i = n - 3; i > -1; i--) {
    L_lower.push_back(p[i]);

    while (L_lower.size() > 2 &&
           Left_Rotation(*(L_lower.end() - 3), *(L_lower.end() - 2),
                         *(L_lower.end() - 1))) {
      L_lower.erase(L_lower.end() - 2);
    }
  }

  L_lower.pop_back();
  L_lower.erase(L_lower.begin());

  L_upper.insert(L_upper.end(), L_lower.begin(), L_lower.end());

  return L_upper;
}
} // namespace convex_hull
