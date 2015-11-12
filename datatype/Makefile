all:main

dataType.o: dataType.h dataType.c
	gcc -c dataType.c

main: dataType.o main.c
	gcc dataType.o main.c -o main

clean:
	rm *.o main
