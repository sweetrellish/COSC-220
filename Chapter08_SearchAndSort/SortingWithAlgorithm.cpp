//============================================================================
// Name        : SortingWithAlgorithm.cpp
// Author      : Don Spickler
// Version     : 3/3/2020
// Description : Sorting Algorithms using the algorithm library.
//============================================================================

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int> &vec, bool newline = false);
void printArray(int array[], int size, bool newline = false);

int main() {
  srand(time(0));

  int size = rand() % 21 + 5;

  vector<int> A;
  for (int i = 0; i < size; i++) {
    A.push_back(rand() % 200);
  }

  cout << "Vectors" << endl;
  cout << "-------" << endl;

  cout << "Vector A" << endl;
  printVector(A);
  cout << endl;

  sort(A.begin(), A.end());
  cout << "Vector A Sorted" << endl;
  printVector(A);
  cout << endl;

  reverse(A.begin(), A.end());
  cout << "Vector A Reversed" << endl;
  printVector(A);
  cout << endl;
  cout << endl;

  vector<int> B;
  B = A;

  cout << "Vectors A and B" << endl;
  printVector(A);
  cout << endl;
  printVector(B);
  cout << endl;
  cout << endl;

  random_shuffle(A.begin(), A.end());
  cout << "Vectors A (shuffled) and B" << endl;
  printVector(A);
  cout << endl;
  printVector(B);
  cout << endl;
  cout << endl;

  cout << "Arrays" << endl;
  cout << "------" << endl;

  int Arr[size];
  for (int i = 0; i < size; i++) {
    Arr[i] = rand() % 200;
  }

  cout << "Array Arr" << endl;
  printArray(Arr, size);
  cout << endl;

  cout << "Array Arr Sorted" << endl;
  sort(Arr, Arr + size);
  printArray(Arr, size);
  cout << endl;

  cout << "Array Arr Reversed" << endl;
  reverse(Arr, Arr + size);
  printArray(Arr, size);
  cout << endl;

  cout << "Array Arr Shuffled" << endl;
  random_shuffle(Arr, Arr + size);
  printArray(Arr, size);
  cout << endl;

  return 0;
}

void printVector(const vector<int> &vec, bool newline) {
  for (unsigned int i = 0; i < vec.size(); i++) {
    cout << vec[i];
    if (newline)
      cout << endl;
    else
      cout << "  ";
  }
}

void printArray(int array[], int size, bool newline) {
  for (int i = 0; i < size; i++) {
    cout << array[i];
    if (newline)
      cout << endl;
    else
      cout << "  ";
  }
}
