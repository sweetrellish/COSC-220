//============================================================================
// Name        : Vectors004.cpp
// Author      : Don Spickler
// Version     : 2/20/2020
// Description : Vector Example #4: Vector Manipulations
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
void printValuesOneLine(vector<int>);
void printValuesOneLine(vector<double>);

int main() {
  vector<int> nums1;
  vector<int> nums2;

  srand(time(0));

  nums1.push_back(15);
  nums1.push_back(-3);
  nums1.push_back(4);
  nums1.push_back(7);

  printValuesOneLine(nums1);
  cout << nums1.size() << endl;

  nums1.pop_back();

  printValuesOneLine(nums1);
  cout << nums1.size() << endl;

  nums1.push_back(23);
  for (int i = 27; i < 35; i++)
    nums1.push_back(i);

  printValuesOneLine(nums1);
  cout << nums1.size() << endl;

  nums1.erase(nums1.begin());

  printValuesOneLine(nums1);
  cout << nums1.size() << endl;

  nums1.erase(nums1.begin() + 5);

  printValuesOneLine(nums1);
  cout << nums1.size() << endl;

  nums1.erase(nums1.begin() + 5, nums1.begin() + 8);

  printValuesOneLine(nums1);
  cout << nums1.size() << endl;

  for (int i = 127; i < 135; i++)
    nums1.push_back(i);

  printValuesOneLine(nums1);
  cout << nums1.size() << endl;

  nums1.erase(nums1.begin() + 7, nums1.end() - 5);

  printValuesOneLine(nums1);
  cout << nums1.size() << endl;

  nums1.erase(nums1.end() - 2, nums1.end());

  printValuesOneLine(nums1);
  cout << nums1.size() << endl;

  for (int i = 127; i < 135; i++)
    nums1.push_back(i);

  printValuesOneLine(nums1);
  cout << nums1.size() << endl;

  for (int i = 1; i < 11; i++)
    nums2.push_back(i);
  printValuesOneLine(nums2);

  nums1.insert(nums1.begin() + 3, nums2.begin(), nums2.end());
  printValuesOneLine(nums1);
  cout << nums1.size() << endl;

  cout << nums2.empty() << endl;
  nums2.clear();
  cout << nums2.empty() << endl;

  for (int i = 1; i <= 1000000; i++)
    nums2.push_back(i);

  cout << nums2.size() << endl;

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

void printValuesOneLine(vector<int> vect) {
  for (unsigned int count = 0; count < vect.size(); count++)
    cout << vect[count] << " ";

  cout << endl;
}

void printValuesOneLine(vector<double> vect) {
  for (unsigned int count = 0; count < vect.size(); count++)
    cout << vect[count] << " ";

  cout << endl;
}

void populateValues(vector<double> &vect, int size) {
  for (int i = 0; i < size; i++)
    vect.push_back(frand());
}
