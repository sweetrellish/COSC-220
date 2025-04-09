//============================================================================
// Name        : FormattedOutputPrintf.cpp
// Author      : Don Spickler
// Version     : 1/30/2020
// Description : The printf command, C construct.
//============================================================================

#include <cmath> // Math functions
#include <iostream>

using namespace std;

int main() {
  double sqrt2 = sqrt(2);
  double pi = 3.141592653589793;
  int a = 23;
  char ch = 'T';
  string str = "This is a string...";

  printf("%10.3f \n", sqrt2);
  printf("%10.4f \n", sqrt2);
  printf("%10.5f \n", sqrt2);
  printf("%10.6f \n", sqrt2);
  printf("%10.7f \n", sqrt2);
  printf("%0.7f \n", sqrt2);
  printf("%0.30f \n", sqrt2);
  cout << endl;

  printf("%10.3f \n", pi);
  printf("%10.4f \n", pi);
  printf("%10.5f \n", pi);
  printf("%10.6f \n", pi);
  printf("%10.7f \n", pi);
  printf("%0.7f \n", pi);
  printf("%0.30f \n", pi);
  cout << endl;

  printf("%10d \n", a);
  printf("%9d \n", a);
  printf("%8d \n", a);
  printf("%2d \n", a);
  printf("%1d \n", a);
  cout << endl;

  printf("%5.3f %5d %5.3f \n", pi, a, sqrt2);
  printf("%5.3f %5d %5.3f   %3c  %s \n", pi, a, sqrt2, ch, str);
  printf("%5.3f %5d %5.3f   %3c  %s \n", pi, a, sqrt2, ch,
         str.c_str()); // Converts to C-style strings for printf.

  return 0;
}
