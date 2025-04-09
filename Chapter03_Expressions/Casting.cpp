//============================================================================
// Name        : Casting.cpp
// Author      : Don Spickler
// Version     : 1/30/2020
// Description : Casting in C++
//============================================================================

#include <iostream>

using namespace std;

int main() {
  cout << (4 / 3) << endl;
  cout << (4.0 / 3) << endl;
  cout << (4 / 3.0) << endl;
  cout << (4.0 / 3.0) << endl;
  cout << endl;

  int a = 4, b = 3;
  cout << (a / b) << endl;
  cout << (1.0 * a / b) << endl;
  cout << ((double)a / b)
       << endl; // C style cast, Okay but not the best for C++ applications.
  cout << (static_cast<double>(a) / b) << endl; // C++ style cast.
  cout << (a / static_cast<double>(b)) << endl; // C++ style cast.
  cout << (static_cast<double>(a) / static_cast<double>(b))
       << endl; // C++ style cast.

  return 0;
}
