//============================================================================
// Name        : FileInput003.cpp
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
  ofstream outputFile;
  string inputfilename, outputfilename;
  int linecount = 0;

  cout << "Input the input filename: ";
  cin >> inputfilename;

  cout << "Input the output filename: ";
  cin >> outputfilename;

  // Open the files.
  inputFile.open(inputfilename);
  outputFile.open(outputfilename);

  // If the files were successfully opened continue.
  if (inputFile && outputFile) {
    string line;
    cout << endl;

    //  Read the input, print to the console and the output file.
    while (getline(inputFile, line)) {
      cout << line << endl;
      outputFile << line << endl;
      linecount++;
    }

    // Close the files.
    inputFile.close();
    outputFile.close();
  } else {
    // Display an error message.
    cerr << "Error opening the file.\n";
    return 1;
  }

  cout << endl;
  cout << "The file contained " << linecount << " lines." << endl;

  return 0;
}
