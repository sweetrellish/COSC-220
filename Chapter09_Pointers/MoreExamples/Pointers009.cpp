//============================================================================
// Name        : Pointers009.cpp
// Author      : Don Spickler
// Version     : 3/25/2020
// Description : Pointer Example #6: Smart pointers to avoid memory leaks.
//============================================================================

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>

using namespace std;

int main() {
  srand(time(0));

  long size = 0;
  cout << "Array size = ";
  cin >> size;

  unique_ptr<int[]> A(new int[size]);

  for (long i = 0; i < size; i++)
    A[i] = rand();

  for (int i = 0; i < size; i++) {
    cout << A[i] << " ";
  }
  cout << endl;

  // Notice no delete is used.

  return 0;
}
