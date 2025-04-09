//============================================================================
// Name        : CString002.cpp
// Author      : Don Spickler
// Version     : 3/14/2020
// Description : C-String Example #2
//============================================================================

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main() {
  const int SIZE = 80;
  char numstr1[SIZE];
  char numstr2[SIZE];

  cout << "Input num1: ";
  cin.getline(numstr1, SIZE);
  cout << "Input num2: ";
  cin.getline(numstr2, SIZE);

  cout << numstr1 << "  " << numstr2 << endl;

  int n1 = atoi(numstr1);
  int n2 = atoi(numstr2);

  cout << n1 << "  " << n2 << "  " << n1 + n2 << endl;

  long n1L = atol(numstr1);
  long n2L = atol(numstr2);

  cout << n1L << "  " << n2L << "  " << n1L + n2L << endl;
  cout << endl;

  cout << "Input float num1: ";
  cin.getline(numstr1, SIZE);
  cout << "Input float num2: ";
  cin.getline(numstr2, SIZE);

  double n1F = atof(numstr1);
  double n2F = atof(numstr2);

  cout << n1F << "  " << n2F << "  " << n1F + n2F << endl;

  string numberstr = to_string(n1F);
  cout << numberstr << endl;

  return 0;
}
