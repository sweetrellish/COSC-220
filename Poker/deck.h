//============================================================================
// Name        : deck.h
// Author      : Ryan C. Ellis
// Creation Date: 9/20/2024
// Last Update: 10/11/2024
// Description: This header file outlines the Deck class structure
// and contains private data of a pointer to an array of Cards which will define the deck,
// the value of the top card, and public functions to manipulate cards in the deck
// along with overloaded operator for output streaming.
//============================================================================

#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <string>
#include "card.h"

using namespace std;

class Deck {

    private:
        Card *cards;
        int top = 0;
        int size;

    public :

        Deck();
        ~Deck();
        void PrintDeck();
        void ShuffleDeck();
        Card dealCard();
        Card getCard(int i);
        void reset();

        friend ostream &operator<<(ostream &, const Deck&);
};
#endif
