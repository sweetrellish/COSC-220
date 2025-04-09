//============================================================================
// Name        : Ch09_Ex04.cpp
// Author      : Don Spickler
// Version     : 1.1
// Description : Syntax Example #4 for Chapter 9 on Pointers
// Note        : This is a combination of examples from the text with some
//               minor changes.
//============================================================================

#include <iostream>

using namespace std;

void displayValues(const int *, int);
void displayValuesVar(int *, int);

int main() {
  const int SIZE = 6;
  const int array1[SIZE] = {1, 2, 3, 4, 5, 6};
  int array2[SIZE] = {2, 4, 6, 8, 10, 12};

  displayValues(array1, SIZE);
  displayValues(array2, SIZE);

  // displayValuesVar(array1, SIZE); // Error sending an array of constants to a
  // non-constant array.
  displayValuesVar(array2, SIZE);
  return 0;
}

void displayValues(const int *numbers, int size) {
  for (int count = 0; count < size; count++) {
    cout << *(numbers + count) << " ";
  }
  cout << endl;
}

void displayValuesVar(int *numbers, int size) {
  for (int count = 0; count < size; count++) {
    cout << *(numbers + count) << " ";
  }
  cout << endl;
}
