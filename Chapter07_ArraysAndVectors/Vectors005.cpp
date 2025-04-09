//============================================================================
// Name        : Vectors005.cpp
// Author      : Don Spickler
// Version     : 2/20/2020
// Description : Vector Example #5: File loading into a vector.
//============================================================================

#include <fstream>
#include <iostream>
#include <string>
#include <vector> // Load in vectors from the STL

using namespace std;

string toUpper(string);
string toLower(string);

int main() {
  ifstream inputFile;
  inputFile.open("words.txt");
  vector<string> dict;

  if (!inputFile) {
    cerr << "Error opening the file.\n";
    return 1;
  }

  string line = "";
  while (getline(inputFile, line)) {
    dict.push_back(line);
  }
  inputFile.close();

  cout << dict.size() << endl;
  cout << dict[dict.size() / 2] << endl;

  string word = "";
  cout << "Input word to find: ";
  cin >> word;

  word = toUpper(word);
  unsigned int i = 0;
  while (i < dict.size() && toUpper(dict[i]) != word)
    i++;

  if (i < dict.size())
    cout << "Word is in the dictionary.";
  else
    cout << "Word is not in the dictionary.";

  return 0;
}

string toUpper(string str) {
  for (unsigned int i = 0; i < str.length(); i++)
    str[i] = toupper(str[i]);

  return str;
}

string toLower(string str) {
  for (unsigned int i = 0; i < str.length(); i++)
    str[i] = toupper(str[i]);

  return str;
}
