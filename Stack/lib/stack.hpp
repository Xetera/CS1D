#include "vector.hpp"

template<typename T>
class Stack {
//  void move(Vector<T> &one, Vector<T> &two) {
//    two.reserve(two.size + one.size);
//    while (!one.empty()) {
//      int next = one.at(one.size);
//      one.pop_back();
//      two.push_back(next);
//    }
//  }

  Vector<T> elems;
public:
  explicit Stack(const Vector<T> &stack) : elems{stack} {}
  Stack(std::initializer_list<T> lst) : elems{lst} {}

  Stack() = default;
  ~Stack() = default;

  /** Push element x to the back of queue. */
  void push(T x) {
    elems.push_back(x);
  }

  /** Removes the element from in front of stack and returns that element. */
  T pop() {
    int out = elems.at(elems.size);
    elems.pop_back();
    return out;
  }

  /** Get the front element. */
  T top() const {
    return *(elems.end());
  }

  /** Returns whether the stack is empty. */
  bool empty() const {
    return elems.empty();
  }

  size_t size() const {
    return elems.size;
  }
};
