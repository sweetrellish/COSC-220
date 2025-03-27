#Created by Ryan Ells  9/12/2024

PROG = data
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = dataFile.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

dataFile.o : dataFile.cpp
	$(CC) $(CPPFLAGS) -c dataFile.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
