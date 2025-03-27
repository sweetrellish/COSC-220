//================================================================
// Filename: 
// Author: Ryan and Joshua Ellis
// Creation Date: 10/9/2024
// Last Update: 10/13/2024
// Description: 
// Notes: 
//================================================================

#include <iostream>
#include "persondata.h"
#include "customerdata.h"

using namespace std;

int main() {
    
    PersonData P1;
    
    P1.setName("Don", "Spickler");
    P1.setAddress("1101 Camden Ave.", "Salisbury", "MD", "21801");
    P1.setPhone("410-543-6148");
    P1.PrintRecord();
    
    cout << endl;
    cout << P1.getRecord() << endl;
    cout << endl;
    
    PersonData *P2 = new PersonData();
    
    P2->setName("John", "Doe");
    P2->setAddress("Nowhere Ave.", "Podunk", "NB", "66666");
    P2->setPhone("123-456-7890");
    P2->PrintRecord();
    
    cout << endl;
    cout << P2->getRecord() << endl;
    cout << endl;
    
    CustomerData *P3 = new CustomerData();
    P3->setName("Jane", "Doe");
    P3->setAddress("Nowhere Ct.", "Podunk", "NB", "66666");
    P3->setPhone("987-798-1111");
    P3->setCustomerNumber(12345);
    P3->setMailingList(false);
    P3->PrintRecord();
    cout << "\n" << P3->getRecord() << "\n\n";
    PersonData *P4;
    P4 = P3;
    P3->PrintRecord();
    cout << endl;
    P4 = P2;
    P4->PrintRecord();
    delete P2;
    delete P3;
    P2 = nullptr;
    P3 = nullptr;
    
    return 0;
}
