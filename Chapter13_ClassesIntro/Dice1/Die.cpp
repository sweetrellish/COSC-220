/*
    Name          : Die.cpp
    Author        : Don Spickler
    Creation Date : 1/21/2022
    Last Update   : 1/21/2022
    Description   : Implementation file for the Die class.
*/

#include <cstdlib> // For rand and srand
#include <ctime>   // For the time function

#include "Die.h"

using namespace std;

/*
    Description: Constructor
    Parameters: numSides - Number of sides to the die.
    Return: None
    Note: This is a bad use of the seed setting of the random number generator.
    Since the resolution of time(0) is a second in most cases if there are
    multiple instances of this class created they may result in rolling the
    same number.  It is better to set the RNG up one time in the main or
    helper class and then not reset the seed again. The downside to this
    is that the main is expected to set the RNG seed which is a bit against
    encapsulation.
*/

Die::Die(int numSides) {
  // Seed the random number generator to the system time.
  srand(time(0));

  // Set the number of sides.
  sides = numSides;

  // Perform an initial roll.
  roll();
}

/*
    Description: Roll function that will roll the die and store the value.
    Parameters: None
    Return: None
*/

void Die::roll() {
  // Get a random value for the die.
  value = (rand() % sides) + MIN_VALUE;
}

/*
    Description: Accessor for the number of sides of the die.
    Parameters: None
    Return: Number of sides of the die.
*/

int Die::getSides() const { return sides; }

/*
    Description: Accessor for the value of the last roll.
    Parameters: None
    Return: Value of the last roll.
*/

int Die::getValue() const { return value; }
