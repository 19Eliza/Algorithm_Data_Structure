#pragma once

#include <iostream>
#include <map>
#include <vector>

struct Node {
  double key;
  double el;
};

class Heap {
private:
  std::vector<Node> heap; //вектор элементов
  std::map<double, size_t> position; //ключ элемента-позиция элемента в куче
public:
  Heap(){};
  Heap(const Heap &h);

  //позиция i счиатется с 0

  std::size_t LeftChild(std::size_t i) const;
  std::size_t RightChild(std::size_t i) const;
  std::size_t Parent(std::size_t i) const;

  std::size_t Length() const;

  double GetKey(Node nd) const;

  bool HeapifyUp(std::size_t i);
  bool HeapifyDown(std::size_t i);

  void Position();

  bool Insert(const Node &elem);
  bool Delete(const std::size_t &i);
  Node FindMin() const;
  void ExtractMin();

  virtual void ChangeKey(Node w, double new_key);

  void ShowHeap() const;
  void ShowPosition();
  void ShowPosition(Node elem);

  virtual ~Heap(){};
};