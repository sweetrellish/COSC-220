// Implementation file for the Rectangle class.
#include "Rectangle.h"
#include "NegativeNumberException.h"

//***********************************************************
// setWidth sets the value of the member variable width.    *
//***********************************************************

void Rectangle::setWidth(double w) {
  if (w >= 0)
    width = w;
  else {
    char badval[100];
    sprintf(badval, "Invalid Value: %f", w);
    throw NegativeNumberException(badval);
  }
}

//***********************************************************
// setLength sets the value of the member variable length.  *
//***********************************************************

void Rectangle::setLength(double len) {
  if (len >= 0)
    length = len;
  else {
    char badval[100];
    sprintf(badval, "Invalid Value: %f", len);
    throw NegativeNumberException(badval);
  }
}
