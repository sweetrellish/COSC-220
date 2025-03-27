// The program solves the 8-Queens problem. it prompts the user for
// the starting row for the queen in column 0 and calls the recursive
// backtracking function queens() to determine if there is a solution.
// if there is a solution, the position of the queens is passed to
// the chessboard object, board, and a call to its drawBoard() function
// shows the placement of the queens.
// This is an update from the textbook of Ford and Topp.

#include <iostream>
#include <vector>

using namespace std;

// Can a queen at (row,col) be attacked by any of the
// non-attacking queens in columns 0 to col-1 ?
bool safeLocation(int row, int col, const vector<int> &queenList) {
  for (int qCol = 0; qCol < col; qCol++) {
    int qRow = queenList[qCol];
    if (qRow == row)
      return false;
    else if (qCol == col)
      return false;
    else if (qCol - qRow == col - row || qCol + qRow == col + row)
      return false;
  }
  return true;
}


// Place a queen in columns col through 7
void placeQueens(vector<int> &queenList, int col, vector<vector<int>> & sol) {

  if (col == 8){ // stopping condition
    sol.push_back(queenList); //add queenlist vector to solutions
    return;
  }
    for(int row = 0; row < 8; row++){         //recursive call to determine solution vector
      if (safeLocation(row, col, queenList)) {
        queenList[col] = row;
        placeQueens(queenList, col + 1, sol);

    }
  }

}

int main() {
  vector<int> queenList(8);
  vector<vector<int>> solutions;    //vector declarations


  for(int i = 0; i < 8; i++){       //function call to populate solution vector of vectors with all solutions
    queenList[0] = i;
    placeQueens(queenList,1 ,solutions );
  }


  if(solutions.empty()){
    cout << "No solution" << endl;    //print out if no solutions

  } else{
        //print out all solutions using range for loop
    for(const vector<int> &solution : solutions){
      for(int i = 0; i < 8; i++){
        cout<< solution[i]<< " ";
      }
      cout<<endl;
    }cout<<"Total solutions: "<<solutions.size()<<endl;
  }



  return 0;
}
