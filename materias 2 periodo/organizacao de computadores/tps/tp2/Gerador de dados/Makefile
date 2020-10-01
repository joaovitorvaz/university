all: Instructions.o Menu.o Bloco.o Cache.o Cpu.o Machine.o main.c
	gcc -o main main.c Instructions.o Menu.o Bloco.o Cache.o Cpu.o Machine.o -Wall

Instructions.o: Instructions.c
	gcc -o Instructions.o -c Instructions.c

Menu.o: Menu.c
	gcc -o Menu.o -c Menu.c

Bloco.o: Bloco.c
	gcc -o Bloco.o -c Bloco.c

Cache.o: Cache.c
	gcc -o Cache.o -c Cache.c

Cpu.o: Cpu.c
	gcc -o Cpu.o -c Cpu.c

Machine.o: Machine.c
	gcc -o Machine.o -c Machine.c

clean:
	rm -f *.o main

run:
	./main < input.txt> resultados.txt
