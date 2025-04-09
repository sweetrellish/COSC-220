//============================================================================
// Name        : CInNumbersAndStrings.cpp
// Author      : Don Spickler
// Version     : 1/30/2020
// Description : Numbers and strings, same problem as in Java.
//============================================================================

#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  int number;

  cout << "Enter a number: ";
  cin >> number;
  cout << "Enter a string: ";
  getline(cin, str);
  cout << "Thank You!\n";

  return 0;
}
