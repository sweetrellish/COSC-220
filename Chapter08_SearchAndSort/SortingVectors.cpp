//============================================================================
// Name        : SortingVectors.cpp
// Author      : Don Spickler
// Version     : 3/3/2020
// Description : Sorting Algorithms
//============================================================================

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void swap(int &, int &);
void bubbleSort(vector<int> &);
void selectionSort(vector<int> &);
void insertionSort(vector<int> &);
void printVector(const vector<int> &vec, bool newline = false);

int main() {
  srand(time(0));

  int size = rand() % 21 + 5;

  vector<int> A;
  for (int i = 0; i < size; i++) {
    A.push_back(rand() % 200);
  }

  printVector(A);
  cout << endl;

  bubbleSort(A);
  // selectionSort(A|);
  // insertionSort(A);

  printVector(A);
  cout << endl;

  return 0;
}

void bubbleSort(vector<int> &vec) {
  int maxElement;
  int index;

  for (maxElement = vec.size() - 1; maxElement > 0; maxElement--)
    for (index = 0; index < maxElement; index++)
      if (vec[index] > vec[index + 1])
        swap(vec[index], vec[index + 1]);
}

void selectionSort(vector<int> &vec) {
  int minIndex, minValue;

  for (unsigned int start = 0; start < (vec.size() - 1); start++) {
    minIndex = start;
    minValue = vec[start];
    for (unsigned int index = start + 1; index < vec.size(); index++) {
      if (vec[index] < minValue) {
        minValue = vec[index];
        minIndex = index;
      }
    }
    swap(vec[minIndex], vec[start]);
  }
}

void insertionSort(vector<int> &vec) {
  for (unsigned int itemsSorted = 1; itemsSorted < vec.size(); itemsSorted++) {
    int temp = vec[itemsSorted];
    int loc = itemsSorted - 1;
    while (loc >= 0 && vec[loc] > temp) {
      vec[loc + 1] = vec[loc];
      loc = loc - 1;
    }
    vec[loc + 1] = temp;
  }
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
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
