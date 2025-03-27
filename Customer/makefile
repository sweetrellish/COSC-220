#Created by Ryan Ellis 10/9/2024

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o persondata.o customerdata.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp 
	$(CC) $(CPPFLAGS) -c main.cpp
persondata.o : persondata.cpp
	$(CC) $(CPPFLAGS) -c persondata.cpp
customerdata.o : customerdata.cpp
	$(CC) $(CPPFLAGS) -c customerdata.cpp
clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
