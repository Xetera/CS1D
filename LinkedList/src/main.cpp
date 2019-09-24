#include <unordered_map>
#include "linked_list.hpp"

int loopsAt(const LinkedList<int>& list) {
  std::unordered_map<Node<int>*, int> seen;
  Node<int>* iter = list.head;
  int index = 0;
  while (iter != nullptr) {
    auto previousNode = seen.find(iter);
    bool seenBefore = previousNode != seen.end();
    if (seenBefore) {
      return seen.at(iter);
    }
    seen[iter] = index;
    index += 1;
    iter = iter->next;
  }
  return -1;
}

int main() {
  return 0;
}
