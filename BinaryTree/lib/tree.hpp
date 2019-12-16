#pragma once

#include <algorithm>

template <typename T>
struct Node {
  T elem;
  Node* left  = nullptr;
  Node* right = nullptr;
  explicit Node(T elem) : elem{ std::move(elem) } {}
};

template <typename T>
Node<T> invert(Node<T>& node) {
  Node<T>* temp   = node.left;
  node.left  = node.right;
  node.right = temp;
  if(node.left) {
    invert(*node.left);
  }
  if(node.right) {
    invert(*node.right);
  }
}