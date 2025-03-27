//==============================================================
//Filename : persondata.h
//Author: Ryan Ellis
//Creation Date: 10/14/24
//Last Update: 10/18/2024
//Description: Header file for the PersonData class structure. Private data contains
//strings to hold relevant data such as name, address, phone, etc. Public functions
//include accessors and mutuators for private data and PrintRecord and getRecord
//which prints out data in a format.
//Notes: 
//==============================================================

#ifndef PERSONDATA_H
#define PERSONDATA_H
#include <string>

using namespace std;

class PersonData {
    
protected:
    string firstName = "";
    string lastName = "";
    string address = "";
    string city = "";
    string state = "";
    string zip = "";
    string phone = "";

public:
    PersonData();
    virtual ~PersonData();

    void setName(string, string);
    void setAddress(string, string, string, string);
    void setCity(string);
    void setState(string);
    void setZip(string);
    void setPhone(string);
    string getfirstName();
    string getlastName();
    string getAddress();
    string getCity();
    string getState();
    string getZip();
    string getPhone();

    virtual void PrintRecord();
    virtual string getRecord();
    
};

#endif
