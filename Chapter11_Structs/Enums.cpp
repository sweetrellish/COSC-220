//============================================================================
// Name        : Enums.cpp
// Author      : Don Spickler
// Version     : 3/16/2020
// Description : Enumerated Data Types Example
//============================================================================

#include <cstdlib> // For rand and srand
#include <ctime>   // For the time function
#include <iostream>

using namespace std;

enum Day { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY };

int main() {
  srand(time(0));

  Day day = WEDNESDAY;
  cout << day << endl;

  //	day++;  // error
  //	day = day + 1;  // error
  //	day = THURSDAY - 1; //error

  day = static_cast<Day>(day + 1);
  cout << day << endl;
  cout << FRIDAY << endl;
  cout << endl;

  for (int today = MONDAY; today <= FRIDAY; today++) {
    cout << today << endl;
  }
  cout << endl;

  int daynumbers[5];

  for (int today = MONDAY; today <= FRIDAY; today++) {
    daynumbers[today] = rand();
  }

  daynumbers[TUESDAY] = 123456;

  for (int today = MONDAY; today <= FRIDAY; today++) {
    cout << daynumbers[today] << endl;
  }
  cout << endl;

  int daynum = THURSDAY;
  cout << daynum << endl;

  return 0;
}
