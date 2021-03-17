//Beau Hodes
//EECS 560 Lab 4

#include <iostream>
#include <string>

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
  private:
  T item;
  int rank;
  Node<T>* parent;

  public:

  /**
  * @pre None
  * @post Constructor for a node with anItem value
  * @return A node with anItem as its item
  **/
  Node(T anItem);

  /**
  * @pre None
  * @post Constructor for a node with anItem value and given nextNode
  * @return A node with anItem as its item and nextNode as its pointer
  **/
  Node(T anItem, Node* parentNode);

  /**
  * @pre None
  * @post None
  * @return The value of the entry
  **/
  T getItem() const;

  /**
  * @pre None
  * @post None
  * @return The value of next
  **/
  Node<T>* getParent() const;

  /**
  * @pre None
  * @post Sets the entry of the node
  * @param The value to insert into the node
  * @return None
  **/
  void setItem(T newItem);

  /**
  * @pre headptr does not equal nullptr
  * @post Sets the "next" pointer
  * @param The node to set the next pointer to
  * @return None
  **/
  void setParent(Node* nextNode);

  int getRank() const;

  void incRank();
};
#include "Node.cpp"
#endif
