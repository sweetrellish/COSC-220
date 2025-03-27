//============================================================================
// Name        : main.cpp - IntArrayList
// Author      : Ryan C. Ellis
// Creation Date: 9/18/2024
// Last Update: 9/19/2024
// Description: This program applies instantiation of 2 IntArrayList objects
// and manipulates them using the public functions defined in the header and
// implementation file.
//============================================================================

#include "list.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void div();           //prototype for div function

int main() {

  srand(time(0));     //seeding random to time 0

  IntArrayList L1, L2;    //instantiation of IntArrayList objects

  for (int i = 0; i < 10; i++)
    L1.add((rand() % 100 + 1));   //for loop to set random values to L1

  L1.display();
  cout << L1.sorted() << endl;    //display L1 and check to see if sorted

  L1.sort();                    //sort L1
  L1.display();                 //display and check if sorted again
  cout << L1.sorted() << endl;
  div();
                          //display address of L1 and L2
  L1.displayAddress();
  L2.displayAddress();

  L1.duplicate(L2);       //duplicate L2 and display L1 and L2 and then the addresses
  L1.display();
  L2.display();
  L1.displayAddress();
  L2.displayAddress();
  div();

  L2.set(34, 3);        //set values of L2 at different indexes and display L1, L2
  L2.set(21, 4);
  L2.set(-15, 5);
  L1.display();
  L2.display();
  div();

  L2.add(123);        //add values to list, display, duplicate and display addresses
  L2.add(27);
  L2.add(-19);
  L1.display();
  L2.display();
  L1.duplicate(L2);
  L1.display();
  L2.display();
  L1.displayAddress();
  L2.displayAddress();
  div();

  L2.resize(5);       //resize L2 and display L1, L2
  L1.display();
  L2.display();

  for (int i = 0; i < 5; i++)       //for loop to set values in resized L2 with range 25
    L2.set(rand() % 25, i);

  L1.display();         //display L1, L2 and concatenate L2 to L1 and display
  L2.display();
  L1.concat(L2);
  L1.display();
  L2.display();
  div();

  L1.display();       //display changes in array once shuffled and sorted
  L1.sort();
  L1.display();
  L1.shuffle();
  L1.display();
  div();

  L1.display();       //insert L2 into position 5 of L1
  L2.display();
  L1.insert(L2, 5);
  L1.display();
  div();

  L2.display();
  L2.insert(5, 0);
  L2.display();         //insert given values into certain indexes of L2 and display
  L2.insert(2, -5);
  L2.display();
  L2.insert(54, 100);
  L2.display();
  L2.insert(123, 4);
  L2.display();
  div();

  L1.display();
  L1.remove(5, 10);         //remove given values at index and then sub values in range
  L1.display();
  L1.sub(4, 12);
  L1.display();

  for (int i = 0; i < L1.length(); i++)       //for loop to get values in L1
    cout << L1.get(i) << endl;


  return 0;
}

//============================================================================
// Description: Function call will display a break line and new line.
// Parameters: N/A
// Return: void function no return.
// Notes: N/A
//============================================================================
void div() {
  // display break line
  cout << "\n==============================\n" << endl;
}
