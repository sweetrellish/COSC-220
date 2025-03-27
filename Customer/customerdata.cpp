//==============================================================
//Author: Ryan and Joshua Ellis
//Creation Date: 10/9/2024
//Last Update: 10/13/2024
//Description: Implementation file for the CustomerData class structure and public
//functions defined in the header file.
//Notes: 
//==============================================================

#include "customerdata.h"
#include <iostream>
#include <string>

//====================================================
// Description: Function call will set the value of the
// customer number dependent on the passed
// parameter value into the function.
// Parameters: int num - customer number
// Return: void function, no return.
// Notes:
//====================================================
void CustomerData :: setCustomerNumber(int num){
    customerNumber = num;
}

//====================================================
// Description: Function call will return the private value
// of the customerNumber.
// Parameters: N/A
// Return: int customerNumber
// Notes:
//====================================================
int CustomerData :: getcustomerNumber(){
    return customerNumber;
}

//====================================================
// Description: Function call will set the value of if the
// customer is on the mailing list dependent on the passed
// parameter into the function.
// Parameters: bool set - boolean value if customer is on
// mailing list or not.
// Return: void function, no return.
// Notes:
//====================================================
void CustomerData :: setMailingList(bool set){
    mailingList = set;
}
//====================================================
// Description: Function call will return a true or false statement
// if the customer is on the mailing list.
// Parameters: N/A
// Return: boolean value (true/false).
// Notes:
//====================================================
bool CustomerData:: getMailingList(){
    return mailingList;
}
//====================================================
// Description: Function call will print out a string of concatenated information given
// the parent call function of PrintRecord and adding additional data regarding the
// customer number and if they are on the mailing list in a clean format.
// Parameters: N/A
// Return: void function, no return.
// Notes:
//====================================================
void CustomerData :: PrintRecord(){
    
    PersonData :: PrintRecord();
    
    string output = "";
    if(mailingList)
        output = "Yes";
    else
        output = "No";
    cout<<"Customer Number : "<<customerNumber<<endl;
    cout<<"On the mailing List:" <<output<<endl;
    
}

//====================================================
// Description: Function call will return a string of concatenated information given
// the parent call function of getRecord and adding additional data regarding the
// customer number and if they are on the mailing list in specific '/' format.
// Parameters: N/A
// Return: string of record data.
// Notes:
//====================================================
string CustomerData :: getRecord(){
    
    string out = PersonData :: getRecord();
    string out1 = "";
    string output = "";
    if(mailingList)
        output = "Yes";
    else
        output = "No";
    out1 =  "C#: " + to_string(customerNumber) + " / " + "ML: " + output;

    return out + out1;
}
