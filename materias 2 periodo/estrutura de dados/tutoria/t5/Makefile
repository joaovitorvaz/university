all: Lista.o No.o Main.c
	gcc -o main main.c Lista.o No.o -Wall

Lista.o: Lista.c
	gcc -o Lista.o -c Lista.c

No.o: No.c
	gcc -o No.o -c No.c

clean:
	rm -f *.o main

run:
	./main < input.txt
