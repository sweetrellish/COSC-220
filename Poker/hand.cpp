//============================================================================
// Name        : hand.cpp
// Author      : Ryan C. Ellis
// Creation Date: 9/29/2024
// Last Update: 10/11/2024
// Description: This implementation file outlines the public Hand class functions
// that are defined in the header file.
//============================================================================

#include "hand.h"
#include "card.h"
#include <string>
#include <cmath>

using namespace std;

//============================================================================
// Description:Constructor that creates the hand of cards.
// Parameters:N/A
// Return:Constructor function, no return.
// Notes:
//============================================================================
Hand :: Hand(){
    size = 5;
    hand = new Card[size];
}

//============================================================================
// Description: Destructor for the Hand class structure. Destructor will delete
// instances of hands within main function.
// Parameters: N/A
// Return: Destructor, no return type.
// Notes:
//============================================================================
Hand :: ~Hand(){
    delete[] hand;
}

//============================================================================
// Description: Function call will delete hand and reset to new dynamic creation of hand with size.
// Parameters: N/A
// Return: void function no return.
// Notes:
//============================================================================
void Hand :: clearHand(){
    delete[] hand;
    hand = new Card[size];

}

//============================================================================
// Description: Function call will parse through hand and add cards to empty hand.
// Parameters: Card c - card input to add to hand
// Return: void function, no return.
// Notes:
//============================================================================
void Hand :: addToHand(Card c){
    for(int i = 0; i < 5; i++){
        if(hand[i].getVal() == 0){
            hand[i] = c;
            break;
        }
                        //did not use this function to add cards to hand, used replace instead with for loop
    }

    // size += 1;
    // Card *copy = new Card[size];
    //
    // for(int i = 0; i < size -1; i++)
    //     copy[i] = hand[i];
    //
    // delete [] hand;
    // hand = copy;
    //
    // for(int i = 0; i < size; i++)
    //     if(i == size -1)
    //         hand[i] = c;
    //
    // delete[] copy;
    // copy = nullptr;

}

//============================================================================
// Description: Function call will print hand with one space in between each card from hand.
// Parameters:N/A
// Return: void function, no return.
// Notes:
//============================================================================
void Hand :: printHand(){
    for(int i = 0; i < size; i++)
        cout<<hand[i]<< " ";
}

//============================================================================
// Description: Function call will print hand with given spacing of passed value in between each card from hand.
// Parameters: int width - spacing for each card.
// Return: void function, no return.
// Notes:
//============================================================================
void Hand :: printHand(int width){
    int count = 0;

    for(int i = 0; i < size; i++){
        cout<<hand[i]<< " "<<endl;
        while(count < width -1){
            cout<<" ";
            count++;
        }
        count = 0;
    }


}

//============================================================================
// Description: Function call will sort hand by face value in ascending order.
// Parameters: N/A
// Return: void function, no return.
// Notes:
//============================================================================
void Hand :: sortHand(){
    bool swap;
    Card temp;

    do{
        swap = false;
        for(int i = 0; i < size - 1; i++){
            if(hand[i] > hand[i + 1])
            {
                temp = hand[i];
                hand[i] = hand[i + 1];
                hand[i + 1] = temp;
                swap = true;
            }
        }
    } while(swap);

}


//============================================================================
// Description: Function call will take in card through parameter and replace given card to index of hand passed through parameter.
// Parameters: int pos - position in hand
//             Card c - card to be replaced
// Return: void function, no return.
// Notes:
//============================================================================
void Hand :: replace(int pos, Card c){
    if(pos >= 0 && pos <= 5)
        hand[pos] = c;
    else
        cerr<<"Incorrect index."<<endl;
}

//============================================================================
// Description: Function call will sort hand and then create dynamic array of size 13 and will then increment each index if hand value is equivalent to the index value.
// Parameters: N/A
// Return: int pointer
// Notes: ============================================================================
int* Hand :: convertHandToArray(){

    sortHand();

    int* array = new int[13]{0};

    for(int i = 0; i < size; i++){
        array[(hand[i].getVal()) - 1] += 1;
    }
    return array;
}

//============================================================================
// Description: Function call will use functions defined to establish type of hand and then return a string to display what kind of hand it is.
// Parameters: N/A
// Return: void function, no return.
// Notes:
//============================================================================
string Hand ::HandType(){

    if(isStraightFlush() && isRoyal())
        return "Royal Flush";
    else if(isStraightFlush())
        return "Straight Flush";
    else if(isFourOfKind())
        return "Four of a Kind";
    else if(isFullHouse())
        return "Full House";
    else if(isFlush())
        return "Flush";
    else if(isStraight())
        return "Straight";
    else if(isThreeOfKind())
        return "Three of a Kind";
    else if(isTwoPair())
        return "Two Pair";
    else if(isPair())
        return "Pair";
    else
        return "High Card";
}

//============================================================================
// Description: Function call will parse through hand to see if certain values are found to make royal flush and return true/false depending on findings.
// Parameters: N/A
// Return: boolean true/false.
// Notes:
//============================================================================
bool Hand :: isRoyal(){
    bool flag = true;
    for (int i = 0; i < size; i++){
        if(hand[i].getVal() >= 2 && hand[i].getVal() < 10 )
            flag = false;
    }
    return flag;
}
//============================================================================
// Description: Function call will call functions for isStraight and isFlush and return true/false depending on findings.
// Parameters: N/A
// Return: boolean true/false.
// Notes:
//============================================================================
bool Hand ::isStraightFlush(){
    if(isFlush() && isStraight())
        return true;
    else
        return false;
}
//============================================================================
// Description: Function call will parse through hand to see if consecutive suits are found and return true/false depending on findings.
// Parameters: N/A
// Return: boolean true/false.
// Notes:
//============================================================================
bool Hand :: isFlush(){

    sortHand();

    bool flag = true;
    int test;
    test = hand[0].getSuit();

    for(int i = 0; i <size; i++){

        if((hand[i].getSuit()) != test)
            flag = false;
    }

    if(flag == true){
        return true;
    }
    else
        return false;

}

//============================================================================
// Description: Function call will parse through hand to see if consecutive face values are found and return true/false depending on findings.
// Parameters: N/A
// Return: boolean true/false.
// Notes:
//============================================================================
bool Hand :: isStraight(){

    sortHand();

    bool flag = true;

    for(int i = 0; i <size-1; i++){
        if(hand[i].getVal() == 1 && hand[i + 1].getVal() == 10)             //if ace is 1 and 10 is next card, reset to 14 and sort
            hand[i].setVal(14);
        sortHand();

        if((hand[i].getVal()+1) != (hand[i+1].getVal()))
            flag = false;

    }

    if(flag == true){
        return true;
    }
    else
        return false;
}

//============================================================================
// Description: Function call will create int pointer array and set function call of convertHandToArray equal to that, and will parse through array to see if 3 is found in array  and if a pair is found and return true/false depending on findings.
// Parameters: N/A
// Return: boolean true/false.
// Notes:
//============================================================================
bool Hand :: isFullHouse(){

    sortHand();

    bool partial = false;
    bool flag = false;

    int * copy = convertHandToArray();

    for (int i = 0; i < 13; i++){
        if (copy[i] == 3)
            partial = true;
        else if(copy[i] == 2)
            flag = true;
    }

    if(partial && flag){
        delete [] copy;
        return true;
    }
    else{
        delete [] copy;
        return false;
    }
}

//============================================================================
// Description: Function call will create int pointer array and set function call of convertHandToArray equal to that, and will parse through array to see if 4 is found in array and return true/false depending on findings.
// Parameters: N/A
// Return: boolean true/false.
// Notes:
//============================================================================
bool Hand :: isFourOfKind(){

    sortHand();


    int * copy = convertHandToArray();

    for(int i = 0; i < 13; i++){
        if(copy[i] == 4){
            delete [] copy;
            return true;
        }
    }
    delete [] copy;
    return false;
}

//============================================================================
// Description: Function call will create int pointer array and set function call of convertHandToArray equal to that, and will parse through array to see if 3 is found in array  and return true/false depending on findings.
// Parameters: N/A
// Return: boolean true/false.
// Notes:
//============================================================================
bool Hand :: isThreeOfKind(){

    sortHand();

    int * copy = convertHandToArray();

    for(int i = 0; i < 13; i++){
        if(copy[i] == 3){
            delete [] copy;
            return true;
        }

    }
    delete [] copy;
    return false;
}

//============================================================================
// Description: Function call will create int pointer array and set function call of convertHandToArray equal to that, and will parse through array to see if pair is found and increment count variable if another pair is found and return true/false depending on findings.
// Parameters: N/A
// Return: boolean true/false.
// Parameters:
// Return:
// Notes:
//============================================================================
bool Hand :: isTwoPair(){

    sortHand();

    int * copy = convertHandToArray();
    int count = 0;


    for(int i = 0; i < 13; i++){
        if(copy[i] == 2)
            count++;
    }

    if(count > 1){
        delete [] copy;
        return true;
    }
    else{
        delete [] copy;
        return false;
    }
}

//============================================================================
// Description: Function call will create int pointer array and set function call of convertHandToArray equal to that, and will parse through array to see if pair is found and return true/false depending on findings.
// Parameters: N/A
// Return: boolean true/false.
// Notes:
//============================================================================
bool Hand :: isPair(){


    sortHand();

    int* copy = convertHandToArray();

    for(int i = 0; i < 13; i++){
        if(copy[i] == 2){
            delete [] copy;
            return true;
        }
    }
    delete [] copy;
    return false;
}

//============================================================================
// Description: Function call will sort hand and then determine what value to assign to handvalue given boolean values returned from function calls. Default values will be set based on position in hand.
// Parameters: N/A
// Return: long long handValue
// Notes:
//============================================================================
long long Hand :: getValue(){
    //need to be careful here and make sure cards aren't being counted that are used in'
    //if they are a specific hand, like excluding the four of a kind in the addition of
    //the rest of the hand, might have to keep calculations in is functions for conditions

    sortHand();

    int v = 0;          //placeholder variable
    int v2 = 0;         //placeholder for two pair and full house
    handValue = 0;      //set handvalue to 0 on function call

    if(isRoyal() && isStraightFlush())
        handValue += 9000000000000000000;
    else if (isStraightFlush())
        handValue += 8000000000000000000;
    else if(isFourOfKind()){
        handValue += 7000000000000000000;
        int * copy = convertHandToArray();
        for(int i = 0; i < 13; i++){
            if(copy[i] == 4)
                v = i + 1;
        }
        handValue += (v * 1000000000000000);
        for(int i = 0; i < size; i++)
            if(hand[i].getVal() != v)
                handValue += (hand[i].getVal() * 1000000000000);
        delete [] copy;
    }
    else if(isFullHouse()){
        v = 0;
        v2 = 0;
        handValue += 6000000000000000000;
        int * copy = convertHandToArray();
        for(int i = 0; i < 13; i++){
            if(copy[i] == 3)
                v = i + 1;
            if(copy[i] ==2)
                v2 = i + 1;
        }
       for(int i = 0; i < size; i++){
            if(v > v2){
                handValue += (v * 1000000000000000);
                handValue += (v2 * 1000000000000);
            }
            else{
                handValue += (v2 * 1000000000000000);
                handValue += (v * 1000000000000);
            }
        }
        delete [] copy;
    }
    else if(isFlush())
        handValue += 5000000000000000000;
    else if(isStraight())
        handValue += 4000000000000000000;
    else if(isThreeOfKind()){
        handValue += 3000000000000000000;
        int * copy = convertHandToArray();
        for(int i = 0; i < 13; i++){
            if(copy[i] == 3)
                v = i + 1;
        }
        handValue += (v * 1000000000000000);
        for(int i = 1; i < size -1; i++){
            if(hand[i].getVal() !=v && (hand[i].getVal() > hand[i + 1].getVal() || hand[i].getVal() > hand[i -1].getVal()))
                handValue += (hand[i].getVal() * 1000000000000);
        }
        delete [] copy;
    }
    else if(isTwoPair()){
        v = 0;
        v2 = 0;
        handValue += 2000000000000000000;
        int * copy = convertHandToArray();
        for(int i = 0; i < 13; i++){
            if(copy[i] == 2 && v == 0)
                v = i + 1;
            else if(copy[i] == 2 && v != 0)
                v2 = i + 1;
        }
        for(int i = 0; i < size; i++){
            if(v > v2){
                handValue += (v * 1000000000000000);
                handValue += (v2 * 1000000000000);
            }
            else{
                handValue += (v2 * 1000000000000000);
                handValue += (v * 1000000000000);
            }
        }
        delete []  copy;

    }
    else if(isPair()){
        handValue += 1000000000000000000;
        int * copy = convertHandToArray();
        for(int i = 0; i < 13; i++){
            if(copy[i] == 2)
                v = i + 1;
        }
        handValue += (v * 1000000000000000);
        for(int i = 1; i < size -1; i++){
            if(hand[i].getVal() !=v && (hand[i].getVal() > hand[i + 1].getVal() || hand[i].getVal() > hand[i -1].getVal()))
                handValue += (hand[i].getVal() * 1000000000000);
        }
        delete [] copy;
    }


    else if (isFlush() || isStraight() || isStraightFlush() || (isRoyal() && isStraightFlush())){
        for(int i = 0; i < size; i++){

            if(i == 0){
                handValue += (hand[i].getVal() * 1000);
            }
            else if(i == 1){
                handValue += (hand[i].getVal() * 1000000);
            }
            else if(i == 2){
                handValue += (hand[i].getVal() * 1000000000);
            }
            else if(i == 3){
                handValue += (hand[i].getVal() * 1000000000000);
            }
            else if(i == 4){
                handValue += (hand[i].getVal() * 1000000000000000);
            }

        }
    }

    return handValue;

}

//============================================================================
// Description: Function will return a string of formatted hand values given width passed through by user/main program.
// Parameters: int width - margin length
// Return: string stringhand
// Notes:
//============================================================================
string Hand :: HandAndTypeToString(int width){

    sortHand();

    int count = 0;
    string stringhand = "";

    for(int i = 0; i < size; i++){
        stringhand += hand[i].toString() + " ";
        while(count < width -1){
            stringhand += " ";
            count++;
        }
        count = 0;
    }
    stringhand += "---- " + HandType();
    return stringhand;
}

//============================================================================
// Description: Overloaded operator for less than operator in Hand class. Function
// will compare called object and passed object to see if hand  value on left is
// less than hand value on right and return true/false.
// Parameters: const Hand &h - passed hand object.
// Return: boolean true/false.
//============================================================================
bool Hand :: operator<(const Hand &h){
    if(handValue < h.handValue)
        return true;
    else
        return false;
}

//============================================================================
// Description: Overloaded operator for greater than operator in Hand class. Function
// will compare called object and passed object to see if hand  value on left is
// greater than hand value on right and return true/false.
// Parameters: const Hand &h - passed hand object.
// Return: boolean true/false.
// Notes:
//============================================================================
bool Hand :: operator>(const Hand &h){
    if(handValue > h.handValue)
        return true;
    else
        return false;
}

//============================================================================
// Description: Overloaded operator for less than or equal to than operator in Hand class.
// Function  will compare called object and passed object to see if hand value on
// left is less or equal to the hand value on right and return true/false.
// Parameters: const Hand &h - passed hand object.
// Return: boolean true/false.
// Notes:
//============================================================================
bool Hand :: operator<=(const Hand &h){
    if(handValue <= h.handValue)
        return true;
    else
        return false;
}

//============================================================================
// Description: Overloaded operator for greater than or equal to than operator in Hand class.
// Function  will compare called object and passed object to see if hand  value on
// left is greater than or equal to the hand value on right and return true/false.
// Parameters: const Hand &h - passed hand object.
// Return: boolean true/false.
// Notes:
//============================================================================
bool Hand :: operator>=(const Hand &h){
    if(handValue >= h.handValue)
        return true;
    else
        return false;
}

//============================================================================
// Description: Overloaded operator for equivalence operator in Hand class.
// Function  will compare called object and passed object to see if hand  value on
// left is equivalent to the hand value on right and return true/false.
// Parameters: const Hand &h - passed hand object.
// Return: boolean true/false.
// Notes:
//============================================================================
bool Hand :: operator==(const Hand &h){
    if(handValue == h.handValue)
        return true;
    else
        return false;
}

//============================================================================
// Description: Overloaded operator for not equivalent operator in Hand class.
// Function  will compare called object and passed object to see if hand value on
// left is not equivalent to the hand value on right and return true/false.
// Parameters: const Hand &h - passed hand object.
// Return: boolean true/false.
// Notes:
//============================================================================
bool Hand :: operator!=(const Hand &h){
    if(handValue != h.handValue)
        return true;
    else
        return false;
}

//============================================================================
// Description: Overloaded operator for stream operator in Hand class. This
// will set the formatting for how the Hand object is to be passed through
// an ostream operation.
// Parameters:ostream &strm - ostream object
//            const Hand &h - Hand object
// Return: ostream return type
// Notes:
//============================================================================
ostream &operator<<(ostream &strm, const Hand &h){
    for(int i = 0; i < h.size; i++){
        strm<< h.hand[i].toStringFace()<<h.hand[i].toStringSuit()<<"    ";
    }
    return strm;
}
