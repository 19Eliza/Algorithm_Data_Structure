#include<iostream>
#include<vector>
#include <iterator> 

using T=double;

class Stack{
    private:
    std::vector<T> data;
    std::vector<T>::iterator top;
    public:
    void push(const T&);
    void pop();
    T get_top() const;
    bool empty() const;
};