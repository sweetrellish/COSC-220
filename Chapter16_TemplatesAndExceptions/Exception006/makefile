#Created by Don Spickler  1/28/2022

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o DivisionByZeroException.o ExceptionSystem.o NegativeNumberException.o Rectangle.o 

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Rectangle.o : Rectangle.h Rectangle.cpp
	$(CC) $(CPPFLAGS) -c Rectangle.cpp

DivisionByZeroException.o : DivisionByZeroException.h DivisionByZeroException.cpp
	$(CC) $(CPPFLAGS) -c DivisionByZeroException.cpp

ExceptionSystem.o : ExceptionSystem.h ExceptionSystem.cpp
	$(CC) $(CPPFLAGS) -c ExceptionSystem.cpp

NegativeNumberException.o : NegativeNumberException.h NegativeNumberException.cpp
	$(CC) $(CPPFLAGS) -c NegativeNumberException.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
