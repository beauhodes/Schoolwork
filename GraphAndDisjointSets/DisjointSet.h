//Beau Hodes
//EECS 560 Lab 10

#include <stdexcept>
#include <iostream>
#include "Node.h"

#ifndef DISJOINT_SET
#define DISJOINT_SET

class DisjointSet
{
private:
  Node<int>** nodePtrs;
  int size;

public:
  DisjointSet();
  DisjointSet(int newSize);
  ~DisjointSet();
  void makeSet(int arr[], int size);
  void doUnion(int x, int y);
  int find(int k);
  int pathCompression(int k);
  void printPath(int k);
  void printAllIndexesAndVals();
};
#endif
