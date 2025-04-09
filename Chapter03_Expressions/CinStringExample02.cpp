//============================================================================
// Name        : CinStringExample02.cpp
// Author      : Don Spickler
// Version     : 1/30/2020
// Description : cin with strings and using getline.
//============================================================================

#include <iostream>
#include <string>

using namespace std;

int main() {
  string name;
  string city;

  cout << "Please enter your name: ";
  getline(cin, name);
  cout << "Enter the city you live in: ";
  getline(cin, city);

  cout << "Hello, " << name << endl;
  cout << "You live in " << city << endl;

  return 0;
}
