//============================================================================
// Name        : list.cpp
// Author      : Ryan Ellis
// Creation Date: 9/13/2024
// Last Update: 9/13/2024
// Description: Class implementation of IntArrayList, that lists public
// functions that were previously outlined in the header file.
//============================================================================

#include "list.h"
#include <algorithm>
#include <iostream>

using namespace std;

//============================================================================
// Description: Constructor for the IntArrayList class, sets the list pointer
// to nullptr and the value of the array size to 0.
// Parameters: N/A
// Return: no return, constructor function.
// Notes:
//============================================================================
IntArrayList ::IntArrayList() {
  size = 0;
  list = new int[size];
  list = nullptr;
};
//============================================================================
// Description: Destructor for the IntArrayList class, deletes list array and
// sets it to nullptr to free allocated memory.
// Parameters: N/A
// Return: no return, destructor function.
// Notes:
//============================================================================
IntArrayList ::~IntArrayList() {
  delete[] list;
  list = nullptr;
};
//============================================================================
// Description: Function call will take in an array of IntArrayList type
// passed by reference the function and set the private values of the pointer
// array list and size listed in the called object to the list and size of the
// IntArrayList object passed into function.
// Parameters: arr - IntArrayList array
// Return: void function, no return.
// Notes: N/A
//============================================================================
void IntArrayList ::duplicate(IntArrayList &arr) {
  arr.list = new int[size];
  arr.size = size;

  for(int i = 0; i< size; i++)
    arr.list[i] = list[i];

};
//============================================================================
// Description: Function call will take in a boolean value which gets passed into
// the function and determines whether the array gets printed verticall or horizontally
// depending on the value of the boolean (true/false).
// Return: void function, no return.
// Notes: N/A
//============================================================================
void IntArrayList ::display(bool vert) {

  if (vert == true) {
    for (int i = 0; i < size; i++) {
      cout << list[i] << endl;
    }
  }
  else{
    for (int i = 0; i < size; i++)
      cout << list[i] << " ";
    cout<<endl;
  }
};
//============================================================================
// Description: Function call will take in an int num to get
// passed into the function. Validity checking ensures num is within the bounds
// of the array and if the list is empty return 0. If num falls within bounds
// the function will return indexed value of list.
// Parameters: int num - input number
//
// Return: int indexed value of list
// Notes: N/A
//============================================================================
int IntArrayList ::get(int num) {
  if (num < 0)
    num = 0;
  if (num > size)
    num = size - 1;
  if (list == nullptr)
    return 0;
  else
    return list[num];
};
//============================================================================
// Description: Function call will sort values in list array of object called.
// A swap value is set to 0 and then a nested for loop runs through and uses
// bubble sort to swap values if they aren't in order.
// Parameters: N/A
// Return: void function no return.
// Notes: N/A
//============================================================================
void IntArrayList ::sort() { // sort function using
                             // bubble sort
  int swap = 0;

  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (*(list + j) > *(list + j + 1)) {
        swap = *(list + j);
        *(list + j) = *(list + j + 1);
        *(list + j + 1) = swap;
      }
    }
  }
};
//============================================================================
// Description: Function call will determine if  list in object referenced is
// sorted. A for loop goes through the array and checks to
// see if array is sorted and returns true/false.
// Parameters: N/A
// Return: boolean value true/false if sorted/not.
// Notes: N/A
//============================================================================
bool IntArrayList ::sorted() { // boolean function to
                               // determine if array is sorted
  int count = 0;

  for (int i = 0; i < size; i++) {
    if (*(list + i) <= *(list + i + 1))
      count++;
    else
      break;
  }

  if (count == size )
    return true;
  else
    return false;
};
//============================================================================
// Description: Function call will take in an array passed by reference which gets
// passed into the function. The new size for the array is set by adding array sizes
// of object called and object that is passed in function. Values of passed array are
// appended to the object array.
// Parameters: const IntArrayList &arr - array passed by reference.
// Return: void function no return.
// Notes: N/A
//============================================================================
void IntArrayList ::concat(const IntArrayList &arr) {

  int newSize = size + arr.size; // set new size
  resize(newSize);

  int count = 0; // counter for arr index

  for (int i = size; i < newSize; i++) {
      *(list + i) = *(arr.list + count); // start adding 2nd array
    count++;
    }
};
//============================================================================
// Description: Function call will take in starting and ending indexes for range
// of values to remove, which get passed into the function. For loop goes through
// array and removes values in range given.
// Parameters: int start - starting index
//             int end - ending index
// Return: void function no return.
// Notes: N/A
//============================================================================
void IntArrayList ::remove(int start, int end) {

  if (start < 0) // validity checking
    start = 1;
  if (end >= size)
    return;
  if (end > size)
    end = size;

  int length = end - start;
  int newSize = size - length;
  int count = 0;
  size = newSize;

  for (int i = 0; i < size; i++) {
    if (start >= end)
      break;
    else if (i == start - 1) { // start inner while at start index
      while (count < end - 1) {
        count++; // runs until count var meets end
      }
    } else
      *(list + i) = *(list + count); // add values outside of range
    count++;
  }
};

//============================================================================
// Description: Function call will shuffle values in the object array in main
// function. Indexes start at 0 to size.
// Parameters:
// Return: void function no return.
// Notes: N/A
//============================================================================
void IntArrayList ::shuffle() {
  // shuffles array values using first index and last (size)
  random_shuffle(&list[0], &list[size]); // pass by reference
};
//============================================================================
// Description: Function call will take in starting and ending indexes for range
// of values to keep within array which get passed into the function.
// For loop goes through object list array and removes values not in range given.
// Parameters: int start - starting index
//             int end - ending index
// Return: void function no return.
// Notes: N/A
//============================================================================
void IntArrayList ::sub(int start, int end) { // takes values of start and end index to
                                            // remove all values outside
  int length = end - start;                // length is size of  new array
  int count = start;

  // IntArrayList arr;
  // arr.list = nullptr; // dynamic array to return as arrayptr
  // arr.list = new int[length];

  for (int i = 0; i < size;i++) { // sets value of arr[i] to arraptr[i] within the range
    if (i >= start || i <= end) {   //maybe change to ampersand?
      *(list + i) = *(list + count);
      count++;
    }
  }
  size = length;
};
//============================================================================
// Description: Function call will take in IntArrayList pointer array and the
// position index, which get passed into the function. For loop goes through
// array and inserts passed object array into given index for object called.
// Parameters: int index - position index
//             const IntArrayList &arr- IntArrayList pointer passed by reference
// Return: void function no return.
// Notes: N/A
//============================================================================
void IntArrayList ::insert(const IntArrayList &arr, int index) {

  int newSize = size + arr.size; // set new size
  resize(newSize);

  int count;
  if (size > arr.size) // determines loop longevity based on sizes of arrays
    count = size - arr.size;
  else if (size < arr.size)
    count = arr.size - size;

  count += index;

  int counter = 0; // counter for array 2 index
  int n = index;

  for (int i = 0; i < newSize; i++) {

    if (i >= index && i <= count) { // if  i == index
      *(list + i) = *(arr.list + counter);
      counter++; // start adding 2nd array
    } else if (i >= count) {
      *(list + i - 1) = *(arr.list + n); // else mirror values
      n++;
    } else
      *(list + i) = *(arr.list + i);
  }
  size = newSize;
};
//============================================================================
// Description: Function call will take in position index and value to be added, which get
// passed into the function. For loop goes through array and will add value to position
// and swap values ahead of index until the end is reached.
// Parameters: int val - value to be set in index
//             int index - position of index
// Return: void function no return.
// Notes: N/A
//============================================================================
void IntArrayList ::insert(int val, int index) {
  int swap = 0;
  int temp = 0;

  if (index < 0)
    index = 0;
  if (index > size)
    index = size;

  for (int i = 0; i < size + 1; i++) {
    if (i == index) {
      swap = list[i];
      list[i] = val;
    } else if (i > index) {
      temp = list[i];
      list[i] = swap;
      list[i + 1] = temp;
    }

    else
      list[i] = list[i];
  }
};

//============================================================================
// Description: Function call will take in size of array which get passed into
// the function.For loop goes through array and resizes array to size given.
// Parameters: int newSize - new size of array
// Return: void function no return.
// Notes: N/A
//============================================================================
void IntArrayList ::resize(int newSize) { // adds 0 to new entries of array
                                          // and null if subtracting entries
  if (size > newSize)
    size = newSize;

  IntArrayList arr;
  arr.list = nullptr;
  arr.list = new int[newSize]{0};

  if(size < newSize){
    int temp = size;
    size = newSize;
    for (int i = 0; i < newSize; i++) {
      list[i +temp] = 0;
      }
    }

};
//============================================================================
// Description: Function call will return the size/length of the arry.
// Parameters: N/A
// Return: int size.
// Notes: N/A
//============================================================================
int IntArrayList ::length() { return size; };
//============================================================================
// Description: Function call will take in int value which gets passed into the
// function. A new list is dynamically made with given size and then a for loop
// runs to add value to array.
// Parameters:
// Return: void function no return.
// Notes:
//============================================================================
void IntArrayList::add(int val) {

  size = size +1;             //set new size of array to one more
  int *list2 = new int[size];   //create new dynamic array of size

  for (int i = 0; i < size-1; i++){
    list2[i] = list[i];
  }

  list = list2;
  for ( int i = 0; i < size ; i++) {
        if ( i == size-1){
          list[i] = val;
        }
  // delete[] list2;
  // list2 = nullptr;
  }
};
//============================================================================
// Description: Function call will display the address of the array list.
// Parameters:
// Return: void function no return.
// Notes:
//============================================================================
void IntArrayList::displayAddress() { cout << list << endl; };
//============================================================================
// Description: Function call will take in two ints for value to set at the index
// and the index value. Validity checking is in place to ensure index is within
// boundaries of array. An error message is displayed if this is true, otherwise
// the array at the index is set to the value passed.
// Parameters:
// Return: void function no return.
// Notes:
//============================================================================
void IntArrayList::set(int val, int index) {
  if (index < 0 || index > size)
    cerr << "Index out of bounds." << endl;
  else
    list[index] = val;
};

//Feedback notes
/*1.
Don't need semicolons at the end of the function blocks, just at then end of the class spec.
duplicate: delete arr.list before making a new one.
Problem is in resize, look over the logic of the solutions.
No need for list[i] = list[i];
insert has a similar problem.  In general allocate the space you need, transfer data, readjust pointers and remove old space.
Helps to draw pictures of what is happening in memory.*/
