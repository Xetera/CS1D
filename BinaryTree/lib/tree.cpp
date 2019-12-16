#include "tree.hpp"

int main() {
  Node<int> e{ 1 };
  Node<int> left{ 2 };
  Node<int> right{ 3 };
  e.left = &left;
  e.right = &right;
  Solution2 s;
  invert(e);
  return 0;
}
