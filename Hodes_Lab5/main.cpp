//Beau Hodes
//EECS 560 Lab 2
//Feb 4, 2020

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <limits>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include "HashTableQuadratic.h"
#include "HashTableDouble.h"

struct outputColumn
{
  int inputSize;
  double buildTime;
  int found;
  int notFound;
};

int M = 1000003; //table size
int R = 773; //double hashing value
int k = 25; //max k value

double insertQuadraticData(HashTableQuadratic& table, int setNum)
{
  srand(time(NULL));
  int inputSize = floor(.1*setNum*M);
  int randomNum;
  clock_t t;
  t = clock();
  for(int i = 0; i < inputSize; i++)
  {
    randomNum = rand() % 5000000 + 1;
    table.insert(randomNum);
  }
  t = clock() - t;
  return t/(double)CLOCKS_PER_SEC;
}

int findQuadraticData(HashTableQuadratic& table, int setNum)
{
  int findSize = floor(.01*setNum*M);
  int randomNum;
  int foundCount = 0;
  for(int i = 0; i < findSize; i++)
  {
    randomNum = rand() % 5000000 + 1;
    if(table.find(randomNum))
    {
      foundCount++;
    }
  }
  return foundCount;
}

double insertDoubleData(HashTableDouble& table, int setNum)
{
  srand(time(NULL));
  int inputSize = floor(.1*setNum*M);
  int randomNum;
  clock_t t;
  t = clock();
  for(int i = 0; i < inputSize; i++)
  {
    randomNum = rand() % 5000000 + 1;
    table.insert(randomNum);
  }
  t = clock() - t;
  return t/(double)CLOCKS_PER_SEC;
}

int findDoubleData(HashTableDouble& table, int setNum)
{
  int findSize = floor(.01*setNum*M);
  int randomNum;
  int foundCount = 0;
  for(int i = 0; i < findSize; i++)
  {
    randomNum = rand() % 5000000 + 1;
    if(table.find(randomNum))
    {
      foundCount++;
    }
  }
  return foundCount;
}

int main(int argc, char* argv[])
{
  const char separator = ' ';
  const int width = 16;

  HashTableQuadratic tempTable1(floor(.1*M), k);
  outputColumn col1;
  col1.inputSize = floor(.1*M);
  col1.buildTime = insertQuadraticData(tempTable1, 1);
  col1.found = findQuadraticData(tempTable1, 1);
  col1.notFound = (floor(.01*1*M) - col1.found);
  //delete tempTable1;

  HashTableQuadratic tempTable2(floor(.2*M), k);
  outputColumn col2;
  col2.inputSize = floor(.2*M);
  col2.buildTime = insertQuadraticData(tempTable2, 2);
  col2.found = findQuadraticData(tempTable2, 2);
  col2.notFound = (floor(.01*2*M) - col2.found);
  //delete tempTable2;

  HashTableQuadratic tempTable3(floor(.3*M), k);
  outputColumn col3;
  col3.inputSize = floor(.3*M);
  col3.buildTime = insertQuadraticData(tempTable3, 3);
  col3.found = findQuadraticData(tempTable3, 3);
  col3.notFound = (floor(.01*3*M) - col3.found);
  //delete tempTable3;

  HashTableQuadratic tempTable4(floor(.4*M), k);
  outputColumn col4;
  col4.inputSize = floor(.4*M);
  col4.buildTime = insertQuadraticData(tempTable4, 4);
  col4.found = findQuadraticData(tempTable4, 4);
  col4.notFound = (floor(.01*4*M) - col4.found);
  //delete tempTable4;

  HashTableQuadratic tempTable5(floor(.5*M), k);
  outputColumn col5;
  col5.inputSize = floor(.5*M);
  col5.buildTime = insertQuadraticData(tempTable5, 5);
  col5.found = findQuadraticData(tempTable5, 5);
  col5.notFound = (floor(.01*5*M) - col5.found);
  //delete tempTable5;

  HashTableDouble tempTableDouble1(floor(.1*M), k, R);
  outputColumn colDouble1;
  colDouble1.inputSize = floor(.1*M);
  colDouble1.buildTime = insertDoubleData(tempTableDouble1, 1);
  colDouble1.found = findDoubleData(tempTableDouble1, 1);
  colDouble1.notFound = (floor(.01*1*M) - colDouble1.found);
  //delete tempTableDouble1;

  HashTableDouble tempTableDouble2(floor(.2*M), k, R);
  outputColumn colDouble2;
  colDouble2.inputSize = floor(.2*M);
  colDouble2.buildTime = insertDoubleData(tempTableDouble2, 2);
  colDouble2.found = findDoubleData(tempTableDouble2, 2);
  colDouble2.notFound = (floor(.01*2*M) - colDouble2.found);
  //delete tempTableDouble2;

  HashTableDouble tempTableDouble3(floor(.3*M), k, R);
  outputColumn colDouble3;
  colDouble3.inputSize = floor(.3*M);
  colDouble3.buildTime = insertDoubleData(tempTableDouble3, 3);
  colDouble3.found = findDoubleData(tempTableDouble3, 3);
  colDouble3.notFound = (floor(.01*3*M) - colDouble3.found);
  //delete tempTableDouble3;

  HashTableDouble tempTableDouble4(floor(.4*M), k, R);
  outputColumn colDouble4;
  colDouble4.inputSize = floor(.4*M);
  colDouble4.buildTime = insertDoubleData(tempTableDouble4, 4);
  colDouble4.found = findDoubleData(tempTableDouble4, 4);
  colDouble4.notFound = (floor(.01*4*M) - colDouble4.found);
  //delete tempTableDouble4;

  HashTableDouble tempTableDouble5(floor(.5*M), k, R);
  outputColumn colDouble5;
  colDouble5.inputSize = floor(.5*M);
  colDouble5.buildTime = insertDoubleData(tempTableDouble5, 5);
  colDouble5.found = findDoubleData(tempTableDouble5, 5);
  colDouble5.notFound = (floor(.01*5*M) - colDouble5.found);
  //delete tempTableDouble5;

  std::cout << '\n';
  std::cout << '\n';
  std::cout << "____________________Performance (Quadratic Probing)________________________\n";
  std::cout << std::left << std::setw(width) << std::setfill(separator) << "Input size";
  std::cout << std::left << std::setw(width) << std::setfill(separator) << col1.inputSize;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << col2.inputSize;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << col3.inputSize;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << col4.inputSize;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << col5.inputSize;
  std::cout << '\n';
  std::cout << std::left << std::setw(width) << std::setfill(separator) << "Build(s)";
  std::cout << std::left << std::setw(width) << std::setfill(separator) << col1.buildTime;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << col2.buildTime;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << col3.buildTime;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << col4.buildTime;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << col5.buildTime;
  std::cout << '\n';
  std::cout << std::left << std::setw(width) << std::setfill(separator) << "Items found";
  std::cout << std::left << std::setw(width) << std::setfill(separator) << col1.found;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << col2.found;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << col3.found;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << col4.found;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << col5.found;
  std::cout << '\n';
  std::cout << std::left << std::setw(width) << std::setfill(separator) << "Items not found";
  std::cout << std::left << std::setw(width) << std::setfill(separator) << col1.notFound;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << col2.notFound;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << col3.notFound;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << col4.notFound;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << col5.notFound;
  std::cout << '\n';
  std::cout << '\n';

  std::cout << "____________________Performance (Double Hashing)________________________\n";
  std::cout << std::left << std::setw(width) << std::setfill(separator) << "Input size";
  std::cout << std::left << std::setw(width) << std::setfill(separator) << colDouble1.inputSize;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << colDouble2.inputSize;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << colDouble3.inputSize;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << colDouble4.inputSize;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << colDouble5.inputSize;
  std::cout << '\n';
  std::cout << std::left << std::setw(width) << std::setfill(separator) << "Build(s)";
  std::cout << std::left << std::setw(width) << std::setfill(separator) << colDouble1.buildTime;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << colDouble2.buildTime;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << colDouble3.buildTime;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << colDouble4.buildTime;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << colDouble5.buildTime;
  std::cout << '\n';
  std::cout << std::left << std::setw(width) << std::setfill(separator) << "Items found";
  std::cout << std::left << std::setw(width) << std::setfill(separator) << colDouble1.found;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << colDouble2.found;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << colDouble3.found;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << colDouble4.found;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << colDouble5.found;
  std::cout << '\n';
  std::cout << std::left << std::setw(width) << std::setfill(separator) << "Items not found";
  std::cout << std::left << std::setw(width) << std::setfill(separator) << colDouble1.notFound;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << colDouble2.notFound;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << colDouble3.notFound;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << colDouble4.notFound;
  std::cout << std::left << std::setw(width) << std::setfill(separator) << colDouble5.notFound;
  std::cout << '\n';
}
