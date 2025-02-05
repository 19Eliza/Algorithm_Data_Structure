#include"point_class.h"

    Point::Point(){
        x=y=0.0;
    };

    Point::Point(double x1,double y1){
        x=x1;
        y=y1;
    };
    
    Point::Point(const Point& p){
        x=p.x;
        y=p.y;
    };

    Point& Point::operator=(const Point& p){
        x=p.x;
        y=p.y;
        return *this;
    };

    double Point::getX()const{
        return x;
    };
    
    double Point::getY()const{
        return y;
    };

    bool Point::setX(const double& x1){
        x=x1;
        return true;
    }

    bool Point::setY(const double& y1){
        y=y1;
        return true;
    }

    double Point::module()const{
        return sqrt(x*x+y*y);
    };

    double distance(const Point& p1,const Point& p2){
        return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
    };

    std::ostream& operator<<(std::ostream& os,const Point& p){
        os<<"("<<p.x<<","<<p.y<<")"<<std::endl;
        return os;
    };

    std::istream& operator>>(std::istream& is,Point& p){
        is>>p.x>>p.y;
        return is;
    };