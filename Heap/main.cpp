#include"heap_class.h"

int main(){
    Heap hp;
    Node nd{2,3};
    hp.Insert(nd);
    hp.Insert(Node {1,4});
    std::cout<<hp.Length()<<std::endl;
    return 0;
}