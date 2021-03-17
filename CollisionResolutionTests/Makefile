Lab5: main.o HashTableQuadratic.o HashTableDouble.o
	g++ -std=c++11 -g -Wall main.o HashTableQuadratic.o HashTableDouble.o -o Lab5

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

HashTableQuadratic.o: HashTableQuadratic.h HashTableQuadratic.cpp
	g++ -std=c++11 -g -Wall -c HashTableQuadratic.cpp

HashTableDouble.o: HashTableDouble.h HashTableDouble.cpp
	g++ -std=c++11 -g -Wall -c HashTableDouble.cpp

clean:
	rm -f Lab5 *.o

leak:
	valgrind --leak-check=full ./Lab5
