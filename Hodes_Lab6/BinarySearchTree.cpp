//Beau Hodes
//EECS 268 Lab 9
//BinarySearchTree.cpp

#include <iostream>
#include <string>
#include <stack>
//#include "BinarySearchTree.h"

//______________________________________________________________________________
//PROTECTED
//______________________________________________________________________________

template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNode)
{
  if (subTreePtr == nullptr)
  {
    return newNode;
  }
  else if (newNode->getItem() >= subTreePtr->getItem())
  {
    BinaryNode<ItemType>* tempPtr = insertInorder(subTreePtr->getRightChildPtr(), newNode);
    subTreePtr->setRightChildPtr(tempPtr);
  }
  else
  {
    BinaryNode<ItemType>* tempPtr = insertInorder(subTreePtr->getLeftChildPtr(), newNode);
    subTreePtr->setLeftChildPtr(tempPtr);
  }
  return subTreePtr;
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::heightHelper(BinaryNode<ItemType>* treePtr) const
{
  if (treePtr == nullptr)
  {
    return 0;
  }
  else
  {
    return 1 + std::max(heightHelper(treePtr->getLeftChildPtr()), heightHelper(treePtr->getRightChildPtr()));
  }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroyTree(BinaryNode<ItemType>* treePtr)
{
  if (treePtr != nullptr)
  {
    destroyTree(treePtr->getLeftChildPtr());
    destroyTree(treePtr->getRightChildPtr());
    delete treePtr;
  }
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::numberOfNodesHelper(BinaryNode<ItemType>* treePtr) const
{
  if (treePtr == nullptr)
  {
    return 0;
  }
  else
  {
    return 1 + numberOfNodesHelper(treePtr -> getLeftChildPtr()) + numberOfNodesHelper(treePtr -> getRightChildPtr());
  }
}

template <typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const
{
  BinaryNode<ItemType>* newTree = nullptr;
  if (treePtr != nullptr)
  {
    newTree = new BinaryNode<ItemType>(treePtr->getItem(), nullptr, nullptr);
    newTree->setLeftChildPtr(treePtr->getLeftChildPtr());
    newTree->setRightChildPtr(treePtr->getRightChildPtr());
  }
  return newTree;
}



template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr, KeyType aKey, bool& success)
{
  if (subTreePtr == nullptr)
  {
    success = false;
    return nullptr;
  }
  else if (subTreePtr->getItem() == aKey)
  {
    subTreePtr = removeNode(subTreePtr);
    success = true;
    return subTreePtr;
  }
  else if (subTreePtr->getItem() >= aKey)
  {
    BinaryNode<ItemType>* tempPtr = removeValue(subTreePtr->getLeftChildPtr(), aKey, success);
    subTreePtr->setLeftChildPtr(tempPtr);
    return subTreePtr;
  }
  else
  {
    BinaryNode<ItemType>* tempPtr = removeValue(subTreePtr->getRightChildPtr(), aKey, success);
    subTreePtr->setRightChildPtr(tempPtr);
    return subTreePtr;
  }
}

template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeNode(BinaryNode<ItemType>* nodePtr)
{
  if (nodePtr->isLeaf() == true)
  {
    delete nodePtr;
    nodePtr = nullptr;
    return nodePtr;
   }
   else if ((nodePtr->getLeftChildPtr() == nullptr && nodePtr->getRightChildPtr() != nullptr) || (nodePtr->getRightChildPtr() == nullptr && nodePtr->getLeftChildPtr() != nullptr))
   {
     BinaryNode<ItemType>* tempNodePtr;
     if (nodePtr->getLeftChildPtr() != nullptr)
     {
       tempNodePtr = nodePtr->getLeftChildPtr();
     }
     else
     {
       tempNodePtr = nodePtr->getRightChildPtr();
     }
     delete nodePtr;
     nodePtr = nullptr;
     return tempNodePtr;
   }
   else
   {
     ItemType nextInOrder;
     BinaryNode<ItemType>* tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), nextInOrder);
     nodePtr->setRightChildPtr(tempPtr);
     nodePtr->setItem(nextInOrder);
     return nodePtr;
   }
}

template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeLeftmostNode(BinaryNode<ItemType>* subTreePtr, ItemType& inorderSuccessor)
{
  if (subTreePtr->getLeftChildPtr() == nullptr)
  {
    inorderSuccessor = subTreePtr->getItem();
    return removeNode(subTreePtr);
  }
  else
  {
    subTreePtr->setLeftChildPtr(removeLeftmostNode(subTreePtr->getLeftChildPtr(), inorderSuccessor));
    return subTreePtr;
  }
}

template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::findNode(BinaryNode<ItemType>* treePtr, KeyType aKey) const
{
  if (treePtr == nullptr)
  {
        return nullptr;
  }
  else if (treePtr->getItem() == aKey)
  {
    return treePtr;
  }
  else if (treePtr->getItem() >= aKey)
  {
    return findNode(treePtr->getLeftChildPtr(), aKey);
  }
  else
  {
    return findNode(treePtr->getRightChildPtr(), aKey);
  }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::levelOrderHelper(BinaryNode<ItemType>* root)
{
  int h = heightHelper(root);
  for (int i = 1; i <= h; i++)
  {
    traverseLevel(root, i);
  }
}
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::traverseLevel(BinaryNode<ItemType>* root, int level)
{
    if (root == nullptr)
    {
      return;
    }
    if (level == 1)
    {
      std::cout << root->getItem() << ", ";
    }
    else if (level > 1)
    {
      traverseLevel(root->getLeftChildPtr(), level-1);
      traverseLevel(root->getRightChildPtr(), level-1);
    }
    else
    {
      return;
    }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::spiralOrderHelper(BinaryNode<ItemType>* root)
{
  bool leftRight = true;
  int h = heightHelper(root);
  for (int i = 1; i <= h; i++)
  {
    spiralLevel(root, i, leftRight);
    leftRight = !leftRight;
  }
}
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::spiralLevel(BinaryNode<ItemType>* root, int level, bool leftRight)
{
    if (root == nullptr)
    {
      return;
    }
    if (level == 1)
    {
      std::cout << root->getItem() << ", ";
    }
    else if (level > 1)
    {
      if(leftRight)
      {
        spiralLevel(root->getLeftChildPtr(), level - 1, leftRight);
        spiralLevel(root->getRightChildPtr(), level - 1, leftRight);
      }
      else
      {
        spiralLevel(root->getRightChildPtr(), level - 1, leftRight);
        spiralLevel(root->getLeftChildPtr(), level - 1, leftRight);
      }
    }
    else
    {
      return;
    }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::leftRightViewHelper(BinaryNode<ItemType>* root, bool isLeft)
{
  int deepestLevel = 0;
  if(isLeft) {
    leftViewPrinter(root, 1, &deepestLevel);
  }
  else {
    rightViewPrinter(root, 1, &deepestLevel);
  }
}
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::leftViewPrinter(BinaryNode<ItemType>* root, int curLevel, int* deepLevel)
{
  if(root == nullptr)
  {
    return;
  }
  if(*deepLevel < curLevel)
  {
    std::cout << root->getItem() << ", ";
    *deepLevel = curLevel;
  }
  leftViewPrinter(root->getLeftChildPtr(), curLevel + 1, deepLevel);
  leftViewPrinter(root->getRightChildPtr(), curLevel+1, deepLevel);
}
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::rightViewPrinter(BinaryNode<ItemType>* root, int curLevel, int* deepLevel)
{
  if(root == nullptr)
  {
    return;
  }
  if(*deepLevel < curLevel)
  {
    std::cout << root->getItem() << ", ";
    *deepLevel = curLevel;
  }
  rightViewPrinter(root->getRightChildPtr(), curLevel + 1, deepLevel);
  rightViewPrinter(root->getLeftChildPtr(), curLevel+1, deepLevel);
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::kthSmallestHelper(BinaryNode<ItemType>* root, int k)
{
  std::stack<BinaryNode<ItemType>*> theStack;
  while(k >= 0)
  {
    while(root != nullptr)
    {
      theStack.push(root);
      root = root->getLeftChildPtr();
    }
    if(theStack.empty() == true)
    {
      std::cout << "Invalid k.\n";
      return;
    }
    root = theStack.top();
    theStack.pop();
    k--;
    if(k == 0)
    {
      std::cout << root->getItem() << '\n';
      std::cout << std::flush;
      return;
    }
    root = root->getRightChildPtr();
  }
}

//______________________________________________________________________________
//PUBLIC
//______________________________________________________________________________

template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree()
{
  rootPtr = nullptr;
}

template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(const ItemType& rootItem)
{
  rootPtr = rootItem;
}
template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(const BinarySearchTree<KeyType, ItemType>& tree)
{
  rootPtr = copyTree(tree.rootPtr);
}

template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
  destroyTree(rootPtr);
}

template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty() const
{
  if (rootPtr == nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getHeight() const
{
  return heightHelper(rootPtr);
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getNumberOfNodes() const
{
  return numberOfNodesHelper(rootPtr);
}

template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::add(const ItemType& newEntry)
{
  BinaryNode<ItemType>* newNode = new BinaryNode<ItemType>(newEntry);
  rootPtr = insertInorder(rootPtr, newNode);
  return true;
}

template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(const KeyType& aKey)
{
  bool success = true;
  rootPtr = removeValue(rootPtr, aKey, success);
  if (success == false)
  {
    throw std::runtime_error("Error, key requested to delete not found");
  }
  else
  {
    return true;
  }
}

template<typename KeyType, typename ItemType>
ItemType BinarySearchTree<KeyType, ItemType>::getEntry(const KeyType& aKey)
{
  BinaryNode<ItemType>* findPtr = findNode(rootPtr, aKey);
  if (findPtr == nullptr)
  {
    std::cout << "Key not found!";
  }
  else
  {
    return findPtr->getItem();
  }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::setEntry(const KeyType& aKey, const ItemType& item)
{
  BinaryNode<ItemType>* findPtr = findNode(rootPtr, aKey);
  if (findPtr == nullptr)
  {
    std::cout << "Key not found!";
  }
  else
  {
    findPtr->setItem(item);
  }
}

template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::contains(const KeyType& aKey) const
{
  if (findNode(rootPtr, aKey) != nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::clear()
{
  destroyTree(rootPtr);
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inOrderSuccessor(int val)
{
  std::cout << "The in order successor of " << val << " is ";
  BinaryNode<ItemType>* root = rootPtr;
  BinaryNode<ItemType>* tracker = findNode(rootPtr, val);
  if(tracker == nullptr)
  {
    std::cout << "not found.\n";
    return;
  }
  BinaryNode<ItemType>* next = nullptr;
  if(tracker->getRightChildPtr() != nullptr)
  {
    next = findMin(tracker->getRightChildPtr());
  }
  else
  {
    while(root != nullptr)
    {
      if(tracker->getItem() < root->getItem())
      {
        next = root;
        root = root->getLeftChildPtr();
      }
      else if (tracker->getItem() >= root->getItem())
      {
        root = root->getRightChildPtr();
      }
      else
      {
        break;
      }
    }
  }
  if(next == nullptr)
  {
    std::cout << "not found.\n";
  }
  else
  {
    std::cout << next->getItem() << '\n';
  }
}
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::findMin(BinaryNode<ItemType>* tracker)
{
  BinaryNode<ItemType>* cur = tracker;
  while(cur->getLeftChildPtr() != nullptr)
  {
    cur = cur->getLeftChildPtr();
  }
  return cur;
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::kthSmallest(int k)
{
  kthSmallestHelper(rootPtr, k);
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::levelOrderPrint()
{
  std::cout << "Printing in Level-Order - ";
  levelOrderHelper(rootPtr);
  std::cout << '\n';
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::spiralOrderPrint()
{
  std::cout << "Printing in Spiral-Level-Order - ";
  spiralOrderHelper(rootPtr);
  std::cout << '\n';
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::leftView()
{
  std::cout << "Printing left view - ";
  leftRightViewHelper(rootPtr, true);
  std::cout << '\n';
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::rightView()
{
  std::cout << "Printing right view - ";
  leftRightViewHelper(rootPtr, false);
  std::cout << '\n';
}

template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>& BinarySearchTree<KeyType, ItemType>::operator=(const BinarySearchTree<KeyType, ItemType>& rightHandSide)
{
  rootPtr = copyTree(rightHandSide);
}
