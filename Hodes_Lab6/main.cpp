//Beau Hodes
//EECS 560 Lab 6

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <limits>
#include <string>
#include <limits>
#include "BinarySearchTree.h"

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

void getValFromUser(std::string& theNumber)
{
  while(1)
  {
    std::cin >> theNumber;
    if(theNumber.find_first_not_of("1234567890.-") != std::string::npos)
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

void isString(std::string& checkThis)
{
  std::cin >> checkThis;
  while(std::cin.fail())
  {
    std::cout << "Invalid input, try again.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

int main(int argc, char* argv[])
{
  BinarySearchTree<int, int>* BST;
  BST = new BinarySearchTree<int, int>;
  int temp;
  std::ifstream infile;
  infile.open("data.txt");
  if(!infile)
  {
    std::cout << "data.txt could not be read.\n";
    exit(1);
  }
  while(infile >> temp)
  {
    BST->add(temp);
  }

  //------------------------------------------------------END READ FILE------------------------------------------------
  int stopFlag = 0;
  int choice = 0;
  while(stopFlag == 0)
  {
    choice = 0;
    std::cout << "-----------------------------------\n";
    std::cout << "Please choose one of the following commands:\n";
    std::cout << "1. AddItem\n2. DeleteItem\n3. InorderSuccessor\n4. LevelOrder\n5. SpiralLevelOrder\n6. LeftSideView\n7. RightSideView\n8. KthSmallestItem\n9. Exit\n";
    getChoiceFromUser(choice);
    if(!std::cin) {
      std::cout << "Invalid input, try again.\n";
    }
    else if (choice == 1) {
      std::string tempNum;
      std::cout << "Enter the element to be added: ";
      getValFromUser(tempNum);
      bool result = BST->add(std::stoi(tempNum));
      if(result) {
        std::cout << "Element " << tempNum << " was successfully added.\n";
      }
      else {
        std::cout << "Element " << tempNum << " was not added.\n";
      }
    }
    else if (choice == 2) {
      std::string tempNum;
      std::cout << "Enter the element to be deleted: ";
      getValFromUser(tempNum);
      bool result = BST->remove(std::stoi(tempNum));
      if(result) {
        std::cout << "Element " << tempNum << " was successfully removed.\n";
      }
      else {
        std::cout << "Element " << tempNum << " was not removed.\n";
      }
    }
    else if (choice == 3) {
      std::string tempNum;
      std::cout << "Enter the element to find in order successor of: ";
      getValFromUser(tempNum);
      BST->inOrderSuccessor(std::stoi(tempNum));
    }
    else if (choice == 4) {
      BST->levelOrderPrint();
    }
    else if (choice == 5) {
      BST->spiralOrderPrint();
    }
    else if (choice == 6) {
      BST->leftView();
    }
    else if (choice == 7) {
      BST->rightView();
    }
    else if (choice == 8) {
      std::string tempNum;
      std::cout << "Enter value of k: ";
      getValFromUser(tempNum);
      BST->kthSmallest(std::stoi(tempNum));
    }
    else if (choice == 9) {
      std::cout << "Bye bye.\n";
      //delete BST;
      exit(0);
    }
    else
    {
      std::cout << "Invalid input, try again.\n";
    }
  }
}
