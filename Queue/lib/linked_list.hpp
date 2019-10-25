#pragma once

#include <cstdio>
#include <functional>
#include <initializer_list>

template <typename T>
struct Node {
  T item;
  Node* next;
};

template <typename T>
class LinkedList {
  class NodeIterator {
    Node<T>* elem;

   public:
    explicit NodeIterator(const LinkedList<T>* ptr) : elem(ptr ? ptr->head : nullptr) {}
    NodeIterator& operator++() {
      elem = elem->next;
      return *this;
    }
    bool operator!=(const NodeIterator& other) const {
      return elem != other.elem;
    }
    const T& operator*() const {
      return elem->item;
    }
    ~NodeIterator() {
      elem = nullptr;
    }
  };
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
  void swap(LinkedList& list) noexcept {
    std::swap(this->head, list.head);
    std::swap(length, list.length);
  }

 public:
  Node<T>* head      = nullptr;
  std::size_t length = 0;
  /**
   * Adds a single element to the linked list
   * @param elem
   * @return this
   */
  LinkedList<T>& add(const T& elem) {
    auto* node   = new Node<T>();
    node->item   = elem;
    Node<T>* end = last(head);
    if(!end) {
      head = node;
    } else {
      end->next = node;
    }
    length += 1;
    return *this;
  }
  LinkedList() = default;

  template <typename C>
  explicit LinkedList(const C& iter) : LinkedList{ iter.begin(), iter.end() } {}
  LinkedList(const std::initializer_list<T>& list)
      : LinkedList{ list.begin(), list.end() } {}
  LinkedList(const LinkedList<T>& copy)
      : LinkedList{ copy.begin(), copy.end() } {}
  LinkedList(const LinkedList<T>&& copy) noexcept
      : LinkedList{ copy.begin(), copy.end() } {}
  template <typename Iter>
  LinkedList(Iter begin, Iter end) {
    for(auto i = begin; i != end; ++i) {
      add(*i);
    }
  }
  T peek() {
    if (head == nullptr) {
      throw std::out_of_range("List is empty");
    }
    return head->item;
  }
  void pop_front() noexcept(false) {
    if (head == nullptr) {
      throw std::out_of_range("List is empty");
    }
    const Node<T>* first = head;
    head = head->next;
    length--;
    delete first;
  }
  bool empty() const {
    return head == nullptr;
  }
  LinkedList<T>::NodeIterator begin() {
    return LinkedList<T>::NodeIterator { this };
  }
  LinkedList<T>::NodeIterator end() {
    return LinkedList<T>::NodeIterator { nullptr };
  }
  LinkedList& operator=(LinkedList rhs) {
    rhs.swap(*this);
    return *this;
  }
  ~LinkedList() {
    Node<T>* node = this->head;
    while(node != nullptr) {
      Node<T>* next = node->next;
      delete node;
      node = next;
    }
  }
};
