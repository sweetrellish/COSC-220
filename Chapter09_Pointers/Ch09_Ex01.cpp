//============================================================================
// Name        : Ch09_Ex01.cpp
// Author      : Don Spickler
// Version     : 1.1
// Description : Syntax Example #1 for Chapter 9 on Pointers
// Note        : This is a combination of examples from the text with some
//               minor changes.
//============================================================================

#include <iostream>

using namespace std;

void div();

int main() {
  int x = 25;

  cout << "The address of x is " << &x << endl;
  cout << "The size of x is " << sizeof(x) << " bytes\n";
  cout << "The size of the pointer to x is " << sizeof(&x) << " bytes\n";
  cout << "The value in x is " << x << endl;

  div();

  int *ptr = nullptr;

  ptr = &x;
  cout << "The value in x is " << x << endl;
  cout << "The value in x is " << *ptr << endl;
  cout << "The address of x is " << ptr << endl;

  div();

  x = 123;
  cout << "The value in x is " << x << endl;
  cout << "The value in x is " << *ptr << endl;

  div();

  *ptr = 987;
  cout << "The value in x is " << x << endl;
  cout << "The value in x is " << *ptr << endl;

  div();

  int y = 42;
  ptr = &y;

  cout << "The value in y is " << y << endl;
  cout << "The value in y is " << *ptr << endl;
  cout << "The address of x is " << ptr << endl;

  div();

  *ptr += 100;
  cout << "The value in y is " << y << endl;
  cout << "The value in y is " << *ptr << endl;

  return 0;
}

void div() { cout << "\n-----------------------------------\n\n"; }
