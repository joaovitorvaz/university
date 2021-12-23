all: dijkstra.o bellmanford.o principal.cpp
	g++ -o principal principal.cpp dijkstra.o bellmanford.o -Wall

dijkstra.o: dijkstra.cpp
	g++ -o dijkstra.o -c dijkstra.cpp

bellmanford.o: bellmanford.cpp
	g++ -o bellmanford.o -c bellmanford.cpp

clean:
	rm -f *.o principal

run:
	./principal