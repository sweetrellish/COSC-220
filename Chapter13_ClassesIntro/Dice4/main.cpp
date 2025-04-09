/*
    Name          : main.cpp
    Author        : Don Spickler
    Creation Date : 1/21/2022
    Last Update   : 1/21/2022
    Description   : This program simulates the rolling of dice.
    User Interface: None
    Note          : This program demonstrates the use of the Die class.
    This program creates a set of DnD dice using constructor parameter values
    for the constructor.
*/

#include <cstdlib> // For rand and srand
#include <ctime>   // For the time function
#include <iostream>

#include "Die.h"

using namespace std;

int main() {
  // Seed the random number generator to the system time.
  srand(time(0));

  Die DnDdice[] = {4, 6, 8, 10, 12, 20};

  cout << "Dice sides: ";
  for (int i = 0; i < 6; i++) {
    cout << DnDdice[i].getSides() << " ";
  }
  cout << endl;

  // Display the values of the dice.
  cout << "Roll values: ";
  for (int i = 0; i < 6; i++) {
    cout << DnDdice[i].getValue() << " ";
  }
  cout << endl;

  return 0;
}
