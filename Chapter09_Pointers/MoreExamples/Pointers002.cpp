//============================================================================
// Name        : Pointers002.cpp
// Author      : Don Spickler
// Version     : 3/25/2020
// Description : Pointer Example #2: Using them to move around an array and
//                                   the array name is a pointer as well.
//============================================================================

#include <iostream>

using namespace std;

void printarray(const int A[], int sz) {
  for (int i = 0; i < sz; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
}

int main() {
  const int size = 20;
  int A[size];
  int *ptr = nullptr;

  for (int i = 0; i < size; i++) {
    A[i] = i * i - 50;
  }

  printarray(A, size);

  cout << A << endl;
  cout << &A[0] << endl;
  cout << &A[1] << endl;
  cout << &A[2] << endl;
  cout << &A[3] << endl;
  cout << endl;

  cout << *A << endl;
  cout << *(A + 1) << endl;
  cout << *(A + 2) << endl;
  cout << *(A + 3) << endl;
  cout << endl;

  ptr = A;
  for (int i = 0; i < size; i++) {
    cout << *(A + i) << endl;
  }
  cout << endl;

  ptr = A;
  cout << *ptr << endl;
  ptr++;
  cout << *ptr << endl;
  ptr += 4;
  cout << *ptr << endl;
  ptr--;
  cout << *ptr << endl;

  cout << endl;
  ptr = A;
  while (ptr < &A[size]) {
    cout << *ptr++ << endl;
  }
  cout << endl;

  ptr = A;
  cout << ptr[0] << endl;
  cout << ptr[1] << endl;
  cout << ptr[2] << endl;
  cout << ptr[3] << endl;
  cout << *(ptr + 3) << endl;

  return 0;
}
