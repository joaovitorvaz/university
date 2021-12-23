all: floydwarshall.o principal.cpp
	g++ -o principal principal.cpp floydwarshall.o -Wall

floydwarshall.o: floydwarshall.cpp
	g++ -o floydwarshall.o -c floydwarshall.cpp

clean:
	rm -f *.o principal

run:
	./principal