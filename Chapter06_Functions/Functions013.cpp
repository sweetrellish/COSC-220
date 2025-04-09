//============================================================================
// Name        : Functions013.cpp
// Author      : Don Spickler
// Version     : 2/9/2020
// Description : static variables.
//============================================================================

#include <cmath>
#include <iostream>

using namespace std;

void statictest() {
  static int i = 7;
  cout << "Value of i = " << i << endl;
  i++;
}

int main() {
  for (int i = 0; i < 10; i++)
    statictest();

  return 0;
}
