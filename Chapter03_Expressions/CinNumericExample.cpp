//============================================================================
// Name        : CinNumericExample.cpp
// Author      : Don Spickler
// Version     : 1/30/2020
// Description : Examples of using cin for numeric input.
//============================================================================

#include <iostream>
using namespace std;

int main() {
  int x, y, z;
  double a, b, c;

  cout << "Input integer x: ";
  cin >> x;
  cout << "Input integer y: ";
  cin >> y;
  cout << "Input integer z: ";
  cin >> z;
  cout << x << " " << y << " " << z << endl;
  cout << endl;

  cout << "Input integers x, y, and z." << endl;
  cin >> x >> y >> z;
  cout << x << " " << y << " " << z << endl;
  cout << endl;

  cout << "Input integers x, decimal a, and integer z." << endl;
  cin >> x >> a >> z;
  cout << x << " " << a << " " << z << endl;
  cout << endl;

  return 0;
}
