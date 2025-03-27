//================================================================
// Author: Ryan Ellis
// Creation Date: 9/23/2024
// Last Update: 9/23/2024
// Description: Main function that includes class header file and implentation
// file and instantiates 2 objects of Array2D class and tests built in class functions.
// User Interface: 
// Notes: 
//================================================================

//----Feedback----
//Should check validity before creating B.
//display just include a setw

//Want
//for (int i = 0; i < rows; i ++)
    //delete[] A[i];

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array2D.h"

using namespace std;

int main() {
    srand(time(0));                 //set time seed
    
    Array2D A(3, 5, -1);            //instantiate new 2D arrays

    
    A.display();
    cout << endl;                   //display the array A
    
    for(int i = 0; i < A.getRows(); i++)
        for (int j = 0; j < A.getCols(); j++)     //sets values of 2D arrays to random values and then display them
            A.set(i, j, rand() % 100);

    A.display();
    cout << endl;

    A.resize(5,3);
    //A.set(10, 3, -15);                  //sets new values of A
    A.display();                        //display A
    cout << endl;
    
    A.resize(5,5);                   //sets new values of A
    A.display();                        //display A
    cout<<endl;
    
    A.resize(7,2);

    A.display();
    cout<< endl;

    A.resize(6, 5, 17);             //resize array and display

    A.display();
    cout << endl;

    A.display(4);
    cout << endl;
    
    return 0;
    
}
