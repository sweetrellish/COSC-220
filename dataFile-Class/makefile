#Created by Ryan Ells  9/12/2024

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o dataFile.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

dataFile.o : data.h dataFile.cpp
	$(CC) $(CPPFLAGS) -c dataFile.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
