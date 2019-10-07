#include <stack>

/**
 * Members of MyQueue are not dynamically allocated and all of its
 * members have their own
 * - destructors
 * - copy constructors
 * - move constructors
 * - copy assignment operators
 * - move assignment operators
 * Therefore the compiler can generate those for `MyQueue` as well,
 * rule of 5 is not necessary.
 */
class MyQueue {
  void move(std::stack<int>& one, std::stack<int>& two) {
    while(!one.empty()) {
      int next = one.top();
      one.pop();
      two.push(next);
    }
  }
  std::stack<int> elems{};

 public:
  /** Push element x to the back of queue. */
  void push(int x) {
    std::stack<int> temp;
    move(elems, temp);
    elems.push(x);
    move(temp, elems);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int out = elems.top();
    elems.pop();
    return out;
  }

  /** Get the front element. */
  int peek() const {
    return elems.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() const {
    return elems.empty();
  }
};
