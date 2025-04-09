//============================================================================
// Name        : Pointers005.cpp
// Author      : Don Spickler
// Version     : 3/25/2020
// Description : Pointer Example #5: Dynamic memory allocation.
//============================================================================

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int *CreateArray(int size) {
  if (size <= 0)
    return nullptr;

  int *Arr = new int[size];

  for (long i = 0; i < size; i++)
    Arr[i] = rand();

  return Arr;
}

void printarray(const int *p, int sz) {
  for (int i = 0; i < sz; i++) {
    cout << *p++ << " ";
  }
  cout << endl;
}

int main() {
  srand(time(0));

  long size = 0;
  cout << "Array size = ";
  cin >> size;

  int *A = CreateArray(size);
  printarray(A, size);

  long long sum = 0;
  for (long i = 0; i < size; i++)
    sum += A[i];

  cout << "Sum = " << sum << endl;

  delete[] A;  // Clear the memory set aside for A.
  A = nullptr; // Have A point to nothing.

  return 0;
}
