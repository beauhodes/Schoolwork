//Beau Hodes
//EECS 560 Lab 7

#include <stdexcept>
#include <iostream>

struct edge
{
  int cost;
  int startIndex;
  int endIndex;

  bool operator<(const edge& rhs) const
  {
    return this->cost < rhs.cost;
  }
  bool operator>(const edge& rhs) const
  {
    return this->cost > rhs.cost;
  }
  edge& operator=(const edge& rhs)
  {
    this->cost = rhs.cost;
    this->startIndex = rhs.startIndex;
    this->endIndex = rhs.endIndex;
    return *this;
  }
};

#ifndef MIN_HEAP
#define MIN_HEAP

class MinHeap
{
private:
  edge* heapArr;
  int numNums;

public:
  MinHeap();
  ~MinHeap();

  void buildHeap(edge* arrVals, int arrSize);
  void heapify();
  void compareToChildren(int parent);
  void printHeap();
  int getParentIndex(int childIndex);
  void swap(int first, int second);
  edge removeEdge();
  void removeEdgesWithEndPoint(int endPoint);
  void addEdge(edge newEdge);
  int getSize();
};
#endif
