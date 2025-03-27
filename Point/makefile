#Created by Ryan Ellis 9/18/2024

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o point.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp 
	$(CC) $(CPPFLAGS) -c main.cpp
point.o : point.h point.cpp
	$(CC) $(CPPFLAGS) -c point.cpp
clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
