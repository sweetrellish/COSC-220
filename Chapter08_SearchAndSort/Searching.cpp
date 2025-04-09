//============================================================================
// Name        : Searching.cpp
// Author      : Don Spickler
// Version     : 3/3/2020
// Description : Searching Algorithms
//============================================================================

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int linearSearch(const int[], int, int);
int linearSearch(const vector<int> &, int);
int binarySearch(const vector<int> &v, int);
int binarySearch(const int[], int, int);

void selectionSort(vector<int> &);
void selectionSort(int[], int);
void printVector(const vector<int> &vec, bool newline = false);
void printArray(int array[], int size, bool newline = false);

int main() {
  srand(time(0));

  int target = 0;
  int size = rand() % 21 + 5;

  vector<int> A;
  for (int i = 0; i < size; i++) {
    A.push_back(rand() % 20);
  }

  int Arr[size];
  for (int i = 0; i < size; i++) {
    Arr[i] = rand() % 20;
  }

  cout << "Array: ";
  printArray(Arr, size);
  cout << endl;

  cout << "Vector: ";
  printVector(A);
  cout << endl;
  cout << endl;

  cout << "Search for: ";
  cin >> target;

  int posArr = linearSearch(Arr, size, target);
  int posVect = linearSearch(A, target);

  if (posArr > -1)
    cout << target << " found in the array at position " << posArr << "."
         << endl;
  else
    cout << target << " not found in the array." << endl;

  if (posVect > -1)
    cout << target << " found in the vector at position " << posVect << "."
         << endl;
  else
    cout << target << " not found in the vector." << endl;

  cout << endl;
  cout << "Sort the containers." << endl;
  cout << endl;

  selectionSort(A);
  selectionSort(Arr, size);

  cout << "Array: ";
  printArray(Arr, size);
  cout << endl;

  cout << "Vector: ";
  printVector(A);
  cout << endl;
  cout << endl;

  posArr = binarySearch(Arr, size, target);
  posVect = binarySearch(A, target);

  if (posArr > -1)
    cout << target << " found in the array at position " << posArr << "."
         << endl;
  else
    cout << target << " not found in the array." << endl;

  if (posVect > -1)
    cout << target << " found in the vector at position " << posVect << "."
         << endl;
  else
    cout << target << " not found in the vector." << endl;

  return 0;
}

int linearSearch(const int arr[], int size, int value) {
  int index = 0;
  while (index < size) {
    if (arr[index] == value)
      return index;
    index++;
  }
  return -1;
}

int linearSearch(const vector<int> &A, int value) {
  unsigned int index = 0;
  while (index < A.size()) {
    if (A[index] == value)
      return index;
    index++;
  }
  return -1;
}

int binarySearch(const vector<int> &v, int value) {
  int first = 0;
  int last = v.size() - 1;
  int middle = 0;

  while (first <= last) {
    middle = (first + last) / 2;
    if (v[middle] == value) {
      return middle;
    } else if (v[middle] > value)
      last = middle - 1;
    else
      first = middle + 1;
  }
  return -1;
}

int binarySearch(const int A[], int size, int value) {
  int first = 0;
  int last = size - 1;
  int middle = 0;

  while (first <= last) {
    middle = (first + last) / 2;
    if (A[middle] == value) {
      return middle;
    } else if (A[middle] > value)
      last = middle - 1;
    else
      first = middle + 1;
  }
  return -1;
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
