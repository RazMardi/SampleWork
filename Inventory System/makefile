CC=g++
CFLAGS=-c -Wall -Wextra -ansi -pedantic -std=c++11

all: Inventory

Inventory: Driver.o Inventory.o Item.o Serializer.o
	$(CC) Driver.o  Inventory.o Item.o Serializer.o -o Inventory

Driver.o: Driver.cpp
	$(CC) $(CFLAGS) Driver.cpp
	
Inventory.o: Inventory.cpp Serializer.cpp
	$(CC) $(CFLAGS) Inventory.cpp
	
Item.o: Item.cpp
	$(CC) $(CFLAGS) Item.cpp
	
Serializer.o: Serializer.cpp 
	$(CC) $(CFLAGS) Serializer.cpp

clean:
	rm *o Inventory

