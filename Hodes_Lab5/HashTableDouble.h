//Beau Hodes
//EECS 560 Lab 5

#include <string>

#ifndef HASHTABLEDOUBLE_H
#define HASHTABLEDOUBLE_H

class HashTableDouble
{
private:
  int* table;
  int numBuckets;
  int maxK;
  int rVal;

public:
  /**
  *  @pre None
  *  @post Creates and initializes a HashTable
  *  @param size The number of buckets in the hash table
  *  @return None
  */
  HashTableDouble(int size, int k, int r);

  /**
  *  @pre None
  *  @post Destructor for hash table
  *  @return None
  */
  ~HashTableDouble();

  /**
  * @pre None
  * @post Inserts element into hash table using double hashing
  * @param elem The number to insert
  * @return None
  **/
  bool insert(int elem);

  /**
  * @pre None
  * @post None
  * @param testName The name to check whether or not it is in the hash table
  **/
  bool find(int testElem);

};

#endif
