//============================================================================
// Name        : Vectors001.cpp
// Author      : Don Spickler
// Version     : 2/20/2020
// Description : Vector Example #1: Declaring vectors with initial size,
//                                  initial elements, and access.
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector> // Load in vectors from the STL

using namespace std;

double frand();

int main() {
  // Declare vectors with initial size.
  vector<int> nums1(25);
  vector<double> nums2(7);
  vector<int> nums3{10, 20, 30, 40, 50};

  srand(time(0));

  for (int val : nums2)
    cout << val << " ";
  cout << endl;

  cout << nums1.size() << endl;
  cout << nums2.size() << endl;

  for (unsigned int i = 0; i < nums2.size(); i++) {
    cout << "Input number: ";
    cin >> nums2[i];
  }

  double sum = 0;
  for (unsigned int i = 0; i < nums2.size(); i++) {
    sum += nums2[i];
  }

  for (int val : nums2)
    cout << val << endl;

  cout << endl;

  cout << "Sum = " << sum << endl;
  cout << endl;

  for (auto val : nums2)
    cout << val << endl;

  cout << endl;

  for (auto &val : nums1)
    val = rand();

  for (auto val : nums1)
    cout << val << endl;

  cout << endl;

  for (auto &val : nums2)
    val = frand();

  for (double val : nums2)
    cout << val << endl;

  cout << endl;

  for (int val : nums3)
    cout << val << " ";

  cout << endl;

  return 0;
}

double frand() { return static_cast<double>(rand()) / RAND_MAX; }
