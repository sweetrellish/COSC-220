//============================================================================
// Name          : Ch09_CardExample.cpp
// Author        : Don Spickler
// Creation Date : 1/20/2022
// Last Update   : 1/20/2022
// Description   : Card Example for Chapter 9 on Pointers
//                 Simple program that simulates a deck of cards using
// User Interface: No input.
//============================================================================

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// Function prototypes.
int *duplicateArray(const int *, int);
void displayArray(const int[], int);
int *createDeck();
void printDeck(const int[], int);
void shuffleDeck(int *, int);
void swap(int *, int, int);
void deal(const int *, int *, int, int &);

int main() {
  srand(time(0));

  int *deck;
  int top = 0;

  // Create and print the deck.
  deck = createDeck();
  printDeck(deck, 52);

  // Shuffle the deck and print.
  shuffleDeck(deck, 52);
  printDeck(deck, 52);

  // Create two hand arrays.
  int *hand1 = new int[5];
  int *hand2 = new int[5];

  // Deal 5 cards to the two hands.
  for (int i = 0; i < 5; i++) {
    deal(deck, hand1, i, top);
    deal(deck, hand2, i, top);
  }

  // Print the two hands.
  printDeck(hand1, 5);
  printDeck(hand2, 5);

  // free the memory.
  delete[] deck;
  delete[] hand1;
  delete[] hand2;
  deck = nullptr;
  hand1 = nullptr;
  hand2 = nullptr;

  return 0;
}

/*
 Description: Deals a card from the deck into the hand at position pos and
 updates the top of the deck.

 Parameters:
 deck - The deck of cards array.
 hand - The hand to be dealt to.
 pos -  Position in the hand to place the card.
 top - The current top position of the deck.

 Return: None
 */

void deal(const int *deck, int *hand, int pos, int &top) {
  hand[pos] = deck[top++];
}

/*
 Description: Shuffles the deck of cards by randomly swapping two cards 500
 times.

 Parameters:
 deck - The deck of cards array.
 size - The size of the deck.

 Return: None
 */

void shuffleDeck(int *deck, int size) {
  for (int i = 0; i < 500; i++)
    swap(deck, rand() % size, rand() % size);
}

/*
 Description: Swaps two cards in the deck/array.

 Parameters:
 arr - Array of integers to be altered.
 p1 - Position 1 for the swap.
 p2 - Position 2 for the swap.

 Return: None
 */

void swap(int *arr, int p1, int p2) {
  int temp = *(arr + p1);
  *(arr + p1) = *(arr + p2);
  *(arr + p2) = temp;
}

/*
 Description: Creates a new "deck of cards".  Really just an array with numbers
 0 to 51.

 Parameters: None

 Return: Pointer to the array of cards.
 */

int *createDeck() {
  int *newDeck = new int[52];
  for (int i = 0; i < 52; i++)
    newDeck[i] = i;

  return newDeck;
}

/*
 Description: Prints the deck of cards to the console in card like output.

 Parameters:
 deck - The deck of cards array.
 size - The size of the deck.

 Return: None
 */

void printDeck(const int deck[], int size) {
  for (int i = 0; i < size; i++) {
    int card = deck[i];

    // Convert integer stored to a face/suit pair.
    int face = card % 13 + 1;
    int suit = card / 13;

    // Print the face value.
    if (face == 1)
      cout << "A";
    else if (face == 11)
      cout << "J";
    else if (face == 12)
      cout << "Q";
    else if (face == 13)
      cout << "K";
    else
      cout << face;

    // Print the suit value.
    if (suit == 0)
      cout << "H";
    else if (suit == 1)
      cout << "C";
    else if (suit == 2)
      cout << "D";
    else if (suit == 3)
      cout << "S";

    cout << " ";
  }
  cout << endl;
}

/*
 Description: Duplicates an integer array.

 Parameters:
 arr - The array of integers.
 size - The size of the array.

 Return: Pointer to the copied array.
 */

int *duplicateArray(const int *arr, int size) {
  int *newArray = nullptr;

  if (size <= 0)
    return nullptr;

  newArray = new int[size];

  for (int index = 0; index < size; index++)
    newArray[index] = arr[index];

  return newArray;
}

/*
 Description: Prints an integer array to the console screen.

 Parameters:
 arr - The array of integers.
 size - The size of the array.

 Return: None
 */

void displayArray(const int arr[], int size) {
  for (int index = 0; index < size; index++)
    cout << arr[index] << " ";
  cout << endl;
}
