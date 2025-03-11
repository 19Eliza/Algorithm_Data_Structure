#include "LFU.h"


LFUCache::LFUCache(int capacity)
    : cache(), capacity_(capacity), min_freq_(0){};


int LFUCache::get(int key) {

  auto cache_iter = cache.find(key);

  if (cache_iter != cache.end()) {
    auto value = cache[key];//1

    auto prev_freq = key_freq[key];//1

    ++key_freq[key];//2

    auto new_freq = key_freq[key];//2

    auto prev_key_iter = key_iter_list[key];

    freq_keys[prev_freq].erase(prev_key_iter);

    freq_keys[new_freq].push_back(key);

    auto new_key_iter = prev(freq_keys[new_freq].end());

    key_iter_list[key] = new_key_iter;

    if (freq_keys[min_freq_].empty())//////
      min_freq_++;
  } else
    return -1;
}

void LFUCache::put(int key, int value) {

  auto cache_iter = cache.find(key);

  if (cache_iter != cache.end()) {
    cache_iter->second = value;

    auto prev_freq = key_freq[key];
    auto current_freq = ++key_freq[key];

    freq_keys[prev_freq].erase(key_iter_list[key]);

    if (min_freq_ == prev_freq) {
      if (freq_keys[min_freq_].empty())
        min_freq_++;
    }

    key_iter_list.erase(key);

    freq_keys[current_freq].push_back(key);
    auto iter_key = prev(freq_keys[current_freq].end());

    key_iter_list[key] = iter_key;

  } else {
    if (cache.size() == capacity_) {

      auto key_last = freq_keys[min_freq_].front();//3

      cache.erase(key_last);
      key_freq.erase(key_last);

      freq_keys[min_freq_].pop_front();

      key_iter_list.erase(key_last);

    }

    cache.insert({key, value});

    key_freq.insert({key, 1});

    freq_keys[1].push_back(key);
    
    min_freq_ = 1;

    key_iter_list[key] = prev(freq_keys[key_freq[key]].end());
  }
}