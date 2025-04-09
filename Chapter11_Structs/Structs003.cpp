//============================================================================
// Name        : Structs003.cpp
// Author      : Don Spickler
// Version     : 3/15/2020
// Description : Struct Example 3: Structs and functions, returning a struct.
//============================================================================

#include <iostream>
#include <string>

using namespace std;

struct Person {
  string name;
  long idNumber;
  int YearOfBirth;
};

Person InputPersonData();
void DisplayPersonInformation(Person &);

int main() {
  Person p = InputPersonData();
  DisplayPersonInformation(p);

  return 0;
}

Person InputPersonData() {
  Person person;
  cout << "Input your name: ";
  getline(cin, person.name);
  cout << "Input your ID number: ";
  cin >> person.idNumber;
  cout << "Input your year of birth: ";
  cin >> person.YearOfBirth;

  return person;
}

void DisplayPersonInformation(Person &person) {
  cout << "Name: " << person.name << endl;
  cout << "ID: " << person.idNumber << endl;
  cout << "Year of Birth: " << person.YearOfBirth << endl;
  cout << "Age: " << 2020 - person.YearOfBirth << endl;
}
