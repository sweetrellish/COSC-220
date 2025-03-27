#Created by Ryan Ellis 9/29/2024

PROG = poker
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o card.o deck.o hand.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

card.o : card.h card.cpp
	$(CC) $(CPPFLAGS) -c card.cpp

deck.o : deck.h deck.cpp
	$(CC) $(CPPFLAGS) -c deck.cpp

hand.o : hand.h hand.cpp
	$(CC) $(CPPFLAGS) -c hand.cpp
clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
