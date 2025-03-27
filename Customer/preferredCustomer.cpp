//==============================================================
//Filename : preferredCustomer.cpp
//Author: Ryan Ellis
//Creation Date: 10/14/2024
//Last Update: 10/18/2024
//Description: Implementation file for the preferredCustomer class structure and public
//functions defined in the header file.
//Notes:
//==============================================================

#include "preferredCustomer.h"
#include <string>
#include <iostream>

//============================================================================
// Description: Function call will construct an object of the preferredCustomer
// class structure inherited from CustomerData class.
// Parameters:N/A
// Return: Constructor function, no return.
// Notes:
//============================================================================
preferredCustomer::preferredCustomer() : CustomerData(){

}
//============================================================================
// Description: Destructor for the preferredCustomer class, this is a placeholder
// function and doesn't need any further declarations.
// Parameters: N/A
// Return: Destructor function, no return.
// Notes:
//============================================================================
preferredCustomer ::~preferredCustomer(){

}
//====================================================
// Description: Function call will set the value of the
// customer purchase amount dependent on the passed
// parameter value into the function.
// Parameters: int num - purchase amount
// Return: void function, no return.
// Notes:
//====================================================
void preferredCustomer :: setPurchasesAmount(double num){
    if(num < 0){
        string exceptionString = "ERROR: Negative value.";
        throw exceptionString;
    }
    purchasesAmount = num;

    if(purchasesAmount >= 500.00 && purchasesAmount< 1000.00)
        setDiscountLevel(0.05);
    else if(purchasesAmount >= 1000.00 && purchasesAmount < 1500.00)
        setDiscountLevel(0.06);
    else if(purchasesAmount >= 1500.00 && purchasesAmount < 2000.00)
        setDiscountLevel(0.07);
    else if(purchasesAmount >= 2000.00)
        setDiscountLevel(0.1);
}

//====================================================
// Description: Function call will return the private value
// of the purchase amount.
// Parameters: N/A
// Return: int purchasesAmount
// Notes:
//====================================================
double preferredCustomer :: getPurchasesAmount(){
    return purchasesAmount;
}

//====================================================
// Description: Function call will set the value of the customer discount.
// Parameters: double discount - percentage double value of discount
// Return: void function, no return.
// Notes:
//====================================================
void preferredCustomer :: setDiscountLevel(double discount){
    discountLevel = discount;
}
//====================================================
// Description: Function call will return a double value of the
// customer's discount level based off purchases amount.
// Parameters: N/A
// Return: double discountLevel.
// Notes:
//====================================================
double preferredCustomer:: getDiscountLevel() {
    return discountLevel;
}
//====================================================
// Description: Function call will print out a string of concatenated information given
// the parent call function of CustomerData :: PrintRecord() and adding additional data regarding the
// customer number and if they are on the mailing list in a clean format.
// Parameters: N/A
// Return: void function, no return.
// Notes:
//====================================================
void preferredCustomer :: PrintRecord() {

    CustomerData :: PrintRecord();
    cout<<"Purchases Amount: "<<getPurchasesAmount()<<endl;
    cout<<"Discount Level: "<<to_string(getDiscountLevel() * 100) + "%"<<endl;


}

//====================================================
// Description: Function call will return a string of concatenated information given
// the parent call function of CustomerData:: getRecord() and adding additional data regarding the
// customer number and if they are on the mailing list in specific '/' format.
// Parameters: N/A
// Return: string of record data.
// Notes:
//====================================================
string preferredCustomer :: getRecord() {

    string out = CustomerData :: getRecord();
    string out1 = "";

    out1 ="/ Account : "+ to_string(getPurchasesAmount())  + "/ "+ "Discount: " + to_string(getDiscountLevel()*100) + "\n";
    return out + out1;
}
