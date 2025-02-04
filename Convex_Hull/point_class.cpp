#include"point_class.h"

    Point::Point(){
        X=Y=0.0;
    };

    Point::Point(double a,double b){
        X=a;
        Y=b;
    };
    
    Point::Point(const Point& p){
        X=p.X;
        Y=p.Y;
    };

    Point& Point::operator=(const Point& p){
        X=p.X;
        Y=p.Y;
        return *this;
    };

    double Point::x()const{
        return X;
    };
    double Point::y()const{
        return Y;
    };

    double Point::module()const{
        return sqrt(X*X+Y*Y);
    };

    double distance(const Point& p1,const Point& p2){
        return sqrt((p1.X-p2.X)*(p1.X-p2.X)+(p1.Y-p2.Y)*(p1.Y-p2.Y));
    };
    std::ostream& operator<<(std::ostream& os,const Point& p){
        os<<"("<<p.X<<","<<p.Y<<")"<<std::endl;
        return os;
    };
    std::istream& operator>>(std::istream& is,Point& p){
        is>>p.X>>p.Y;
        return is;
    };