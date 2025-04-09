//============================================================================
// Name        : FormattedOutput.cpp
// Author      : Don Spickler
// Version     : 1/30/2020
// Description : Formatted output example,
//============================================================================

#include <cmath>   // Math functions
#include <iomanip> // Required for setw, setprecision
#include <iostream>

using namespace std;

int main() {
  int num1 = 2897, num2 = 5, num3 = 837, num4 = 34, num5 = 7, num6 = 1623,
      num7 = 390, num8 = 3456, num9 = 12;

  // Display the numbers in three rows.
  cout << setw(6) << num1 << setw(6) << num2 << setw(6) << num3 << endl;
  cout << setw(6) << num4 << setw(6) << num5 << setw(6) << num6 << endl;
  cout << setw(6) << num7 << setw(6) << num8 << setw(6) << num9 << endl;
  cout << endl;

  double pi = 3.141592653589793;

  cout << pi << endl;
  cout << setprecision(20) << pi << endl;
  cout << setprecision(15) << pi << endl;
  cout << setprecision(10) << pi << endl;
  cout << setprecision(5) << pi << endl;
  cout << setprecision(4) << pi << endl;
  cout << setprecision(3) << pi << endl;
  cout << setprecision(2) << pi << endl;
  cout << setprecision(1) << pi << endl;
  cout << endl;

  double sqrt2 = sqrt(2);

  cout << sqrt2 << endl;
  cout << setprecision(20) << sqrt2 << endl;
  cout << setprecision(15) << sqrt2 << endl;
  cout << setprecision(10) << sqrt2 << endl;
  cout << setprecision(5) << sqrt2 << endl;
  cout << setprecision(4) << sqrt2 << endl;
  cout << setprecision(3) << sqrt2 << endl;
  cout << setprecision(2) << sqrt2 << endl;
  cout << setprecision(1) << sqrt2 << endl;
  cout << endl;

  cout << setprecision(2) << fixed;
  cout << pi << endl;
  cout << sqrt2 << endl;
  cout << 12345.6789 << endl;
  cout << 17 << endl;
  cout << 17. << endl;
  cout << 22.2 << endl;
  cout << endl;

  cout << setprecision(3) << fixed << showpoint;
  cout << pi << endl;
  cout << sqrt2 << endl;
  cout << 12345.6789 << endl;
  cout << 17 << endl;
  cout << 17. << endl;
  cout << 22.2 << endl;
  cout << endl;

  return 0;
}
