//===========================================================================================================================
// Name        : matrix.h
// Author      : Ryan C. Ellis
// Creation Date: 10/16/2024
// Last Update: 10/24/2024
// Description: Header file for the templated Matrix (vector) class structure. Private values of a vector of a vector A, int rows
// and cols and class T default value along with public functions for the constructor/destructor, overloaded operators and
// accessors and mutators are listed and defined within the header for templating.
//===========================================================================================================================

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

//FEEDBACK
// In resize
// vector<vector<T>> B(r, vector<T>(c, defvalue));
//
// Got a bit of a logic error in the simulation.  The unfortunate thing here is that since the die class is just a pair of integers the compiler cannot (and should not) distinguish  between setting an int to a die.

template <class T> class Matrix {
private:

    int rows;
    int cols;
    T defvalue;
    vector <vector<T>> A;

public:
    Matrix(int , int , T defval);
    ~Matrix();
    Matrix(const Matrix &);
    Matrix<T> &operator =(const Matrix &);
    bool operator ==(const Matrix &) const;
    bool operator !=(const Matrix &) const;

    void display(int w = 0);
    int getRows();
    int getCols();
    void resize(int , int);
    void set(int, int, T);
    T get(int, int);

    vector<T> &operator[](const int &sub);

    template <class U>
    friend ostream &operator<<(ostream &, const Matrix<U> &);

    //vector<vector<T>> transpose();        //no transpose needed
};

//============================================================================
// Description: Function call will construct an object of the templated Matrix
// class structure and take in parameters from user input in main function.
// Validity checking for values that are input, and then setting templated default value
// for each index in vector of vector A.
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
    defvalue = defval;

    A.resize(rows);
    for(int i = 0; i < rows; i++){
        A[i].resize(cols, defval);
    }

}

//============================================================================
// Description: Destructor for the templated Matrix class, empty no code needed.
// Parameters: N/A
// Return: Destructor function, no return.
// Notes:
//============================================================================
template <class T>
Matrix<T> :: ~Matrix() {

}

//============================================================================
// Description: Copy constructor sets values of called object to object that
// is passed into parameters of constructor call.
// Parameters: const Matrix &obj - constant Matrix object of obj address.
// Return: Constructor function, no return.
// Notes:
//============================================================================
template <class T>
Matrix<T>::Matrix(const Matrix<T> &obj) {

    rows = obj.rows;
    cols = obj.cols;

    A.resize(rows);
    for (int i = 0; i < obj.rows; i++){
        A[i].resize(cols);
        for (int j = 0; j < obj.cols; j++){
            A[i][j] = obj.A[i][j];
        }
    }

}

//============================================================================
// Description: Overloaded operator for the assignment operator in templated Matrix class.
// If the objects are equivalent already, return the object called, otherwise,
// clear current vector of vector A and set rows and columns to passed object values and
// populate called object with vector values.
// Parameters: const Matrix &right - constant Matrix of right address.
// Return: templated Matrix object.
// Notes:
//============================================================================
template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix &right) {
    if(this == &right)
        return *this;

    rows = right.rows;
    cols = right.cols;

    A.resize(rows);

    for(int i = 0; i < rows; i++){
        A[i].resize(cols);
        for(int j = 0; j < cols; j++){
            A[i][j] = right.A[i][j];
        }
    }

    return *this;


}

//============================================================================
// Description: Function call will take in values of new sizes of rows and columns. The copy vector
// of vector values are set to the called objects values after checking sizes for boundary setting.
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

    vector<vector<T>> B(r, vector<T>(c));

    int minrows = rows;
    if (r < minrows)
        minrows = r;

    int mincols = cols;
    if (c < mincols)
        mincols = c;

    for (int i = 0; i < minrows; i++)
        for (int j = 0; j < mincols; j++)
            B[i][j] = A[i][j];

    rows = r;
    cols = c;
    A = B;
}

//============================================================================
// Description: Function call will print out vector of vector using for loop iteration indexing
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
        return defvalue;
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
// Description: Overloaded operator for indexing operator in Matrix class for vector
// of vector, no error checking.
// Parameters:const int &sub - index value
// Return: Templated pointer to rows.
// Notes:
//============================================================================
template <class T>
vector<T>& Matrix<T>::operator[](const int &sub) {
    //  no bounds checking per prompt
        return A[sub];

}

//============================================================================
// Description: Function call will create dynamic vector of vector to copy called object
// array, and then will wipe the current 2D array and populate it with the copy and
// swapped colum and row lengths. Values of each are swapped after and memory is freed.
// Parameters: N/A
// Return: Templated Matrix object with transposed vector of vector.
// Notes:
//============================================================================
// template <class T>
// vector<vector<T>> Matrix<T>::transpose() {
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
//            const Matrix<T> &obj - Templated Matrix object
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
// Conditional if statement will check if rows and columns aren't the same size and will return false if true, otherwise for loop
// iteration will check each index value and return false if they aren't equivalent.
// Parameters: const Matrix &right - constant Matrix object of right address.
// Return: boolean value (true/false).
// Notes:
//============================================================================
template <class T> bool Matrix<T> ::operator==(const Matrix &right) const{
    if(rows != right.rows || cols != right.cols){
        return false;
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j <cols; j++){
            if(A[i][j] != right.A[i][j]){
                return false;
            }
        }
    }
    return true;
}

//============================================================================
// Description: Overloaded operator for non-equivalence operator in Templated Matrix class. Function will return boolean value if called Templated Matrix object isn't equivalent to the passed object.
// Parameters: const Matrix &right - constant Matrix object of right address.
// Return: boolean value (true/false).
// Notes:
//============================================================================
template <class T> bool Matrix<T>::operator!=(const Matrix &right) const{
    return !(*this == right);
}

#endif
