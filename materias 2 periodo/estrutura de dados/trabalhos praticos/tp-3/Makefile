all: Huffman.o Aluno.o Hash.o Programa.o Main.c
	gcc -o main Main.c Huffman.o Aluno.o Hash.o Programa.o -Wall -lm

Huffman.o: Huffman.c
	gcc -o Huffman.o -c Huffman.c

Aluno.o: Aluno.c
	gcc -o Aluno.o -c Aluno.c

Hash.o: Hash.c
	gcc -o Hash.o -c Hash.c

Programa.o: Programa.c
	gcc -o Programa.o -c Programa.c

clean:
	rm -f *.o main

run:
	./main < entrada.txt > saida.txt
