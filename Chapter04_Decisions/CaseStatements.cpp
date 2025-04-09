//============================================================================
// Name        : CaseStatements.cpp
// Author      : Don Spickler
// Version     : 2/1/2020
// Description : Case (switch) statement example.
//============================================================================

#include <iostream>

using namespace std;

int main() {
  int modelNum; // Model number

  // Get a model number from the user.
  cout << "Our TVs come in three models:\n";
  cout << "The 100, 200, and 300. Which do you want? ";
  cin >> modelNum;

  // Display the model's features.
  cout << "That model has the following features:\n";
  switch (modelNum) {
  case 300:
    cout << "\tPicture-in-a-picture.\n";
  case 200:
    cout << "\tStereo sound.\n";
  case 100:
    cout << "\tRemote control.\n";
    break;
  default:
    cout << "You can only choose the 100,";
    cout << "200, or 300.\n";
  }

  cout << "That model has the following features:\n";
  switch (modelNum) {
  case 300:
    cout << "\tPicture-in-a-picture.\n";
    break;
  case 200:
    cout << "\tStereo sound.\n";
    break;
  case 100:
    cout << "\tRemote control.\n";
    break;
  default:
    cout << "You can only choose the 100,";
    cout << "200, or 300.\n";
  }

  cout << endl;

  char feedGrade;

  // Get the desired grade of feed.
  cout << "Our pet food is available in three grades:\n";
  cout << "A, B, and C. Which do you want pricing for? ";
  cin >> feedGrade;

  // Display the price.
  switch (feedGrade) {
  case 'a':
  case 'A':
    cout << "30 cents per pound.\n";
    break;
  case 'b':
  case 'B':
    cout << "20 cents per pound.\n";
    break;
  case 'c':
  case 'C':
    cout << "15 cents per pound.\n";
    break;
  default:
    cout << "That is an invalid choice.\n";
  }

  return 0;
}
