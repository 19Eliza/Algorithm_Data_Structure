#pragma once

#include <limits>
#include <list>
#include <unordered_map>
#include <iterator> 

class LFUCache {
private:
  std::unordered_map<int, int> cache;    // key-value
  std::unordered_map<int, int> key_freq; // key-frequency
  std::unordered_map<int, std::list<int>>
      freq_keys; // freq - set of key with this freq
  std::unordered_map<int, std::list<int>::iterator>
      key_iter_list; // key -iter in list
  int capacity_;
  int min_freq_;

public:
  LFUCache(int capacity);

  int get(int key);

  void put(int key, int value);

  
};