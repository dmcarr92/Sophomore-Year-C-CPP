all:main

recr.o: recr.h recr.c
	gcc -g -c recr.c

main: recr.o main.c
	gcc -g recr.o main.c -o main

clean:
	rm *.o main
