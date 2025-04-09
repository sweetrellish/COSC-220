//============================================================================
// Name        : CinStringExample01.cpp
// Author      : Don Spickler
// Version     : 1/30/2020
// Description : cin with strings.
//============================================================================

#include <iostream>
#include <string>

using namespace std;

int main() {
  string name, fname, lname;
  string city;

  /*
      cout << "Please enter your name: ";
      cin >> name;
      cout << "Enter the city you live in: ";
      cin >> city;

      cout << "Hello, " << name << endl;
      cout << "You live in " << city << endl;
  */

  cout << "Please enter your name: ";
  cin >> fname;
  cin >> lname;

  cout << "Hello, " << fname << " " << lname << endl;

  return 0;
}
