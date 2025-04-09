//============================================================================
// Name        : Pointers003.cpp
// Author      : Don Spickler
// Version     : 3/25/2020
// Description : Pointer Example #3: Pointers as parameters.
//============================================================================

#include <iostream>

using namespace std;

void printarray(const int *p, int sz) {
  for (int i = 0; i < sz; i++) {
    cout << *p++ << " ";
  }
  cout << endl;
}

void dec(int *p) {
  (*p)--; // Note that this is not *p--
}

int main() {
  const int size = 20;
  int A[size];

  for (int i = 0; i < size; i++) {
    A[i] = i * i - 50;
  }

  printarray(A, size);

  int x = 15;
  cout << x << endl;
  dec(&x);
  cout << x << endl;

  return 0;
}
