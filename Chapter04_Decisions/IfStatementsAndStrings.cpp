//============================================================================
// Name        : IfStatementsAndStrings.cpp
// Author      : Don Spickler
// Version     : 2/1/2020
// Description : If statement examples with strings.
//============================================================================

#include <iostream>
#include <string>

using namespace std;

int main() {
  string s1, s2, s3, s4;

  cout << "Input two words: ";
  cin >> s1 >> s2;

  if (s1 == s2)
    cout << "s1 and s2 are the same.";

  if (s1 < s2)
    cout << "s1 is before s2.";

  if (s1 > s2)
    cout << "s1 is after s2.";

  cout << endl;

  // Convert to uppercase
  for (int i = 0; i < s1.length(); i++) {
    char ch = s1[i];
    if (ch >= 'a' && ch <= 'z')
      ch = ch + ('A' - 'a');
    s3 += ch;
  }

  for (int i = 0; i < s2.length(); i++) {
    char ch = s2[i];
    if (ch >= 'a' && ch <= 'z')
      ch = ch + ('A' - 'a');
    s4 += ch;
  }

  cout << s3 << endl;
  cout << s4 << endl;

  if (s3 == s4)
    cout << "s3 and s4 are the same.";
  else if (s3 < s4)
    cout << "s3 is before s4.";
  else
    cout << "s3 is after s4.";

  return 0;
}
