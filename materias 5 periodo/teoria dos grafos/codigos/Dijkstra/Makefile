all: dijkstra.o principal.cpp
	g++ -o principal principal.cpp dijkstra.o -Wall

dijkstra.o: dijkstra.cpp
	g++ -o dijkstra.o -c dijkstra.cpp

clean:
	rm -f *.o principal

run:
	./principal