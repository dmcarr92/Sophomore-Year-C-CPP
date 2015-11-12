all:main

readWrite.o: readWrite.h readWrite.c
	gcc -c readWrite.c

dataType.o: dataType.h dataType.c
	gcc -c dataType.c

main: readWrite.o dataType.o main.c
	gcc readWrite.o dataType.o main.c -o main

clean:
	rm *.o main
