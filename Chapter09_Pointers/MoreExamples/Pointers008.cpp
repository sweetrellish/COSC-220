//============================================================================
// Name        : Pointers008.cpp
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
    Arr[i] = i;

  return Arr;
}

void printarray(const int *p, int sz) {
  for (int i = 0; i < sz; i++) {
    cout << *p++ << " ";
  }
  cout << endl;
}

int *duplicateArray(const int *arr, int size) {
  int *newArray = nullptr;

  if (size <= 0)
    return nullptr;

  newArray = new int[size];
  for (int index = 0; index < size; index++)
    newArray[index] = arr[index];

  return newArray;
}

int main() {
  srand(time(0));

  long size = 0;
  cout << "Array size = ";
  cin >> size;

  int *A = CreateArray(size);
  printarray(A, size);

  int *B = A;
  printarray(B, size);
  cout << A << " " << B << endl;
  cout << endl;

  B[3] = 12345;
  printarray(A, size);
  printarray(B, size);
  cout << A << " " << B << endl;
  cout << endl;

  B = duplicateArray(A, size);
  B[3] = 17;
  printarray(A, size);
  printarray(B, size);
  cout << A << " " << B << endl;

  delete[] A;
  delete[] B;
  A = nullptr;
  B = nullptr;

  return 0;
}
