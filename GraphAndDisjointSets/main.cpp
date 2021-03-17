//Beau Hodes
//EECS 560 Lab 7

#include <iostream>
#include <stdexcept>
#include <limits>
#include <fstream>
#include <string>
#include <limits>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include "DisjointSet.h"
#include "Graph.h"

DisjointSet* djs = nullptr;

void getChoiceFromUser(int& theChoice)
{
  while(1)
  {
    std::cin >> theChoice;
    if(std::cin.fail())
    {
      std::cout << "Invalid input, try again.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else
    {
      break;
    }
  }
}

void buildDisjointSet()
{
  int temp;
  int counter = 0;
  std::ifstream infile;
  infile.open("data.txt");
  if (!infile)
  {
    std::cout << "data.txt could not be read.\n";
    exit(1);
  }
  while (infile >> temp)
  {
    counter++;
  }
  infile.close();
  infile.open("data.txt");
  int tempArr[counter];
  for (int i = 0; i < counter; i++) //create array of all elements
  {
    infile >> tempArr[i];
  }
  infile.close();
  for (int i = 0; i < counter; i++)
  {
    for (int j = 0; j < counter; j ++)
    {
      if (i != j && tempArr[i] == tempArr[j])
      {
        std::cout << "Duplicate values not allowed, remove duplicates from data.txt.\n";
        exit(1);
      }
    }
  }
  int largest = 0;
  for (int i = 0; i < counter; i++)
  {
    if (tempArr[i] > largest)
    {
      largest = tempArr[i];
    }
  }
  djs = new DisjointSet(largest);
  djs->makeSet(tempArr, largest);
}

int main(int argc, char* argv[])
{
  buildDisjointSet();
  Graph g;

  //start build graph
  std::string temp;
  std::string tempHolder = "";
  int length = 0;
  int i = 0;

  int matrixSize = 0;
  std::string* islands;
  int** tempMatrix;
  std::ifstream infile;
  infile.open("data1.txt");
  if (!infile)
  {
    std::cout << "data1.txt could not be read.\n";
    exit(1);
  }
  while (infile >> temp)
  {
    while(temp[i] != '\0')
    {
      tempHolder += temp[i];
      length++;
      i++;
    }
    if(length == 3)
    {
      if(tempHolder[0] == 'n' && tempHolder[1] == ',') //matrix size
      {
        matrixSize = tempHolder[2] - 48;
        islands = new std::string[matrixSize + 1]; //needs extra space to store long names
        tempMatrix = new int*[matrixSize + 1];
      }
    }
    tempHolder = "";
    length = 0;
    i = 0;
  }
  infile.close();
  infile.open("data1.txt");
  if (!infile)
  {
    std::cout << "data1.txt could not be read.\n";
    exit(1);
  }
  while (infile >> temp)
  {
    while(temp[i] != '\0')
    {
      tempHolder[i] += temp[i];
      length++;
      i++;
    }
    if(length > 3) //island name
    {
      std::string tempIsland = "";
      int islNum = 0;
      std::string tracker = "";
      int trackerLength = 0;
      bool foundIslNum = false;
      while(foundIslNum == false)
      {
        int iterator = 0;
        while(temp[iterator] != ',' && temp[iterator] != '\0')
        {
          tracker += temp[iterator];
          trackerLength++;
          iterator++;
        }
        if(trackerLength == 1) //found the island number
        {
          islNum = tracker[0] - 48;
          foundIslNum = true;
          break;
        }
        else
        {
          tempIsland += tracker;
        }
        tracker = "";
        trackerLength = 0;
        infile >> temp;
      }
      islands[islNum] = tempIsland;
    }
    else if(length == 3)
    {
      for (int i = 1; i <= matrixSize; i++)
      {
        tempMatrix[i] = new int[matrixSize + 1];
        for (int j = 1; j <= matrixSize; j++)
        {
          infile >> tempMatrix[i][j];
        }
      }
    }
    tempHolder = "";
    length = 0;
    i = 0;
  }
  infile.close();
  g.buildGraph(tempMatrix, matrixSize, islands);
  //end build graph

  int stopFlag = 0;
  int choice = 0;
  while(stopFlag == 0)
  {
    choice = 0;
    std::cout << "---------------------------------------------------\n";
    std::cout << "Please choose one of the following commands:\n";
    std::cout << "1. MakeSet\n2. Union\n3. Find\n4. PathCompression\n5. PrintPath\n6. BFS\n7. DFS\n8. Kruskal MST\n9. Prim MST\n10. Exit\n";
    getChoiceFromUser(choice);
    if(!std::cin) {
      std::cout << "Invalid input, try again.\n";
    }
    else if (choice == 1) {
      std::cout << "The disjoint sets have been constructed.\n";
    }
    else if (choice == 2) {
      int tempX;
      int tempY;
      std::cout << "Enter the representative element for the first set which you wish to union: ";
      getChoiceFromUser(tempX);
      std::cout << "Enter the representative element for the second set which you wish to union: ";
      getChoiceFromUser(tempY);
      djs->doUnion(tempX, tempY);
    }
    else if (choice == 3) {
      int tempK;
      std::cout << "Enter the element you want to find: ";
      getChoiceFromUser(tempK);
      int result = djs->find(tempK);
      if(result == -1)
      {
        std::cout << "Find failed.\n";
      }
      else
      {
        std::cout << "Element " << tempK << " found in set with representative " << result << "\n";
      }
    }
    else if (choice == 4) {
      int tempK;
      std::cout << "Enter the element on whose set you would want to perform path compression: ";
      getChoiceFromUser(tempK);
      int result = djs->pathCompression(tempK);
      if(result == -1)
      {
        std::cout << "Find failed.\n";
      }
      else
      {
        std::cout << "Path successfully compressed, " << tempK << " now points to parent " << result << "\n";
      }
    }
    else if (choice == 5) {
      int tempK;
      std::cout << "Enter the element to print its path: ";
      getChoiceFromUser(tempK);
      djs->printPath(tempK);
    }
    else if (choice == 6) {
      g.bfs();
    }
    else if (choice == 7) {
      g.dfs();
    }
    else if (choice == 8)
    {
      g.kruskal();
    }
    else if (choice == 9)
    {
      g.prim();
    }
    else if (choice == 10) {
      std::cout << "Bye bye!\n";
      return 0;
    }
    else
    {
      std::cout << "Invalid input, try again.\n";
    }
  }
}
