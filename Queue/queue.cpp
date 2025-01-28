#include"queue_class.h"

int main(){
    Queue q;
    std::cout<<"Isempty:"<<q.isempty()<<std::endl;
    for(auto i:{1,5,10,15})q.enqueue(i);
    std::cout<<q.queuecount()<<std::endl;
    q.dequeue();
    std::cout<<q.queuecount()<<std::endl;
    std::cout<<"Isfull:"<<q.isfull()<<std::endl;
    return 0;
}