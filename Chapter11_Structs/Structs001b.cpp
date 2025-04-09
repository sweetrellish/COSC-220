//============================================================================
// Name        : Structs001.cpp
// Author      : Don Spickler
// Version     : 3/15/2020
// Description : Struct Example 1: Declaring a struct and accessing fields.
//============================================================================

#include <iostream>
#include <string>

using namespace std;

struct Person {
  string name;
  long idNumber;
  int YearOfBirth;
};

ostream &operator<<(ostream &strm, const Person &person) {
  strm << person.name << ": ID: " << person.idNumber
       << "  YOB: " << person.YearOfBirth;
  return strm;
}

int main() {
  Person person;
  person.name = "John Smith";
  person.idNumber = 123456789;
  person.YearOfBirth = 1987;

  cout << "Name: " << person.name << endl;
  cout << "ID: " << person.idNumber << endl;
  cout << "Year of Birth: " << person.YearOfBirth << endl;
  cout << endl;

  cout << person << endl;

  return 0;
}
