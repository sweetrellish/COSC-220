//============================================================================
// Name        : FileInput002.cpp
// Author      : Don Spickler
// Version     : 2/1/2020
// Description : File input example.
//============================================================================

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream inputFile;
  int number, count, sum;
  string filename;

  cout << "Input the filename: ";
  cin >> filename;

  // Open the file.
  inputFile.open(filename);

  // If the file successfully opened, process it.
  if (inputFile) {
    // Read the numbers from the file and print to console.
    sum = 0;
    while (inputFile >> number) {
      cout << number << endl;
      sum += number;
      count++;
    }

    // Close the file.
    inputFile.close();
  } else {
    // Display an error message.
    cerr << "Error opening the file.\n";
    return 1;
  }

  cout << endl;
  cout << "Count = " << count << endl;
  cout << "Sum = " << sum << endl;

  return 0;
}
