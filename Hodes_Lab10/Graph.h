//Beau Hodes
//EECS 560 Lab 9

#include <stdexcept>
#include <iostream>
#include "DisjointSet.h"
#include "MinHeap.h"

#ifndef GRAPH
#define GRAPH

class Graph
{
private:
  int** matrix;
  int size;
  std::string* islandNames;

public:
  Graph();
  ~Graph();
  void buildGraph(int** costs, int newSize, std::string* newIslands);
  void printMatrix();
  void dfs();
  void bfs();
  void kruskal();
  void prim();
};
#endif
