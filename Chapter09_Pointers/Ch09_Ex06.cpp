//============================================================================
// Name        : Ch09_Ex06.cpp
// Author      : Don Spickler
// Version     : 1.1
// Description : Syntax Example #5 for Chapter 9 on Pointers
// Note        : Memory leak to the point of exhausting the memory space.
//============================================================================

#include <iostream>
using namespace std;

int main() {

  while (true)
    double *arr = new double[1000000];

  return 0;
}
