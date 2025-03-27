//===========================================================================================================================
// Name        : main.cpp - Lab6
// Author      : Ryan C. Ellis and Joshua Ellis
// Creation Date: 10/16/2024
// Last Update: 10/17/2024
// Description: Main function that includes Matrix class structure header file, and implements public functions to manipulate
// templated Matrix objects and overloaded functions associated with those objects within main.
//===========================================================================================================================

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "matrix.h"

using namespace std;

void div();

int main() {
    srand(time(0));

    Matrix<int> A(3, 5, -1);
    Matrix<string> B(3, 3, "George");
    A.display();
    cout << endl;
    B.display();
    div();
    for (int i = 0; i < A.getRows(); i++)
        for (int j = 0; j < A.getCols(); j++)
            A.set(i, j, rand() % 100);
    Matrix<int> C = A;
    A.display(5);
    cout << endl;
    C.display(5);
    cout << endl;
    A.set(2, 1, 123);
    A.set(1, 3, -15);
    A.display(5);
    cout << endl;
    C.display(5);
    div();
    A.set(20, 1, 123);
    cout << A.get(2, 2) << endl;
    cout << A.get(2, 20) << endl;
    cout << A << endl;
    div();
    A.resize(5, 6);
    A.display(5);
    cout << endl;
    A.resize(3, 6);
    A.display(5);
    cout << endl;
    A.resize(4, 5);
    A.display(5);
    div();
    for (int i = 0; i < A.getCols(); i++)
        A[A.getRows() - 1][i] = i + 1;
    A.display(5);
    div();
    C = A;
    A.display(5);
    cout << endl;
    C.display(5);
    div();
    if (C == A)
        cout << "Arrays are equal." << endl;
    else
        cout << "Arrays are not equal." << endl;
    A[0][0]++;
    if (C == A)
        cout << "Arrays are equal." << endl;
    else
        cout << "Arrays are not equal." << endl;
    if (C != A)
        cout << "Arrays are not equal." << endl;
    else
        cout << "Arrays are equal." << endl;
    return 0;
}
void div() { cout << "\n---------------------------------\n\n";     //definition of div function, prints out break line
}
