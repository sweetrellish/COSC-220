//===========================================================================================================================
// Name        : main.cpp
// Author      : Ryan C. Ellis
// Creation Date: 10/16/2024
// Last Update: 10/24/2024
// Description: Main function that includes Matrix and Dice class structure header file, and implements public functions to manipulate
// templated Matrix objects and overloaded functions associated with those objects within main.
//===========================================================================================================================

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "matrix.h"
#include "Die.h"

using namespace std;

void div();

int main() {

    srand(time(0));                 //set time seed

    Die a, b;                       //declaration of Die objects a, b
    int trials = 0;                 //variable to hold number of trials
    int rolls = 0;                  //variable to hold number of rolls
    int sum = 0;                    //variable to hold sum total of dice roll values
    int count = 0;                  //variable to hold count of consecutive rolls
    char print;


    cout<< "Input the number of trials : ";
    cin>> trials;
    cout<< "Input the number of rolls per trial : ";    //user prompt to enter trials and rolls
    cin>> rolls;
    cout<<"Do you want to display the array (Y/N) : ";
    cin>>print;

    Matrix <Die> simulation(trials, rolls, 1);            //sets simulation array size to number of trials and rolls

    for(int i = 0; i < trials; i++){                //triple nested for loop to go through array and roll Die
        for(int j = 0; j < rolls; j++){             //adding values together and setting sum to value
            a.roll();
            b.roll();
            sum = a.getValue() + b.getValue();      //sets values of sum to the index
            simulation.set(i,j,sum);

            if (j >= rolls - 1) {                   //run third for loop when j is number of rolls
            bool check = true;                      //boolean value to check if values are equal
            for( int k = 0; k < rolls; k++){
                if(simulation.get(i, j) != simulation.get(i,j-k )){     //if values aren't equal then set false
                    check = false;                                      //and break from loop
                    break;
                }

            }
            if (check)                      //if check is true, increase count
            count++;
            }
        }
    }


    if(print == 'y' || print == 'Y'){
        for(int i = 0; i < trials; i++){                    //print out values of rolls in array
            for(int j = 0; j < rolls; j++){
                cout<<simulation.get(i,j)<< " ";
            }
            cout<<endl;
        }
    }
    cout<< "There were "<<count<< " matches of equal die in the "<<trials<<" trials of the simulation"<<endl;     //output findings

    return 0;
}
