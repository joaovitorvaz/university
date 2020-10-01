all: No.o Lista.o Main.c
	gcc -o main Main.c No.o Lista.o

No.o: No.c
	gcc -o No.o -c No.c

Lista.o: Lista.c
	gcc -o Lista.o -c Lista.c

clean:
	rm -f *.o main

run:
	./main < input.txt > output.txt
