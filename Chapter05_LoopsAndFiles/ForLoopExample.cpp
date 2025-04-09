//============================================================================
// Name        : ForLoopExample.cpp
// Author      : Don Spickler
// Version     : 2/1/2020
// Description : For loop examples.
//============================================================================

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {

  for (int i = 0; i < 20; i++) {
    cout << i << "  " << sin(i) << endl;
  }

  cout << endl;

  cout << setprecision(10) << fixed << showpoint;
  for (double i = 0; i < 1; i += 0.1) {
    cout << setw(5) << i << "   " << setw(10) << sin(i) << endl;
  }

  cout << endl;

  for (double i = 0; i < 1;) {
    cout << setw(5) << i << "   " << setw(10) << sin(i) << endl;
    i += 0.1;
  }

  cout << endl;

  double i = 0;
  for (; i < 1;) {
    cout << setw(5) << i << "   " << setw(10) << sin(i) << endl;
    i += 0.1;
  }

  cout << endl;

  i = 0;
  for (;;) {
    cout << setw(5) << i << "   " << setw(10) << sin(i) << endl;
    i += 0.1;
    if (i > 1)
      break;
  }

  return 0;
}
