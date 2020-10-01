all: Ponto.o Circulo.o main.c
	gcc -o main main.c Ponto.o Circulo.o -lm

Ponto.o: Ponto.c
	gcc -o Ponto.o -c Ponto.c

Circulo.o: Circulo.c
	gcc -o Circulo.o -c Circulo.c

clean:
	rm -f *.o main

run:
	./main < input.txt > output.txt
