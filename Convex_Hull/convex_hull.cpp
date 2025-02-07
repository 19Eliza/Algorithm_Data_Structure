#include "point_class.h"
#include "alg_convex_hull.h"

using namespace convex_hull;

int main()
{
    Point p1;
    p1.setX(0);
    p1.setY(0);
    Point p2(1, 0);
    Point p3;
    p3.setX(0.5);
    p3.setY(0.5);
    std::cout << "p1:" << p1;
    std::cout << "p2:" << p2;
    std::cout << "p3:" << p3;

    Point p4;
    // std::cin>>p4;
    p4.setX(0);
    p4.setY(1);
    std::cout << "p4:" << p4;

    std::cout << Point::How_many() << std::endl;

    std::vector<Point> p;
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);

    std::cout << Point::How_many() << std::endl;

    auto CH = Convex_Hull(p);
    std::cout << "Convex Hull:\n";
    for (auto elem : CH)
        std::cout << elem;

    std::cout << "Count points " << Point::How_many() << std::endl;
    p1.~Point();
    std::cout << "Count points " << Point::How_many() << std::endl;

    return 0;
}