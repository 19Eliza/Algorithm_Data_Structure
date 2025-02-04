#include"point_class.h"

int main(){
    Point p1;
    Point p2(1,1);
    Point p3(p2);
    p1=p3;
    std::cout<<"p1:"<<p1;
    std::cout<<"p2:"<<p2;
    std::cout<<"p3:"<<p3;

    Point p4;
    std::cin>>p4;
    std::cout<<"p3:"<<p3<<"p4:"<<p4;
    
    return 0;
}