#include"LRU.h"

LRUCache::LRUCache(int capacity): cache(), capacity_(capacity), ls_cache(){};

int LRUCache::get(int key){
    auto iter_cache=cache.find(key);

    if(iter_cache!=cache.end()){
        auto iter_key=key_iter_list[key];
        ls_cache.erase(iter_key);
        key_iter_list.erase(key);
        ls_cache.push_back(key);
        auto new_iter_key=prev(ls_cache.end());
        key_iter_list[key]=new_iter_key;
        return cache[key];
    }
    else return -1;
}

void LRUCache::put(int key,int value){
    auto iter_cache=cache.find(key);

    if(iter_cache!=cache.end()){
        cache[key]=value;
        auto list_iter=key_iter_list[key];
        ls_cache.erase(list_iter);
        key_iter_list.erase(key);
        ls_cache.push_back(key);
        auto new_iter_key=prev(ls_cache.end());
        key_iter_list[key]=new_iter_key;
    }
    else{
        if(cache.size()==capacity_){
            auto lru_key=ls_cache.front();
            cache.erase(lru_key);
            key_iter_list.erase(lru_key);
            ls_cache.pop_front();
        }
        cache[key]=value;
        ls_cache.push_back(key);
        auto iter_key=prev(ls_cache.end());
        key_iter_list[key]=iter_key;
    }
}