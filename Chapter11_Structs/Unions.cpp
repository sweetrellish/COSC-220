//============================================================================
// Name        : Unions.cpp
// Author      : Don Spickler
// Version     : 3/16/2020
// Description : Unions Example
//============================================================================

#include <cstring>
#include <iostream>

using namespace std;

union Thing1 {
  int num;
  double dbnum;
};

union Thing2 {
  // Note that a string cannot be used in a union.
  char str[100];
  int num;
  double dbnum;
};

int main() {
  Thing1 t1;

  t1.num = 7;
  cout << t1.num << endl;
  cout << t1.dbnum << endl;

  t1.dbnum = 3.14159;
  cout << t1.num << endl;
  cout << t1.dbnum << endl;

  cout << endl;

  Thing2 t2;

  t2.num = 7;
  cout << t2.num << endl;
  cout << t2.dbnum << endl;
  cout << t2.str << endl;

  t2.dbnum = 3.14159;
  cout << t2.num << endl;
  cout << t2.dbnum << endl;
  cout << t2.str << endl;

  strcpy(t2.str, "Hello World!");
  cout << t2.num << endl;
  cout << t2.dbnum << endl;
  cout << t2.str << endl;

  return 0;
}
