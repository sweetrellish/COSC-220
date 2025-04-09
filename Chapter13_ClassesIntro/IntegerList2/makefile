#Created by Don Spickler  1/21/2022

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o IntegerList.o Die.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

IntegerList.o : IntegerList.h IntegerList.cpp
	$(CC) $(CPPFLAGS) -c IntegerList.cpp

Die.o : Die.h Die.cpp
	$(CC) $(CPPFLAGS) -c Die.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
