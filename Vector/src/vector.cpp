#include <cstddef>
#include <sstream>
#include <stdexcept>

using std::size_t;

template <class T>
class Vector {
  static constexpr size_t DEFAULT_CAPACITY = 1;
  static constexpr size_t DEFAULT_SIZE     = 0;
  T* array;

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
  void move_vector(Vector& vector) {
    array        = vector.array;
    size         = vector.size;
    capacity     = vector.capacity;
    vector.array = nullptr;
  }
  void move_vector(Vector&& vector) {
    array        = vector.array;
    size         = vector.size;
    capacity     = vector.capacity;
    vector.array = nullptr;
  }

 public:
  size_t capacity = DEFAULT_CAPACITY;
  size_t size     = DEFAULT_SIZE;
  Vector() {
    array = new T[capacity];
  }
  Vector(const Vector& vector) {
    array = new T[vector.capacity];
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
          "attempted to reserve array to less than its current size");
    }
    T* temp = new T[target];
    copy(array, temp);
    delete[] array;
    array    = temp;
    capacity = target;
  }
  T& at(size_t pos) const {
    const auto isOutOfBounds = pos >= size;
    if(isOutOfBounds) {
      const auto errMessage =
          "index: " + std::to_string(pos) +
          " is out of range (size: " + std::to_string(size) + ")";
      throw std::out_of_range(errMessage);
    }
    return array[pos];
  }
  T* data() {
    return array;
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
    return *this;
  }
  Vector& operator=(Vector&& other) noexcept {
    move_vector(other);
    return *this;
  }
};

