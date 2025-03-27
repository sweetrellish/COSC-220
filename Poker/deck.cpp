//============================================================================
// Name        : deck.cpp
// Author      : Ryan C. Ellis
// Creation Date: 9/20/2024
// Last Update: 10/11/2024
// Description: This implementation file outlines the public Deck class functions
// that are defined in the header file.
//============================================================================

#include "deck.h"
#include <algorithm>
#include <random>
#include <iostream>

using namespace std;


//============================================================================
// Description:Constructor that creates the deck of cards.
// Parameters:N/A
// Return:Constructor function, no return.
// Notes:
//============================================================================
Deck :: Deck(){
    size = 52;
    cards = new Card[size];

    int sucount = 1;
    int valcount = 1;
    int count = 0;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            Card c = Card(valcount, sucount);
            c.toStringFace();
            c.toStringSuit();
            cards[count] = c;
            valcount++;
            count++;
        }
    sucount++;
    valcount = 1;
    }

}

//============================================================================
// Description: Destructor for the Deck class structure. Destructor will delete
// instances of deck within main function.
// Parameters: N/A
// Return: Destructor, no return type.
// Notes:
//============================================================================
Deck :: ~Deck(){
    delete[] cards;
}
//============================================================================
// Description: Prints out the deck in a single line using no space between
// the value and suit for each card and one space between the cards.
// Parameters:N/A
// Return: Void function, no return.
// Notes:
//============================================================================
void Deck :: PrintDeck(){
    for (int i = 0; i < 52; i++){
        cout<< (cards[i]).toStringFace() + cards[i].toStringSuit() << " ";
        if(i == 12 || i == 25 || i == 38 || i ==51)
            cout<<endl;

    }
}
//============================================================================
// Description:Shuffles the deck of cards.
// Parameters:N/A
// Return: Void function, no return
// Notes:
//============================================================================
void Deck :: ShuffleDeck(){
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards, cards + 52, g);
}
//============================================================================
// Description:Deals the next card off the top of the deck.
// Parameters:N/A
// Return: Returns card on top of deck.
// Notes: Fixed from previous edition to include top card, then increment after.
//============================================================================
Card Deck :: dealCard(){
    int temp = top;
    top++;
    size--; //decrement deck size
    return cards[temp];
}
//============================================================================
// Description: Gets the card at index i in the deck.
// Parameters: int i - index value in deck.
// Return: Returns card value at index.
// Notes:
//============================================================================
Card Deck :: getCard(int i){
    return cards[i];
}
//============================================================================
// Description: Resets the top to 0.
// Parameters: N/A
// Return: Void function, no return.
// Notes:
//============================================================================
void Deck :: reset(){
    top = 0;
}

ostream &operator<<(ostream &strm, const Deck&d){

    int temp = d.size;
    for (int i = 0; i < temp ; i++)
        strm << d.cards[i];
    return strm;

}
