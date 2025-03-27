//==============================================================
// Filename : Array2D.h
// Author: Ryan Ellis
// Creation Date: 9/23/24
// Last Update: 9/26/2024
// Description: This header file outlines the Array2D class structure
// and contains private data of double pointer A which is set to nullptr,
// and int rows for number of rows in the 2D array, and int columns to hold
// the number of columns in the array. Public functions inlcude the constructor,
// which is set to default values, the destructor, a function to
// display the array, to get rows, get columns and the set/get
// functions for the array.
// Notes:
//==============================================================

#ifndef ARRAY2D_H
#define ARRAY2D_H



class Array2D {
    
private:
    int** A = nullptr;
    int rows;
    int cols;
    
public:
    Array2D(int r = 3, int c = 3, int defval = 0);
    ~Array2D();
    void resize(int row =3 , int col =3, int val=0 );
    void display();
    int getRows();
    int getCols();
    void set(int, int, int);
    int get(int, int);
    void display(int);
};

#endif
