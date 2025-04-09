//============================================================================
// Name        : CInNumbersAndStrings2.cpp
// Author      : Don Spickler
// Version     : 1/30/2020
// Description : Numbers and strings, same problem and solution as in Java.
//============================================================================

#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  int number;

  cout << "Enter a number: ";
  cin >> number;
  cin.ignore(5, '\n');
  cout << "Enter a string: ";
  getline(cin, str);
  cout << str << endl;
  cout << number << endl;

  return 0;
}
