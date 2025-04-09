//============================================================================
// Name        : DataTypesInteger.cpp
// Author      : Don Spickler
// Version     : 1/26/2020
// Description : Integer data types.
//============================================================================

#include <iostream>
using namespace std;

int main() {
  short a = 34;
  unsigned short b = 34;
  int c = -12345;
  unsigned int d = 23;
  long e = -672914673;
  unsigned long f = 32324534;
  long long g = 73191153429473947;
  unsigned long long h = 1234567890;

  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  cout << d << endl;
  cout << e << endl;
  cout << f << endl;
  cout << g << endl;
  cout << h << endl;
  cout << endl;

  c = e;
  h = g;

  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  cout << d << endl;
  cout << e << endl;
  cout << f << endl;
  cout << g << endl;
  cout << h << endl;

  int x, y, z;
  cout << x << " " << y << " " << z << endl;
  x = y = z = 10;
  cout << x << " " << y << " " << z << endl;
  cout << (x = 3) << endl;
  y = 7;
  cout << x << " " << y << " " << z << endl;
  cout << endl;

  cout << x + y << endl;
  cout << x - y << endl;
  cout << x * y << endl;
  cout << y / x << endl;
  cout << y % x << endl;
  cout << endl;

  cout << x << " " << y << " " << z << endl;
  x++;
  --y;
  z *= 3;
  cout << x << " " << y << " " << z << endl;
  cout << x++ << " " << --y << " " << ++z << endl;
  cout << x << " " << y << " " << z << endl;

  return 0;
}
