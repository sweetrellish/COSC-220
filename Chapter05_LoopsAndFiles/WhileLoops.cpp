//============================================================================
// Name        : WhileLoops.cpp
// Author      : Don Spickler
// Version     : 2/1/2020
// Description : While loop examples.
//============================================================================

#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int chartbegin, chartend;

  cout << "Input starting value (>= 0): ";
  cin >> chartbegin;

  while (chartbegin < 0) {
    cout << "Invalid value, input starting value (>= 0): ";
    cin >> chartbegin;
  }

  cout << "Input ending value (> " << chartbegin << "): ";
  cin >> chartend;

  while (chartend < chartbegin) {
    cout << "Invalid value, input ending value (> " << chartbegin << "): ";
    cin >> chartend;
  }

  int i = chartbegin;
  while (i <= chartend) {
    cout << i << "  " << pow(i, 1.0 / 3.0) << endl;
    i++;
  }

  return 0;
}
