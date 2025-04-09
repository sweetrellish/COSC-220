//============================================================================
// Name        : Structs004.cpp
// Author      : Don Spickler
// Version     : 3/15/2020
// Description : Struct Example 4: Arrays and Vectors of Structs.
//============================================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person {
  string name;
  long idNumber;
  int YearOfBirth;
};

Person InputPersonData();
void DisplayPersonInformation(Person &);

int main() {
  int num = 0;
  cout << "Input the number in your company: ";
  cin >> num;
  cin.ignore();

  Person company[num];

  for (int i = 0; i < num; i++) {
    cout << endl;
    company[i] = InputPersonData();
  }

  cout << endl;
  cout << "Company Employees" << endl;
  for (int i = 0; i < num; i++) {
    cout << endl;
    DisplayPersonInformation(company[i]);
  }

  vector<Person> EmployeeList;

  for (int i = 0; i < num; i++)
    EmployeeList.push_back(company[i]);

  cout << endl;
  cout << "Company Employees" << endl;
  for (int i = 0; i < EmployeeList.size(); i++) {
    cout << endl;
    DisplayPersonInformation(EmployeeList[i]);
  }

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
  cin.ignore();

  return person;
}

void DisplayPersonInformation(Person &person) {
  cout << "Name: " << person.name << endl;
  cout << "ID: " << person.idNumber << endl;
  cout << "Year of Birth: " << person.YearOfBirth << endl;
  cout << "Age: " << 2020 - person.YearOfBirth << endl;
}
