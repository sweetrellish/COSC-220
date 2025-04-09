#Created by Don Spickler  1/28/2022

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o DynIntStack.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

DynIntStack.o : DynIntStack.cpp DynIntStack.h
	$(CC) $(CPPFLAGS) -c DynIntStack.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
