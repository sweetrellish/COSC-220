//============================================================================
// Name        : Arrays001.cpp
// Author      : Don Spickler
// Version     : 2/16/2020
// Description : Array Example #1.  Declaring and initializing.
//============================================================================

#include <cmath>   // Math functions
#include <cstdlib> // For rand and srand
#include <ctime>   // For the time function
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int size = 10;
  int inputsize = 0;
  int A[size];
  int B[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int C[size] = {1, 2, 3};
  double D[size] = {0};
  string E[size] = {"Hello World"};
  int G[] = {1, 2, 3};

  srand(time(0));

  cout << "Input the array size: ";
  cin >> inputsize;
  int F[inputsize];

  for (int i = 0; i < inputsize; i++)
    F[i] = rand();

  for (int i = 0; i < size; i++)
    cout << A[i] << "  ";
  cout << endl;

  for (int i = 0; i < size; i++)
    cout << B[i] << "  ";
  cout << endl;

  for (int i = 0; i < size; i++)
    cout << C[i] << "  ";
  cout << endl;

  for (int i = 0; i < size; i++)
    cout << D[i] << "  ";
  cout << endl;

  for (int i = 0; i < size; i++)
    cout << E[i] << "  ";
  cout << endl;

  for (int i = 0; i < inputsize; i++)
    cout << F[i] << "  ";
  cout << endl;

  for (int val : A)
    cout << val << "  ";
  cout << endl;

  for (auto val : B)
    cout << val << "  ";
  cout << endl;

  for (auto val : F)
    cout << val << "  ";
  cout << endl;

  for (auto val : G)
    cout << val << "  ";
  cout << endl;

  cout << sizeof(A) << endl;
  cout << sizeof(A) / sizeof(int) << endl;

  cout << A << endl;
  cout << A + 1 << endl;
  cout << A + 2 << endl;

  return 0;
}
