//===========================================================================================================================
// Name        : main.cpp
// Author      : Ryan C. Ellis
// Creation Date: 10/25/2024
// Last Update: 11/7/2024
// Description: Main function will take list structures and sorting methods and time the functions of each method.
//===========================================================================================================================
#include "TLinkedList.h"
#include "DLinkedList.h"
#include "LinkedList.h"
#include <ctime>
#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

//Feedback:Please PDF the document, there is a button in the toolbar of Libre that will do this.

// Nice discussion on this and easy to read data layout.  I suppose if I had any comments on this it would be to add in lines on the graphs to connect the points and maybe add in a second graph with the dominant series removed.  This will bring out the relationship of the other methods a little better.

void div(string s = "") {           //div display function
  cout << "\n" << s << "----------------------------------\n\n";
}


int main() {

  srand(time(0));               //set random seed

  LinkedList<int> lst;            //list declarations of textbook, linked list, Double linked, vector and STL list
  TLinkedList<int> tlst;
  DLinkedList<int> dlst;
  vector<int> vec;
  list<int> list;


  int numval = 0;

  cout<<"Input the number of values to store: ";      //prompt for user to input amount of values
  cin>>numval;

  div();

  auto start = high_resolution_clock::now();
  for (int i = 0; i < numval; i++)            //tlist push front timing
    tlst.push_front(numval);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Time to push front with linked list: " << duration.count() / 1000000.0 << " seconds" << endl;

  start = high_resolution_clock::now();
  for(int i = 0; i <numval; i++)
    dlst.push_front(numval);
  stop = high_resolution_clock::now();                    //dlist push front timing
  duration = duration_cast<microseconds>(stop - start);
  cout << "Time to push front with double linked list: "
  << duration.count() / 1000000.0 << " seconds" << endl;

  start = high_resolution_clock::now();
  for(int i = 0; i <numval; i++)
    lst.insertNode(numval-i);
  stop = high_resolution_clock::now();                  //lst insertnode timing
  duration = duration_cast<microseconds>(stop - start);
  cout << "Time to push front with textbook linked list: "
  << duration.count() / 1000000.0 << " seconds" << endl;

  start = high_resolution_clock::now();
  for(int i = 0; i <numval; i++)
    vec.insert(vec.begin(), rand());
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);       //vector insert timing
  cout << "Time to insert at front with vector: "
  << duration.count() / 1000000.0 << " seconds" << endl;

  start = high_resolution_clock::now();
  for(int i = 0; i <numval; i++)
    list.push_front(numval);
  stop = high_resolution_clock::now();                  //list push front timing
  duration = duration_cast<microseconds>(stop - start);
  cout << "Time to push front with STL linked list: "
  << duration.count() / 1000000.0 << " seconds" << endl;

  list.clear();
  lst.clear();
  tlst.clear();
  dlst.clear();     //clear lists
  vec.clear();

  div();

  start = high_resolution_clock::now();
  for (int i = 0; i < numval; i++)
    tlst.push_back(rand());
  stop = high_resolution_clock::now();                  //tlist push back timing
  duration = duration_cast<microseconds>(stop - start);
  cout << "Time to push back with linked list: " << duration.count() / 1000000.0 << " seconds" << endl;

  start = high_resolution_clock::now();
  for(int i = 0; i <numval; i++)
    dlst.push_back(rand());
  stop = high_resolution_clock::now();                    //dlist push back timing
  duration = duration_cast<microseconds>(stop - start);
  cout << "Time to push back with double linked list: "
  << duration.count() / 1000000.0 << " seconds" << endl;

  start = high_resolution_clock::now();
  for(int i = 0; i <numval; i++)
    lst.appendNode(rand());
  stop = high_resolution_clock::now();                  //lst appendNode timing
  duration = duration_cast<microseconds>(stop - start);
  cout << "Time to push back with textbook linked list: "
  << duration.count() / 1000000.0 << " seconds" << endl;

  start = high_resolution_clock::now();
  for(int i = 0; i <numval; i++)
    vec.insert(vec.end(), rand());
  stop = high_resolution_clock::now();                  //vector insert from end timing
  duration = duration_cast<microseconds>(stop - start);
  cout << "Time to push back with vector: "
  << duration.count() / 1000000.0 << " seconds" << endl;

  start = high_resolution_clock::now();
  for(int i = 0; i <numval; i++)
    list.push_back(rand());
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);     //list push back timing
  cout << "Time to push back with STL linked list: "
  << duration.count() / 1000000.0 << " seconds" << endl;


  return 0;

}

