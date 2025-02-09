#include"heap_class.h"

Heap::Heap(){};

Heap::Heap(const Heap& h){
    heap=h.heap;
};

std::size_t Heap::Left_Child(std::size_t i)const{return 2*i;}
std::size_t Heap::Right_Child(std::size_t i)const{return 2*i+1;}
std::size_t Heap::Parent(std::size_t i)const{return i/2;}

std::size_t Heap::Length()const{return heap.size();}

bool Heap::Heapify_up(std::size_t i){
    if(i>0){
        auto j=this->Parent(i);
        if(heap[i].key<heap[j].key){
            std::swap(heap[i],heap[j]);
            Heapify_up(j);
        }
    }
    return true;
}


bool Heap::Insert(const Node& elem){
    heap.push_back(elem);
    return true;
}


Node Heap::Find_Min()const{return heap[0];}
