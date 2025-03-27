//================================================================
// Filename: Matrix.cpp
// Author: Ryan Ellis
// Creation Date: 9/28/2024
// Last Update: 10/3/2024
// Description: This is the implementation file for the Matrix class
// structure. This includes the header file and lists all the public functions
// that are defined in that header.
// Notes: 
//================================================================

#include "Matrix.h"
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
Matrix :: Matrix(int r, int c , double defval  ){
    if (r < 1)
        r = 1;
    if (c < 1)
        c = 1;
    rows = r;
    cols = c;
    
    A = new double*[rows];
    
    for(int i = 0; i < rows; i++){
        A[i] = new double[cols];
        for(int j = 0; j <cols; j++){
            A[i][j] = defval;
        }
    }

    
}

//============================================================================
// Description: Copy constructor sets values of called object to object that
// is passed into parameters of constructor call.
// Parameters: const Matrix &mat - constant object of mat address.
// Return: Constructor function, no return.
// Notes:
//============================================================================
Matrix :: Matrix(const Matrix &mat){
    rows = mat.rows;
    cols = mat.cols;

    A = new double*[rows];

    for(int i = 0; i < rows; i++){
        A[i] = new double[cols];
    }
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            A[i][j] = mat.A[i][j];
}


//====================================================
// Description: Destructor for the Matrix class, deletes columns and rows in array A
// and sets it to nullptr to free allocated memory.
// Parameters: N/A
// Return: Destructor function, no return.
// Notes:
//====================================================
Matrix:: ~Matrix(){
    for(int i = 0; i < rows; i++){
        delete[] A[i];
    }
    delete[] A;
}


//====================================================
// Description: Function call will print out 2D array using for loop iteration indexing
// and prints right justified array given passed value of width.
// Parameters: int width - spacing for justification.
// Return: Void function, no return.
// Notes:
//====================================================
void Matrix:: display(int width){
    int count = 0;

    if(width > 0){
        for (int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                while(count < width){
                    cout<<" ";
                    count++;
                }
                cout<< A[i][j];
                count = 0;
            }

            cout<<endl;
        }
    }
}


//====================================================
// Description: Function call will access private data for rows and return that value.
// Parameters: N/A
// Return: private int rows.
//====================================================
int Matrix:: getRows(){
    return rows;
}


//====================================================
// Description: Function call will access private data for columns and return that value.
// Parameters: N/A
// Return: private int columns.
//====================================================
int Matrix:: getCols(){
    return cols;
}


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
void Matrix :: set(int row, int col, double pos){
    if (row >= rows || col >= cols)
        cerr<< "Index out of bounds"<<endl;
    else if(row < 0 || col < 0)
        cerr<< "Index out of bounds"<<endl;
    else
        A[row][col] = pos;
    
}


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
int Matrix :: get(int row, int col){
    if (row >= rows || col >= cols){
        cerr<< "Index out of bounds"<<endl;
        return 0;
    }
    else if(row < 0 || col < 0){
        cerr<< "Index out of bounds"<<endl;
        return 0;
    }
    else
        return A[row][col];
}

//============================================================================
// Description: Function call will create dynamic 2D array to copy called object
// array, and then will wipe the current 2D array and populate it with the copy and
// swapped colum and row lengths. Values of each are swapped after and memory is freed.
// Parameters: N/A
// Return: Matrix object with transposed 2D array.
// Notes:
//============================================================================
Matrix Matrix :: transpose(){
    double **T = new double*[cols];

    for (int i = 0; i < cols; i++)
        T[i] = new double[rows];

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            T[j][i] = A[i][j];

    for (int i = 0; i < rows; i++)
        delete [] A[i];

    delete[] A;
    A = T;

    int temp = rows;
    rows = cols;
    cols = temp;

    return *this;
}

//============================================================================
// Description: Overloaded operator for the assignment operator in Matrix class.
// If the objects are equivalent already, return the object called, otherwise,
// clear current 2D array and set rows and columns to passed object values and
// populate called object with array values.
// Parameters: const Matrix &mat - constant Matrix of mat address.
// Return: Matrix object.
// Notes:
//============================================================================
Matrix Matrix :: operator=(const Matrix &mat){
    if(this == &mat){
        return *this;
    }
    else{
        for(int i = 0; i < rows; i++)
            delete[] A[i];
        delete[] A;

        rows = mat.rows;
        cols = mat.cols;

        A = new double*[rows];

        for(int i = 0; i < rows; i++){
            A[i] = new double[cols];
            for(int j = 0; j < cols; j++){
                A[i][j] = mat.A[i][j];
            }
        }
        return *this;
    }
}


//============================================================================
// Description: Overloaded operator for the addition operator in Matrix class.
// Conditional statement for if rows and columns are equal and then add values
// within arrays if true, otherwise return 1x1 zeroed array.
// Parameters: const Matrix &mat - constant Matrix of mat address.
// Return: Matrix object.
// Notes:
//============================================================================
Matrix Matrix :: operator+(const Matrix &mat){
    Matrix temp = mat;
    Matrix temp2 = *this;
    Matrix zero;

    if(temp.rows == temp2.rows && temp.cols == temp2.cols){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                temp2.A[i][j] += temp.A[i][j];
            }
        }
    }
    else{
        for(int i = 0; i < 1; i++)
            for(int j = 0; j <1; j++)
                zero.A[i][j] = 0;
        return zero;
    }
    return temp2;

}

//============================================================================
// Description: Overloaded operator for the subtraction operator in Matrix class.
// Conditional statement for if rows and columns are equal and then subtract values
// within arrays if true, otherwise return 1x1 zeroed array.
// Parameters: const Matrix &mat - constant Matrix of mat address.
// Return: Matrix object.
// Notes:
//============================================================================
Matrix Matrix :: operator-(const Matrix &mat){
    Matrix temp = mat;
    Matrix temp2 = *this;
    Matrix zero;

    if(temp.rows == temp2.rows && temp.cols == temp2.cols){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                temp2.A[i][j] -= temp.A[i][j];
            }
        }
    }
    else{
        for(int i = 0; i < 1; i++)
            for(int j = 0; j <1; j++)
                zero.A[i][j] = 0;
        return zero;
    }
    return temp2;
}

//============================================================================
// Description: Overloaded operator for the multiplication operator in Matrix class.
// Conditional statement for if rows and columns are equal and then multiply values
// within arrays if true and returns the sum of this as a scalar product.
// Parameters: const Matrix &mat - constant Matrix of mat address.
// Return: Matrix object.
// Notes: ***ATTENTION PROF DON*** This is my feeble attempt at the extra credit.
// The output that I get from this function doesn't match up to what is in the prompt.
// This function sets values of matrices to 0 and then transpose will run with no issue.
// I've reworked it several times and it just doesn't want to work with me. Hopefully there
// is some merit in here for some partial credit on the extra credit, if not I understand!
//============================================================================
double Matrix::  operator*(const Matrix &mat){

    double sum= 0.0;

    if(this->cols == mat.rows){
        for(int i = 0; i< cols; i++){
            for(int j = 0; j< mat.rows; j++){
                sum += (this->A[i][j]*mat.A[j][i]);
            }
        }
        return sum;
    }
    else{
        cerr<<"Matrices must be same.";
        return -1;
    }

}

//============================================================================
// Description: Overloaded operator for the multiplication operator in Matrix class.
// Temp Matrix object holds values of passed int, and is multiplied to every index
// of copy Matrix of called object.
// Parameters: int val - value to multiply as scalar.
// Return: Matrix object.
// Notes:
//============================================================================
Matrix Matrix :: operator*(int val){
    Matrix temp(rows, cols, val);
    Matrix temp2 = *this;

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            temp2[i][j] *= temp[i][j];

    return temp2;
}
//============================================================================
// Description: Overloaded operator for the multiplication operator in Matrix class.
// This instance takes in int value and Matrix value to relate on left and right
// side of assignment and multiplies all values in array by scalar.
// Parameters: const Matrix &mat - constant Matrix of mat address.
//             int r - right hand int in expression.
// Notes:
//============================================================================
Matrix operator*(const Matrix &mat, int r){
    Matrix temp = mat;

    for(int i = 0; i < temp.rows; i++)
        for(int j = 0; j < temp.cols; j++)
            temp.A[i][j] *= r;

    return temp;
}

//============================================================================
// Description: Overloaded operator for the multiplication operator in Matrix class.
// This instance takes in int value and Matrix value to relate on left and right
// side of assignment and multiplies all values in array by scalar.
// Parameters: const Matrix &mat - constant Matrix of mat address.
//             int l - left hand int in expression.
// Return: Matrix object.
// Notes:
//============================================================================
Matrix operator*(int l, const Matrix &mat){
     Matrix temp = mat;

    for(int i = 0; i < temp.rows; i++)
        for(int j = 0; j < temp.cols; j++)
            temp.A[i][j] *= l;

    return temp;
}

//============================================================================
// Description: Overloaded operator for stream operator in Matrix class. This
// will set the formatting for how the Matrix object is to be passed through
// an ostream operation.
// Parameters:ostream &strm - ostream object
//            const Matrix &mat - Matrix object
// Return: ostream return type
// Notes:
//============================================================================
ostream &operator<<(ostream &strm, const Matrix &mat){
    strm << "[";
    for(int i = 0; i < mat.rows; i++){
        strm << "[";
        for(int j = 0; j < mat.cols; j++){
            strm << mat.A[i][j]<< " ";
        }
        strm<<"]";
    }
    strm << "]";
    return strm;
}

//============================================================================
// Description: Overloaded operator for indexing operator in Matrix class.
// Temp double pointer is initialized to null and then set equal to pointer
// of rows A in mat, and temp is returned.
// Parameters:const Matrix &mat - constant Matrix object of mat address.
// Return: double pointer to rows.
// Notes:
//============================================================================
double* Matrix :: operator[](const int &i){
    if (i >= rows ){
        cerr<< "Index out of bounds"<<endl;
        return nullptr;
    }
    else if(i < 0){
        cerr<< "Index out of bounds"<<endl;
        return nullptr;
    }
    else
        return A[i];

}

//============================================================================
// Description: Overloaded operator for equivalence operator in Matrix class.
// Conditional if statement will check if rows and columns are the same size and
// will proceed to check each index if true, and return false otherwise.
// Parameters: const Matrix &mat - constant Matrix object of mat address.
// Return: boolean value (true/false).
// Notes:
//============================================================================
bool Matrix :: operator==(const Matrix &mat){
    Matrix temp = mat;
    bool check = false;

    if(rows == temp.rows && cols == temp.cols){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(A[i][j] == temp[i][j])
                    check = true;
            }
        }
    }

    if(check)
        return true;
    else
        return false;
}
