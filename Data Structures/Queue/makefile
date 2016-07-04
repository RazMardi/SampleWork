CC=g++
CFLAGS=-c -Wall -Wextra -ansi -pedantic -std=c++11

all: Queue

Queue: Driver.o Queue.h
	$(CC) Driver.o -o Queue

Driver.o: Driver.cpp
	$(CC) $(CFLAGS) Driver.cpp

clean:
	rm *o Queue

