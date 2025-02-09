#pragma once

#include<iostream>
#include<vector>

struct Node{
    double key;
    double el;
};

class Heap{
    private:
    std::vector<Node> heap;
    public:
    Heap();
    Heap(const Heap& h);

    std::size_t Left_Child(std::size_t i) const;
    std::size_t Right_Child(std::size_t i) const;
    std::size_t Parent(std::size_t i) const;

    std::size_t Length()const;

    bool Heapify_up(std::size_t i);
    bool Heapify_down(std::size_t i);

    bool Insert(const Node& elem);
    bool Delete(const std::size_t& i);
    Node Find_Min() const;
    bool Extract_Min();

};