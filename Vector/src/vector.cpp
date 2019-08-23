#include "vector.hpp"

// class implemented in header
// because of templates

int main() {
  Vector<int> e;
  e.push_back(1);
  e.push_back(2);
  e.push_back(3);
  e.push_back(4);
  const auto n = Vector<int>(e);
  return 0;
}