//============================================================================
// Name        : Pointers004.cpp
// Author      : Don Spickler
// Version     : 3/25/2020
// Description : Pointer Example #4: Dynamic memory allocation.
//============================================================================

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
  srand(time(0));

  long size = 0;
  cout << "Array size = ";
  cin >> size;

  int *A = new int[size];

  int *t = new int;
  *t = 5;
  cout << t << "  " << *t << endl;

  for (long i = 0; i < size; i++)
    A[i] = rand();

  long long sum = 0;
  for (long i = 0; i < size; i++)
    sum += A[i];

  cout << "Sum = " << sum << endl;

  delete[] A;  // Clear the memory set aside for A.
  A = nullptr; // Have A point to nothing.

  delete t;
  t = nullptr;

  return 0;
}
