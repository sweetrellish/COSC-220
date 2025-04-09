//============================================================================
// Name        : Arrays003.cpp
// Author      : Don Spickler
// Version     : 2/16/2020
// Description : Array Example #3.  File loading and saving.
//============================================================================

#include <cmath>   // Math functions
#include <cstdlib> // For rand and srand
#include <ctime>   // For the time function
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  srand(time(0));
  int size = 0;
  ofstream outputFile;
  ifstream inputFile;

  cout << "Input the array size: ";
  cin >> size;
  int A[size];

  //  Populate array with random numbers.
  for (int i = 0; i < size; i++)
    A[i] = rand();
  cout << endl;

  // Two different ways to write the array to a file.
  outputFile.open("RandomNumbers.txt");
  for (int i = 0; i < size; i++)
    outputFile << A[i] << endl;
  outputFile.close();

  outputFile.open("RandomNumbers2.txt");
  for (auto val : A)
    outputFile << val << endl;
  outputFile.close();

  // Find the number of entries in the file.
  int filesize = 0;
  double testval = 0;
  inputFile.open("IntelWeek.txt");
  while (inputFile >> testval)
    filesize++;
  inputFile.close();

  // Declare array of correct size.
  double intelData[filesize];

  // Load file into array.
  int count = 0;
  inputFile.open("IntelWeek.txt");
  while (count < filesize && inputFile >> intelData[count])
    count++;
  inputFile.close();

  for (auto val : intelData)
    cout << val << endl;

  return 0;
}
