//============================================================================
// Name        : SearchingWithAlgorithm2.cpp
// Author      : Don Spickler
// Version     : 3/3/2020
// Description : Searching Algorithms using the algorithm library.
//============================================================================

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

void printVector(const vector<int> &vec, bool newline = false);
void printArray(int array[], int size, bool newline = false);
void printVector(const vector<double> &vec, bool newline = false);
void printArray(double array[], int size, bool newline = false);
void printVector(const vector<string> &vec, bool newline = false);
void printArray(string array[], int size, bool newline = false);

int main() {
  srand(time(0));

  double target = 0;
  int size = rand() % 21 + 5;

  vector<double> A;
  for (int i = 0; i < size; i++) {
    A.push_back(i + 0.5);
  }

  double Arr[size];
  for (int i = 0; i < size; i++) {
    Arr[i] = i * i + 0.5;
  }

  random_shuffle(A.begin(), A.end());
  random_shuffle(Arr, Arr + size);

  cout << "Array: ";
  printArray(Arr, size);
  cout << endl;

  cout << "Vector: ";
  printVector(A);
  cout << endl;
  cout << endl;

  cout << "Search for: ";
  cin >> target;

  double *posadd = find(Arr, Arr + size, target);
  int pos = posadd - Arr;
  cout << pos << endl;

  if (pos < size)
    cout << target << " found in the array at position " << pos << "." << endl;
  else
    cout << target << " not found in the array." << endl;

  vector<double>::iterator vposadd = find(A.begin(), A.end(), target);
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

  cout << "-----------------------------------------------" << endl;

  size = 6;
  string stringtarget = "";

  vector<string> B;
  B.push_back("Sam");
  B.push_back("Jane");
  B.push_back("George");
  B.push_back("Sue");
  B.push_back("April");
  B.push_back("Kara");

  string Brr[size] = {"Sam", "Jane", "George", "Sue", "April", "Kara"};

  random_shuffle(B.begin(), B.end());
  random_shuffle(Brr, Brr + size);

  cout << "Array: ";
  printArray(Brr, size);
  cout << endl;

  cout << "Vector: ";
  printVector(B);
  cout << endl;
  cout << endl;

  cout << "Search for: ";
  cin >> stringtarget;

  string *strposadd = find(Brr, Brr + size, stringtarget);
  int strpos = strposadd - Brr;
  cout << strpos << endl;

  if (strpos < size)
    cout << stringtarget << " found in the array at position " << strpos << "."
         << endl;
  else
    cout << stringtarget << " not found in the array." << endl;

  vector<string>::iterator svposadd = find(B.begin(), B.end(), stringtarget);
  unsigned int strvecpos = svposadd - B.begin();
  cout << strvecpos << endl;

  if (strvecpos < B.size())
    cout << stringtarget << " found in the vector at position " << vecpos << "."
         << endl;
  else
    cout << stringtarget << " not found in the vector." << endl;

  cout << endl;
  cout << "Sort Containers" << endl;
  cout << endl;

  sort(B.begin(), B.end());
  sort(Brr, Brr + size);

  cout << "Array: ";
  printArray(Brr, size);
  cout << endl;

  cout << "Vector: ";
  printVector(B);
  cout << endl;

  strposadd = find(Brr, Brr + size, stringtarget);
  strpos = strposadd - Brr;
  cout << strpos << endl;

  if (strpos < size)
    cout << stringtarget << " found in the array at position " << strpos << "."
         << endl;
  else
    cout << stringtarget << " not found in the array." << endl;

  svposadd = find(B.begin(), B.end(), stringtarget);
  strvecpos = svposadd - B.begin();
  cout << strvecpos << endl;

  if (strvecpos < B.size())
    cout << stringtarget << " found in the vector at position " << strvecpos
         << "." << endl;
  else
    cout << stringtarget << " not found in the vector." << endl;

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

void printVector(const vector<double> &vec, bool newline) {
  for (unsigned int i = 0; i < vec.size(); i++) {
    cout << vec[i];
    if (newline)
      cout << endl;
    else
      cout << "  ";
  }
}

void printArray(double array[], int size, bool newline) {
  for (int i = 0; i < size; i++) {
    cout << array[i];
    if (newline)
      cout << endl;
    else
      cout << "  ";
  }
}

void printVector(const vector<string> &vec, bool newline) {
  for (unsigned int i = 0; i < vec.size(); i++) {
    cout << vec[i];
    if (newline)
      cout << endl;
    else
      cout << "  ";
  }
}

void printArray(string array[], int size, bool newline) {
  for (int i = 0; i < size; i++) {
    cout << array[i];
    if (newline)
      cout << endl;
    else
      cout << "  ";
  }
}
