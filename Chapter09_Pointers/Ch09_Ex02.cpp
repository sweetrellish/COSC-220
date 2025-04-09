//============================================================================
// Name        : Ch09_Ex02.cpp
// Author      : Don Spickler
// Version     : 1.1
// Description : Syntax Example #2 for Chapter 9 on Pointers
// Note        : This is a combination of examples from the text with some
//               minor changes.
//============================================================================

#include <iostream>

using namespace std;

void div();

int main() {
  const int SIZE = 7;
  int numbers[] = {20, 5, 3, 15, 23, 42, 56};

  cout << "The first element of the array is ";
  cout << *numbers << endl;
  cout << *(numbers + 3) << endl;
  cout << *(numbers + 1) << endl;
  cout << numbers << endl;
  cout << numbers + 1 << endl;
  cout << numbers + 2 << endl;
  cout << numbers + 3 << endl;

  div();

  for (int count = 0; count < SIZE; count++)
    cout << *(numbers + count) << " ";
  cout << endl;

  for (int count = 0; count < SIZE; count++)
    cout << numbers[count] << " ";
  cout << endl;

  int *pint = nullptr;
  pint = numbers;

  for (int count = 0; count < SIZE; count++)
    cout << *(pint + count) << " ";
  cout << endl;

  for (int count = 0; count < SIZE; count++)
    cout << pint[count] << " ";
  cout << endl;

  for (int count = 0; count < SIZE; count++) {
    pint = &numbers[count];
    cout << *pint << " ";
  }
  cout << endl;

  div();

  pint = numbers;
  for (int count = 0; count < SIZE; count++) {
    cout << *pint << " ";
    pint++;
  }
  cout << endl;

  pint = numbers;
  while (pint < &numbers[SIZE]) {
    cout << *pint << " ";
    pint++;
  }
  cout << endl;

  pint = &numbers[SIZE - 1];
  while (pint >= numbers) {
    cout << *pint << " ";
    pint--;
  }
  cout << endl;

  div();

  // Remember that you can read past the end, or beginning of an array in C/C++.
  pint = numbers;
  while (pint < &numbers[SIZE + 5]) {
    cout << *pint << " ";
    pint++;
  }
  cout << endl;

  pint = &numbers[SIZE - 1];
  while (pint >= numbers - 5) {
    cout << *pint << " ";
    pint--;
  }
  cout << endl;

  return 0;
}

void div() { cout << "\n-----------------------------------\n\n"; }
