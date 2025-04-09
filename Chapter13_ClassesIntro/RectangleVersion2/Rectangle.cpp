// Textbook example with some minor alterations.
// Date: 1/22/2022

// Implementation file for the Rectangle class.
// In this version of the class, the getWidth, getLength,
// and getArea functions are written inline in Rectangle.h.

#include "Rectangle.h" // Needed for the Rectangle class
#include <iostream>    // Needed for cout

using namespace std;

//***********************************************************
// setWidth sets the value of the member variable width.    *
//***********************************************************

void Rectangle::setWidth(double w) {
  if (w >= 0)
    width = w;
  else {
    cout << "Invalid width, no change made.\n";
  }
}

//***********************************************************
// setLength sets the value of the member variable length.  *
//***********************************************************

void Rectangle::setLength(double len) {
  if (len >= 0)
    length = len;
  else {
    cout << "Invalid length, no change made.\n";
  }
}
