all: Morador.o Tarefa.o Afazer.o Republica.o Menu.o main.c
	gcc -o main main.c Morador.o Tarefa.o Afazer.o Republica.o Menu.o

Morador.o: Morador.c
	gcc -o Morador.o -c Morador.c -Wall

Tarefa.o: Tarefa.c
	gcc -o Tarefa.o -c Tarefa.c -Wall

Afazer.o: Afazer.c
	gcc -o Afazer.o -c Afazer.c -Wall

Republica.o: Republica.c
	gcc -o Republica.o -c Republica.c -Wall

Menu.o: Menu.c
	gcc -o Menu.o -c Menu.c -Wall

clean:
	rm -f *.o main

run:
	./main < input.txt > output.txt
