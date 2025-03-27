//============================================================================
// Name        : main.cpp
// Author      : Ryan C. Ellis
// Creation Date: 9/29/2024
// Last Update: 10/11/2024
// Description: This main function implements class structures for a Hand class,
// a Deck class and by inlusion of the deck a Card Class as well. The main will
// output prompts to the user for input regarding their prospectives hands and
// will display the winner of the game once all the players have made their
// selection of keeping/replacing their cards.
//============================================================================

//**FEEDBACK 10/14/2024**
// In the hand value function, for a full house the three of a kind is always in the first slot and the pair in the second.  Also, not sure why you have a loop there.
//
// Bit of a logic error here.  Your final section is in an else if so if the hand is a straight it will do the straight but then never go into this block to populate the rest of the number.  You also need to do this block on high card.
//
// Player 1: 2S    3C    4S    5D    9C    ---- High Card
// Player 2: 2D    5C    6H    JS    QC    ---- High Card
// Player 3: AH    7C    8C    10C    JD    ---- High Card
//
// Player 1 won this hand.
//
// I probably would not store the hand value as a member variable since it could be stale, you must run the value function before any comparison.
//
// Dealing loops are backwards.

#include "hand.h"
#include "deck.h"
#include <cctype>
#include <iostream>

using namespace std;

void div();
void title();

int main(){
                                            //new deck with size for players
    Deck deck;                              //int to hold number of players
    int players;                            //int to hold how many cards to draw
    int draw;                               //int to hold how many cardds to replace in hand
    int replace;                            //loop variable for user prompt on replacing
    int loop = 0;                           //boolean input variable to validate input and keep loop going
    bool input = false;                     //int to hold index of player that won the game
    int win = 0;
    long long max = 0;                      //add vars to header for data hiding?


    title();                //print title to user

    do{

    cout<<"Input number of players 2-6: ";          //loop to prompt for how many players with validity checking
    cin>>players;
    if(cin.fail()){                 //check if input is integer
        cerr<<"Input was not between 2 and 6, try again"<<endl;
        cin.clear();                //clear state of input failure
        cin.ignore(10000, '\n');    //discard input
    }
    else if(players >= 2 && players <= 6)
        break;
    else
        cerr<<"Input was not between 2 and 6, try again"<<endl;

    }while(true);

    deck.ShuffleDeck();                 //shuffle the deck and print the deck
    div();

    // cout<<"\t\tDeck\n";              //test code to print deck
    // deck.PrintDeck();
    // div();

    Hand hands[players];                //set array of hands for users given input
    long long handTotals[players];

    for(int i = 0; i < players; i++){
        for(int j = 0; j < 5; j++){                 //deal cards to each player from deck
            hands[i].replace(j,(deck.dealCard()));
        }
    }



    for(int i = 0; i < players; i++){                   //for loop to go through each player and ask prompts
        loop = 0;
        cout<<"Player "<< i + 1<<": "<<hands[i].HandAndTypeToString(4)<<endl;

        do{

        cout<<"Input the number of cards to draw (0-3) : ";
        cin>>draw;

        if(cin.fail() || draw < 0 || draw > 3 ){            //check if input is integer
            cerr<<"Enter a valid input, try again"<<endl;
            cin.clear();                                     //clear state of failure
            cin.ignore(10000, '\n');                        //discard input
            input = true;

        }
        else
            input = false;

        }while(input);

        bool selected[5]{false};
        while(loop < draw){

            cout<<"Input the number of the card to replace (1-5) : ";
            cin>>replace;
                                                                        //validity checking for if slot has been selected
            if(replace < 1 || replace > 5 || selected[replace -1]){
            cerr<<"This input is out of bounds, or the card was already replaced, please select another card."<<endl;
            cin.clear();
            cin.ignore(10000, '\n');                    //clear state of failure and discard input
            continue;
            }
            hands[i].replace(replace - 1, deck.dealCard());
            selected[replace -1] = true;
            loop++;                                         //replace cards

            }

        div();
    }

    for (int i = 0; i <players; i++){       //call getvalue only once
        handTotals[i] = hands[i].getValue();
    }

    for(int i = 0; i < players; i++){
        if(handTotals[i] > max){            //finds max value and returns index
            max = handTotals[i];
            win = i;
        }

        //cout<<handTotals[i]<<endl;        //test code to print hand totals
    }

    for(int i = 0; i < players; i++)
        cout<<"Player "<< i + 1<<": "<<hands[i].HandAndTypeToString(4)<<endl;       //print out selected hands for players
                                                                                    //display who won the hand
    cout<<"\nPlayer "<<win + 1<<" won this hand."<<endl;


    return 0;
}

void div(){                                                             //function displays break line
    cout<<"\n================================================="<<endl;
}
void title(){                                                           //function displays menu header
    cout<<"***************************************************"<<endl;
    cout<<"*              ~Let's Play Poker!~                *"<<endl;
    cout<<"***************************************************"<<endl;
}

