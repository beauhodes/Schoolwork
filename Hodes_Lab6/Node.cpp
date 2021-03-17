//Beau Hodes
//EECS Lab 268 Lab 9
//Node.cpp

#include <iostream>
#include <string>

template <typename T>
Node<T>::Node(T anItem)
{
  item = anItem;
  next = nullptr;
}

template <typename T>
Node<T>::Node(T anItem, Node* nextNode)
{
  item = anItem;
  next = nextNode;
}

template <typename T>
T Node<T>::getItem() const
{
  return (item);
}

template <typename T>
Node<T>* Node<T>::getNext() const
{
  return (next);
}

template <typename T>
void Node<T>::setItem(T newItem)
{
  item = newItem;
}

template <typename T>
void Node<T>::setNext(Node* nextNode)
{
  next = nextNode;
}
