//============================================================================
// Name        : SortingArrays.cpp
// Author      : Don Spickler
// Version     : 3/3/2020
// Description : Sorting Algorithms
//============================================================================

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void swap(int &, int &);
void bubbleSort(int[], int);
void selectionSort(int[], int);
void insertionSort(int[], int);
void printArray(int array[], int size, bool newline = false);

int main() {
  srand(time(0));

  int size = rand() % 21 + 5;

  int A[size];
  for (int i = 0; i < size; i++) {
    A[i] = rand() % 200;
  }

  printArray(A, size);
  cout << endl;

  // bubbleSort(A, size);
  // selectionSort(A, size);
  insertionSort(A, size);

  printArray(A, size);
  cout << endl;

  return 0;
}

void bubbleSort(int array[], int size) {
  int maxElement;
  int index;

  for (maxElement = size - 1; maxElement > 0; maxElement--)
    for (index = 0; index < maxElement; index++)
      if (array[index] > array[index + 1])
        swap(array[index], array[index + 1]);
}

void selectionSort(int array[], int size) {
  int minIndex, minValue;

  for (int start = 0; start < (size - 1); start++) {
    minIndex = start;
    minValue = array[start];
    for (int index = start + 1; index < size; index++) {
      if (array[index] < minValue) {
        minValue = array[index];
        minIndex = index;
      }
    }
    swap(array[minIndex], array[start]);
  }
}

void insertionSort(int array[], int size) {
  for (int itemsSorted = 1; itemsSorted < size; itemsSorted++) {
    int temp = array[itemsSorted];
    int loc = itemsSorted - 1;
    while (loc >= 0 && array[loc] > temp) {
      array[loc + 1] = array[loc];
      loc = loc - 1;
    }
    array[loc + 1] = temp;
  }
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
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
