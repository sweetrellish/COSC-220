//============================================================================
// Name        : IfStatements.cpp
// Author      : Don Spickler
// Version     : 2/1/2020
// Description : If statement examples with numeric and boolean expressions.
//============================================================================

#include <iostream>

using namespace std;

int main() {
  int x, y, z;
  cout << "Input x, y, and z: ";
  cin >> x >> y >> z;

  if (x >= y) {
    cout << "x >= y" << endl;
    cout << endl;
  }

  if (x >= y)
    cout << "x >= y" << endl;

  if (x >= y)
    cout << "x >= y" << endl;
  else
    cout << "x < y" << endl;

  cout << endl;

  if (x >= y) {
    if (z > y) {
      cout << "x >= y and z > y" << endl;
    } else {
      cout << "x >= y and z <= y" << endl;
    }
  } else {
    if (z > y)
      cout << "x < y and z > y" << endl;
    else
      cout << "x < y and z <= y" << endl;
  }

  if (x >= y && z > y) {
    cout << "x >= y and z > y" << endl;
  } else if (x >= y && z <= y) {
    cout << "x >= y and z <= y" << endl;
  } else if (x < y && z > y) {
    cout << "x < y and z > y" << endl;
  } else if (x < y && z <= y) {
    cout << "x < y and z <= y" << endl;
  }

  cout << endl;

  if (3.5) {
    cout << "3.5 is true." << endl;
  } else {
    cout << "3.5 is false." << endl;
  }

  if (0) {
    cout << "0 is true." << endl;
  } else {
    cout << "0 is false." << endl;
  }

  if (0.0) {
    cout << "0.0 is true." << endl;
  } else {
    cout << "0.0 is false." << endl;
  }

  if (1E-1000) {
    cout << "1E-1000 is true." << endl;
  } else {
    cout << "1E-1000 is false." << endl;
  }

  cout << endl;

  bool b1, b2;

  b1 = x >= y;
  b2 = z > y;

  if (b1) {
    if (b2) {
      cout << "x >= y and z > y" << endl;
    } else {
      cout << "x >= y and z <= y" << endl;
    }
  } else {
    if (b2)
      cout << "x < y and z > y" << endl;
    else
      cout << "x < y and z <= y" << endl;
  }

  return 0;
}
