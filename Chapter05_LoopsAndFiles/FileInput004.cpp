//============================================================================
// Name        : FileInput004.cpp
// Author      : Don Spickler
// Version     : 2/8/2020
// Description : File example of fstream and appending.
//============================================================================

#include <fstream>
#include <iostream>

using namespace std;

int main() {
  fstream dataFile;
  double price;
  int number;
  double total = 0;
  char ch;

  dataFile.open("DataFile01.txt", ios::in);

  if (!dataFile) {
    cerr << "Error opening file.\n";
    return 1;
  }

  while ((ch = dataFile.peek()) != EOF) {
    dataFile >> price;
    dataFile >> number;
    double cost = price * number;
    total += cost;
  }
  dataFile.close();

  dataFile.open("DataFile01.txt", ios::out | ios::app);
  dataFile << endl << "Total:  " << total << endl;
  dataFile.close();

  cout << "Done with total..." << endl;

  dataFile.open("DataFile02.txt", ios::in);

  if (!dataFile) {
    cerr << "Error opening file.\n";
    return 1;
  }

  dataFile.seekg(2L, ios::beg);
  dataFile.get(ch);
  cout << ch << endl;

  dataFile.seekg(0L, ios::beg);
  dataFile.get(ch);
  cout << ch << endl;

  dataFile.seekg(13L, ios::beg);
  dataFile.get(ch);
  cout << ch << endl;

  dataFile.seekg(3L, ios::cur);
  dataFile.get(ch);
  cout << ch << endl;

  dataFile.seekg(-4L, ios::end);
  dataFile.get(ch);
  cout << ch << endl;

  dataFile.close();

  return 0;
}
