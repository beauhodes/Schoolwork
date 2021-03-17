Lab6: main.o
	g++ -std=c++11 -g -Wall main.o -o Lab6

main.o: main.cpp BinarySearchTree.h BinarySearchTree.cpp Node.h Node.cpp BinaryNode.h BinaryNode.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

#BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp Node.h Node.cpp BinaryNode.h BinaryNode.cpp
#	g++ -std=c++11 -g -Wall -c BinarySearchTree.cpp

clean:
	rm *.o Lab6
