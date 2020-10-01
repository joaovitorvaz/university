all: Aleatorio.o Ordenacao.o Main.c
	gcc -o main Main.c Aleatorio.o Ordenacao.o -Wall

Aleatorio.o: Aleatorio.c
	gcc -o Aleatorio.o -c Aleatorio.c

Ordenacao.o: Ordenacao.c
	gcc -o Ordenacao.o -c Ordenacao.c

clean:
	rm -f *.o main

run:
	./main < input.txt > output.txt
