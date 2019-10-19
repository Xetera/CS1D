#include <cstdio>
#include <stdexcept>
#include <iostream>
#include "Vector.hpp"

int main () {
  Vector v{ 1,2,3 };
  for (auto a : v) {
    std::cout << a;
  }
  return 0;
}
