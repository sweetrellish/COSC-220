#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "matrix.h"

using namespace std;

void solveMaze(matrix<char> maze, matrix<char> &solmaze, int x, int y) {
  if (maze[x][y] == 'F') {
    maze[x][y] = '-';
    solmaze = maze;
  } else {
    maze[x][y] = '-';
    if ((x - 1 >= 0) && ((maze[x - 1][y] == ' ') || (maze[x - 1][y] == 'F')))
      solveMaze(maze, solmaze, x - 1, y);

    if ((y - 1 >= 0) && ((maze[x][y - 1] == ' ') || (maze[x][y - 1] == 'F')))
      solveMaze(maze, solmaze, x, y - 1);

    if ((x + 1 < maze.rows()) &&
        ((maze[x + 1][y] == ' ') || (maze[x + 1][y] == 'F')))
      solveMaze(maze, solmaze, x + 1, y);

    if ((y + 1 < maze.cols()) &&
        ((maze[x][y + 1] == ' ') || (maze[x][y + 1] == 'F')))
      solveMaze(maze, solmaze, x, y + 1);
  }
}

int main() {
  string filename;
  cout << "Enter the maze filename: ";
  cin >> filename;

  fstream mazefile;

  mazefile.open(filename.c_str());
  if (!mazefile) {
    cerr << "Cannot open " << filename << endl;
    exit(1);
  }

  char c;
  int rows = 0;
  int cols = 0;
  while (mazefile) {
    mazefile.get(c);
    if (c == '\n')
      rows++;
    if ((c != '\n') && (rows == 0))
      cols++;

    if (!mazefile)
      break;
  }

  rows++; // Add 1 since the last return is not counted.
  cols++; // Add 1 so we can store the end line character in the maze.
  mazefile.close();

  matrix<char> maze(rows, cols);

  //  Load maze into matrix.
  mazefile.open(filename.c_str());
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      mazefile.get(c);
      if (mazefile)
        maze[i][j] = c;
    }
  }

  mazefile.close();

  //  Find the S
  int sposx = 0;
  int sposy = 0;
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      if (maze[i][j] == 'S') {
        sposx = i;
        sposy = j;
      }

  //  Solve the maze.
  matrix<char> solmaze;
  solveMaze(maze, solmaze, sposx, sposy);

  //  Write Result to Screen
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      cout << solmaze[i][j];

  cout << endl;

  //  Write Result to Solution File
  string solfile = "Solution_" + filename;
  mazefile.open(solfile.c_str(), ios::out | ios::trunc);
  if (!mazefile) {
    cerr << "Cannot open " << solfile << endl;
    exit(1);
  }

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      mazefile.put(solmaze[i][j]);

  mazefile.close();

  return 0;
}
