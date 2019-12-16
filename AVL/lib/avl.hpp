#pragma once

#include <fstream>
#include <functional>
#include <initializer_list>
#include "tree.hpp"

template <typename T>
class AVLTree {
  Node<T>* root = nullptr;
  int numNodes  = 0;
  void withPostOrder(std::function<T&(void)>& f, Node<T>* node) {
    if(!node) {
      return;
    }
    withPostOrder(f, node->l);
    withPostOrder(f, node->r);
    f(node);
  }
  void withPostOrder(std::function<T(void)>& f) {
    return withPostOrder(f, root);
  }
  void deleteNode(Node<T>* node) {
    delete node;
  }

  ~AVLTree() {
    withPostOrder(this->deleteNode);
  }
  AVLTree() = default;
  AVLTree(std::initializer_list<T> const& lst) {
    for(const auto& elem : lst) {
      insert(elem);
    }
  }
  bool isBalanced() const {}
  void slr(const Node<T>* temp) {}
  void srr(Node<T>* temp);
  void dlr(Node<T>* temp);
  void drr(Node<T>* temp);

 public:
  void build(std::fstream& fin);
  void insert(T val);
  void printTree();  // preorder, inorder, postorder, level order
  bool deleteNode(int searchterm);
};
