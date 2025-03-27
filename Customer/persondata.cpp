//================================================================
// Filename: persondata.cpp
// Author: Ryan and Joshua Ellis
// Creation Date: 10/9/2024
// Last Update: 10/13/2024
// Description: Implementation file for the PersonData class structure and public
// functions defined in the header file.
// Notes: 
//================================================================

#include "persondata.h"
#include <iostream>
#include <string>

using namespace std;

//====================================================
// Description: Function call will set the private value
// of the customer name given the passed values into the parameter
// of the first and last name of the customer.
// Parameters: string first - first name
//             string last - last name
// Return: void function, no return.
// Notes:
//====================================================
void PersonData :: setName(string first, string last){
    firstName = first;
    lastName = last;
}

//====================================================
// Description: Function call will set the private value
// of the customer address given the parameters of the street
// city, state and zip. Function calls to set these values will
// be within this function.
// Parameters: string street - street address
//             string c - city
//             string st - state
//             string z - zip code
// Return: void function, no return.
// Notes:
//====================================================
void PersonData :: setAddress(string street, string c, string st, string z){
    
    setCity(c);
    setState(st);
    setZip(z);
    
    address = street;
}

//====================================================
// Description: Function call will set the private value
// of the customer city of residence given the passed parameter.
// Parameters: string c - city
// Return: void function, no return.
// Notes:
//====================================================
void PersonData :: setCity(string c){
    city = c;
}

//====================================================
// Description: Function call will set the private value
// of the customer state of residence given the passed parameter.
// Parameters: string st - state
// Return: void function, no return.
// Notes:
//====================================================

void PersonData :: setState(string st){
    state = st;
    
}

//====================================================
// Description: Function call will set the private value
// of the customer zip code given the passed parameter.
// Parameters: string z - zip code
// Return: void function, no return.
// Notes:
//====================================================
void PersonData :: setZip(string z){
    zip = z;
}

//====================================================
// Description: Function call will set the private value
// of the customer phone number given the passed parameter.
// Parameters: string p - phone number
// Return: void function, no return.
// Notes:
//====================================================
void PersonData :: setPhone(string p){
    phone = p;
    
}

//====================================================
// Description: Function call will return the private value
// of the customer first name.
// Parameters: N/A
// Return: string firstName
// Notes:
//====================================================
string PersonData :: getfirstName(){
    return firstName;
}

//====================================================
// Description: Function call will return the private value
// of the customer last name.
// Parameters: N/A
// Return: string state
// Notes:
//====================================================
string PersonData :: getlastName(){
    return lastName;
}

//====================================================
// Description: Function call will return the private value
// of the customer address.
// Parameters: N/A
// Return: string address
// Notes:
//====================================================
string PersonData :: getAddress(){
    return address;
}

//====================================================
// Description: Function call will return the private value
// of the customer city of residence.
// Parameters: N/A
// Return: string city
// Notes:
//====================================================
string PersonData :: getCity(){
    return city;
}

//====================================================
// Description: Function call will return the private value
// of the customer state of residence.
// Parameters: N/A
// Return: string state
// Notes:
//====================================================
string PersonData :: getState(){
    return state;
}

//====================================================
// Description: Function call will return the private value
// of the customer zip code.
// Parameters: N/A
// Return: string zip
// Notes:
//====================================================
string PersonData :: getZip(){
    return zip;
}

//====================================================
// Description: Function call will return the private value
// of the customer phone number.
// Parameters: N/A
// Return: string phone
// Notes:
//====================================================
string PersonData :: getPhone(){
    return phone;
}

//====================================================
// Description: Function call will print out a string of concatenated information
// using function calls to get private data in a clean output format.
// Parameters: N/A
// Return: void function, no return.
// Notes:
//====================================================
void PersonData :: PrintRecord(){
    
    cout<<getlastName() + ", " + getfirstName()<<endl;
    cout<<getAddress()<<endl;
    cout<<getCity() + ", " + getState() + " " +getZip()<<endl;
    cout<<getPhone()<<endl;
    
}

//====================================================
// Description: Function call will return a string of concatenated information
// in specific '/' format between each set of values of private PersonData data.
// Parameters: N/A
// Return: string of record data.
// Notes:
//====================================================
string PersonData :: getRecord(){
    string record = getfirstName() + " " + getlastName() + " / "+ getAddress() + " / "+ getCity() + ", " + getState() + " " + getZip() + " / "+ getPhone() + " / ";
    return record;
}
