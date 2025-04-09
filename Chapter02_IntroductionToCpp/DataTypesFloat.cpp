//============================================================================
// Name        : DataTypesFloat.cpp
// Author      : Don Spickler
// Version     : 1/26/2020
// Description : Float data types.
//============================================================================

#include <iostream>
using namespace std;

int main() {
  float a = 23.45;
  double b = 732189.241415;
  long double c = 738764332189.244582935721415;
  long double d = 189.244582935721415;

  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  cout << d << endl;
  cout << endl;

  b = a;

  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  cout << d << endl;
  cout << endl;

  b = d;

  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  cout << d << endl;
  cout << endl;

  double x, y, z;
  cout << x << " " << y << " " << z << endl;
  x = y = z = 10.123;
  cout << x << " " << y << " " << z << endl;
  cout << (x = 3.6) << endl;
  y = 7.9;
  cout << x << " " << y << " " << z << endl;
  cout << endl;

  cout << x + y << endl;
  cout << x - y << endl;
  cout << x * y << endl;
  cout << y / x << endl;
  //	cout << y % x << endl;  // Error in C++
  cout << endl;

  cout << x << " " << y << " " << z << endl;
  x--;
  ++y;
  z++;
  cout << x << " " << y << " " << z << endl;
  cout << --x << " " << ++y << " " << z++ << endl;
  cout << x << " " << y << " " << z << endl;

  return 0;
}
