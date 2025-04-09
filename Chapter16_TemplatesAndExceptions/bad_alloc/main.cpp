// This program demonstrates the bad_alloc exception.
#include <iostream>
#include <new> // Needed for bad_alloc
using namespace std;

int main() {
  double *ptr = nullptr; // Pointer to double
  unsigned long sz = 1000000000;

  try {
    ptr = new double[sz];
    cout << "Memory allocated.\n";
    ptr[sz - 1] = 12345;
    cout << ptr[sz - 1] << endl;
    delete[] ptr;
  } catch (bad_alloc &e) {
    cout << "Insufficient memory.\n";
    cout << e.what() << "\n";
  }

  cout << "End Program..." << endl;

  return 0;
}
