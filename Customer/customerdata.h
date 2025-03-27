//==============================================================
//Filename : customerdata.h
//Author: Ryan and Joshua Ellis
//Creation Date: 10/9/24
//Last Update: 10/13/2024
//Description: Header file for the CustomerData class structure which inherits from
//PersonData class structure and has additional private data of customerNumber and
//mailingList. Public functions access and mutate this data.
//Notes: 
//==============================================================

#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H
#include "persondata.h"
#include <string>

using namespace std; 

class CustomerData : public PersonData {
    
private:
    
    int customerNumber;
    bool mailingList;
    
    
public:
    void setCustomerNumber(int);
    void setMailingList(bool);
    int getcustomerNumber();
    bool getMailingList();
    
    void PrintRecord();
    string getRecord();
    
};

#endif

