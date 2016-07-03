CC=g++
CFLAGS=-c -Wall -Wextra -ansi -pedantic -std=c++11

all: Stack

Stack: Driver.o Stack.h
	$(CC) Driver.o -o Stack

Driver.o: Driver.cpp
	$(CC) $(CFLAGS) Driver.cpp

clean:
	rm *o Stack

