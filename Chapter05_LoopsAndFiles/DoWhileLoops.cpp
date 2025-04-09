//============================================================================
// Name        : DoWhileLoops.cpp
// Author      : Don Spickler
// Version     : 2/1/2020
// Description : Do While loop examples.
//============================================================================

#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int chartbegin, chartend;

  do {
    cout << "Input starting value (>= 0): ";
    cin >> chartbegin;
    if (chartbegin < 0)
      cout << "Invalid value. ";
  } while (chartbegin < 0);

  do {
    cout << "Input ending value (> " << chartbegin << "): ";
    cin >> chartend;
    if (chartend < chartbegin)
      cout << "Invalid value. ";
  } while (chartend < chartbegin);

  int i = chartbegin;
  while (i <= chartend) {
    cout << i << "  " << pow(i, 1.0 / 3.0) << endl;
    i++;
  }

  return 0;
}
