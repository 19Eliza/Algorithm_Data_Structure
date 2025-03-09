#include"LFU.h"

LFUCache::LFUCache(int capacity):lfu(capacity),capacity_(capacity){};

int LFUCache::get(int key){

    auto lfu_iter=lfu.find(key);
    if(lfu_iter!=lfu.end()){
        counter[lfu_iter->first]++;
        return lfu_iter->second;
    }
    else return -1;
}

void LFUCache::put(int key,int value){

    auto lfu_iter=lfu.find(key);

    if(lfu_iter!=lfu.end()){
        lfu_iter->second=value;
        counter[lfu_iter->first]++;
    }
    else{
        if (lfu.size() == capacity_) {
            
            int min_freq = std::numeric_limits<int>::max();
            int lfu_key = -1;

            for (auto& pair : counter) {
                if (pair.second < min_freq) {
                    min_freq = pair.second;
                    lfu_key = pair.first;
                }
            }

            if (lfu_key != -1) {
                lfu.erase(lfu_key);
                counter.erase(lfu_key);
            }
        }
        lfu[key] = value;
        counter[key] = 1;
    }
}