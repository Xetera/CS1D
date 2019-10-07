#include <queue>

/**
 * Members of MyStack are not dynamically allocated and all of its
 * members have their own
 * - destructors
 * - copy constructors
 * - move constructors
 * - copy assignment operators
 * - move assignment operators
 * Therefore the compiler can generate those for `MyStack` as well,
 * rule of 5 is not necessary.
 */
class MyStack {
  void move(std::queue<int>& one, std::queue<int>& two) {
    while(!one.empty()) {
      int next = one.front();
      one.pop();
      two.push(next);
    }
  }
  std::queue<int> elems{};
 public:
  /** Push element x to the back of queue. */
  void push(int x) {
    std::queue<int> temp;
    move(elems, temp);
    elems.push(x);
    move (temp, elems);
  }

  /** Removes the element from in front of stack and returns that element. */
  int pop() {
    int out = elems.front();
    elems.pop();
    return out;
  }

  /** Get the front element. */
  int top() const {
    return elems.front();
  }

  /** Returns whether the stack is empty. */
  bool empty() const {
    return elems.empty();
  }
};
