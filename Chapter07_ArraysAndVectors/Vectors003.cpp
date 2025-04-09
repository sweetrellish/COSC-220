//============================================================================
// Name        : Vectors003.cpp
// Author      : Don Spickler
// Version     : 2/20/2020
// Description : Vector Example #3: Vectors and Functions
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector> // Load in vectors from the STL

using namespace std;

double frand();
void printValues(vector<int>);
void printValues(vector<double> vect);
void populateValues(vector<double> &, int);
int sumValues(vector<int>);

int main() {
  vector<int> nums1;
  vector<double> nums2;
  int size = 0;

  srand(time(0));

  cout << nums1.size() << endl;
  cout << nums2.size() << endl;

  cout << "How many numbers: ";
  cin >> size;

  for (int i = 0; i < size; i++) {
    int val = 0;
    cout << "Input number: ";
    cin >> val;
    nums1.push_back(val);
  }

  cout << nums1.size() << endl;
  cout << endl;

  printValues(nums1);

  cout << endl;

  cout << "Sum = " << sumValues(nums1) << endl;
  cout << endl;

  populateValues(nums2, rand() % 100);

  cout << nums2.size() << endl;
  cout << endl;

  printValues(nums2);

  cout << endl;

  return 0;
}

double frand() { return static_cast<double>(rand()) / RAND_MAX; }

void printValues(vector<int> vect) {
  for (unsigned int count = 0; count < vect.size(); count++)
    cout << vect[count] << endl;
}

void printValues(vector<double> vect) {
  for (unsigned int count = 0; count < vect.size(); count++)
    cout << vect[count] << endl;
}

void populateValues(vector<double> &vect, int size) {
  for (int i = 0; i < size; i++)
    vect.push_back(frand());
}

int sumValues(vector<int> vect) {
  int sum = 0;
  for (unsigned int i = 0; i < vect.size(); i++)
    sum += vect[i];

  return sum;
}
