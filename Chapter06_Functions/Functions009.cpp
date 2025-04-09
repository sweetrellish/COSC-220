//============================================================================
// Name        : Functions009.cpp
// Author      : Don Spickler
// Version     : 2/9/2020
// Description : Like Java, values are passed by value.
//               In C++ you can force the values to change by passing by
//               reference.  Here is why.
//============================================================================

#include <cmath>
#include <iostream>

using namespace std;

//  Passing by value.
void fct1(double x, double y) {
  cout << "In fct1" << endl;
  x = 25;
  y = -12;
  cout << x << " " << y << endl;
  cout << "Addresses: " << &x << " " << &y << endl;
}

//  Passing by reference.
void fct2(double &x, double &y) {
  cout << "In fct2" << endl;
  x = 25;
  y = -12;
  cout << x << " " << y << endl;
  cout << "Addresses: " << &x << " " << &y << endl;
}

int main() {
  double x = 0, y = 0;

  cout << "Input x: ";
  cin >> x;
  cout << "Input y: ";
  cin >> y;

  cout << "In main." << endl;
  cout << x << " " << y << endl;
  cout << "Addresses: " << &x << " " << &y << endl;

  fct1(x, y);

  cout << "Back to main." << endl;
  cout << x << " " << y << endl;

  fct2(x, y);

  cout << "Back to main." << endl;
  cout << x << " " << y << endl;

  return 0;
}
