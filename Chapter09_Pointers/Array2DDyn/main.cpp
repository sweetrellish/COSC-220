#include <iostream>

using namespace std;

int **create2Darray(int rows, int cols) {
  int **A = new int *[rows];
  for (int i = 0; i < rows; i++)
    A[i] = new int[cols];

  return A;
}

void delete2Darray(int **A, int rows) {
  for (int i = 0; i < rows; i++)
    delete[] A[i];
  delete[] A;
  A = nullptr;
}

void print2Darray(int **A, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      cout << A[i][j] << " ";

    cout << endl;
  }
}

int main() {
  int **Arr = create2Darray(3, 5);

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 5; j++)
      Arr[i][j] = i + j + 1;

  print2Darray(Arr, 3, 5);
  delete2Darray(Arr, 3);

  return 0;
}
