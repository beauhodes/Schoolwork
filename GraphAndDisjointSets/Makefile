Lab10: main.o DisjointSet.o Graph.o MinHeap.o
	g++ -std=c++11 -g -Wall main.o DisjointSet.o Graph.o MinHeap.o -o Lab10

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

DisjointSet.o: DisjointSet.h DisjointSet.cpp Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c DisjointSet.cpp

Graph.o: Graph.h Graph.cpp DisjointSet.h DisjointSet.cpp MinHeap.h MinHeap.cpp
	g++ -std=c++11 -g -Wall -c Graph.cpp

MinHeap.o: MinHeap.h MinHeap.cpp Graph.h Graph.cpp
		g++ -std=c++11 -g -Wall -c MinHeap.cpp

clean:
	rm -f Lab10 *.o

leak:
	valgrind --leak-check=full ./Lab10
