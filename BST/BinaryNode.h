//Beau Hodes
//EECS 268 Lab 9
//BinaryNode.h

#include "Node.h"
#include <stdexcept>
#include <iostream>

#ifndef _BINARY_NODE
#define _BINARY_NODE

template<class ItemType>
class BinaryNode
{
private:
   ItemType              item;           // Data portion
   BinaryNode<ItemType>* leftChildPtr;   // Pointer to left child
   BinaryNode<ItemType>* rightChildPtr;  // Pointer to right child

public:
   BinaryNode(const ItemType& anItem);
   BinaryNode(const ItemType& anItem,
              BinaryNode<ItemType>* leftPtr,
              BinaryNode<ItemType>* rightPtr);

   void setItem(const ItemType& anItem);
   ItemType getItem() const;

   bool isLeaf() const;

   BinaryNode<ItemType>* getLeftChildPtr() const;
   BinaryNode<ItemType>* getRightChildPtr() const;

   void setLeftChildPtr(BinaryNode<ItemType>* leftPtr);
   void setRightChildPtr(BinaryNode<ItemType>* rightPtr);
}; // end BinaryNode

#include "BinaryNode.cpp"

#endif
