#pragma once

#include<iostream>
#include<cmath>


class Point{
    private:
    double X;
    double Y;
    public:
    Point();
    Point(double,double);
    Point(const Point&);
    Point& operator=(const Point&);

    double x()const;
    double y()const;

    double module()const;

    friend double distance(const Point&,const Point&);
    friend std::ostream& operator<<(std::ostream& os,const Point&);
    friend std::istream& operator>>(std::istream& is,Point&);
};