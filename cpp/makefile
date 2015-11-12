all:main

dataType.o: dataType.h dataType.cpp
	g++ -c dataType.cpp

main.o: main.cpp
	g++ -c main.cpp

main: dataType.o main.o
	g++ dataType.o main.o -o main

clean:
	rm *.o main *~
