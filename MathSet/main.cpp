//===========================================================================================================================
// Name        : main.cpp
// Author      : Ryan C. Ellis
// Creation Date: 12/6/2024
// Last Update: 12/6/2024
// Description: Main program that includes the MathSet class header file and tests and manipulates functions and data of
// that structure.
//===========================================================================================================================

#include "MathSet.h"
#include <iostream>

using namespace std;

int main() {

  srand(time(0));
  MathSet<int> A = {1, 2, 3, 4, 5, 6};
  cout << A << endl;
  MathSet<int> B;
  B.insert(17);
  cout << B << endl;
  MathSet<int> C;
  cout << C << endl;
  B.insert({
      4,
      5,
      6,
      7,
  });
  cout << B << endl;
  cout << A + B << endl;
  cout << A - B << endl;
  cout << B - A << endl;
  cout << A * B << endl;
  cout << (A ^ B) << endl;
  B = A;
  cout << A << endl;
  cout << B << endl;
  B = {4, 3, 6, 7};
  A.insert({10, 11, 12});
  cout << A << endl;
  cout << B << endl;
  MathSet<int> E = A;
  cout << A << endl;
  cout << E << endl;
  MathSet<int> F(A);
  cout << A << endl;
  cout << F << endl;
  cout << &A << endl;
  cout << &E << endl;
  cout << &F << endl;
  MathSet<int>::iterator it = A.begin();
  while (it != A.end())
    cout << *it++ << " ";
  cout << endl;
  it = A.find(6);
  if (it != A.end())
    A.erase(it);
  cout << A << endl;
  A.erase(10);
  cout << A << endl;
  it = A.find(3);
  auto it2 = A.find(11);
  A.erase(it, it2);
  cout << A << endl;
  // cout << "------------- Power Set Test Code" << endl;
  // A.clear();
  // A.insert({1, 2, 3});
  // cout << A << endl;
  // cout << A.PowerSet() << endl;
  // A.insert(4);
  // cout << A.PowerSet() << endl;
  // MathSet<char> S = {'A', 'B', 'C'};
  // cout << S.PowerSet() << endl;
  // S.insert('D');
  // cout << S.PowerSet() << endl;
  // auto D = S.PowerSet();
  // cout << D << endl;
  return 0;
}
