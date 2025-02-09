#include"heap_class.h"

Heap::Heap(){};

Heap::Heap(const Heap& h){
    heap=h.heap;
};

std::size_t Heap::Left_Child(std::size_t i)const{return 2*i+1;}
std::size_t Heap::Right_Child(std::size_t i)const{return 2*i+2;}
std::size_t Heap::Parent(std::size_t i)const{return (i-1)/2;}

std::size_t Heap::Length()const{return heap.size();}

bool Heap::Heapify_up(std::size_t i){
    if(i>=Length())return false;
    if(i>0){
        auto j=Parent(i);
        if(heap[i].key<heap[j].key){
            std::swap(heap[i],heap[j]);
            Heapify_up(j);
        }
    }
    return true;
}
bool Heap::Heapify_down(std::size_t i){
    std::size_t n=Length();
    if(n==0)return false;
    --n;
    std::size_t j;
    if(i>n)return false;
    if((2*i+1)>n)return true;
    else {
        if((2*i+1)<n){
            auto left=2*i+1;
            auto right=2*i+2;
            heap[left].key>heap[right].key?j=right:j=left;
        }
        else j=2*i+1;
    }
    if(heap[i].key>heap[j].key){
        std::swap(heap[i],heap[j]);
        Heapify_down(j);
    }
    return true;
}


bool Heap::Insert(const Node& elem){
    heap.push_back(elem);
    auto i=Length();
    --i;
    Heapify_up(i);
    return true;
}
bool Heap::Delete(const std::size_t& i){
    auto n=Length();
    if(n==0)return false;
    if(i>=n)return false;
    std::swap(heap[n-1],heap[i]);
    heap.pop_back();
    Heapify_down(i);
    return true;
}
Node Heap::Find_Min()const{return heap[0];}
bool Heap::Extract_Min(){
    Delete(0);
}

void Heap::show()const{
    for(auto nd:heap)std::cout<<nd.key<<" ";
    std::cout<<std::endl;
}
