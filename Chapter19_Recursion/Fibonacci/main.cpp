#include <iostream>

using namespace std;

int fib(int n) {
  if (n <= 0)
    return 0; // Base case
  else if (n == 1)
    return 1; // Base case
  else
    return fib(n - 1) + fib(n - 2); // Recursive case
}

int fibiter(int n) {
  int fib = 1;

  if (n <= 0)
    return 0; // Base case
  else if (n == 1)
    return 1; // Base case
  else {
    int last1 = 1;
    int last2 = 1;

    for (int i = 0; i < n - 2; i++) {
      fib = last1 + last2;
      last2 = last1;
      last1 = fib;
    }
  }
  return fib;
}

int main() {
  int n;
  cout << "n = ";
  cin >> n;

  cout << "The first " << n << " Fibonacci numbers are (iterative): ";
  for (int x = 0; x < n; x++)
    cout << fibiter(x) << " ";

  cout << endl;

  cout << "The first " << n << " Fibonacci numbers are: ";
  for (int x = 0; x < n; x++)
    cout << fib(x) << " ";

  cout << endl;
  return 0;
}
