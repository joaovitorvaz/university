all: Valores.o Ordenacao.o Cases.o Main.c
	gcc -o main Main.c Valores.o Ordenacao.o Cases.o -Wall

Valores.o: Valores.c
	gcc -o Valores.o -c Valores.c

Ordenacao.o: Ordenacao.c
	gcc -o Ordenacao.o -c Ordenacao.c

Cases.o: Cases.c
	gcc -o Cases.o -c Cases.c

clean:
	rm -f *.o main

run:
	./main < input.txt > output.txt
