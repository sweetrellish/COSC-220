//============================================================================
// Name        : main.cpp (2DArray)
// Author      : Ryan C. Ellis
// Creation Date: 9/10/2024
// Last Update: 9/12/2024
// Description: This program creates 2 Dimensional arrays and has a few
// functions that are used to manipulate these arrays dynamically.
//
// User Interface: No prompts for user input.
// Notes: This program will output 2 dimensional arrays ofvarying sizes and
// values
//
// Prof Feedback: delete2Darray send A by reference.
// resize2Darray delete array
// copyArray do not want array = ptr;
// 
// Code after feedback : still get seg fault after resize call
//============================================================================
#include <iostream>

using namespace std;

int **create2Darray(int, int);
void delete2Darray(int **&, int);
void print2Darray(int **, int, int);
void resize2Darray(int **&, int, int, int, int);
int **copyArray(int **&, int, int);

int main() {
  int **A = create2Darray(3, 5);

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 5; j++)
      A[i][j] = i + j + 1;

  print2Darray(A, 3, 5);
  cout<<endl;

  resize2Darray(A,3 ,5 ,7 ,8 );
  print2Darray(A,7 ,8 );
  cout<<endl;

  A[4][1] = A[4][3] = A[5][0] = A[5][1] = A[5][7] = 12;
  print2Darray(A, 7, 8);
  cout<<endl;

  resize2Darray(A, 7,8 ,6 ,4 );
  print2Darray(A, 6, 4);
  cout << endl;

  resize2Darray(A, 6, 4, 4, 6);
  print2Darray(A, 4, 6);
  cout<<endl;

  int **B = copyArray(A, 4, 6);
  print2Darray(B,4 ,6 );
  cout << endl;

  cout << A << endl;
  cout << B << endl;

  delete2Darray(A, 4);
  delete2Darray(B, 4);


  return 0;
}
//============================================================================
// Description: Function call will take in size of rows and columns  which get
// passed into the function. A double pointer A is created and set to the size
// of rows and columns passed in by user via a for loop for columns and rows
// dynamically allocated.
// Parameters: int rows - number of rows in new array
//             int cols - number of columns in new array
// Return: 2D array 'A'
// Notes: N/A
//============================================================================
int **create2Darray(int rows, int cols) {
  int **A = new int *[rows];
  for (int i = 0; i < rows; i++)
    A[i] = new int[cols];

  return A;
}
//============================================================================
// Description: Function call will take in double pointer 2D array A and size of
// rows which get passed into the function. For loop will go through A and
// delete columns, and then deletes rows of A. A is set to nullptr.
// Parameters: int **&A - 2D Array passed by reference
//             int rows - number of rows in new array
// Return: void function no return.
// Notes: N/A
//============================================================================
void delete2Darray(int **&A, int rows) {
  for (int i = 0; i < rows; i++)
    delete[] A[i];
  delete[] A;

  A = nullptr;
}
//============================================================================
// Description: Function call will take in double pointer 2D Array and size of
// rows and columns which get passed into the function. Nested for loops will go
// through every iteration of A indexed by i and j and print them to the
// terminal.
// Parameters: int **&A - 2D Array passed by reference
//             int rows - number of rows in  array
//             int cols - number of columns in array
// Return: void function no return.
// Notes: N/A
//============================================================================
void print2Darray(int **A, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      cout << A[i][j] << " ";

    cout << endl;
  }
}
//============================================================================
// Description: Function call will take in double pointer 2D Array and size of
// current rows and columns along with new sizes for rows and columns which get
// passed into the function. Dynamically allocated copy array 'arr' is set to
// the new values of rows and columns. A nested for loop runs through each
// iteration of arr up until the boundary of new rows and columns and breaks
// once that condition is met. The values of array passed in are set to arr at
// each index, and then arr is set to nullptr.
// Parameters: int **&array - 2D Array passed by reference
//             int row - number of rows in passed array
//             int col - number of columns in passed array
//             int newRow - number of new rows
//             int newCol - number of new col
// Return: void function no return.
// Notes: N/A
//============================================================================
void resize2Darray(int **&array, int row, int col, int newRow, int newCol){

  int **arr = new int *[newRow]{0};   //initialize new array to have all 0s
  for (int i = 0; i < newRow; i++)
    arr[i] = new int[newCol]{0};

  if(newRow < row)
    row = newRow;
  if(newCol < col)
    col = newCol;

  for (int i = 0; i < row; i++){    //set current values of passed array to new array
    for (int j = 0; j < col; j++) {
      if (i == newRow || j == newCol)
        break;
      else
        arr[i][j] = array[i][j];
    }
                                    //set passed array equal to new array
  }

  //call delete array on old num of rows for array
  array = arr;
  d;
  arr = nullptr;

}
//============================================================================
// Description: Function call will take in double pointer 2D Array and size of
// rows and columns which get passed into the function. Dynamically allocated
// copy array 'ptr' is set to the size values of rows and columns. Nested for
// loops set values of passed array to copy array.
// Parameters: int **&array - 2D array passed by reference
//             int row - number of rows
//             int col - number of columns
// Return: pointer 2D array ptr
// Notes: N/A
//============================================================================
int **copyArray(int **&array, int row, int col) {

  int **ptr = new int*[row];          // initialize new dynamic pointer to copy array

  for (int i = 0; i < col; i++){
    ptr[i] = new int[col];
  }

  for (int i = 0; i < row; i++){
    for (int j = 0; j < col; j++){    //set array equal to copy
      ptr[i][j] = array[i][j];
      }
    }
                                      //make pointer equal to copy and return pointer
  //array = ptr;
  return ptr;

}
