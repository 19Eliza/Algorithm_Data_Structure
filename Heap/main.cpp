#include"heap_class.h"

int main(){
    Heap hp;
    Node nd{2,3};
    hp.Insert(nd);
    hp.Insert(Node {1,4});
    hp.Insert(Node {5,5});
    hp.Insert(Node {3,4});

    std::cout<<hp.Length()<<std::endl;
    hp.show();
    std::cout<<hp.Find_Min().key<<std::endl;
    hp.Extract_Min();
    hp.show();
    return 0;
}