all:  tp1.o asi.o arvore.o arvoreb.o arvorebestrela.o main.c
	gcc -o pesquisa main.c tp1.o asi.o arvore.o arvoreb.o arvorebestrela.o

tp1.o: tp1.c
	gcc -o tp1.o -c tp1.c

asi.o: asi.c
	gcc -o asi.o -c asi.c

arvore.o: arvore.c
	gcc -o arvore.o -c arvore.c

arvoreb.o: arvoreb.c
	gcc -o arvoreb.o -c arvoreb.c

arvorebestrela.o: arvorebestrela.c
	gcc -o arvorebestrela.o -c arvorebestrela.c

clean:
	rm -f *.o pesquisa

run:
	./pesquisa
