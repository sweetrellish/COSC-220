//===========================================================================================================================
// Name        : matrix.h
// Author      : Ryan C. Ellis and Joshua Ellis
// Creation Date: 10/16/2024
// Last Update: 10/17/2024
// Description: Header file for the templated Matrix (2D array) class structure. Private values of a double pointer A, int rows
// and cols and class T default value along with public functions for the constructor/destructor, overloaded operators and
// accessors and mutators are listed and defined within the header for templating.
//===========================================================================================================================

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>

// FEEDBACK
// Got some memory issues.
// In the Constructor, CC and = you want to copy over the default value as well.  This will remove the memory error.
// You did not need to do a transpose but in your function your return type is not correct.

using namespace std;

template <class T> class Matrix {
private:
    T **A = nullptr;
    int rows;
    int cols;
    T defvalue;
    
public:
    Matrix(int , int , T defval);
    ~Matrix();
    Matrix(const Matrix &);
    Matrix<T> &operator = (const Matrix &);
    bool operator ==(const Matrix &) const;
    bool operator !=(const Matrix &) const;
    
    void display(int w = 0);
    int getRows();
    int getCols();
    void resize(int , int);
    void set(int, int, T);
    T get(int, int);
    
    T *operator[](const int &sub);
    
    template <class U>
    friend ostream &operator<<(ostream &, const Matrix<U> &);
    
    T transpose();
};

//============================================================================
// Description: Function call will construct an object of the templated Matrix
// class structure and take in parameters from user input in main function.
// Validity checking for values that are input, and then setting templated default value
// for each index in 2D array.
// Parameters:int r - number of rows passed in
//            int c - number of columns passed in
//            T defval - default value passed in
// Return: Constructor function, no return.
// Notes:
//============================================================================
 template <class T>
 Matrix<T>::Matrix(int r, int c, T defval) {
    if (r < 1)
        r = 1;
    if (c < 1)
        c = 1;
    rows = r;
    cols = c;
    
    A = new T *[rows];
    for (int i = 0; i < rows; i++)
        A[i] = new T[cols];
    
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            A[i][j] = defval;
}

//============================================================================
// Description: Destructor for the templated Matrix class, deletes columns and rows in array A
// and sets it to nullptr to free allocated memory.
// Parameters: N/A
// Return: Destructor function, no return.
// Notes:
//============================================================================
template <class T>
Matrix<T> :: ~Matrix() {
    for (int i = 0; i < rows; i++)
        delete[] A[i];
    delete[] A;
    A = nullptr;
}

//============================================================================
// Description: Copy constructor sets values of called object to object that
// is passed into parameters of constructor call.
// Parameters: const Matrix &mat - constant object of mat address.
// Return: Constructor function, no return.
// Notes:
//============================================================================
template <class T>
Matrix<T>::Matrix(const Matrix<T> &obj) {
    A = new T *[obj.rows];
    for (int i = 0; i < obj.rows; i++)
        A[i] = new T[obj.cols];
    
    for (int i = 0; i < obj.rows; i++)
        for (int j = 0; j < obj.cols; j++)
            A[i][j] = obj.A[i][j];
        
    rows = obj.rows;
    cols = obj.cols;
}

//============================================================================
// Description: Overloaded operator for the assignment operator in templated Matrix class.
// If the objects are equivalent already, return the object called, otherwise,
// clear current 2D array and set rows and columns to passed object values and
// populate called object with array values.
// Parameters: const Matrix &mat - constant Matrix of mat address.
// Return: templated Matrix object.
// Notes:
//============================================================================
template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix &right) {
    if(this == &right){
        return *this;
    }
    else{
        for(int i = 0; i < rows; i++)
            delete[] A[i];
        delete[] A;

        rows = right.rows;
        cols = right.cols;

        A = new T*[rows];

        for(int i = 0; i < rows; i++){
            A[i] = new T[cols];
            for(int j = 0; j < cols; j++){
                A[i][j] = right.A[i][j];
            }
        }
        return *this;
    }

}

//============================================================================
// Description: Function call will take in values of new sizes of rows and columns. The copy array values are set
// to the called objects values after checking sizes for boundary setting.
// Parameters: int row - number of new rows
//             int col - number of new columns
// Return: Void function, no return.
// Notes:
//============================================================================
template <class T>
void Matrix<T>::resize(int r, int c) {
    if (r < 1)
        r = 1;
    if (c < 1)
        c = 1;
    
    int **B = new T*[r];
    for (int i = 0; i < r; i++)
        B[i] = new T[c];
    
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            B[i][j] = -1;
        
    int minrows = rows;
    if (r < minrows)
        minrows = r;
    
    int mincols = cols;
    if (c < mincols)
        mincols = c;
    
    for (int i = 0; i < minrows; i++)
        for (int j = 0; j < mincols; j++)
            B[i][j] = A[i][j];
        
    for (int i = 0; i < rows; i++)
            delete[] A[i];
        delete[] A;
    
    rows = r;
    cols = c;
    A = B;
}

//============================================================================
// Description: Function call will print out 2D array using for loop iteration indexing
// and prints right justified array given passed value of width.
// Parameters: int width - spacing for justification.
// Return: Void function, no return.
// Notes:
//============================================================================
template <class T>
void Matrix<T> ::display(int w) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            if (w == 0)
                cout << A[i][j] << " ";
            else
                cout << setw(w) << A[i][j] << " ";
            
        cout << endl;
    }
}

//============================================================================
// Description: Function call will take in parameters of row and column position and the
// value to be set in that index by the user. Validity checking for if row and column
// value exceed the boundaries.
// Parameters: int row - row position
//             int col - column position
//             T val - set index value (templated)
// Return: Void function, no return.
// Notes:
//============================================================================
template <class T>
void Matrix<T> ::set(int r, int c, T val) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        cout << "Index out of bounds, no change to the array." << endl;
        return;
    }
    A[r][c] = val;
}

//============================================================================
// Description: Function call will take in parameters of row and column position and
// will access that index and return its value. Validity checking for if row and column
// value exceed the boundaries.
// Parameters: int row - row position
//             int col - column position
// Return: Templated index value.
// Notes:
//============================================================================
template <class T>
T Matrix<T> ::get(int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        cout << "Index out of bounds, returning default value" << endl;
        return -1;
    }
    return A[r][c];
}

//============================================================================
// Description: Function call will access private data for rows and return that value.
// Parameters: N/A
// Return: private int rows.
//============================================================================
template <class T>
int Matrix<T> ::getRows() { return rows; }

//============================================================================
// Description: Function call will access private data for columns and return that value.
// Parameters: N/A
// Return: private int columns.
//============================================================================
template <class T>
int Matrix<T> ::getCols() { return cols; }

//============================================================================
// Description: Overloaded operator for indexing operator in Matrix class. Conditional statement is set
// if index is within bounds to return that index value, else return nullptr.
// Parameters:const int &sub - index value
// Return: Templated pointer to rows.
// Notes:
//============================================================================
template <class T>
T *Matrix<T>::operator[](const int &sub) {
    if (sub >= 0 && sub < rows)
        return A[sub];
    else {
        return nullptr;
    }
}

//============================================================================
// Description: Function call will create dynamic 2D array to copy called object
// array, and then will wipe the current 2D array and populate it with the copy and
// swapped colum and row lengths. Values of each are swapped after and memory is freed.
// Parameters: N/A
// Return: Templated Matrix object with transposed 2D array.
// Notes: Not needed per feddback
//============================================================================
// template <class T>
// T Matrix<T>::transpose() {
//     Matrix C(cols, rows, 0);
//
//     for (int i = 0; i < C.rows; i++)
//         for (int j = 0; j < C.cols; j++)
//             C.A[i][j] = A[j][i];
//
//     return C;
// }

//============================================================================
// Description: Overloaded operator for stream operator in Templated Matrix class. This
// will set the formatting for how the Matrix object is to be passed through
// an ostream operation.
// Parameters:ostream &strm - ostream object
//            const Matrix<T> &mat - Templated Matrix object
// Return: ostream return type
// Notes:
//============================================================================
template <class T>
ostream &operator<<(ostream &strm, const Matrix<T> &obj) {
    strm << "[";
    for (int i = 0; i < obj.rows; i++) {
        strm << "[";
        for (int j = 0; j < obj.cols; j++) {
            
           strm <<obj.A[i][j];
           if(j <obj.cols -1)
               strm << " ";
        }
        strm << "]";
    }
    strm<<"]";
    return strm;
}

//============================================================================
// Description: Overloaded operator for equivalence operator in Templated Matrix class.
// Conditional if statement will check if rows and columns aren't the same size and will return false if true, otherwise for loop iteration will check each index value and return false if they aren't equivalent.
// Parameters: const Matrix &mat - constant Matrix object of mat address.
// Return: boolean value (true/false).
// Notes:
//============================================================================
template <class T> bool Matrix<T> ::operator==(const Matrix &right) const{
    if(rows != right.rows || cols != right.cols)
        return false;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j <cols; j++){
            if(A[i][j] != right.A[i][j])
                return false;
        }
    }
    return true;
}

//============================================================================
// Description: Overloaded operator for non-equivalence operator in Templated Matrix class. Function will return boolean value if called Templated Matrix object isn't equivalent to the passed object.
// Parameters: const Matrix &mat - constant Matrix object of mat address.
// Return: boolean value (true/false).
// Notes:
//============================================================================
template <class T> bool Matrix<T>::operator!=(const Matrix &right) const{
    return !(*this == right);
}

#endif
