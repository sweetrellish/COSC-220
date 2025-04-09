//============================================================================
// Name        : Functions002.cpp
// Author      : Don Spickler
// Version     : 2/9/2020
// Description : In C++ functions must be above their call unless you use a
//               function prototype.
//============================================================================

#include <iostream>

using namespace std;

void fct1() { cout << "In function #1" << endl; }
void fct2() { cout << "In function #2" << endl; }
void fct3() { cout << "In function #3" << endl; }

void fct4() {
  cout << "In function #4" << endl;
  fct3();
  fct2();
  cout << "Leaving function #4" << endl;
}

int main() {
  cout << "In main" << endl;

  fct1();
  fct2();
  fct3();
  fct4();

  cout << "In main" << endl;

  return 0;
}
