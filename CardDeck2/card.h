//============================================================================
// Name        : card.h
// Author      : Ryan C. Ellis
// Creation Date: 9/20/2024
// Last Update: 9/23/2024
// Description: This header file outlines the Card class structure
// and contains private data of the integer card value, the value which relates
// to the suit, and public functions to set and project data of the card.
//============================================================================

#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card {
    private:
        int value;
        int suit;
    public :
        Card();
        Card( int v, int s);
        string toStringSuit();
        string toStringFace();
        bool equals(Card card2);
        string toString();
        string toString(bool space);
        bool greater(Card card2);
};
#endif
