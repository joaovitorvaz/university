all: Funcoes.o main.c
	gcc -o main main.c Funcoes.o

Funcoes.o: Funcoes.c
	gcc -o Funcoes.o -c Funcoes.c

clean:
	rm -f *.o main

run:
	./main < input.txt > output.txt
