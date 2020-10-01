all: Livro.o main.c
			gcc -o main main.c Livro.o

Livro.o: Livro.c
			gcc -o Livro.o -c Livro.c

clean:
			rm -f *.o main

run:
			./main < input.txt > output.txt
