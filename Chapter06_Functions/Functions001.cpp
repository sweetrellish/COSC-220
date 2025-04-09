//============================================================================
// Name        : Functions001.cpp
// Author      : Don Spickler
// Version     : 2/9/2020
// Description : Function example, basic syntax and program flow.
//============================================================================

#include <iostream>

using namespace std;

void displayMessage() { cout << "In displayMessage." << endl; }

int main() {
  cout << "In the main." << endl;
  displayMessage(); //  Function call.
  cout << "Back to the main." << endl;
  return 0;
}
