all: DFS.o principal.cpp
	g++ -o principal principal.cpp DFS.o -Wall

DFS.o: DFS.cpp
	g++ -o DFS.o -c DFS.cpp

clean:
	rm -f *.o principal

run:
	./principal