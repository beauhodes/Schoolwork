//Beau Hodes
//EECS 560 Lab 1
//Jan 28, 2020

#include <iostream>
#include <string>

template <typename T>
Node<T>::Node(T anItem)
{
  item = anItem;
  rank = 0;
  parent = nullptr;
}

template <typename T>
Node<T>::Node(T anItem, Node* parentNode)
{
  item = anItem;
  rank = 0;
  parent = parentNode;
}

template <typename T>
T Node<T>::getItem() const
{
  return (item);
}

template <typename T>
Node<T>* Node<T>::getParent() const
{
  return (parent);
}

template <typename T>
void Node<T>::setItem(T newItem)
{
  item = newItem;
}

template <typename T>
void Node<T>::setParent(Node* parentNode)
{
  parent = parentNode;
}

template <typename T>
int Node<T>::getRank() const
{
  return (rank);
}

template <typename T>
void Node<T>::incRank()
{
  rank++;
}
