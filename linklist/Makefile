all:main

dataType.o: dataType.h dataType.c
	gcc -g -c dataType.c

readWrite.o: readWrite.h readWrite.c
	gcc -g -c readWrite.c

linklist.o: linklist.h linklist.c
	gcc -g -c linklist.c

main: dataType.o readWrite.o linklist.o llmain.c
	gcc dataType.o readWrite.o linklist.o llmain.c -o main

clean:
	rm *.o main
