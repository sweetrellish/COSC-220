/*  Author: Ryan Ellis and Josh Ellis
 *    Creation Date: 9/4/2024
 *    Last Update: 9/9/2024 */

#include <iostream>
#include <random>

using namespace std;


int main(){
    
    int *arr = nullptr;
    int size =0;                //size of the array
    int n = 0;                  //random number variable
    char input;                 //user input
    int loop = 0;               //while loop counter
    int *counts;
    int countsize = 0;
    
    srand(time(0));
    
    cout << "Enter a value to declare the size of the array :" << endl;
    cin >> size; 
    cout << "Enter a maximum random value for n : "<< endl;
    cin >> n;
    
    arr = new int[size];

    for(int i = 0; i < size; i++){
        *(arr + i) = (rand()% n) + 1;
    }
    
    //Sort of some sort
    int buffer = 0;
    for(int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){
            if(*(arr + j) > *(arr + j + 1)){
                buffer = *(arr + j);
                *(arr + j) = *(arr + j + 1); //Swap
                *(arr + j + 1) = buffer;
            }
        }
    }
    
    
    
    
    cout << "Would you like to print out the array?  y/n" << endl;
    cin >> input;
    
    if (input == 'y' || input == 'Y'){
        for(int i = 0; i < size; i++){
            cout << *(arr + i) << " ";
        }
        cout<<endl;
        
        cout << "======================="<<endl;
        while(loop < size){
            cout << *(arr+loop) << " ";
            loop++;
        }
        
        cout<<endl;
        
    }
    else{
        //Return to
    }
    
    cout<< "\nCounts "<<endl;
    
    counts = new int[countsize]; //Dynamically allocated array for how many unique numbers in the array
    
     for(int i = 0; i < size; i++){ //Generates the size of the counts array
             if (*(arr + i) != *(arr + i + 1)){
                 countsize += 1;
}
     }
    
    for(int i = 0; i < countsize; i++){
        *(counts + i) = 1;
    }
    
    //-----------------------

    int j = 0;
    for(int i = 0; i < size; i++){
        if(*(arr + i) == *(arr + i + 1)){
            *(counts + j) += 1;
        }
        else if(*(arr + i) != *(arr + i + 1) && counts[j] != 1){
            cout << *(arr + i) << " shows up: " << *(counts + j) << " times." << endl;
            j++;
        }
    }
    
    
    delete[] arr;
    delete[] counts;
    
    

    return 0;
}

