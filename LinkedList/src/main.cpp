#include <unordered_map>
#include <iostream>

template <typename T>
struct Node {
  T item;
  Node* next;
};

template <typename T>
class LinkedList {
  /**
   * I couldn't get this iterator class to work and I'm so sad about it
   */
  class NodeIterator {
    T* ptr;

  public:
    explicit NodeIterator(T& ptr) : ptr(&ptr) {}
    NodeIterator operator++() {
      ptr->next;
      return *this;
    }
    bool operator!=(const T& other) const {
      return ptr != other.ptr;
    }
    T& operator*() const {
      return *ptr;
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
    // _sigh_ if only C++ had typeclasses...
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
  }

public:
  Node<T>* head      = nullptr;
  std::size_t length = 0;
  /**
   * Adds a single element to the linked list
   * @param elem
   * @return this
   */
  void add(const T& elem) {
    auto* node   = new Node<T>();
    node->item   = elem;
    Node<T>* end = last(head);
    if(!end) {
      head = node;
    } else {
      end->next = node;
    }
    length += 1;
  }
  LinkedList() = default;
  /**
   * Constructing Linked List from iterables
   * @tparam C (extends Iterable)
   * @param iter
   */
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
  NodeIterator begin() {
    return NodeIterator(head);
  }
  NodeIterator end() {
    return nullptr;
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
int loopsAt(const LinkedList<int>& list) {
  // just using this for constant access
  // to prevent using O(n^2) time, otherwise I'd just
  // use the vector from the previous assignment
  std::unordered_map<Node<int>*, int> seen;
  Node<int>* node = list.head;
  int index       = 0;
  while(node != nullptr) {
    try {
      return seen.at(node);
    } catch(const std::out_of_range& _) {
      seen[node] = index;
      index += 1;
      node = node->next;
    }
  }
  return -1;
}

int main() {
  LinkedList<int> list { 1, 2, 3, 4 };

  // this line causes memory leaks because the destructor
  // doesn't clean up circular references properly.

  // uncomment to get it working
//  list.head->next->next->next = list.head->next;
  auto out = loopsAt(list);
  std::cout << "The loop points back to index: " << out; // is 1 (index)
  return 0;
}
