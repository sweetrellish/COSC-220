//============================================================================
// Name        : Functions007.cpp
// Author      : Don Spickler
// Version     : 2/9/2020
// Description : Like Java, values are passed by value.
//               In C++ you can force the values to change by passing by
//               reference.
//============================================================================

#include <cmath>
#include <iostream>

using namespace std;

//  Passing by value.
void fct(double x, double y) {
  cout << "In fct" << endl;
  x = 25;
  y = -12;
  cout << x << " " << y << endl;
}

int main() {
  double x = 0, y = 0;

  cout << "Input x: ";
  cin >> x;
  cout << "Input y: ";
  cin >> y;

  cout << "In main." << endl;
  cout << x << " " << y << endl;

  fct(x, y);

  cout << "Back to main." << endl;
  cout << x << " " << y << endl;

  return 0;
}
