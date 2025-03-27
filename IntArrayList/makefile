#Created by Ryan Ellis 9/13/2024
PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o list.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

list.o : list.h list.cpp
	$(CC) $(CPPFLAGS) -c list.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make

