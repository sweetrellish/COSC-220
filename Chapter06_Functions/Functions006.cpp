//============================================================================
// Name        : Functions006.cpp
// Author      : Don Spickler
// Version     : 2/9/2020
// Description : Like Java, values are sent back through returns.
//============================================================================

#include <cmath>
#include <iostream>

using namespace std;

double Power(double, double);

int main() {
  double x = 0, y = 0;

  cout << "Input base: ";
  cin >> x;
  cout << "Input exponent: ";
  cin >> y;

  cout << "x^y = " << Power(x, y) << endl;

  return 0;
}

double Power(double x, double y) { return pow(x, y); }
