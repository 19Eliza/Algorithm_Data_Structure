#pragma once

#include"point_class.h"
#include<vector>
#include<algorithm>

namespace convex_hull{
    bool cmp(Point p1, Point p2);
    bool Left_Rotation(Point p1, Point p2, Point p3);
    std::vector<Point> Convex_Hull(std::vector<Point>& p);
}