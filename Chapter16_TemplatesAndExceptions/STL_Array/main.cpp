/*
 Author: Don Spickler
 Creation Date: 1/28/2022
 Last Update: 1/28/2022
 Description: Testing program that shows some functionality of the array and
 iterators. User Interface: None
 */

#include <algorithm> // Required for STL algorithms
#include <array>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// Prototypes
template <class T, long unsigned int s>
void print(array<T, s> const &A, bool nl = false);

void div();

int main() {
  srand(time(0));

  array<int, 10> arr;
  array<int, 10>::iterator arrIter;

  for (int i = 0; i < 10; i++)
    arr[i] = i + 1;

  print(arr);

  div();

  print(arr);
  random_shuffle(arr.begin(), arr.end());
  print(arr);
  random_shuffle(arr.begin(), arr.end());
  print(arr);

  div();

  sort(arr.begin(), arr.end());
  print(arr);

  arrIter = arr.begin();
  while (arrIter < arr.end()) {
    cout << *arrIter << "  ";
    arrIter++;
  }
  cout << endl;

  cout << "End Program" << endl;

  return 0;
}

/*
 Description: Print a vector of any data type, as long as the data type can be
 streamed. Parameters: A - Array to be printed to the console screen. nl -
 boolean that flags if there should be a line feed after each print. Return:
 None
 */

template <class T, long unsigned int s>
void print(array<T, s> const &A, bool nl) {
  for (int i = 0; i < A.size(); i++) {
    cout << A[i] << " ";
    if (nl)
      cout << endl;
  }

  if (!nl)
    cout << endl;
}

/*
 Description: Prints a dividing line.
 Parameters: None
 Return: None
 */

void div() {
  cout << endl << "----------------------------------" << endl << endl;
}
