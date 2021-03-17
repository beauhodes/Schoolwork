//Beau Hodes
//EECS 560 Lab 5

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "HashTableDouble.h"

HashTableDouble::HashTableDouble(int size, int k, int r)
{
  table = new int[size];
  for(int i = 0; i < size; i++)
  {
    table[i] = -1; //using as unitialized value
  }
  numBuckets = size;
  maxK = k;
  rVal = r;
}

HashTableDouble::~HashTableDouble()
{
  delete table;
}

bool HashTableDouble::insert(int elem)
{
  int targetBucket = elem % numBuckets;
  int k = 0;
  if(table[targetBucket] != -1)
  {
    int targetBucket2 = rVal - (elem % rVal);
    int hIterator = 1;
    while(k != maxK)
    {
      int doubleHashed = (targetBucket + hIterator * targetBucket2) % numBuckets;
      if(table[doubleHashed] == -1)
      {
        targetBucket = doubleHashed;
        break;
      }
      hIterator++;
      k++;
    }
  }
  if(k == maxK)
  {
    return false;
  }
  //open space to insert has been found at this point
  table[targetBucket] = elem;
  return true;
}

bool HashTableDouble::find(int testElem)
{
  int targetBucket = testElem % numBuckets;
  if(table[targetBucket] == testElem) //found, return true
  {
    return true;
  }
  else if(table[targetBucket] == -1) //empty spot, know false
  {
    return false;
  }
  else if(table[targetBucket] != -1) //different value, double hash
  {
    int targetBucket2 = rVal - (testElem % rVal);
    int hIterator = 1;
    for(int k = 0; k < maxK; k++)
    {
      int doubleHashed = (targetBucket + hIterator * targetBucket2) % numBuckets;
      if(table[doubleHashed] == testElem)
      {
        return true;
      }
      else
      {
        hIterator++;
        k++;
      }
    }
  }
  return false;
}
