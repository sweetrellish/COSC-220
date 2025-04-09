//============================================================================
// Name        : FileOutput.cpp
// Author      : Don Spickler
// Version     : 2/1/2020
// Description : File output example.
//============================================================================

#include <cstdlib> // For rand and srand
#include <ctime>   // For the time function
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  srand(time(0));

  cout << "Open file." << endl;
  ofstream outputFile;
  outputFile.open("outputfile.txt");

  cout << "Write to the file." << endl;

  // Write to the file.
  outputFile << "COSC 120" << endl;
  outputFile << "Computer Science I" << endl << endl;

  for (int i = 0; i < 100; i++) {
    outputFile << rand() << endl;
  }

  // Close the file
  outputFile.close();
  cout << "Done." << endl;

  return 0;
}
