#include "HeapClass.h"

Heap::Heap(const Heap &h) { heap = h.heap; };

std::size_t Heap::LeftChild(std::size_t i) const { return 2 * i + 1; }

std::size_t Heap::RightChild(std::size_t i) const { return 2 * i + 2; }

std::size_t Heap::Parent(std::size_t i) const { return (i - 1) / 2; }

std::size_t Heap::Length() const { return heap.size(); }

double Heap::GetKey(Node nd) const { return nd.key; }

bool Heap::HeapifyUp(std::size_t i) {
  if (i >= Length())
    return false;
  if (i > 0) {
    auto j = Parent(i);
    if (heap[i].key < heap[j].key) {
      std::swap(heap[i], heap[j]);
      HeapifyUp(j);
    }
  }
  return true;
}

bool Heap::HeapifyDown(std::size_t i) {
  std::size_t n = Length();
  if (n == 0)
    return false;
  --n;
  std::size_t j;
  if (i > n)
    return false;
  if ((2 * i + 1) > n)
    return true;
  else {
    if ((2 * i + 1) < n) {
      auto left = 2 * i + 1;
      auto right = 2 * i + 2;
      heap[left].key > heap[right].key ? j = right : j = left;
    } else
      j = 2 * i + 1;
  }
  if (heap[i].key > heap[j].key) {
    std::swap(heap[i], heap[j]);
    HeapifyDown(j);
  }
  return true;
}


void Heap::BuildMaxHeap(std::vector<double>& A){
  std::size_t heapSize=A.size();
  
  for(std::size_t i=heapSize/2+1;i>0;--i) 
}

void Heap::Position() {
  auto n = Length();
  for (std::size_t i = 0; i < n; i++) {
    auto nd = heap[i];
    auto iter = position.find(nd.key);
    if (iter == position.end()) {
      position.insert({nd.key, i});
    } else {
      if (iter->second == i)
        continue;
      else
        iter->second = i;
    }
  }
}

bool Heap::Insert(const Node &elem) {
  heap.push_back(elem);
  auto i = Length();
  --i;
  HeapifyUp(i);
  Position();
  return true;
}

bool Heap::Delete(const std::size_t &i) {
  auto n = Length();
  if (n == 0)
    return false;
  if (i >= n)
    return false;
  std::swap(heap[n - 1], heap[i]);
  heap.pop_back();
  HeapifyDown(i);
  Position();
  return true;
}

Node Heap::FindMin() const { return heap[0]; }

void Heap::ExtractMin() {
  Delete(0);
  Position();
}

void Heap::ChangeKey(Node w, double new_key) {
  auto i = position[w.key];
  w.key = new_key;
  HeapifyUp(i);
  HeapifyDown(i);
}

void Heap::ShowHeap() const {
  for (auto nd : heap)
    std::cout << nd.key << " ";
  std::cout << std::endl;
}

void Heap::ShowPosition() {
  for (auto nd : heap) {
    auto i = position[nd.key];
    std::cout << "Position of " << nd.key << " element in heap:" << i
              << std::endl;
  }
}

void Heap::ShowPosition(Node elem) {
  auto i = position[elem.key];
  std::cout << "Position in heap: " << i << std::endl;
}