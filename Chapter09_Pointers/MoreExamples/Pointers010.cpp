//============================================================================
// Name        : Pointers010.cpp
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

unique_ptr<int[]> CreateArray(int size) {
  if (size <= 0)
    return nullptr;

  unique_ptr<int[]> Arr(new int[size]);

  //*
  for (long i = 0; i < size; i++)
    Arr[i] = rand();
  // */

  return Arr;
}

void printarray(const unique_ptr<int[]> &p, int sz) {
  for (int i = 0; i < sz; i++) {
    cout << p[i] << " ";
  }
  cout << endl;
}

int main() {
  srand(time(0));

  long size = 0;
  cout << "Array size = ";
  cin >> size;

  unique_ptr<int[]> A;
  A = CreateArray(size);
  printarray(A, size);
  A = CreateArray(size);
  printarray(A, size);

  return 0;
}
