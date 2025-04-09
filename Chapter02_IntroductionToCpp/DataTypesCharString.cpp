//============================================================================
// Name        : DataTypesCharString.cpp
// Author      : Don Spickler
// Version     : 1/26/2020
// Description : Strings and characters.
//============================================================================

#include <iostream>
#include <string>

using namespace std;

int main() {
  char ch;
  cout << ch << endl;
  ch = 'T';
  cout << ch << endl;

  int chval = ch;
  cout << chval << endl;

  ch = 72;
  cout << ch << endl;
  cout << "\n";

  string str = "Hello World!";
  cout << str << endl;
  cout << str.length() << endl;

  string str1;
  string str2;
  string str3 = "C++ is so cool!";

  str2 = "I just want you to know that ";
  str1 = str2 + str3;
  cout << str1 << "\n\n";

  cout << str1.length() << endl;
  cout << str1.substr(3, 7) << endl;
  cout << str1.substr(7) << endl;
  cout << str1.size() << endl;

  str1.replace(3, 7, "This is a replacement");
  cout << str1 << endl;

  str1 = str1.substr(0, 20);
  cout << str1 << endl;
  str1.insert(10, "Inserted at position 10");
  cout << str1 << endl;

  cout << str1.at(0) << endl;
  cout << str1.at(20) << endl;
  cout << str1.at(str1.length() - 1) << endl;

  str1.append("Some more text...");
  cout << str1 << endl;

  str1.clear();
  cout << str1 << endl;

  str1 = "Here is some more.";
  cout << str1 << endl;

  str1 += str1;
  cout << str1 << endl;
  cout << str1.length() << endl;

  int t = str1.find("some");
  cout << t << endl;
  cout << str1.find_first_of("some") << endl;
  cout << str1.find_last_of("some") << endl;
  cout << str1.find("some", 10) << endl;

  return 0;
}
