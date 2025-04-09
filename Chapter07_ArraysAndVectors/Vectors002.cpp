//============================================================================
// Name        : Vectors002.cpp
// Author      : Don Spickler
// Version     : 2/20/2020
// Description : Vector Example #2: Variable size vectors.
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector> // Load in vectors from the STL

using namespace std;

double frand();

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

  double sum = 0;
  for (unsigned int i = 0; i < nums1.size(); i++) {
    sum += nums1[i];
  }

  for (int val : nums1)
    cout << val << endl;

  cout << endl;

  cout << "Sum = " << sum << endl;
  cout << endl;

  size = rand() % 100;
  cout << size << endl;

  for (int i = 0; i < size; i++) {
    nums2.push_back(frand());
  }

  cout << nums2.size() << endl;
  cout << endl;

  for (auto val : nums2)
    cout << val << endl;

  cout << endl;

  return 0;
}

double frand() { return static_cast<double>(rand()) / RAND_MAX; }
