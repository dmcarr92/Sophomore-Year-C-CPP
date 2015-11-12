all:main

dataType.o: dataType.h dataType.c
	gcc -g -c dataType.c

readWrite.o: readWrite.h readWrite.c
	gcc -g -c readWrite.c

doubleLL.o: doubleLL.h doubleLL.c
	gcc -g -c doubleLL.c

stack.o: stack.h stack.c
	gcc -g -c stack.c

queue.o: queue.h queue.c
	gcc -g -c queue.c

main: dataType.o readWrite.o doubleLL.o stack.o queue.o
	gcc dataType.o readWrite.o doubleLL.o stack.o queue.o SQmain.c -o main

clean:
	rm *.o main
