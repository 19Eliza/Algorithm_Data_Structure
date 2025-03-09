#pragma once 

#include<unordered_map>
#include<limits>

class LFUCache{
    private:
    std::unordered_map<int,int> lfu;
    std::unordered_map<int,int> counter;
    int min_counter_key;
    int capacity_;
    public:
    LFUCache(int capacity);

    int get(int key);
    
    void put(int key, int value);
};