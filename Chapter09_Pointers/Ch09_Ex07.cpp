//============================================================================
// Name        : Ch09_Ex07.cpp
// Author      : Don Spickler
// Version     : 1.1
// Description : Syntax Example #7 for Chapter 9 on Pointers
// Note        : This is a combination of examples from the text with some
//               minor changes.
//============================================================================

#include <cstdlib> // For rand and srand
#include <ctime>   // For the time function
#include <iostream>

using namespace std;

int *getRandomNumbers(int);
int *duplicateArray(const int *, int);
void displayArray(const int[], int);
void div();

int main() {
  int *numbers = getRandomNumbers(5);
  int *numbers2 = duplicateArray(numbers, 5);

  displayArray(numbers, 5);
  displayArray(numbers2, 5);

  div();

  numbers[2] = 7777777;
  displayArray(numbers, 5);
  displayArray(numbers2, 5);

  delete[] numbers;
  numbers = nullptr;

  delete[] numbers2;
  numbers2 = nullptr;

  return 0;
}

int *getRandomNumbers(int num) {
  int *arr = nullptr;

  if (num <= 0)
    return nullptr;

  arr = new int[num];

  srand(time(0));

  for (int count = 0; count < num; count++)
    arr[count] = rand();

  return arr;
}

int *duplicateArray(const int *arr, int size) {
  int *newArray = nullptr;

  if (size <= 0)
    return nullptr;

  newArray = new int[size];

  for (int index = 0; index < size; index++)
    newArray[index] = arr[index];

  return newArray;
}

void displayArray(const int arr[], int size) {
  for (int index = 0; index < size; index++)
    cout << arr[index] << " ";
  cout << endl;
}

void div() { cout << "\n-----------------------------------\n\n"; }
