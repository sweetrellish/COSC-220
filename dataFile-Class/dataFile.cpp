//============================================================================
// Name        : dataFile.cpp
// Author      : Ryan C. Ellis
// Creation Date: 9/12/2024
// Last Update: 9/19/2024
// Description: This is the implementation file for the StateData class
// structure. Include the header file and lists all the public functions
// that are defined in that header.
//============================================================================

#include "data.h"
#include <string>

using namespace std;

//============================================================================
// Description: Function call will construct object of StateData type, setting
// default values of pointer array data to nullptr, size to 0 and StateName to
// an empty string.
// Parameters:N/A
// Return: constructor function, no return type.
// Notes:
//============================================================================
StateData::StateData(){
    data = nullptr;             //set to default values
    size = 0;
    StateName = "";
};
//============================================================================
// Description: Function call will destructor of StateData type,
// deleting pointer array data and freeing memory space allocation.
// Parameters:N/A
// Return: destructor function, no return type.
// Notes:
//============================================================================
StateData ::~StateData(){
    delete [] data;
}
//============================================================================
// Description: Function call will return state name.
// Parameters: N/A
// Return: returns string state name.
// Notes: N/A
//============================================================================
string StateData:: getStateName(){
    return StateName;
};
//============================================================================
// Description: Function call will take in string for passed state name and
// sets it to the private StateName value.
// Parameters: string state - value of state to be passed.
// Return: void function no return.
// Notes: N/A
//============================================================================
void StateData::setStateName(string state){
    StateName = state;
};

//============================================================================
// Description: Function call takes in parameter value that gets appended into
// the end of the data list.
// Parameters: double val - sets value in data list
// Return: void function no return.
// Notes:
//============================================================================
void StateData :: add(double val){

    double *dat = nullptr;
    dat = new double[size + 1];

    for (int i = 0 ; i < size + 1; i++){                //adding 1 to size to add value
        if ( i == size + 1)
            dat[i] = val;                              //sets data at ith index to new value
    }
    delete[] data;
    data = dat;

};

//============================================================================
// Description: Function call will take in int value index to refer to location
// within StateData data array and return the value in that index.
// Parameters: int index - refers to the index of the array to return.
// Return: double value in the array index.
// Notes:
//============================================================================

double StateData :: get(int index) {
    if (index < 0)                      //validity checking
        return data[0];
    else if (index > size)
        return data[size];
    else
        return data[index];             //returns array at index if all validity checks out
}

//Feedback
/*add need to move old data to the new array.  Also want if (i == size)
Couple other memory errors.*/
