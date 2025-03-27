//============================================================================
// Name        : deck.h
// Author      : Ryan C. Ellis
// Creation Date: 9/20/2024
// Last Update: 9/23/2024
// Description: This header file outlines the Deck class structure
// and contains private data of an array of Cards which will define the deck,
// the value of the top card, and public functions to manipulate cards in the deck.
//============================================================================

#ifndef DECK_H
#define DECK_H

#include <string>
#include "card.h"

using namespace std;

class Deck {
    private:
        Card cards[52];
        int top = 0;
    public :
        Deck();
        void PrintDeck();
        void ShuffleDeck();
        Card dealCard();
        Card getCard(int i);
        void reset();
};
#endif
