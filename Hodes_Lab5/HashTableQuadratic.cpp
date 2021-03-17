//Beau Hodes
//EECS 560 Lab 5

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "HashTableQuadratic.h"

HashTableQuadratic::HashTableQuadratic(int size, int k)
{
  table = new int[size];
  for(int i = 0; i < size; i++)
  {
    table[i] = -1; //using as unitialized value
  }
  numBuckets = size;
  maxK = k;
}

HashTableQuadratic::~HashTableQuadratic()
{
  delete table;
}

bool HashTableQuadratic::insert(int elem)
{
  int targetBucket = elem % numBuckets;
  int quadraticIterator = 1;
  int k = 0;
  while(table[targetBucket] != -1 && k != maxK)
  {
    targetBucket = (targetBucket+(quadraticIterator*quadraticIterator)) % numBuckets;
    quadraticIterator++;
    k++;
  }
  if(k == maxK)
  {
    return false;
  }
  //open space to insert has been found at this point
  table[targetBucket] = elem;
  return true;
}

bool HashTableQuadratic::find(int testElem)
{
  int targetBucket = testElem % numBuckets;
  int quadraticIterator = 1;
  for(int k = 0; k < maxK; k++)
  {
    if(table[targetBucket] == testElem)
    {
      return true;
    }
    else
    {
      targetBucket = (targetBucket+(quadraticIterator*quadraticIterator)) % numBuckets;
      quadraticIterator++;
      k++;
    }
  }
  return false;
}
