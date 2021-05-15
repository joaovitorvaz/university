all: tp2.o quickSortExterno.o intercala.o arquivos.o main.c
	gcc -o ordena main.c tp2.o quickSortExterno.o intercala.o arquivos.o

tp2.o: tp2.c
	gcc -o tp2.o -c tp2.c

quickSortExterno.o: quickSortExterno.c
	gcc -o quickSortExterno.o -c quickSortExterno.c

intercala.o: intercala.c
	gcc -o intercala.o -c intercala.c

arquivos.o: arquivos.c
	gcc -o arquivos.o -c arquivos.c

clean:
	rm -f *.o ordena

run:
	./ordena
