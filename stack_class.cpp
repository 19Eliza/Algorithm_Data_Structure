#include"stack_class.h"

void Stack::push(const T& x){
    data.push_back(x);
    auto iter=std::prev(data.end());
    top=iter;
}

void Stack::pop(){
    data.pop_back();
    if(!data.empty())top=std::prev(data.end());
    else top=data.end();
}

T Stack::get_top() const{
    if(top!=data.end())return *top;
    else {std::cout<<"Stack is empty.";return 0;}
}

bool Stack::empty() const{
    return data.empty();
}
