//Beau Hodes
//EECS 268 Lab 9
//Node.h

#include <iostream>
#include <string>

#ifndef NODE_H
#define NODE_H

template <typename ItemType>
class Node
{
  private:
  ItemType item;
  Node<ItemType>* next;

  public:

  /**
  * @pre None
  * @post Constructor for a node with anItem value
  * @return A node with anItem as its item
  **/
  Node(ItemType anItem);

  /**
  * @pre None
  * @post Constructor for a node with anItem value and given nextNode
  * @return A node with anItem as its item and nextNode as its pointer
  **/
  Node(ItemType anItem, Node* nextNode);

  /**
  * @pre None
  * @post None
  * @return The value of the entry
  **/
  ItemType getItem() const;

  /**
  * @pre None
  * @post None
  * @return The value of next
  **/
  Node<ItemType>* getNext() const;

  /**
  * @pre None
  * @post Sets the entry of the node
  * @return None
  **/
  void setItem(ItemType newItem);

  /**
  * @pre headptr does not equal nullptr
  * @post Sets the "next" pointer
  * @return None
  **/
  void setNext(Node* nextNode);
};

#include "Node.cpp"
#endif
