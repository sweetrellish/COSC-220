//============================================================================
// Name        : Ch09_Ex08.cpp
// Author      : Don Spickler
// Version     : 1.1
// Description : Syntax Example #8 for Chapter 9 on Pointers
// Note        : This is a combination of examples from the text with some
//               minor changes.
//============================================================================

#include <iostream>
#include <memory>

using namespace std;

int main() {
  unique_ptr<int> ptr(new int);
  *ptr = 99;
  cout << *ptr << endl;

  int max;
  cout << "How many numbers do you want: ";
  cin >> max;

  unique_ptr<int[]> arrptr(new int[max]);

  for (int count = 0; count < max; count++)
    arrptr[count] = rand();

  for (int index = 0; index < max; index++)
    cout << arrptr[index] << " ";
  cout << endl;

  return 0;
}
