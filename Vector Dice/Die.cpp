//============================================================================
// Name        : Die.cpp
// Author      : Ryan C. Ellis
// Creation Date: 9/24/2024
// Last Update: 10/24/2024
// Description: Implementation file for the Die class.
//============================================================================


#include <cstdlib> // For rand and srand

#include "Die.h"

using namespace std;

/*
    Description: Constructor
    Parameters: numSides - Number of sides to the die.
    Return: None
    Note: This implementation requires the RNG seed to be set in the main, or at
    least before this class is instantiated.
*/

Die::Die(int numSides) {
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
  value = (rand() % sides) + 1;
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

/*
    Description: Overloaded operator for the equivalency operator in the Die class.
    Parameters: constant Die object d.
    Return: boolean value.
*/
bool Die :: operator==(const Die &d){
    if(value == d.value)
      return true;
    else
      return false;
}

/*
    Description: Overloaded operator for the non-equivalency operator in the Die class.
    Parameters: constant Die object d.
    Return: boolean value.
*/
bool Die :: operator!=(const Die &d){
    if(value != d.value)
      return true;
    else
      return false;
}

/*
    Description: Overloaded operator for the equivalency operator in the Die class.
    Parameters: constant Die object d.
    Return: boolean value.
*/
ostream &operator<<(ostream &strm, const Die &d){
    strm<<d.value;
    return strm;
}
