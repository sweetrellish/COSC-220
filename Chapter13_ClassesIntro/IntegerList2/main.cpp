/*
 Name          : main.cpp
 Author        : Don Spickler
 Creation Date : 1/22/2022
 Last Update   : 1/22/2022
 Description   : This program uses the IntergerList and Die classes to simulate
 rolling two dice an many times as the user wants and then finding the largest
 run of consecutive rolls of 2 (i.e. snake eyes). User Interface: The program
 will ask the user for the number of rolls to do in the simulation.
 */

#include <cstdlib> // For rand and srand
#include <ctime>   // For the time function
#include <iostream>

#include "Die.h"
#include "IntegerList.h"

using namespace std;

int main() {
  // Seed the random number generator to the system time.
  srand(time(0));

  Die die1, die2;
  int rolls = 0;

  // Get user input of the number of rolls for the simulation.
  cout << "Number of rolls to try: ";
  cin >> rolls;

  // Validate input.
  if (rolls <= 0)
    return 1;

  // Create list large enough to hold entire simulation.
  IntegerList dicerolls(rolls);

  // Run simulation of rolling and store results.
  for (int i = 0; i < rolls; i++) {
    die1.roll();
    die2.roll();
    dicerolls.setElement(i, die1.getValue() + die2.getValue());
  }

  // Count the number of consecutive snake eyes.
  int snakeeyesruns = 0;
  int maxsnakeeyesruns = 0;
  for (int i = 0; i < rolls; i++) {
    int roll = dicerolls.getElement(i);

    if (roll == 2)
      snakeeyesruns++;
    else
      snakeeyesruns = 0;

    if (snakeeyesruns > maxsnakeeyesruns)
      maxsnakeeyesruns = snakeeyesruns;
  }

  // Output the results.
  cout << "The maximum run of snake eyes in " << rolls << " trials was "
       << maxsnakeeyesruns << endl;

  return 0;
}
