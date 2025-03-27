//==============================================================
//Filename : customerdata.h
//Author: Ryan Ellis
//Creation Date: 10/14/24
//Last Update: 10/18/2024
//Description: Header file for the CustomerData class structure which inherits from
//PersonData class structure and has additional private data of customerNumber and
//mailingList. Public functions access and mutate this data.
//Notes: 
//==============================================================

#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H
#include "persondata.h"

using namespace std; 

class CustomerData : public PersonData {
    
protected:
    
    int customerNumber = 0;
    bool mailingList = false;
    
    
public:
    CustomerData ();
    virtual ~CustomerData();

    void setCustomerNumber(int);
    void setMailingList(bool);
    int getcustomerNumber();
    bool getMailingList();
    
    void PrintRecord() ;
    string getRecord() ;
    
};

#endif

