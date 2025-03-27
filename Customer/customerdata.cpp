//==============================================================
//Author: Ryan Ellis
//Creation Date: 10/14/2024
//Last Update: 10/18/2024
//Description: Implementation file for the CustomerData class structure and public
//functions defined in the header file.
//Notes: 
//==============================================================

#include "customerdata.h"
#include <iostream>
#include <string>

//============================================================================
// Description: Function call will construct an object of the CustomerData
// class structure inherited from PersonData class.
// Parameters:N/A
// Return: Constructor function, no return.
// Notes:
//============================================================================
CustomerData :: CustomerData() :PersonData(){

}
//============================================================================
// Description: Destructor for the CustomerData class, this is a placeholder
// function and doesn't need any further declarations.
// Parameters: N/A
// Return: Destructor function, no return.
// Notes:
//============================================================================
CustomerData :: ~CustomerData(){

}
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
void CustomerData :: PrintRecord() {
    
    PersonData :: PrintRecord();
    
    string output = "";
    if(mailingList)
        output = " Yes";
    else
        output = " No";
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
string CustomerData :: getRecord() {
    
    string output0 = PersonData :: getRecord();
    string output1 = "";
    string output = "";
    if(mailingList)
        output = "Yes";
    else
        output = "No";
    output1 =  "C#: " + to_string(customerNumber) + " / " + "ML: " + output + "\n";

    return output0 + output1;
}
