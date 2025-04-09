//============================================================================
// Name        : DataTypesConstants.cpp
// Author      : Don Spickler
// Version     : 1/26/2020
// Description : Constants
//============================================================================

#include <iostream>
using namespace std;

int main() {
  const int dozen = 12;
  const int DOZEN = 12; // All caps alerts the programmer to a constant value,
                        // good C++ programming style.
  const double PI = 3.141592653589793;

  cout << "Three dozen is " << 3 * dozen << endl;
  cout << "Three dozen is " << 3 * DOZEN << endl;
  //	dozen = 13;  //  error: assignment of read-only variable ‘dozen’

  double r = 7;
  cout << "Circumference is " << 2 * PI * r << endl;

  return 0;
}
