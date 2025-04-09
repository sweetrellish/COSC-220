//============================================================================
// Name        : Arrays007.cpp
// Author      : Don Spickler
// Version     : 2/16/2020
// Description : Array Example #7.  Two-Dimensional Arrays and Functions
//============================================================================

#include <iostream>

using namespace std;

const int cols = 7;

void PrintArray(const int[][cols], int);
void PopulateArray(int[][cols], int);

int main() {
  int rows = 5;
  int A[rows][cols];

  PopulateArray(A, rows);
  PrintArray(A, rows);

  return 0;
}

void PrintArray(const int A[][cols], int rows) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      cout << A[i][j] << "\t";
    cout << endl;
  }
}

void PopulateArray(int A[][cols], int rows) {
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      A[i][j] = i + j + 1;
}
