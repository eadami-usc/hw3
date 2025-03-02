#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T>>
class Heap {
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m = 2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const& top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

  /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  // Add whatever helper functions and data members you need below
  std::vector<T> heap_;
  int m_;
  PComparator comp_;
  void swap(int index1, int index2);
};

// Add implementation of member functions here
template <typename T, typename PComparator>
void Heap<T, PComparator>::swap(int index1, int index2) {
  T temp = heap_[index1];
  heap_[index1] = heap_[index2];
  heap_[index2] = temp;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_(m), comp_(c) {}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  heap_.push_back(item);
  int currIndex = heap_.size() - 1;
  while (currIndex > 0 && comp_(heap_[currIndex], heap_[(currIndex - 1) / m_])) {
    swap(currIndex, (currIndex - 1) / m_);
    currIndex = (currIndex - 1) / m_;
  }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const& Heap<T, PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap_.front();
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap");
  }
  swap(0, heap_.size() - 1);
  heap_.pop_back();
  int currIndex = 0;
  while (currIndex < heap_.size()) {
    int leftIndex = (currIndex * m_) + 1;
    int rightIndex = (currIndex * m_) + 2;
    int bestIndex = currIndex;
    if (leftIndex < heap_.size() && comp_(heap_[leftIndex], heap_[bestIndex])) {
      bestIndex = leftIndex;
    }
    if (rightIndex < heap_.size() && comp_(heap_[rightIndex], heap_[bestIndex])) {
      bestIndex = rightIndex;
    }
    if (bestIndex == currIndex) {
      break;
    }
    swap(currIndex, bestIndex);
    currIndex = bestIndex;
  }
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return heap_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return heap_.size();
}

#endif