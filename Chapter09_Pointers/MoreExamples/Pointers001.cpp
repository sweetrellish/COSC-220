//============================================================================
// Name        : Pointers001.cpp
// Author      : Don Spickler
// Version     : 3/25/2020
// Description : Pointer Example #1
//============================================================================

#include <iostream>

using namespace std;

int main() {
  int x = 25;
  int *ptr = nullptr;
  cout << "The value of ptr is " << ptr << endl;

  ptr = &x;
  cout << "The value in x is " << x << endl;
  cout << "The address of x is " << ptr << endl;
  cout << "The value in x is " << *ptr << endl;
  cout << "The address of x is " << &x << endl;
  cout << endl;

  x = 37;

  cout << "The value in x is " << x << endl;
  cout << "The address of x is " << ptr << endl;
  cout << "The value in x is " << *ptr << endl;
  cout << "The address of x is " << &x << endl;
  cout << endl;

  *ptr = 123;

  cout << "The value in x is " << x << endl;
  cout << "The address of x is " << ptr << endl;
  cout << "The value in x is " << *ptr << endl;
  cout << "The address of x is " << &x << endl;
  cout << endl;

  //  ptr = 0x123456789; //  Not valid.

  int y = 72;
  int z = 45;

  cout << x << " " << y << " " << z << endl;

  ptr = &y;
  *ptr = *ptr - 13;

  ptr = &z;
  *ptr = *ptr + 25;

  x -= *ptr;

  cout << x << " " << y << " " << z << endl;

  return 0;
}
