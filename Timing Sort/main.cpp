//===========================================================================================================================
// Name        : main.cpp
// Author      : Ryan C. Ellis
// Creation Date: 10/25/2024
// Last Update: 11/7/2024
// Description: Main function will take list structures and sorting methods and time the functions of each method.
//===========================================================================================================================
#include "TLinkedList.h"
#include "DLinkedList.h"
#include <ctime>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

//Feedback: Very nice as well.  Please PDF and again I might include lines.

void div(string s = "") {           //div display function
  cout << "\n" << s << "----------------------------------\n\n";
}
template <class T>void insertionSort(T[], int);       //sort prototypes
template <class T>void selectionSort(T[], int);
template <class T>void bubbleSort(T[], int);

int main() {

  srand(time(0));               //set random seed

              //list declarations of textbook, linked list, Double linked, vector and STL list
  TLinkedList<int> tlst;
  DLinkedList<int> dlst;
  vector<int> vec;
  int* list;



  int numval = 0;

  cout<<"Input the number of values to store: ";      //prompt for user to input amount of values
  cin>>numval;

  list = new int[numval];

  for(int i = 0; i <numval; i++)
    vec.push_back(rand());

  div();

  auto start = high_resolution_clock::now();
  for (int i = 0; i < numval; i++)              //timing sort with tlist
    tlst.insertNode(vec[i]);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Time to sort with linked list: " << duration.count() / 1000000.0 << " seconds" << endl;

  start = high_resolution_clock::now();       //timing sort with double list
  for(int i = 0; i <numval; i++)
    dlst.insertNode(vec[i]);
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout << "Time to push front with double linked list: "
  << duration.count() / 1000000.0 << " seconds" << endl;

  start = high_resolution_clock::now();       //bubble sort timing
  for(int i = 0; i <numval; i++)
    list[i] = vec[i];
  bubbleSort(list,numval);
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout << "Time to sort array with bubble sort: "
  << duration.count() / 1000000.0 << " seconds" << endl;

  start = high_resolution_clock::now();
  for(int i = 0; i <numval; i++)
    list[i] = vec[i];
  insertionSort(list,numval);
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);     //timing with insertion sort
  cout << "Time to sort array with insertion sort: "
  << duration.count() / 1000000.0 << " seconds" << endl;

  start = high_resolution_clock::now();
  for(int i = 0; i <numval; i++)
    list[i] = vec[i];
  selectionSort(list,numval);
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);     //timing with selection sort
  cout << "Time to sort array with selection sort: "
  << duration.count() / 1000000.0 << " seconds" << endl;

  delete [] list;

  return 0;

}
template <class T>
void bubbleSort(T array[], int size) {          //bubble sort method
  int maxElement;
  int index;

    for (maxElement = size - 1; maxElement > 0; maxElement--)
      for (index = 0; index < maxElement; index++)
        if (array[index] > array[index + 1])
    swap(array[index], array[index + 1]);

}
template <class T>
void selectionSort(T array[], int size) {
int minIndex, minValue;
  for (int start = 0; start < (size - 1); start++) {        //selection sort method
    minIndex = start;
  minValue = array[start];
    for (int index = start + 1; index < size; index++) {
      if (array[index] < minValue) {
        minValue = array[index];
        minIndex = index;
      }
    }

  swap(array[minIndex], array[start]);
  }
}
template <class T>
void insertionSort(T array[], int size) {
  for (int itemsSorted = 1; itemsSorted < size; itemsSorted++) {      //insertion sort method
    int temp = array[itemsSorted];
    int loc = itemsSorted - 1;
      while (loc >= 0 && array[loc] > temp) {
      array[loc + 1] = array[loc];
      loc = loc - 1;
      }
    array[loc + 1] = temp;
  }
}
