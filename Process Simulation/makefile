#Created by Ryan Ellis  11/15/2024

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Process.o
$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp
Process.o : Process.cpp
	$(CC) $(CPPFLAGS) -c Process.cpp
clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
