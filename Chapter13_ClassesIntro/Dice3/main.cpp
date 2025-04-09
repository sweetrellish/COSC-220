/*
    Name          : main.cpp
    Author        : Don Spickler
    Creation Date : 1/21/2022
    Last Update   : 1/21/2022
    Description   : This program simulates the rolling of dice.
    User Interface: None
    Note          : This program demonstrates the use of the Die class.
    This program creates 5 6-sided die.  All are created with the default
    constructor, default value of the number of sides of the die.
*/

#include <cstdlib> // For rand and srand
#include <ctime>   // For the time function
#include <iostream>

#include "Die.h"

using namespace std;

int main() {
  // Seed the random number generator to the system time.
  srand(time(0));

  Die dice[5];

  // Display the values of the dice.
  cout << "Roll values: ";
  for (int i = 0; i < 5; i++) {
    cout << dice[i].getValue() << " ";
  }
  cout << endl;

  return 0;
}
