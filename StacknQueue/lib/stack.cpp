#include "stack.hpp"
#include "queue.hpp"

int main() {
  MyQueue e;
  e.push(1);
  e.push(2);
  e.push(3);
  auto b = e.pop();
  auto c = e.pop();
  auto d = e.pop();
  return 0;
}