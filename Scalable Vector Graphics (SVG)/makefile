#Created by Ryan Ellis  11/7/2024

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Rectangle.o shape.o Triangle.o Square.o Circle.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Square.o : Square.h Square.cpp
	$(CC) $(CPPFLAGS) -c Square.cpp

Rectangle.o : Rectangle.h Rectangle.cpp
	$(CC) $(CPPFLAGS) -c Rectangle.cpp

Shape.o : Shape.h shape.cpp
	$(CC) $(CPPFLAGS) -c shape.cpp
	
Triangle.o : Triangle.h Triangle.cpp
	$(CC) $(CPPFLAGS) -c Triangle.cpp
Circle.o : Circle.h Circle.cpp
	$(CC) $(CPPFLAGS) -c Circle.cpp
clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
