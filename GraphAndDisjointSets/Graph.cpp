//Beau Hodes
//EECS 560 Lab 9

#include <iostream>
#include <string>
#include <fstream>
#include "Graph.h"

Graph::Graph()
{
  matrix = nullptr;
  size = 0;
}

Graph::~Graph()
{
  for(int i = 1; i <= size; i++)
  {
    delete [] matrix[i];
  }
  delete [] matrix;
  delete [] islandNames;
}

void Graph::buildGraph(int** costs, int newSize, std::string* newIslands) //size should be directly from input file
{
  size = newSize;

  islandNames = new std::string[size + 1];
  for(int i = 1; i <= size; i++)
  {
    islandNames[i] = newIslands[i];
  }

  matrix = new int*[size + 1];
  for(int i = 1; i <= size; i++)
  {
    matrix[i] = new int[size + 1];
    for(int j = 1; j <= size; j++)
    {
      matrix[i][j] = costs[i][j];
    }
  }
}

void Graph::printMatrix()
{
  for(int i = 1; i <= size; i++)
  {
    for(int j = 1; j <= size; j++)
    {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

void Graph::dfs()
{
  std::cout << "Tree edges: ";
  for (int i = 1; i < size; i++)
  {
    if(matrix[i][i+1] != -1)
    {
      std::cout << "(" << islandNames[i] << ", " << islandNames[i + 1] << ") ";
    }
  }
  std::cout << '\n';
  std::cout << "Back edges: ";
  for (int i = 3; i <= size; i++)
  {
    if (matrix[1][i] != -1)
    {
      std::cout << "(" << islandNames[1] << ", " << islandNames[i] << ") ";
    }
  }
  for (int i = 2; i <= size; i++)
  {
    if (matrix[i][5] == 13) //13 is max value
    {
      std::cout << "(" << islandNames[i] << ", " << islandNames[5] << ") ";
    }
  }
  std::cout << '\n';
}

void Graph::bfs()
{
  std::cout << "Tree edges: ";
  for(int i = 2; i <= size; i++)
  {
    if(matrix[1][i] != -1)
    {
      std::cout << "(" << islandNames[1] << ", " << islandNames[i] << ") ";
    }
  }
  std::cout << '\n';
  std::cout << "Cross edges: ";
  for(int i = 2; i <= size; i++)
  {
    for(int j = i + 1; j <= size; j++)
    {
      if(matrix[i][j] != -1)
      {
        std::cout << "(" << islandNames[i] << ", " << islandNames[j] << ") ";
      }
    }
  }
  std::cout << '\n';
}

void Graph::kruskal()
{
  //build disjoint set
  int tempDjsArr[size];
  for(int i = 1; i <= size; i++)
  {
    tempDjsArr[i] = i;
  }
  DisjointSet s;
  int djsSize = size;
  s.makeSet(tempDjsArr, djsSize);

  //build priority queue
  edge* allEdges = new edge[size * size];
  int allEdgesSize = 0;
  int rowIterator = 1;
  for(int z = 1; z <= (size * size); z++)
  {
    edge tempEdge{matrix[rowIterator][((z - 1) % 5) + 1], rowIterator, ((z - 1) % 5) + 1};
    if(tempEdge.cost != -1 && tempEdge.cost != 1)
    {
      allEdges[allEdgesSize] = edge{tempEdge.cost, tempEdge.startIndex, tempEdge.endIndex};
      allEdgesSize++;
    }
    if(z % size == 0)
    {
      rowIterator++;
    }
  }
  MinHeap q;
  q.buildHeap(allEdges, allEdgesSize);

  //create Et
  edge* Et = new edge[size - 1];
  int EtCount = 0;

  while(q.getSize() > 0 && EtCount < (size - 1))
  {
    edge vwc = q.removeEdge();
    if(s.find(vwc.startIndex) != s.find(vwc.endIndex))
    {
      Et[EtCount] = vwc;
      EtCount++;
      s.doUnion(s.find(vwc.startIndex), s.find(vwc.endIndex));
    }
  }

  if(EtCount == size - 1)
  {
    int totalCost = 0;
    for(int i = 0; i < EtCount; i++)
    {
      std::cout << "(" << islandNames[Et[i].startIndex] << ", " << islandNames[Et[i].endIndex] << "){" << Et[i].cost << "} ";
      totalCost += Et[i].cost;
    }
    std::cout << '\n';
    std::cout << "Total length of the route = " << totalCost << " miles\n";
    std::cout << "Total estimate to construct the bridges in the route = " << totalCost * 250000 << '\n';
  }
  else
  {
    std::cout << "No solution found.\n";
  }

  std::cout << "BeforeEt\n" << std::flush;
  delete [] Et;
  Et = nullptr;
  std::cout << "AfterEt\n" << std::flush;
  delete [] allEdges;
  allEdges = nullptr;
  std::cout << "AfterAllEdges\n" << std::flush;
}

void Graph::prim()
{
  //create Et
  edge* Et = new edge[size - 1];
  int EtCount = 0;

  //create Vt as set with {1}
  int* Vt = new int[size];
  Vt[0] = 1;
  int VtCount = 1;

  //build priority queue containing all edges incident from Vt
  edge* allEdges = new edge[size * size];
  int allEdgesSize = 0;
  for(int z = 1; z <= size; z++)
  {
    edge tempEdge{matrix[1][z], 1, z};
    if(tempEdge.cost != -1 && tempEdge.cost != 1)
    {
      allEdges[allEdgesSize] = edge{tempEdge.cost, tempEdge.startIndex, tempEdge.endIndex};
      allEdgesSize++;
    }
  }
  MinHeap q;
  q.buildHeap(allEdges, allEdgesSize);

  while(q.getSize() != 0 && VtCount < size)
  {
    edge vwc = q.removeEdge();
    Et[EtCount] = vwc;
    EtCount++;
    Vt[VtCount] = vwc.endIndex;
    VtCount++;
    for(int z = 1; z <= size; z++)
    {
      edge tempEdge{matrix[vwc.endIndex][z], vwc.endIndex, z};
      if(tempEdge.cost != -1 && tempEdge.cost != 1)
      {
        q.addEdge(tempEdge);
      }
    }
    for(int i = 0; i < VtCount; i++)
    {
      q.removeEdgesWithEndPoint(Vt[i]);
    }
  }

  if(EtCount == size - 1)
  {
    int totalCost = 0;
    for(int i = 0; i < EtCount; i++)
    {
      std::cout << "(" << islandNames[Et[i].startIndex] << ", " << islandNames[Et[i].endIndex] << "){" << Et[i].cost << "} ";
      totalCost += Et[i].cost;
    }
    std::cout << '\n';
    std::cout << "Total length of the route = " << totalCost << " miles\n";
    std::cout << "Total estimate to construct the bridges in the route = " << totalCost * 250000 << '\n';
  }
  else
  {
    std::cout << "No solution found.\n";
    std::cout << "EtCount was: " << EtCount << '\n';
  }

  std::cout << "BeforeEt\n" << std::flush;
  delete [] Et;
  Et = nullptr;
  std::cout << "AfterEt\n" << std::flush;
  delete [] Vt;
  Vt = nullptr;
  std::cout << "AfterVt\n" << std::flush;
  delete [] allEdges;
  allEdges = nullptr;
  std::cout << "AfterAllEdges\n" << std::flush;
}
