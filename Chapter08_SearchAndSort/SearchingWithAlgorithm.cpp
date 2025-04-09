//============================================================================
// Name        : SearchingWithAlgorithm.cpp
// Author      : Don Spickler
// Version     : 3/3/2020
// Description : Searching Algorithms using the algorithm library.
//============================================================================

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

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

  int *posadd = find(Arr, Arr + size, target);
  int pos = posadd - Arr;
  cout << pos << endl;

  if (pos < size)
    cout << target << " found in the array at position " << pos << "." << endl;
  else
    cout << target << " not found in the array." << endl;

  vector<int>::iterator vposadd = find(A.begin(), A.end(), target);
  unsigned int vecpos = vposadd - A.begin();
  cout << vecpos << endl;

  if (vecpos < A.size())
    cout << target << " found in the vector at position " << vecpos << "."
         << endl;
  else
    cout << target << " not found in the vector." << endl;

  cout << endl;
  cout << "Sort Containers" << endl;
  cout << endl;

  sort(A.begin(), A.end());
  sort(Arr, Arr + size);

  cout << "Array: ";
  printArray(Arr, size);
  cout << endl;

  cout << "Vector: ";
  printVector(A);
  cout << endl;

  posadd = find(Arr, Arr + size, target);
  pos = posadd - Arr;
  cout << pos << endl;

  if (pos < size)
    cout << target << " found in the array at position " << pos << "." << endl;
  else
    cout << target << " not found in the array." << endl;

  vposadd = find(A.begin(), A.end(), target);
  vecpos = vposadd - A.begin();
  cout << vecpos << endl;

  if (vecpos < A.size())
    cout << target << " found in the vector at position " << vecpos << "."
         << endl;
  else
    cout << target << " not found in the vector." << endl;

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
