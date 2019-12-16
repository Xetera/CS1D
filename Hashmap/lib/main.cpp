#include "main.hpp"
#include <iostream>
struct Chain {
  int key;
  int value;
  Chain* next = nullptr;
  explicit Chain(int key, int value) : key{ key }, value{ value } {}
};
class MyHashMap {
  static constexpr int MAX_SIZE = 25;
  static Chain* latestChainOrMatching(Chain& c) {
    Chain* current = &c;
    while(current->next) {
      current = current->next;
    }
    return current;
  }

  Chain*& findChain(int key) {
    return buckets[key % MAX_SIZE];
  }

 public:
  static constexpr int SENTINEL_VALUE = -1;
  int size                            = 0;
  Chain* buckets[MAX_SIZE]{};

  /** Initialize your data structure here. */
  MyHashMap() = default;
  ~MyHashMap() {
    for(Chain*& bucket : buckets) {
      delete bucket;
    }
  }

  /** value will always be non-negative. */
  void put(int key, int value) {
    Chain*& chain = findChain(key);
    auto next     = new Chain(key, value);
    size += 1;
    if(!chain) {
      chain = next;
      return;
    }
    while (chain) {
      if (chain->key == key) {
        chain->value = value;
        return;
      }
      chain = chain->next;
    }
    chain = next;
  }

  /** Returns the value to which the specified key is mapped, or -1 if this map
   * contains no mapping for the key */
  int get(int key) {
    Chain* chain = findChain(key);
    while(chain) {
      if(chain->key == key) {
        return chain->value;
      }
      chain = chain->next;
    }
    return SENTINEL_VALUE;
  }

  /** Removes the mapping of the specified value key if this map contains a
   * mapping for the key */
  void remove(int key) {
    Chain* current = findChain(key);
    if(!current) {
      return;
    }
    Chain*& prev = current;
    while(current) {
      if(current->key == key) {
        prev = current->next;
        size -= 1;
        return;
      }
      prev    = current;
      current = current->next;
    }
  }
};

int main() {
  MyHashMap map;
  map.put(1, 1);
  map.put(2, 2);
  auto one = map.get(1);
  auto te  = map.get(3);
  map.put(2, 1);
  auto a = map.get(2);
  map.remove(2);
  auto e = map.get(2);
  return 0;
}
