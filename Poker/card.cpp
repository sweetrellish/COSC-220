//============================================================================
// Name        : card.cpp
// Author      : Ryan C. Ellis
// Creation Date: 9/20/2024
// Last Update: 10/11/2024
// Description: This implementation file outlines the public Card class functions
// that are defined in the header file.
//============================================================================

#include "card.h"
#include <string>

//============================================================================
// Description: Default constructor will set the value and suit both to 0, so
// that the card will have no values of meaning.
// Parameters: N/A
// Return: Constructor function, no return.
// Notes:
//============================================================================
Card :: Card(){
    value = 0;
    suit = 0;
}
//============================================================================
// Description: Constructor that sets private values value and suit to input values
// passed, val and su.
// Parameters:  int val - value set for card
//              int su - suit set for card
// Return: Constructor function, no return.
// Notes:
//============================================================================
Card :: Card(int val, int su){
    value = val;
    suit = su;
}
//============================================================================
// Description: Returns a string of the face value of the card, depending on the
// value of the private data within the card structure. 1 will be an Ace, 2-10
// will remain their value, and then Jack is 11, Queen is 12, and King is 13.
// Parameters: N/A
// Return: Returns string of card value
// Notes: Ace should be high/low need to figure out input
//============================================================================
string Card ::toStringFace(){
    if (value == 1 || value == 14)
        return "A";
    else if(value >= 2 && value <= 10)
        return to_string(value);
    else if(value == 11)
        return "J";
    else if(value == 12)
        return "Q";
    else if(value == 13)
        return "K";
    else
        return "Value out of bounds.";
}
//============================================================================
// Description:Returns a string of the suit of the card, depending on the private
// value of suit, 1 will be Diamonds, 2 will be Clubs, 3 will be Hearts and 4 is
// Spades.
// Parameters:N/A
// Return:Returns string of card suit.
// Notes:
//============================================================================
string Card ::toStringSuit(){
    if (suit == 1)
        return "D";
    else if( suit == 2)
        return "C";
    else if(suit == 3)
        return "H";
    else
        return "S";
}

//============================================================================
// Description: Returns true if the two cards are identical, where both
// value and suit are the same and will return false otherwise.
// Parameters: Card card2 - card to be compared.
// Return: boolean true/false value.
// Notes:
//============================================================================
bool Card ::equals(Card card2){
    if (value == card2.value && suit == card2.suit)
        return true;
    else
        return false;
}
//============================================================================
// Description: Returns a string of the card in a condensed format, there is no
// spacing between the value and suit.
// Parameters: N/A
// Return: Returns string value of concatenated full card information.
// Notes:
//============================================================================
string Card ::toString(){
    return toStringFace() + toStringSuit();
}
//============================================================================
// Description: Function call will run a check based off the input passed into it,
// and returns a string of the card in condensed format if the check returns false
// and with a space added into the value and suit if true.
// Parameters: bool space - value to determine if space is added.
// Return: Returns string of either concatenated card info or info with space added.
// Notes:
//============================================================================
string Card :: toString(bool space){
    if (space == true)
        return toStringFace() + " " + toStringSuit();
    else
        return toStringFace() + toStringSuit();
}
//============================================================================
// Description: Function call will check passed card and called card object to
// compare if called object value is greater than the card passed and return true
// if this is the case and false otherwise.
// Parameters: Card card2 - card to be compared to called object.
// Return: Boolean value of true/false.
// Notes:
//============================================================================
bool Card ::greater(Card card2){
    if ( value > card2.value)
        return true;
    else
        return false;
}

//============================================================================
// Description: Function call will set private value to passed int val.
// Parameters: int val - number to be set to value.
// Return: Void function, no return.
// Notes:
//============================================================================
void Card::  setVal(int val){
    value = val;
}

//============================================================================
// Description: Function call will set private suit to passed int su.
// Parameters: int su - number to be set to suit.
// Return: Void function, no return.
// Notes:
//============================================================================
void Card :: setSuit(int su){
    suit = su;
}

//============================================================================
// Description: Function call will return card value.
// Parameters: N/A
// Return: int value
// Notes:
//============================================================================
int Card :: getVal(){
    return value;
}

//============================================================================
// Description: Function call will return card suit.
// Parameters:N/A
// Return: int suit
// Notes:
//============================================================================
int Card :: getSuit(){
    return suit;
}

//============================================================================
// Description: Overloaded operator for less than operator in Card class. Function
// will compare called object and passed object to see if card face value on left is
// less than card value on right and return true/false.
// Parameters: const Card &c - passed card object.
// Return: boolean true/false.
// Notes:
//============================================================================
bool Card :: operator<(const Card &c){
    if (value < c.value)
        return true;
    else
        return false;
}

//============================================================================
// Description: Overloaded operator for greater than operator in Card class. Function
// will compare called object and passed object to see if card face value on left is
// greater than card value on right and return true/false.
// Parameters: const Card &c - passed card object.
// Return: boolean true/false.
// Notes:
//============================================================================
bool Card :: operator>(const Card &c){
    if (value > c.value)
        return true;
    else
        return false;
}

//============================================================================
// Description: Overloaded operator for less than or equal to than operator in Card class.
// Function  will compare called object and passed object to see if card face value on
// left is less or equal to the card value on right and return true/false.
// Parameters: const Card &c - passed card object.
// Return: boolean true/false.
// Notes:
//============================================================================
bool Card :: operator<=(const Card &c){
    if(value <= c.value)
        return true;
    else
        return false;
}

//============================================================================
// Description: Overloaded operator for greater than or equal to than operator in Card class.
// Function  will compare called object and passed object to see if card face value on
// left is greater than or equal to the card value on right and return true/false.
// Parameters: const Card &c - passed card object.
// Return: boolean true/false.
// Notes:
//============================================================================
bool Card :: operator>=(const Card &c){
    if(value >= c.value)
        return true;
    else
        return false;
}

//============================================================================
// Description: Overloaded operator for equivalence operator in Card class.
// Function  will compare called object and passed object to see if card face value on
// left is equivalent to the card value on right and return true/false.
// Parameters: const Card &c - passed card object.
// Return: boolean true/false.
// Notes:
//============================================================================
bool Card :: operator==(const Card &c){
    if(value == c.value && suit == c.suit)
        return true;
    else
        return false;
}

//============================================================================
// Description: Overloaded operator for not equivalent operator in Card class.
// Function  will compare called object and passed object to see if card face value on
// left is not equivalent to the card value on right and return true/false.
// Parameters: const Card &c - passed card object.
// Return: boolean true/false.
// Notes:
//============================================================================
bool Card :: operator!=(const Card &c){
    if(value != c.value)
        return true;
    else
        return false;
}

//============================================================================
// Description: Overloaded operator for stream operator in Card class. This
// will set the formatting for how the Card object is to be passed through
// an ostream operation.
// Parameters:ostream &strm - ostream object
//            const Card &c - Card object
// Return: ostream return type
// Notes:
//============================================================================
ostream &operator<<(ostream &strm,const Card &c){
    strm << c.value << ""<< c.suit;
    return strm;
}
