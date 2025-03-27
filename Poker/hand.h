//============================================================================
// Name        : hand.h
// Author      : Ryan C. Ellis
// Creation Date: 9/29/2024
// Last Update: 10/11/2024
// Description: This header file outlines the Hand class structure
// and contains private data of a pointer to an array of Cards which will be the hand,
// the size of the hand, and the value of the hand. Public functions to are defined
// to manipulate cards in the hand along with overloaded operators for comparison
// and output streaming.
//============================================================================

#ifndef HAND_H
#define HAND_H

#include <string>
#include <iostream>
#include "card.h"
#include "deck.h"

using namespace std;

class Hand{
private:
    Card *hand = nullptr;
    int size;
    long long handValue= 0;
public:

    Hand();
    ~Hand();
    void clearHand();
    void addToHand(Card);
    void printHand();
    void printHand(int);
    void sortHand();
    void replace(int, Card);
    int* convertHandToArray();
    bool isRoyal();
    bool isStraightFlush();
    bool isFlush();
    bool isStraight();
    bool isFullHouse();
    bool isFourOfKind();
    bool isThreeOfKind();
    bool isTwoPair();
    bool isPair();
    long long getValue();
    string HandAndTypeToString(int);
    string HandType();


    bool operator<(const Hand &);
    bool operator>(const Hand &);
    bool operator<=(const Hand &);
    bool operator>=(const Hand &);
    bool operator==(const Hand &);
    bool operator!=(const Hand &);

    friend ostream &operator<<(ostream &, const Hand&);

};
#endif
