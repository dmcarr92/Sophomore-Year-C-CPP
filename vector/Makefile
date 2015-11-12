all:main

dataType.o: dataType.h dataType.c
	gcc -g -c dataType.c

readWrite.o: readWrite.h readWrite.c
	gcc -g -c readWrite.c

vector.o: vector.h vector.c
	gcc -g -c vector.c

main: dataType.o readWrite.o vector.o vecMain2.c
	gcc dataType.o readWrite.o vector.o vecMain2.c -o main

clean:
	rm *.o main
