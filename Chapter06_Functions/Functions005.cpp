//============================================================================
// Name        : Functions005.cpp
// Author      : Don Spickler
// Version     : 2/9/2020
// Description : Like Java, values are sent through parameters by position.
//============================================================================

#include <cmath>
#include <iostream>

using namespace std;

void displayPower(double, double);

int main() {
  double x = 0, y = 0;

  cout << "Input base: ";
  cin >> x;
  cout << "Input exponent: ";
  cin >> y;

  displayPower(x, y);

  cout << "Done";

  return 0;
}

void displayPower(double x, double y) { cout << "x^y = " << pow(x, y) << endl; }
