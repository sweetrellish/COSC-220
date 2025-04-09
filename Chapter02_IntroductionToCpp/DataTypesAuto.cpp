//============================================================================
// Name        : DataTypesAuto.cpp
// Author      : Don Spickler
// Version     : 1/26/2020
// Description : The auto data type, C++ 11.
//============================================================================

#include <iostream>
using namespace std;

int main() {
  auto x = 5;
  cout << x << endl;
  x = 4.7;
  cout << x << endl;
  cout << endl;

  auto y = 15.936;
  cout << y << endl;
  y = 8;
  cout << y << endl;
  y = 45.9;
  cout << y << endl;
  cout << endl;

  auto t = "Hello There.";
  cout << t << endl;
  t = "Go home.";
  cout << t << endl;

  return 0;
}
