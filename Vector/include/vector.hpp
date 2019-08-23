#pragma once
#include <cstddef>
#include <sstream>
#include <stdexcept>

using std::size_t;

template <class T>
class Vector {
  static constexpr size_t DEFAULT_CAPACITY = 1;
  static constexpr size_t DEFAULT_SIZE     = 1;
  T* array;
  size_t capacity = DEFAULT_CAPACITY;
  size_t size     = DEFAULT_SIZE;

  void copy(const T* from, T* to) const {
    for(size_t i = 0; i < size; ++i) {
      to[i] = from[i];
    }
  }
  void copy_vector(const Vector& vector) {
    reserve(vector.capacity);
    size = vector.size;
    copy(vector.array, array);
  }
  void move_vector(const Vector& vector) {
    array    = vector.array;
    size     = vector.size;
    capacity = vector.capacity;
  }

 public:
  Vector() {
    array = new T[capacity];
  }
  Vector(const Vector& vector) {
    copy_vector(vector);
  }
  Vector(Vector&& vector) noexcept {
    move_vector(vector);
  }
  ~Vector() {
    delete[] array;
  }
  void reserve(size_t target) {
    if(target < size) {
      // should probably be throwing a more specific error here but whatever
      throw std::runtime_error(
          "Attempted to reserve array to less than its current size");
    }
    T* temp = new T[target];
    copy(array, temp);
    delete[] array;
    array    = temp;
    capacity = target;
  }
  T& at(size_t pos) {
    const auto isOutOfBounds = pos > size - 1;
    if(isOutOfBounds) {
      const auto errMessage =
          "index: " + std::to_string(pos) +
          " is out of range (capacity: " + std::to_string(capacity) + ")";
      throw std::out_of_range(errMessage);
    }
    return array[pos];
  }
  T* data() {
    return array;
  }
  void shrink_to_fit() {
    reserve(size);
  }
  T& back() {
    return array[size - 1];
  }
  bool empty() const noexcept {
    return size == 0;
  }
  Vector& push_back(T elem) {
    const auto isFull = size >= capacity;
    if(isFull) {
      const size_t nextSize = capacity * 2;
      reserve(nextSize);
    }
    array[size++] = elem;
    return *this;
  }
  void pop_back() {
    size -= 1;
  }
  Vector& operator=(const Vector& other) {
    copy_vector(other);
  }
  Vector& operator=(Vector&& other) noexcept {
    move_vector(other);
  }
};
