//============================================================================
// Name        : Functions014.cpp
// Author      : Don Spickler
// Version     : 2/9/2020
// Description : Function overloading: Just like in Java you can overload
//               a function, use the same name, as long as the parameter
//               lists are different.
//============================================================================

#include <iostream>

using namespace std;

void swap(int &, int &);
void swap(double &, double &);

int main() {
  int x = 5, y = 7;
  double a = 3.14, b = 2.718;

  cout << x << " " << y << endl;
  cout << a << " " << b << endl;

  swap(x, y);

  cout << x << " " << y << endl;
  cout << a << " " << b << endl;

  swap(a, b);

  cout << x << " " << y << endl;
  cout << a << " " << b << endl;

  return 0;
}

void swap(int &x, int &y) {
  cout << "Integers" << endl;
  int temp = x;
  x = y;
  y = temp;
}

void swap(double &x, double &y) {
  cout << "Doubles" << endl;
  double temp = x;
  x = y;
  y = temp;
}
