//============================================================================
// Name        : Functions015.cpp
// Author      : Don Spickler
// Version     : 2/9/2020
// Description : Default arguments.
//============================================================================

#include <iostream>

using namespace std;

void fct(int x = 3, double y = 2.7, string s = "COSC 120");

int main() {
  fct(1, 2.5, "Cannot wait until COSC 220.");
  fct(8, 14.723);
  fct(205);
  fct();

  return 0;
}

void fct(int x, double y, string s) {
  cout << x << " " << y << " " << s << endl;
}
