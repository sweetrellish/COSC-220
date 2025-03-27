//===========================================================================================================================
// Name        : main.cpp - Dice
// Author      : Ryan C. Ellis
// Creation Date: 12/5/2024
// Last Update: 12/5/2024
// Description: Main program will prompt user for number of dice to roll, number of sides of dice, and number of rolls, and then the counts of the total rolls are stored in a map data structure and printed out at the end of the program.
//===========================================================================================================================
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

int diceRoll(int);  //prototype of rolling dice function

int main(){

    srand(time(0));     //set time seed

    int numDice, numSides, numRolls;        //variables for user input
    map<int, int> rollCount;                //map structure to hold counts and totals

    cout<<"Input number of dice to roll: ";
    cin>>numDice;
    cout<<"Input number of sides for each die: ";   //user prompt for input
    cin>>numSides;
    cout<<"Input number of rolls of dice: ";
    cin>>numRolls;

    for(int i = 0; i <numRolls; i++){           //nested for loop for setting dice rolls to map structure
        int total = 0;

        for(int j = 0; j <numDice; j++)
            total+= diceRoll(numSides);
        rollCount[total]++;
    }

    cout<<"Results\n";                  //print out results using range for loop
    for(auto& index :rollCount)
        cout<<index.first<< " "<< index.second<<endl;


    return 0;

}

int diceRoll(int sides){            //dice roll function
    return rand()% sides + 1;
}
