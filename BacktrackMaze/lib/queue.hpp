#pragma once

#include "linked_list.hpp"
#include <initializer_list>

template <typename T>
class Queue {
  LinkedList<T> elems;

 public:
  Queue(const std::initializer_list<T>& lst) {
    elems = LinkedList<T>(lst.begin(), lst.end());
  }
  Queue() = default;
  ~Queue() = default;
  /** Push element x to the back of queue. */
  void enqueue(T x) {
    elems.add(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  T dequeue() {
    T out = elems.peek();
    elems.pop_front();
    return out;
  }

  /** Get the front element. */
  int peek() const {
    return elems.peek();
  }

  /** Returns whether the queue is empty. */
  bool empty() const {
    return elems.empty();
  }

  auto begin() {
    return elems.begin();
  }

  auto end() {
    return elems.end();
  }
  std::size_t size() {
   return elems.length;
  }
};
