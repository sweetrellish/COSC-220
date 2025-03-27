/*  Author: Ryan Ellis and Josh Ellis
 *    Creation Date: 9/8/2024
 *    Last Update: 9/8/2024 */

#include <iostream>
#include <random>

using namespace std;


int main(){
    
    
    int random;                 //random max value
    int *arrptr;                   //poiner variable
    int *arr = nullptr;
    int numRolls =0;                //Number of Rolls
    int count = 0;                  //Loop Counter
    int numDie = 0;                  ////Number of Dice
    char input;                 //user input
    int loop = 0;               //while loop counter
    int *counts;
    int countsize;
    int total = 0;
    bool ans =  true;
    
    srand(time(0));
    
    cout << "Enter number of rolls : ";
    cin >> numRolls; 
    
    cout << "Enter number of dice : ";
    cin >> numDie;
    
    
    arr = new int[numRolls]; //Dynamically allocated array tied to number of rolls
    
    for(int i = 0; i < numRolls; i++){
        
        while (count < numDie){
            
            *(arr + i) = 1 + rand() % 6; //From 1 - 6
            total += *(arr + i);
            //arr[i] += arr[i];
            count++;
            
        }
        count = 0;
        *(arr + i) = total;
        total = 0;
        
    }
    
    cout << "Would you like to print out the array?  y/n : ";
    cin >> input;
    
    if (input == 'y' || input == 'Y'){
        cout<< "Rolls\n";
        for(int i = 0; i < numRolls; i++){
            cout << *(arr + i) << " ";
        }
        cout<<endl;
        
    }
    
    
    cout<<"\nCounts"<<endl;
    
    
    //Sort the array holding the rolls
    int buffer = 0;
    for(int i = 0; i < numRolls; i++){
        for (int j = 0; j < numRolls - i - 1; j++){
            if(*(arr + j) > *(arr + j + 1)){
                buffer = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = buffer;
            }
        }
    }
    
    countsize = (numDie * 6) + 1;
    counts = new int[countsize]; //Dynamically allocated array for how many unique numbers in the array
    
    
    for(int i = 0; i < numRolls; i++){
        if(*(arr + i) != 0){
            
            *(counts + *(arr + i)) += 1;
        }
    }
    
    
    for(int i = numDie; i < countsize; i++){
        cout << numDie << ": "<< *(counts + i) << endl;
        numDie++;
    }
    
    
    
    delete[] arr;
    delete[] counts;
    
    return 0;
}

