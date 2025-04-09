/*
 Author: Don Spickler
 Creation Date: 1/28/2022
 Last Update: 1/28/2022
 Description: Testing program that shows some functionality of the vector and
 iterators. User Interface: None
 */

#include <algorithm> // Required for STL algorithms
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

// Prototypes
template <class T> void print(vector<T> const &vect, bool nl = false);
template <class T> void printSizeCap(vector<T> const &vect);

void div();

int main() {
  srand(time(0));

  vector<int> vect;
  vector<int>::iterator vectIter;

  for (int i = 0; i < 10; i++)
    vect.push_back(i + 1);

  print(vect);

  vect.insert(vect.begin() + 5, 123);

  print(vect);

  div();

  vect.erase(vect.begin() + 8);
  print(vect);

  vect.erase(vect.begin() + 3, vect.end() - 2);
  print(vect);

  div();

  for (int i = 0; i < 20; i++)
    vect.push_back(rand() % 100);

  print(vect);
  random_shuffle(vect.begin(), vect.end());
  print(vect);
  random_shuffle(vect.begin(), vect.end());
  print(vect);

  sort(vect.begin(), vect.end());
  print(vect);

  vectIter = vect.begin();
  while (vectIter < vect.end()) {
    cout << *vectIter << "  ";
    vectIter++;
  }
  cout << endl;

  cout << "End Program" << endl;

  return 0;
}

/*
 Description: Print a vector of any data type, as long as the data type can be
 streamed. Parameters: vect - Vector to be printed to the console screen. nl -
 boolean that flags if there should be a line feed after each print. Return:
 None
 */

template <class T> void print(vector<T> const &vect, bool nl) {
  for (size_t i = 0; i < vect.size(); i++) {
    cout << vect[i] << " ";
    if (nl)
      cout << endl;
  }

  if (!nl)
    cout << endl;
}

/*
 Description: Prints the size and capacity the vector.
 Parameters: vect - Vector to use to print the size and capacity.
 Return: None
 */

template <class T> void printSizeCap(vector<T> const &vect) {
  cout << vect.size() << "  " << vect.capacity() << endl;
}

/*
 Description: Prints a dividing line.
 Parameters: None
 Return: None
 */

void div() {
  cout << endl << "----------------------------------" << endl << endl;
}
