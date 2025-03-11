#include <iostream>

using Item = double;

class Queue {
private:
  struct Node {
    Item item;
    Node *next;
  };
  enum { Q_size = 10 };
  Node *front;
  Node *rear;
  int items; //текущее количество элементов в Queue
  const int qsize; //максимальное количество элементов в Queue
public:
  Queue(int qs = Q_size);
  bool isempty() const;
  bool isfull() const;
  int queuecount() const;
  bool enqueue(const Item &item);
  bool dequeue();
  ~Queue();
};