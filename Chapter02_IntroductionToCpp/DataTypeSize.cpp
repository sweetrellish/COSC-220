//============================================================================
// Name        : DataTypeSize.cpp
// Author      : Don Spickler
// Version     : 1/26/2020
// Description : Shows sizes and bounds of the native data types.
//============================================================================

#include <iostream>
#include <string>

#include <float.h>  // for float,double macros
#include <limits.h> // for int,char macros

using namespace std;

int main() {
  long a;

  cout << a << endl;
  string str1 = "Hello World!";
  cout << str1.length() << endl;
  cout << sizeof(str1) << endl;
  cout << sizeof("Hello World!") << endl;
  cout << endl;

  cout << sizeof(a) << endl;
  cout << "int: " << sizeof(int) << endl;
  cout << "short: " << sizeof(short) << endl;
  cout << "char: " << sizeof(char) << endl;
  cout << "long: " << sizeof(long) << endl;
  cout << "long long: " << sizeof(long long) << endl;
  cout << "float: " << sizeof(float) << endl;
  cout << "double: " << sizeof(double) << endl;
  cout << "long double: " << sizeof(long double) << endl;
  cout << endl;

  cout << "char ranges from : " << CHAR_MIN << " to " << CHAR_MAX << endl;
  cout << "short char ranges from : " << SCHAR_MIN << " to " << SCHAR_MAX
       << endl;
  cout << "unsigned char ranges from : " << 0 << " to " << UCHAR_MAX << endl;
  cout << "short int ranges from : " << SHRT_MIN << " to " << SHRT_MAX << endl;
  cout << "unsigned short int ranges from : " << 0 << " to " << USHRT_MAX
       << endl;
  cout << "int ranges from : " << INT_MIN << " to " << INT_MAX << endl;
  cout << "unsigned int ranges from : " << 0 << " to " << UINT_MAX << endl;
  cout << "long int ranges from : " << LONG_MIN << " to " << LONG_MAX << endl;
  cout << "unsigned long int ranges from : " << 0 << " to " << ULONG_MAX
       << endl;
  cout << "long long int ranges from : " << LLONG_MIN << " to " << LLONG_MAX
       << endl;
  cout << "unsigned long long int ranges from : " << 0 << " to " << ULLONG_MAX
       << endl;
  cout << endl;

  cout << "float ranges from : " << FLT_MIN << " to " << FLT_MAX << endl;
  cout << "negative float ranges from : " << -FLT_MIN << " to " << -FLT_MAX
       << endl;
  cout << "double ranges from : " << DBL_MIN << " to " << DBL_MAX << endl;
  cout << "negative double ranges from : " << -DBL_MIN << " to " << -DBL_MAX
       << endl;
  cout << "long double ranges from : " << LDBL_MIN << " to " << LDBL_MAX
       << endl;
  cout << "negative long double ranges from : " << -LDBL_MIN << " to "
       << -LDBL_MAX << endl;

  return 0;
}
