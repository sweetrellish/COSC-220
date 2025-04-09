//============================================================================
// Name        : Arrays004.cpp
// Author      : Don Spickler
// Version     : 2/16/2020
// Description : Array Example #4.  No bounds checking.
//============================================================================

#include <iostream>

using namespace std;

int main() {
  int size = 10;
  int A[size];

  //  Populate array.
  for (int i = 0; i < size; i++)
    A[i] = i;

  //  Print array going too far.
  for (int i = 0; i < 20; i++)
    cout << A[i] << " ";

  cout << endl;

  return 0;
}
