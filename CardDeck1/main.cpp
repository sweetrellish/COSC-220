//============================================================================
// Name        : main.cpp
// Author      : Ryan C. Ellis
// Creation Date: 9/20/2024
// Last Update: 9/23/2024
// Description: This main function utilizes the Card and Deck class structures
// to run through a few instances of public functions to show deck information
// and shuffling of the deck.
//============================================================================


//----Feedback----
//Careful, your dealing misses the first card.

//----Solution idea----
// dealCard(){
// int temp = top;
// top++;
// return temp;
//}


#include "card.h"
#include "deck.h"
#include <iostream>


using namespace std;

void div();

int main() {

  Deck deck1, deck2;          //new deck objects

  deck1.PrintDeck();          //print deck, then shuffle and print again
  deck1.ShuffleDeck();
  deck1.PrintDeck();
  cout << endl;

  for (int i = 0; i < 10; i++)
    cout << deck1.dealCard().toString() << " - ";   //deals 10 cards off the top of the deck
  cout << endl;

  deck1.reset();          //resets top to 0

  for (int i = 0; i < 5; i++)
    cout << deck1.dealCard().toString() << " - ";   //deals 5 cards off the top
  cout << endl;

  for (int i = 3; i < 10; i++)
    cout << deck1.getCard(i).toString() << " - ";   //prints cards from 3-10
  cout << endl;

  deck2 = deck1;      //deck2 set equal to deck1

  cout << endl;
  deck1.PrintDeck();
  div();
  deck2.PrintDeck();
  div();                  //prints decks and shuffles and prints again

  deck1.ShuffleDeck();
  deck1.PrintDeck();
  div();
  deck2.PrintDeck();
  div();

  return 0;
}

void div(){     //div function shows break line
  cout<<"\n========================================================="<<endl;
}
