//============================================================================
// Name        : Ch09_Ex05.cpp
// Author      : Don Spickler
// Version     : 1.1
// Description : Syntax Example #5 for Chapter 9 on Pointers
// Note        : This is a combination of examples from the text with some
//               minor changes.
//============================================================================

#include <iostream>

using namespace std;

int main() {
  double *arr = nullptr;
  int size = 0;

  cout << "Input size of array: ";
  cin >> size;

  if (size <= 0)
    return 1;

  arr = new double[size];

  for (int count = 0; count < size; count++) {
    cout << "Enter number " << (count + 1) << ": ";
    cin >> arr[count];
  }

  double sum = 0;
  for (int count = 0; count < size; count++) {
    sum += arr[count];
  }

  cout << "Sum = " << sum << endl;

  delete[] arr;
  arr = nullptr;

  return 0;
}
