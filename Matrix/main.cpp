//================================================================
// Author: Ryan Ellis
// Creation Date: 9/28/2024
// Last Update: 10/3/2024
// Description: Main function that includes class header file and implentation
// file and instantiates 3 objects of Matrix class and tests built in class
// functions.
//================================================================


//**FEEDBACK**
// Numeric constants in operators should be doubles and not ints.
// get should return a double.
//
// friend Matrix operator*(const Matrix&, int);
// should be a member function.
//
// double operator*(const Matrix &); ?
//
// Use setw in the display.
//
// The zero matrix will have memory access errors since it is 3X3 and the i and j correspond to a different matrix with unknown numbers of rows and columns.
//
// EC started, take a look at the solutions, you need an accumulator loop on the inside.
//
// In transpose you do not want to update the current array.

#include "Matrix.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {

    srand(time(0));             //set random seed

    Matrix A(3, 5, 3.14);       //instantiation of Matrix objects
    Matrix B = A;
    Matrix C;


    A.display(7);               //display A matrix of width 7
    cout << endl;

    for (int i = 0; i < A.getRows(); i++)       //set values of A with random double values 1000/100.0
      for (int j = 0; j < A.getCols(); j++)
        A.set(i, j, (rand() % 1000) / 10.0);

    A.display(7);
    cout << endl;                 //display A

    A.set(10, 3, -15);
    A.display(7);                 //set values of A at index [10][3] (out of bounds)
    cout << endl;

    A.set(1, 3, -15);             //set value of A at index [1][3] to -15
    A.display(7);
    cout << endl;

    cout << A.get(2, 2) << endl;      //get values of A at [2][2] and [2][20] (out of bounds)
    cout << A.get(2, 20) << endl;
    cout << endl;
    B.display();
    cout << endl;

    C = A = B;            //assignment operator for C

    A.display(7);         //display A
    cout << endl;

    C.display(6);         //display C
    cout << endl;

    for (int i = 0; i < B.getRows(); i++)       //set values of B and C to random values between 0-10
      for (int j = 0; j < B.getCols(); j++)
        B.set(i, j, rand() % 10);

    for (int i = 0; i < C.getRows(); i++)
      for (int j = 0; j < C.getCols(); j++)
        C.set(i, j, rand() % 10);


    B.display(7);           //display B
    cout << endl;

    C.display(7);           //display C
    cout << endl;

    A = B + C;              //assignment of A = B + C

    A.display(7);           //display A
    cout << endl;

    A = B - C;              //assignment of A = B - C

    A.display(7);           //display A
    cout << endl;

    for (int i = 0; i < A.getRows(); i++)     //set values of A to random 1000/100.0
      for (int j = 0; j < A.getCols(); j++)
        A.set(i, j, (rand() % 1000) / 10.0);


    A.display(7);       //display A
    cout << endl;


    B = 3 * A;          //assignment of B = 3 * A, display B
    B.display(7);
    cout << endl;

    B = A * 7;          //assignment of B = A * 7, display B
    B.display(7);
    cout << endl;

    B = 2 * A - 7 * C;    //assignment of B = 2 * A - 7 * C, display B
    B.display(7);
    cout << endl;

    A.display(7);       //display A
    cout << endl;

    A[2][2] = 123;      //indexing operator
    A[1][3] = -15;
    A[0][4] = -25;

    A.display(7);       //display A
    cout << endl;
    cout << A[0][1] << " " << A[1][4] << " " << A[2][3] << " " << endl;     //ostream operator call to print A at indexes

    //cout << A[10][11] << endl;      //Error

    cout << A << endl << endl;      //ostream operator to print out A

    Matrix D(3, 4);
    Matrix E(4, 2);                 //new instances of Matrices D and E

    for (int i = 0; i < D.getRows(); i++)
      for (int j = 0; j < D.getCols(); j++)
        D[i][j] = rand() % 11 - 5;

    for (int i = 0; i < E.getRows(); i++)
      for (int j = 0; j < E.getCols(); j++)       //set values of D and E to random values 0-6
        E[i][j] = rand() % 11 - 5;

    D.display(7);       //display D
    cout << endl;

    E.display(7);       //display E
    cout << endl;

    // cout<<"display B= D*E"<< endl;       //extra credit portion multiplication of matrices
    // B = D * E;
    // B.display(7);
    // cout << endl;

    cout << B << endl << endl;        //ostream operator to print B
    B = B.transpose();                //transpose B and print out B
    B.display(7);
    cout << endl;
    cout << B << endl << endl;        //ostream operator to print B
    return 0;
  }
