//================================================================
// Author: Ryan and Joshua Ellis
// Creation Date: 9/18/2024
// Last Update: 9/19/2024
// Description: Main function that includes class header file and implentation
// file and instantiates 2 objects of Array2D class and tests built in class functions.
// User Interface: 
// Notes: 
//================================================================


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array2D.h"

using namespace std;

int main() {
    srand(time(0));                 //set time seed
    
    Array2D A(3, 5, -1);            //instantiate new 2D arrays
    Array2D B;
    
    A.display();
    cout << endl;                   //display the array A
    
    for(int i = 0; i < A.getRows(); i++){
        for (int j = 0; j < A.getCols(); j++){      //sets values of 2D arrays to random values and then display them
            A.set(i, j, rand() % 100);
        }
        A.display();
    }
    cout << endl;
    
    A.set(10, 3, -15);                  //sets new values of A
    A.display();                        //display A
    cout << endl;
    
    A.set(1, 3, -15);                   //sets new values of A
    A.display();                        //display A
    
    cout << endl;
    cout << A.get(2, 2) << endl;        //gets values of A given row and column values
    cout << A.get(2, 20) << endl;
    cout << endl;
    
    B.display();                        //display B
    
    return 0;
    
}
