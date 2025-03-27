//============================================================================
// Name        : Die.h
// Author      : Ryan C. Ellis
// Creation Date: 9/24/2024
// Last Update: 10/24/2024
// Description: Specification file for the Die class.  Stores the number
// of sides of the die and the value of the last roll.  There are accessor
// functions for the number of sides and the value of the last roll as
// well as a function to do the roll.
//============================================================================

#ifndef DIE_H
#define DIE_H
#include <iostream>

using namespace std;

class Die {
private:
  int sides; // Number of sides
  int value; // The die's value

  //const int MIN_VALUE = 1; // Minimum die value

public:
  Die(int numSides = 6); // Constructor
  void roll();           // Rolls the die
  int getSides() const;  // Returns the number of sides
  int getValue() const;  // Returns the die's value

  bool operator==(const Die&);
  bool operator!=(const Die&);

  friend ostream &operator<<(ostream&, const Die&);
};
#endif
