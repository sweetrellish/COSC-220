//==========================================================================================================================
// Filename : Matrix.h
// Author: Ryan Ellis
// Creation Date: 9/28/24
// Last Update: 10/3/24
// Description: This header file outlines the Matrix class structure and contains private data of double pointer A which is
// set to nullptr, and int rows for number of rows in the 2D array, and int columns to hold the number of columns in the array.
// Public functions inlcude the constructor, which is set to default values, the destructor, a function to display the array,
// to get rows, get columns, the set/get functions for the array, and a transpose function. Overloaded operator functions
// are defined for the use of computation and comparison of Matrix objects.
// Notes:
//========================================================================================================================

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;



class Matrix {
    
private:
    double** A = nullptr;
    int rows;
    int cols;
    
public:
    Matrix(int r = 5, int c = 5, double defval = 0.0);
    Matrix(const Matrix &);
    ~Matrix();
    void display(int width = 2);
    int getRows();
    int getCols();
    void set(int, int, double);
    int get(int, int);
    Matrix transpose();

    Matrix operator=(const Matrix &);
    Matrix operator+(const Matrix &);
    Matrix operator-(const Matrix &);
    double operator*(const Matrix &);
    Matrix operator*(int);
    double* operator[](const int &);
    bool operator==(const Matrix &);


    friend ostream &operator<<(ostream &, const Matrix &);
    friend Matrix operator*(const Matrix&, int);
    friend Matrix operator*(int, const Matrix &);
};

#endif
