all: BFS.o principal.cpp
	g++ -o principal principal.cpp BFS.o -Wall

BFS.o: BFS.cpp
	g++ -o BFS.o -c BFS.cpp

clean:
	rm -f *.o principal

run:
	./principal