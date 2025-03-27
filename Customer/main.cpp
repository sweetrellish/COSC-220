//================================================================
// Filename: main.cpp
// Author: Ryan Ellis
// Creation Date: 10/14/2024
// Last Update: 10/18/2024
// Description: Main function that sets a prompt for the user to select
// between creation of a PersonData object, CustomerData object, preferredCustomer
// data object, printing of the customer object record in short or long form,
// or quit the program. Function reads in header files for parent class
// structure PersonData and both child class structures of CustomerData and
// preferredCustomer.
// Notes: 
//================================================================

#include <iostream>
#include <string>
#include "customerdata.h"
#include "persondata.h"
#include "preferredCustomer.h"

// FEEDBACK
// Nice Job!

using namespace std;

void menu();

int main() {

    PersonData *data[10];           //creation of array of pointers to PersonData objects

    int databaseSize = 0;           //databaseSize to count the size of the objects
    bool mlist = true;              // boolean for mailing list value
    bool loop = true;               // boolean flag for while loop
    int input;                      // input value from menu prompt
    string firstN;                  // values to be stored and set to private object values of PersonData
    string lastN;
    string streetstring;
    string citystring;
    string statestring;
    string zipstring;
    string phonestring;
    int custNum;                    //variable to hold customer number input by user
    char list;                      //variable to check validity of y/n answer
    double purchase;                //variable to hold purchase amount from user

    do{
        menu();
        do{
            cin>> input;                //do while loop for initial menu prompt for user input

            if(cin.fail()){
                cerr<<"Input was not between 1-6, try again."<<endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else if(input >= 1 && input <= 6 )
                break;
            else
                cerr<<"Input was not between 1-6, try again."<<endl;
        }while(true);

        // if(databaseSize > 0){
        //     for(int i = 0; i <databaseSize -1; i++){             //attempt at writing push back
        //         PersonData *swap;
        //         swap = data[databaseSize - 1];
        //         data[databaseSize - 1] = data[databaseSize];
        //         data[databaseSize] = swap;
        //     }
        // }
        if(input == 1){
            data[databaseSize] = new PersonData();          //conditional setting if input is 1
                                                            //new PersonData object wil be created in data[databaseSize]
            cout<< "Input First Name : ";
            cin>> firstN;
            cout<< "Input Last Name : ";
            cin>>lastN;
            cout<< "Input Street Address : ";
            cin.ignore();
            getline(cin, streetstring);
            cout<< "Input City : ";
            getline(cin, citystring);
            cout<< "Input State : ";
            getline(cin, statestring);                      //data input
            cout<< "Input Zip Code : ";
            getline(cin, zipstring);
            cout<< "Input Phone Number : ";
            cin>>phonestring;



            data[databaseSize]->setAddress(streetstring,citystring ,statestring ,zipstring );       //mutuators for data input
            data[databaseSize]->setName(firstN,lastN );
            data[databaseSize]->setPhone(phonestring);
            databaseSize += 1;                              //increment databaseSize
        }
        else if(input == 2){
            CustomerData *obj = new CustomerData();         //conditional setting if input is 2
                                                            //new CustomerData object wil be created in data[databaseSize]

            cout<< "Input First Name : ";
            cin>> firstN;
            cout<< "Input Last Name : ";
            cin>>lastN;
            cout<< "Input Street Address : ";
            cin.ignore();
            getline(cin, streetstring);
            cout<< "Input City : ";
            getline(cin, citystring);                       //data input
            cout<< "Input State : ";
            getline(cin, statestring);
            cout<< "Input Zip Code : ";
            getline(cin, zipstring);
            cout<< "Input Phone Number : ";
            cin>>phonestring;

            cout<< "Input Customer Number: "<<endl;         //validity checking for customer number
            do{
                cin>>custNum;

                if(cin.fail()){
                    cerr<<"Input was not a number value, try again."<<endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                else if(custNum)
                    break;
                else
                    cerr<<"Input was not a number value, try again."<<endl;
            }while(true);

            cout<< "Do they wish to be on the mailing list (Y/N) : "<<endl;
            cin>>list;

            obj->setName(firstN,lastN );                                        //mutuators for data input
            obj->setAddress(streetstring,citystring ,statestring ,zipstring );
            obj->setPhone(phonestring);
            obj->setCustomerNumber(custNum);

            do{
            if(list == 'n' || list == 'N'){
                mlist = false;
                break;
            }
            else if(list == 'y' || list == 'Y'){                //validity checking for mailing list option
                mlist = true;
                break;
            }
            else
                cout<<"Please enter correct input: (Y/N)"<<endl;
            }while(true);

            obj->setMailingList(mlist);
            data[databaseSize] = obj;           //set element of pointer arry equal to obj
            databaseSize += 1;                  //increment databaseSize
        }
        else if(input == 3){

            preferredCustomer *obj2 = new preferredCustomer();          //conditional setting if input is 3
                                                                        //new preferredCustomer object wil be created in data[databaseSize]

            cout<< "Input First Name : ";
            cin>> firstN;
            cout<< "Input Last Name : ";
            cin>>lastN;
            cout<< "Input Street Address : ";
            cin.ignore();
            getline(cin, streetstring);
            cout<< "Input City : ";
            getline(cin, citystring);
            cout<< "Input State : ";
            getline(cin, statestring);                              //data input
            cout<< "Input Zip Code : ";
            getline(cin, zipstring);
            cout<< "Input Phone Number : ";
            cin>>phonestring;
            cout<< "Input Customer Number: ";
            cin>>custNum;

            do{
                cin>>custNum;

                if(cin.fail()){
                    cerr<<"Input was not a number value, try again."<<endl;         //validity checking for customer number input
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                else if(custNum)
                    break;
                else
                    cerr<<"Input was not a number value, try again."<<endl;
            }while(true);


            cout<< "Do they wish to be on the mailing list (Y/N) : ";
            cin>>list;

            obj2->setName(firstN,lastN );
            obj2->setAddress(streetstring,citystring ,statestring ,zipstring );     //mutuators for data input
            obj2->setPhone(phonestring);
            obj2->setCustomerNumber(custNum);

            do{
            if(list == 'n' || list == 'N'){                 //validity checking for mailing list
                mlist = false;
                break;
            }
            else if(list == 'y' || list == 'Y'){
                mlist = true;
                break;
            }
            else
                cout<<"Please enter correct input: (Y/N)"<<endl;
            }while(true);

            obj2->setMailingList(mlist);

            try{
            cout<< "Input Purchase Amount: ";               //exception handling for purchase amount
            cin>>purchase;
            obj2->setPurchasesAmount(purchase);
            }catch(string exceptionString){
                cout<<exceptionString;
            }

            data[databaseSize] = obj2;              //set element of pointer arry equal to obj
            databaseSize += 1;                      //increment databaseSize
        }
        else if(input == 4){
            for(int i = 0; i <databaseSize; i++){       //conditional setting if input is 4, for loop iteration will call
                data[i]->PrintRecord();                 //virtual PrintRecord function of either parent/child class structure
                cout<<endl;
            }

        }
        else if(input ==5){
            for(int i = 0; i < databaseSize; i++ ){             //conditional setting if input is 5, for loop iteration will call
                string dataRecord = data[i]->getRecord();       //virtual getRecord function of either parent/child class structure
                cout<< dataRecord << endl;                      //and store that value into a string and print that string.
            }
        }
        else if(input == 6){                        //condition setting if input is 6, will break the loop and continue to
            break;                                  //memory management and ending the program.
        }


    }while(loop && databaseSize <= 10);         //runs do while loop while loop is true and databaseSize is less than or equal to 10

    for(int i = 0; i < databaseSize; i++)
        delete data[i];

    return 0;
}

void menu(){
    cout<< "1. Add Personal Data Object "<<endl;                //menu function that prints out menu prompt for user
    cout<< "2. Add Customer Data Object "<<endl;
    cout<< "3. Add Preferred Customer Data Object "<<endl;
    cout<< "4. View Database Long Form "<<endl;
    cout<< "5. View Database Short Form "<<endl;
    cout<< "6. Quit "<<endl;
    cout<< "Choice : ";
}
