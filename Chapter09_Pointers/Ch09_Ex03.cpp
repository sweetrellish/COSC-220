//============================================================================
// Name        : Ch09_Ex03.cpp
// Author      : Don Spickler
// Version     : 1.1
// Description : Syntax Example #3 for Chapter 9 on Pointers
// Note        : This is a combination of examples from the text with some
//               minor changes.
//============================================================================

#include <iostream>

using namespace std;

void getNumber(int *);
void doubleValue(int *);

int main() {
  int number;
  getNumber(&number);
  doubleValue(&number);
  cout << "That value doubled is " << number << endl;
  return 0;
}

void getNumber(int *input) {
  cout << "Enter an integer number: ";
  cin >> *input;
}

void doubleValue(int *val) { *val *= 2; }
