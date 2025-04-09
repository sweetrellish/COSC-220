//============================================================================
// Name        : Functions011.cpp
// Author      : Don Spickler
// Version     : 2/9/2020
// Description : Passing by reference can be convenient but sometimes risky.
//============================================================================

#include <cmath>
#include <iostream>

using namespace std;

void swap(int &, int &);

int main() {
  int x = 0, y = 0;

  cout << "Input x: ";
  cin >> x;
  cout << "Input y: ";
  cin >> y;

  cout << "In main." << endl;
  cout << x << " " << y << endl;

  swap(x, y);

  cout << "Back to main." << endl;
  cout << x << " " << y << endl;

  return 0;
}

void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}
