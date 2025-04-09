//============================================================================
// Name        : Functions012.cpp
// Author      : Don Spickler
// Version     : 2/9/2020
// Description : Global variables are very risky. Global constants are okay.
//============================================================================

#include <cmath>
#include <iostream>

using namespace std;

int x = 0, y = 0;
const double PI = 3.141592653589793;

void swap() {
  int temp = x;
  x = y;
  y = temp;
}

int main() {
  // int x = 0, y = 0;

  cout << "Input x: ";
  cin >> x;
  cout << "Input y: ";
  cin >> y;

  cout << "In main." << endl;
  cout << x << " " << y << endl;

  swap();

  cout << "Back to main." << endl;
  cout << x << " " << y << endl;

  return 0;
}
