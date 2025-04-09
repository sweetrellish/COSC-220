#Created by Don Spickler  1/26/2022

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o DateTime.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

DateTime.o : DateTime.h DateTime.cpp
	$(CC) $(CPPFLAGS) -c DateTime.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
