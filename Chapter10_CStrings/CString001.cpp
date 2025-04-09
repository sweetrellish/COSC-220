//============================================================================
// Name        : CString001.cpp
// Author      : Don Spickler
// Version     : 3/14/2020
// Description : C-String Example #1
//============================================================================

#include <cstring>
#include <iostream>

using namespace std;

int main() {
  const int SIZE = 80;
  char string1[SIZE] = "Hello ";
  char string2[] = "Small World!";
  char string3[SIZE];

  cout << string1 << endl;
  cout << string2 << endl;

  cout << strlen(string1) << endl;
  cout << strlen(string2) << endl;

  strcat(string1, string2);
  cout << string1 << endl;
  cout << strlen(string1) << endl;

  strcpy(string3, "COSC 120: Computer Science I");
  cout << string3 << endl;
  cout << strlen(string3) << endl;

  char string4[10];
  cout << "Input: ";
  cin.getline(string4, 10);
  cout << string4 << endl;

  /*
  for (int i = 0; i < 20; i++) {
    strcat(string1, string2);
    cout << string1 << endl;
  }
  */

  cout << endl;

  char arr[] = "Four score and seven years ago";
  char *strPtr = nullptr;
  cout << arr << endl;
  strPtr = strstr(arr, "seven"); // search for "seven"
  cout << strPtr << endl;

  strPtr = strstr(arr, "Five"); // search for "Five"

  if (strPtr == nullptr)
    cout << "Not found..." << endl;
  else
    cout << strPtr << endl;

  strcpy(string1, "dog");
  strcpy(string2, "dog");

  if (strcmp(string1, string2) == 0)
    cout << "The strings are equal.\n";
  else
    cout << "The strings are not equal.\n";

  if (!strcmp(string1, string2))
    cout << "The strings are equal.\n";
  else
    cout << "The strings are not equal.\n";

  strcpy(string1, "dog");
  strcpy(string2, "Dog");

  if (strcmp(string1, string2) == 0)
    cout << "The strings are equal.\n";
  else
    cout << "The strings are not equal.\n";

  if (strcmp(string1, string2) < 0)
    cout << string1 << "  " << string2 << endl;
  else if (strcmp(string1, string2) > 0)
    cout << string2 << "  " << string1 << endl;
  else
    cout << "Strings equal" << endl;

  cout << "Done" << endl;
  return 0;
}
