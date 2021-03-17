//Beau Hodes
//EECS 560 Lab 7

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include "MinHeap.h"

MinHeap::MinHeap()
{
  heapArr = nullptr;
  numNums = 0;
}

MinHeap::~MinHeap()
{
  std::cout << "STARTINGDES HEAP\n";
  delete [] heapArr;
  std::cout << "END DEst HEAP\n";
}

void MinHeap::buildHeap(edge* arrVals, int arrSize)
{
  numNums = arrSize;
  heapArr = new edge[numNums];
  for(int i = 0; i < numNums; i++)
  {
    heapArr[i] = arrVals[i];
  }
  heapify();
}

void MinHeap::heapify()
{
  int lastParent = floor((numNums - 1) / 3);
  while(lastParent >= 0)
  {
    compareToChildren(lastParent);
    lastParent--;
  }
}

void MinHeap::compareToChildren(int parent)
{
  int minChild = 3 * parent + 1;
  if(minChild < numNums)
  {
    for(int j=1; j<=3; j++)
    {
      if(heapArr[3 * parent + j].cost < heapArr[minChild].cost && (3*parent+j < numNums))
      {
        minChild = 3 * parent + j;
      }
    }
    if(heapArr[parent].cost > heapArr[minChild].cost)
    {
      edge tempEdge = heapArr[parent];
      heapArr[parent] = heapArr[minChild];
      heapArr[minChild] = tempEdge;
      compareToChildren(minChild);
    }
  }
}

void MinHeap::printHeap()
{
  for(int i = 0; i < numNums; i++)
  {
    std::cout << heapArr[i].cost << " ";
  }
  std::cout << '\n';
}

int MinHeap::getParentIndex(int childIndex)
{
  return floor((childIndex - 1) / 3);
}

void MinHeap::swap(int first, int second){
  edge tempEdge = heapArr[first];
  heapArr[first] = heapArr[second];
  heapArr[second] = tempEdge;
}

edge MinHeap::removeEdge()
{
  if(numNums == 0)
  {
    return edge{-1, -1, -1};
  }
  edge lowestCost = heapArr[0];
  swap(0, numNums - 1);
  numNums--;
  heapify();
  return lowestCost;
}

void MinHeap::removeEdgesWithEndPoint(int endPoint)
{
  for(int i = 0; i < numNums; i++)
  {
    if (heapArr[i].endIndex == endPoint)
    {
      swap(i, numNums - 1);
      numNums--;
    }
  }
  heapify();
}

void MinHeap::addEdge(edge newEdge)
{
  heapArr[numNums] = newEdge;
  numNums++;
  heapify();
}

int MinHeap::getSize()
{
  return numNums;
}
