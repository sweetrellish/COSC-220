//============================================================================
// Name        : Arrays005.cpp
// Author      : Don Spickler
// Version     : 2/16/2020
// Description : Array Example #5.  Functions
//============================================================================

#include <cmath>
#include <iostream>

using namespace std;

void PopulateArray(int[], int);
void PrintArray(const int[], int);
void PrintArray(const double[], int);
void DoubleArray(const double[], double[], int);

const double PI = 3.141592653589793;

int main() {
  int size = 10;
  int A[size];
  double B[size];

  PopulateArray(A, size);
  PrintArray(A, size);

  // Populate array with values of the sine function.
  for (int i = 0; i < size; i++)
    B[i] = sin(i * PI / 2);

  PrintArray(B, size);

  double C[size];
  DoubleArray(B, C, size);

  PrintArray(C, size);

  return 0;
}

void PopulateArray(int A[], int size) {
  for (int i = 0; i < size; i++)
    A[i] = i;
}

void PrintArray(const int A[], int size) {
  for (int i = 0; i < size; i++)
    cout << A[i] << "  ";
  cout << endl;
}

void PrintArray(const double A[], int size) {
  for (int i = 0; i < size; i++)
    cout << A[i] << "  ";
  cout << endl;
}

void DoubleArray(const double A[], double B[], int size) {
  for (int i = 0; i < size; i++)
    B[i] = 2 * A[i];
}
