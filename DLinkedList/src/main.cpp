#include <linked_list.hpp>

int main() {
  DLinkedList<int> list { 4, 1, 10, 5, 3, 4 };
  list.sort();

  return 0;
}
