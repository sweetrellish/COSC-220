//============================================================================
// Name        : Pointers006.cpp
// Author      : Don Spickler
// Version     : 3/25/2020
// Description : Pointer Example #6: Memory Leaks
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

  /*
  for (long i = 0; i < size; i++)
          Arr[i] = rand();
  // */

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

  int *A = nullptr;

  A = CreateArray(size);
  // printarray(A, size);
  A = CreateArray(size);
  // printarray(A, size);

  /*
  for (int i = 0; i < 10; i++)
          A = CreateArray(size);
  // */

  delete[] A;  // Clear the memory set aside for A.
  A = nullptr; // Have A point to nothing.

  cout << "Done" << endl;

  return 0;
}
