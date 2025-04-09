//============================================================================
// Name        : Arrays006.cpp
// Author      : Don Spickler
// Version     : 2/16/2020
// Description : Array Example #6.  Two-Dimensional Arrays
//============================================================================

#include <iostream>

using namespace std;

int main() {
  int rows = 5;
  int cols = 7;
  int A[rows][cols];

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      A[i][j] = i + j + 1;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      cout << A[i][j] << "\t";
    cout << endl;
  }

  return 0;
}
