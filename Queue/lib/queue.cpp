#include "queue.hpp"
#include <iostream>

int main() {
  Queue<int> q{1, 2, 3 };
  q.enqueue(1);
  for (auto e : q) {
    auto a = e;
  }
  q.dequeue();
  return 0;
}
