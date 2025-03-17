#pragma once

#include<iostream>
#include<unordered_map>
#include<list>
#include<iterator>

class LRUCache{
private:
  std::unordered_map<int, int> cache;// key-value
  std::unordered_map<int, std::list<int>::iterator> key_iter_list; // key -iter in list
  std::list<int> ls_cache;
  int capacity_;
public:
LRUCache(int capacity);

int get(int key);

void put(int key,int value);

};