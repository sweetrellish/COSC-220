//============================================================================
// Name        : main.cpp
// Author      : Ryan C. Ellis
// Creation Date: 9/20/2024
// Last Update: 9/23/2024
// Description: This main function utilizes the Card and Deck class structures
// to run through a defined number of trials to compare whether a derangement has
// occured between shuffles and calculates the probability of having a derangement
// occur.
//============================================================================


//----Feedback----
//Good


#include "card.h"
#include "deck.h"
#include <iostream>


using namespace std;

void div();

int main() {

  int notDerange = 0;                                     //var to keep track of not deranges
  double numtrials = 0;                                   //double var to keep number of trials
  double prob = 0;                                        //probability of derangements
  double count = 0;                                       //counter for derangements
  Deck *deck1;                                            //new Deck pointer
  int trial = 0;                                          //variable for trials
  bool loop = false;                                      //boolean variable for do while loop

  do {                                                    //do while loop- user prompt for number of trials

  cout<< "How many trials would you like to shuffle? "<<endl;
  cin>> trial;
  if (trial < 0)
    cerr<< "Please enter a valid number."<<endl;

  else
    loop = true;

  }while(loop != true);

  deck1 = new Deck[trial];            //create dynamic array of decks based on trials
  Deck deck2 = deck1[0];              //set first deck equal to a separate deck for comparison

  div();
  cout<<"Original Deck"<<endl;     //prints out first shuffle
  for(int i = 0; i < 52; i++){
    cout<< deck2.getCard(i).toString()<< " ";
  }
  div();


  for(int i = 0; i < trial; i++){     //loop through arrays with nested for loops
                                      //and compare values if true then increment count
    cout<< "Shuffle "<< i + 1<< ":";
    div();
    deck1[i].ShuffleDeck();           //shuffle deck and print
    deck1[i].PrintDeck();
    div();

    for(int j = 0; j < 52; j++){
      if (deck2.getCard(j).equals(deck1[i].getCard(j)))    //compares if original at index is equal to
        count++;                                           //shuffle deck index and increase count if true
    }
    if(count > 0)                                         //if count is greater than 0 increase number of not deranges
      notDerange++;
    count = 0;
  }

  double derange = trial - notDerange;                    //deranges is the total trials minus not deranges

  numtrials = trial;                                       //set double trials to number of trials for precision

  prob = (derange/numtrials);                               //calculates probability
  double recip = 0;
  if(prob ==0)
    recip = 0;
  else
    recip = 1/prob;

  cout<< "Not derangements : "<<notDerange<<endl;         //output findings
  cout<< "Trials : "<<trial<<endl;
  cout<< "Derangements found : "<< derange<<endl;
  cout<< "\nThe probability of having a derangement is "<< prob << " or "<< prob * 100<< "%"<<endl;
  cout<< "There is a 1 in "<<recip<< " chance of a derangment."<<endl;

  delete[] deck1;     //free memory

  return 0;

}

void div(){                                         //function to display break line
  cout<<"\n================================"<<endl;
}
