//Beau Hodes
//EECS 560 Lab 5

#include <string>

#ifndef HASHTABLEQUADRATIC_H
#define HASHTABLEQUADRATIC_H

class HashTableQuadratic
{
private:
  int* table;
  int numBuckets;
  int maxK;

public:
  /**
  *  @pre None
  *  @post Creates and initializes a HashTable
  *  @param size The number of buckets in the hash table
  *  @return None
  */
  HashTableQuadratic(int size, int k);

  /**
  *  @pre None
  *  @post Destructor for hash table
  *  @return None
  */
  ~HashTableQuadratic();

  /**
  * @pre Username must not be in hash table and load factor must remain < .5 (rehash if not)
  * @post Checks to confirm user is not in hash table, inserts into hash table if not
  * @param username The username to insert
  * @param password The password to insert (and use to compute the hash value)
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
