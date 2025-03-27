//===========================================================================================================================
// Name        : main.cpp
// Author      : Ryan C. Ellis
// Creation Date: 11/12/2024
// Last Update: 11/14/2024
// Description: Updated main program for Towers of Hanoi (3 pegs) to use 4 pegs. Implemented new function hanoi4 to execute
// this solution.
//===========================================================================================================================
#include <iostream>

using namespace std;


void moveDiscs(int num, char fromPeg, char toPeg, char tempPeg, int &count) {   //original move disc function to move discs for 3 pegs

  if (num > 0) {
    moveDiscs(num - 1, fromPeg, tempPeg, toPeg, count);
    cout << "Move " << fromPeg << " to " << toPeg << endl;
    moveDiscs(num - 1, tempPeg, toPeg, fromPeg, count);
    count++;
  }
}
void hanoi4(int num, char fromPeg, char toPeg, char tempPeg, char fourPeg, int &count){   //function to move discs with 4 pegs

  if(num <= 0)
    return;     //stop condition for recursion

  if(num == 1){
    cout<<"Move "<<fromPeg <<" to "<<fourPeg<<endl;   //if there is 1 disc, move it to the end
    count++;
  }

  if(num >= 2){
    hanoi4(num - 2, fromPeg, fourPeg, toPeg, tempPeg, count);   //solve problem from first peg to first temp peg
    cout<< "Move "<<fromPeg<< " to "<<fourPeg<<endl;
    count++;
    cout<< "Move "<<fromPeg <<" to "<< toPeg<<endl;         //move the pegs
    count++;
    cout<< "Move "<< fourPeg<<" to "<< toPeg<<endl;
    count++;
    hanoi4(num - 2, tempPeg, fromPeg, fourPeg, toPeg, count); //solve problem again from temp peg to end peg
  }

}
int main() {
  int NUM_DISCS = 3; // Number of discs to move

  cout << "Input number of disks: ";
  cin >> NUM_DISCS;

  const char FROM_PEG = 'A'; // Initial "from" peg
  const char TO_PEG = 'B';   // Initial "to" peg
  const char TEMP_PEG = 'C'; // Initial "temp" peg
  const char FOUR_PEG = 'D'; //fourth peg

  int count1 = 0;   //counters for moves
  int count2 = 0;

  // Play the game.
  cout<<"The solution for n = "<<NUM_DISCS<<" Using 3 pegs"<<endl;      //print out solutions and number of moves
  moveDiscs(NUM_DISCS, FROM_PEG, TO_PEG, TEMP_PEG, count1);
  cout<<"Number of moves used in the solution: "<<count1<<endl;
  cout<<"The solution for n = "<<NUM_DISCS<<" Using 4 pegs"<<endl;
  hanoi4(NUM_DISCS, FROM_PEG, TO_PEG, TEMP_PEG, FOUR_PEG, count2);
  cout<<"Number of moves used in the solution: "<<count2<<endl;
  return 0;
}
