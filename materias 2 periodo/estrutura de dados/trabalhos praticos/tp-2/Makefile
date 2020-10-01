all: Times.o No.o Fila.o Quadrado.o Losango.o Trapezio.o Pilha.o Operacoes.o Main.c
	gcc -o main Main.c Times.o No.o Fila.o Quadrado.o Losango.o Trapezio.o Pilha.o Operacoes.o -Wall

Times.o: Times.c
	gcc -o Times.o -c Times.c

No.o: No.c
	gcc -o No.o -c No.c

Fila.o: Fila.c
	gcc -o Fila.o -c Fila.c

Quadrado.o: Quadrado.c
	gcc -o Quadrado.o -c Quadrado.c

Losango.o: Losango.c
	gcc -o Losango.o -c Losango.c

Trapezio.o: Trapezio.c
	gcc -o Trapezio.o -c Trapezio.c

Pilha.o: Pilha.c
	gcc -o Pilha.o -c Pilha.c

Operacoes.o: Operacoes.c
	gcc -o Operacoes.o -c Operacoes.c

clean:
	rm -f *.o main

run:
	./main < input.txt > output.txt
