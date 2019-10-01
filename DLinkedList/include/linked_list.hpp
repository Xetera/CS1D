#pragma once

#include <cstdio>
#include <functional>
#include <initializer_list>

template <typename T>
class DLinkedList;

template <typename T>
struct Node {
  T item;
  Node* next;
  Node* prev;
  DLinkedList<T>* origin;
};

template <typename T>
using NodePairs = std::pair<Node<T>*, Node<T>*>;

/**
 * Split a linked list into two at its midpoint
 * @time_complexity O(n)
 * @tparam T - node type
 * @param source - Beginning of node
 * @return std::pair of two node pointers at the beginning and middle
 */
template <typename T>
NodePairs<T> splitMiddle(Node<T>* const source) {
  Node<T>* slow = source;
  Node<T>* fast = source->next;

  while(fast != nullptr) {
    fast = fast->next;
    if(fast != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }
  }
  // at this point, slow is at the middle
  auto second = slow->next;
  slow->next  = nullptr;
  return { source, second };
}

template <typename T>
class DLinkedList {
  /**
   * Grabs the last item in the linked list
   *
   * @bigO O(n)
   * @param item
   * @return
   */
  Node<T>* last(Node<T>* const item) {
    if(item == nullptr) {
      return nullptr;
    }
    Node<T>* current = item;
    while(current->next != nullptr) {
      current = current->next;
    }
    return current;
  }
  void swap(DLinkedList& list) noexcept {
    std::swap(this->head, list.head);
  }

  Node<T>* mergeBack(Node<T>* a, Node<T>* b) {
    if(a == nullptr) {
      return b;
    }
    if(b == nullptr) {
      return a;
    }
    Node<T>* out;
    if(a->item <= b->item) {
      out       = a;
      out->next = mergeBack(a->next, b);
    } else {
      out       = b;
      out->next = mergeBack(a, b->next);
    }
    return out;
  }

  /**
   * Merge sort algorithm
   */
  void sort(Node<T>* node) {
    Node<T>* nptr    = node;
    bool noMoreNodes = nptr == nullptr || nptr->next == nullptr;

    if(noMoreNodes) {
      return;
    }

    auto [begin, middle] = splitMiddle(node);
    sort(begin);
    sort(middle);

    nptr             = mergeBack(begin, middle);
    nptr->prev       = nullptr;
  }

 public:
  Node<T>* head      = nullptr;
  Node<T>* tail      = nullptr;
  std::size_t length = 0;
  /**
   * Adds a single element to the linked list
   * @param elem
   * @return this
   */
  void add(const T& elem) {
    auto* node   = new Node<T>();
    node->item   = elem;
    node->origin = this;
    if(!tail || !head) {
      head = node;
    } else {
      node->prev = tail;
      tail->next = node;
    }
    tail = node;
    length += 1;
  }
  void sort() {
    sort(head);
  }
  DLinkedList() = default;
  /**
   * Constructing Linked List from iterables
   * @tparam C (extends Iterable)
   * @param iter
   */
  template <typename C>
  explicit DLinkedList(const C& iter)
      : DLinkedList{ iter.begin(), iter.end() } {}
  DLinkedList(const std::initializer_list<T>& list)
      : DLinkedList{ list.begin(), list.end() } {}
  DLinkedList(const DLinkedList<T>& copy)
      : DLinkedList{ copy.begin(), copy.end() } {}
  DLinkedList(const DLinkedList<T>&& copy) noexcept
      : DLinkedList{ copy.begin(), copy.end() } {}
  template <typename Iter>
  DLinkedList(Iter begin, Iter end) {
    for(auto i = begin; i != end; ++i) {
      add(*i);
    }
  }
  DLinkedList& operator=(DLinkedList rhs) {
    rhs.swap(*this);
    return *this;
  }
  ~DLinkedList() {
    Node<T>* node = this->head;
    while(node != nullptr) {
      Node<T>* next = node->next;
      delete node;
      node = next;
    }
  }
};
