//Beau Hodes
//EECS 268 Lab 9
//BinaryNodeTree.cpp

#include <iostream>
#include <string>

template <typename ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem)
{
  item = anItem;
  leftChildPtr = nullptr;
  rightChildPtr = nullptr;
}

template <typename ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem, BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr)
{
  item = anItem;
  leftChildPtr = leftPtr;
  rightChildPtr = rightPtr;
}

template <typename ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
  item = anItem;
}

template <typename ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
  return item;
}

template <typename ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
  if (leftChildPtr == nullptr && rightChildPtr == nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const
{
  return leftChildPtr;
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const
{
  return rightChildPtr;
}

template <typename ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* leftPtr)
{
  leftChildPtr = leftPtr;
}

template <typename ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType>* rightPtr)
{
  rightChildPtr = rightPtr;
}
