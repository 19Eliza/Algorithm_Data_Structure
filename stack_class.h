#include<iostream>
#include<vector>
#include <iterator> 

template<class T>
class Stack{
    private:
    vector<T> data;
    vector<T>::iterator top;
    public:
    Stack(){
        top=nullptr;
    }

};