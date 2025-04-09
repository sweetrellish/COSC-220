//============================================================================
// Name        : Arrays002.cpp
// Author      : Don Spickler
// Version     : 2/16/2020
// Description : Array Example #2.  Accessing and loading.
//============================================================================

#include <cmath>   // Math functions
#include <cstdlib> // For rand and srand
#include <ctime>   // For the time function
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  srand(time(0));
  int size = 0;

  cout << "Input the array size: ";
  cin >> size;
  int A[size];

  for (int i = 0; i < size; i++) {
    cout << "Enter element " << (i + 1) << ": ";
    cin >> A[i];
  }
  cout << endl;

  for (auto val : A)
    cout << val << "  ";
  cout << endl;

  int count = 1;
  for (auto &val : A) {
    cout << "Enter element " << count++ << ": ";
    cin >> val;
  }

  for (auto val : A)
    cout << val << "  ";
  cout << endl;

  return 0;
}
