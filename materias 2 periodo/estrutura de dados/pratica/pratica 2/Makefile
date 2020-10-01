all: Aluno.o Disciplina.o Atestado.o main.c
	gcc -o main main.c Aluno.o Disciplina.o Atestado.o

Aluno.o: Aluno.c
	gcc -o Aluno.o -c Aluno.c

Disciplina.o: Disciplina.c
	gcc -o Disciplina.o -c Disciplina.c

Atestado.o: Atestado.c
	gcc -o Atestado.o -c Atestado.c

clean:
	rm -f *.o main

run:
	./main < input.txt > output.txt
