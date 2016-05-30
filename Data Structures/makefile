CC=g++
CFLAGS=-c -Wall -Wextra -ansi -pedantic -std=c++11

all: List

List: Driver.o List.h
	$(CC) Driver.o -o List

Driver.o: Driver.cpp
	$(CC) $(CFLAGS) Driver.cpp

clean:
	rm *o List

