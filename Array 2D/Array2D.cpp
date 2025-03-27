//================================================================
// Filename: Array2D.cpp
// Author: Ryan and Joshua Ellis
// Creation Date: 9/18/2024
// Last Update: 9/19/2024
// Description: This is the implementation file for the Array2D class
// structure. This includes the header file and lists all the public functions
// that are defined in that header.
// Notes: 
//================================================================

#include "Array2D.h"
#include <iostream> 

using namespace std;

//====================================================
// Description: Function call will construct an object of the Array2D
// class structure and take in parameters from user input in main function.
// Validity checking for values that are input, and then setting default value
// for each index in 2D array.
// Parameters:int r - number of rows passed in
//            int c - number of columns passed in
//            int defval - default value passed in
// Return: Constructor function, no return.
// Notes:
//====================================================
Array2D :: Array2D(int r, int c , int defval ){                 
    if (r < 1)
        r = 1;
    if (c < 1)
        c = 1;
    rows = r;
    cols = c;
    
    A = new int*[rows];
    
    for(int i = 0; i < rows; i++){
        A[i] = new int[cols];
    }
    
    for(int i = 0 ; i < rows; i++){
        for(int j = 0; j <cols; j++){
            A[i][j] = defval;
        }
    }
    
};
//====================================================
// Description: Destructor for the Array2D class, deletes columns and rows in array A
// and sets it to nullptr to free allocated memory.
// Parameters: N/A
// Return: Destructor function, no return.
// Notes:
//====================================================
Array2D:: ~Array2D(){
    for(int i = 0; i < rows; i++){
        delete[] A[i];
    }
    delete[] A;
    A = nullptr;
};
//====================================================
// Description: Function call will print out 2D array using for loop iteration indexing.
// Parameters: N/A
// Return: Void function, no return.
// Notes:
//====================================================
void Array2D:: display(){
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout<< A[i][j] << " ";
        }
        cout<<endl;
    }
};
//====================================================
// Description: Function call will access private data for rows and return that value.
// Parameters: N/A
// Return: private int rows.
//====================================================
int Array2D:: getRows(){
    return rows;
};
//====================================================
// Description: Function call will access private data for columns and return that value.
// Parameters: N/A
// Return: private int columns.
//====================================================
int Array2D:: getCols(){
    return cols;
};
//====================================================
// Description: Function call will take in parameters of row and column position and the
// value to be set in that index by the user. Validity checking for if row and column
// value exceed the boundaries.
// Parameters: int row - row position
//             int col - column position
//             int pos - set index value
// Return: Void function, no return.
// Notes:
//====================================================
void Array2D :: set(int row, int col, int pos){
    if (row > rows || col > cols)
        cerr<< "Index out of bounds"<<endl;
    else if(row < 0 || col < 0)
        cerr<< "Index out of bounds"<<endl;
    else
        A[row][col] = pos;
    
};

//====================================================
// Description: Function call will take in parameters of row and column position and
// will access that index and return its value. Validity checking for if row and column
// value exceed the boundaries.
// Parameters: int row - row position
//             int col - column position
//             int pos - set index value
// Return: int index value.
// Notes:
//====================================================
int Array2D :: get(int row, int col){
    if (row > rows || col > cols){
        cerr<< "Index out of bounds"<<endl;
        return 0;
    }
    else if(row < 0 || col < 0){
        cerr<< "Index out of bounds"<<endl;
        return 0;
    }
    else
        return A[row][col];
};
