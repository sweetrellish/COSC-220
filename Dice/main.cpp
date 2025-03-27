//================================================================
// Author: Ryan Ellis
// Creation Date: 9/23/2024
// Last Update: 9/26/2024
// Description: Main function that includes class header file and implentation
// for Array2D and Die classes. Main function will create a 2D array and
// set values of rolls added to together for each die into each index of the array.
// The program will count the consecutive amount of rolls and return that to the
// user.
//================================================================


//----Feedback----
//OK, I wanted you to populate the array with the roll data first and then
//go through the data to determine the trials that were equal.
//You did both at the same time.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array2D.h"
#include "Die.h"

using namespace std;

int main() {

    srand(time(0));                 //set time seed
    
    Array2D simulation;             //declaration of Array2D object simulation
    Die a, b;                       //declaration of Die objects a, b
    int trials = 0;                 //variable to hold number of trials
    int rolls = 0;                  //variable to hold number of rolls
    int sum = 0;                    //variable to hold sum total of dice roll values
    int count = 0;                  //variable to hold count of consecutive rolls


    cout<< "Input the number of trials : ";
    cin>> trials;
    cout<< "Input the number of rolls per trial : ";    //user prompt to enter trials and rolls
    cin>> rolls;

    simulation.resize(trials, rolls, 0);            //sets simulation array size to number of trials and rolls

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

    cout<< "Number of trials resulting in the same roll value was "<<count  <<endl;     //output findings

    for(int i = 0; i < trials; i++){                    //print out values of rolls in array
        for(int j = 0; j < rolls; j++){
            cout<<simulation.get(i,j)<< " ";
        }
        cout<<endl;
    }


    return 0;
    
}
