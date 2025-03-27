//==============================================================
//Filename : preferredCustomer.h
//Author: Ryan Ellis
//Creation Date: 10/14/24
//Last Update: 10/18/2024
//Description: Header file for the preferredCustomer class structure which inherits from
//PersonData class structure and has additional private data of customerNumber and
//mailingList. Public functions access and mutate this data.
//Notes:
//==============================================================

#ifndef PREFERREDCUSTOMER_H
#define PREFERREDCUSTOMER_H
#include "customerdata.h"
#include <string>

using namespace std;

class preferredCustomer : public CustomerData {

protected:

    double purchasesAmount = 0.0;
    double discountLevel = 0.0;


public:
    preferredCustomer();
    virtual ~preferredCustomer();

    void setDiscountLevel(double);
    double getDiscountLevel() ;
    void setPurchasesAmount(double);
    double getPurchasesAmount() ;


    void PrintRecord();
    string getRecord();

};

#endif

