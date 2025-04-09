#include <iostream>

using namespace std;

void moveDiscs(int num, int fromPeg, int toPeg, int tempPeg) {
  if (num > 0) {
    moveDiscs(num - 1, fromPeg, tempPeg, toPeg);
    cout << "Move a disc from peg " << fromPeg << " to peg " << toPeg << endl;
    moveDiscs(num - 1, tempPeg, toPeg, fromPeg);
  }
}

int main() {
  int NUM_DISCS = 3; // Number of discs to move

  cout << "Input number of disks: ";
  cin >> NUM_DISCS;

  const int FROM_PEG = 1; // Initial "from" peg
  const int TO_PEG = 3;   // Initial "to" peg
  const int TEMP_PEG = 2; // Initial "temp" peg

  // Play the game.
  moveDiscs(NUM_DISCS, FROM_PEG, TO_PEG, TEMP_PEG);
  cout << "All the pegs are moved!\n";
  return 0;
}
