//============================================================================
// Name        : Structs002.cpp
// Author      : Don Spickler
// Version     : 3/15/2020
// Description : Struct Example 2: Structs and functions.
//============================================================================

#include <iostream>
#include <string>

using namespace std;

struct Person {
  string name;
  long idNumber;
  int YearOfBirth;
};

void InputPersonData(Person &);
void DisplayPersonInformation(Person &);

int main() {
  Person p;
  InputPersonData(p);
  DisplayPersonInformation(p);

  return 0;
}

void InputPersonData(Person &person) {
  cout << "Input your name: ";
  getline(cin, person.name);
  cout << "Input your ID number: ";
  cin >> person.idNumber;
  cout << "Input your year of birth: ";
  cin >> person.YearOfBirth;
}

void DisplayPersonInformation(Person &person) {
  cout << "Name: " << person.name << endl;
  cout << "ID: " << person.idNumber << endl;
  cout << "Year of Birth: " << person.YearOfBirth << endl;
  cout << "Age: " << 2020 - person.YearOfBirth << endl;
}
