//============================================================================
// Name        : SomeMath.cpp
// Author      : Don Spickler
// Version     : 1/30.2020
// Description : Some mathematical functions in C++.
//============================================================================

#include <cmath>   // Math functions
#include <cstdlib> // For rand and srand
#include <ctime>   // For the time function
#include <iostream>

using namespace std;

int main() {
  const double PI = 3.141592653589793;

  srand(time(0)); //  Sets the seed of the random number generator.
  cout << time(0) << endl;
  cout << endl;

  cout << rand() << endl;
  cout << rand() << endl;
  cout << rand() << endl;
  cout << endl;

  // Die roll calculation.
  cout << (rand() % 6 + 1) << endl;
  cout << (rand() % 6 + 1) << endl;
  cout << endl;

  cout << RAND_MAX << endl;
  cout << static_cast<double>(rand()) / RAND_MAX << endl;
  cout << endl;

  cout << sin(PI / 4) << endl;
  cout << cos(PI / 6) << endl;
  cout << tan(PI / 3) << endl;
  cout << endl;

  cout << asin(0.5) << endl;
  cout << acos(0.25) << endl;
  cout << endl;

  cout << pow(2, 5) << endl;
  cout << pow(PI, 3) << endl;
  cout << (pow(sin(PI / 6), 2) + pow(cos(PI / 6), 2)) << endl;
  cout << pow(2, 0.5) << endl;
  cout << sqrt(2) << endl;
  cout << endl;

  cout << floor(3.7) << endl;
  cout << ceil(3.7) << endl;
  cout << endl;

  int t;
  double r = 7.658;
  t = r;
  cout << r << "   " << t << endl;

  cout << abs(-3.7) << endl;
  cout << abs(3.7) << endl;
  cout << endl;

  return 0;
}
