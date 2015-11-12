all:main

dataType.o: dataType.h dataType.c
	gcc -c -g dataType.c

readWrite.o: readWrite.h readWrite.c
	gcc -c -g readWrite.c

doubleLL.o: doubleLL.h doubleLL.c
	gcc -c -g doubleLL.c

stack.o: stack.h stack.c
	gcc -c -g stack.c

queue.o: queue.h queue.c
	gcc -c -g queue.c

bsTree.o: bsTree.h bsTree.c
	gcc -c -g bsTree.c

main: dataType.o readWrite.o doubleLL.o stack.o queue.o bsTree.o main.c
	gcc -g dataType.o readWrite.o doubleLL.o stack.o queue.o bsTree.o main.c -o main

clean:
	rm *.o
	rm *.txt main


