//Beau Hodes
//EECS 560 Lab 9

#include <iostream>
#include <string>
#include <fstream>
#include "DisjointSet.h"

DisjointSet::DisjointSet()
{
  nodePtrs = new Node<int>*[100];
  for(int i = 0; i < 100; i++)
  {
    nodePtrs[i] = nullptr;
  }
  size = 100;
}

DisjointSet::DisjointSet(int newSize)
{
  nodePtrs = new Node<int>*[newSize + 1];
  for(int i = 0; i <= newSize; i++)
  {
    nodePtrs[i] = nullptr;
  }
  size = newSize + 1; //highest array index should match highest value
}

DisjointSet::~DisjointSet()
{
  std::cout << "STARTINGDESDJS\n";
  for(int i = 0; i < size; i++)
  {
    if(nodePtrs[i] != nullptr)
    {
      delete [] nodePtrs[i];
    }
  }
  if(nodePtrs != nullptr)
  {
    delete [] nodePtrs;
  }
  std::cout << "ENDDESDJS\n";
}

void DisjointSet::makeSet(int arr[], int size)
{
  int temp;
  for(int i = 1; i <= size; i++)
  {
    temp = arr[i];
    Node<int>* newNode = new Node<int>(temp);
    newNode->setParent(newNode);
    nodePtrs[temp] = newNode;
  }
}

void DisjointSet::doUnion(int x, int y)
{
  //check to make sure x and y exist
  if(x < 0 || y < 0 || x >= size || y >= size)
  {
    std::cout << "Invalid element.\n";
    return;
  }
  if(nodePtrs[x] == nullptr || nodePtrs[y] == nullptr)
  {
    std::cout << "One or both of the requested elements do not exist.\n";
    return;
  }

  //get parent pointers of x and y if either is not already the parent pointer
  int parentXIndex = x;
  int parentYIndex = y;
  while(nodePtrs[parentXIndex]->getParent()->getItem() != nodePtrs[parentXIndex]->getItem())
  {
    parentXIndex = nodePtrs[parentXIndex]->getParent()->getItem();
  }
  while(nodePtrs[parentYIndex]->getParent()->getItem() != nodePtrs[parentYIndex]->getItem())
  {
    parentYIndex = nodePtrs[parentYIndex]->getParent()->getItem();
  }

  //do union by rank
  if(nodePtrs[parentXIndex]->getRank() <= nodePtrs[parentYIndex]->getRank())
  {
    nodePtrs[parentXIndex]->setParent(nodePtrs[parentYIndex]);
    if(nodePtrs[parentXIndex]->getRank() == nodePtrs[parentYIndex]->getRank())
    {
      nodePtrs[parentYIndex]->incRank();
    }
  }
  else
  {
    nodePtrs[parentYIndex]->setParent(nodePtrs[parentXIndex]);
  }
}

int DisjointSet::find(int k)
{
  if(k >= 0 && k < size)
  {
    if(nodePtrs[k] == nullptr)
    {
      return -1;
    }
    if(nodePtrs[k]->getParent()->getItem() == nodePtrs[k]->getItem()) //representative found
    {
      return nodePtrs[k]->getItem();
    }
    else
    {
      return find(nodePtrs[k]->getParent()->getItem()); //no compression
    }
  }
  else
  {
    return -1;
  }
}

int DisjointSet::pathCompression(int k)
{
  if(k >= 0 && k < size)
  {
    if(nodePtrs[k] == nullptr)
    {
      return -1;
    }
    if(nodePtrs[k]->getParent()->getItem() == nodePtrs[k]->getItem()) //representative found
    {
      return nodePtrs[k]->getItem();
    }
    else
    {
      int par;
      par = find(nodePtrs[k]->getParent()->getItem());
      nodePtrs[k]->setParent(nodePtrs[par]); //do compression
      return par;
    }
  }
  else
  {
    return -1;
  }
}

void DisjointSet::printPath(int k)
{
  if(k < 0 || k >= size)
  {
    std::cout << "No path because this element does not exist.\n";
    return;
  }
  if(nodePtrs[k] == nullptr)
  {
    std::cout << "No path because this element does not exist.\n";
    return;
  }
  else
  {
    Node<int>* tempNode = nodePtrs[k];
    while(tempNode->getItem() != tempNode->getParent()->getItem())
    {
      std::cout << tempNode->getItem() << " -> ";
      tempNode = tempNode->getParent();
    }
    std::cout << tempNode->getItem() << '\n';
  }
}

void DisjointSet::printAllIndexesAndVals()
{
  for(int i = 0; i < size; i++)
  {
    if(nodePtrs[i] != nullptr)
    {
      std::cout << "Index " << i << ": " << nodePtrs[i]->getItem() << ", has parent " << nodePtrs[i]->getParent()->getItem() << '\n' << std::flush;
    }
  }
}
