//============================================================================
// Name        : DataTypeBool.cpp
// Author      : Don Spickler
// Version     : 1/26/2020
// Description : Boolean data types.
//============================================================================

#include <iostream>
using namespace std;

int main() {
  bool b1;
  bool b2;

  b1 = true;
  b2 = false;

  cout << b1 << "  " << b2 << endl;

  cout << (b1 && b2) << endl;
  cout << (b1 || b2) << endl;
  cout << b1 << "  " << !b1 << endl;
  cout << endl;

  int i = b1;
  cout << i << endl;
  cout << endl;

  b1 = 1;
  b2 = 0;

  cout << b1 << "  " << b2 << endl;

  cout << (b1 && b2) << endl;
  cout << (b1 || b2) << endl;
  cout << b1 << "  " << !b1 << endl;
  cout << endl;

  cout << (1 && 0) << endl;
  cout << (1 || 0) << endl;
  cout << 1 << "  " << !1 << endl;
  cout << endl;

  i = 5;
  cout << (3 < 5) << endl;
  cout << (4 >= -3) << endl;
  cout << !(4 >= -3) << endl;
  cout << (i == 5) << endl;
  cout << endl;

  cout << 5 << endl;
  cout << !5 << endl;
  cout << !!5 << endl;

  return 0;
}
