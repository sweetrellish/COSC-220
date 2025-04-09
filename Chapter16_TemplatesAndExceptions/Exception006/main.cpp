// This program demonstrates Rectangle class exceptions.
#include <iostream>

#include "Exceptions.h"
#include "Rectangle.h"

using namespace std;

// Function prototype
double divide(int, int);

int main() {
  int width;
  int length;
  int num1, num2;  // To hold two numbers
  double quotient; // To hold the quotient of the numbers

  // Create a Rectangle object.
  Rectangle myRectangle;

  // Get the width and length.
  cout << "Enter the rectangle's width: ";
  cin >> width;
  cout << "Enter the rectangle's length: ";
  cin >> length;

  // Store these values in the Rectangle object.
  try {
    myRectangle.setWidth(width);
    myRectangle.setLength(length);
    cout << "The area of the rectangle is " << myRectangle.getArea() << endl;
  } catch (NegativeNumberException &e) {
    cout << "Error: " << e.message() << endl;
  }

  // Get two numbers.
  cout << "Enter two numbers: ";
  cin >> num1 >> num2;

  // Divide num1 by num2 and catch any
  // potential exceptions.
  try {
    quotient = divide(num1, num2);
    cout << "The quotient is " << quotient << endl;
  } catch (DivisionByZeroException &e) {
    cout << "Error: " << e.message() << endl;
  }

  cout << "End of the program.\n";
  return 0;
}

double divide(int numerator, int denominator) {
  if (denominator == 0)
    throw DivisionByZeroException("ERROR: Cannot divide by zero.");

  return static_cast<double>(numerator) / denominator;
}
