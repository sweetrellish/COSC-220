/*
 Name          : IntegerList.cpp
 Author        : Don Spickler
 Creation Date : 1/21/2022
 Last Update   : 1/21/2022
 Description   : Implementation file for the IntegerList class.
 */

#include <iostream>

#include "IntegerList.h"

using namespace std;

/*
 Description: Constructor
 Parameters: size - Number of entries for the array.
 Return: None
 Note: This will also populate the array with 0s in a similar fashion as with
 a non-pointer declaration.
 */

IntegerList::IntegerList(int size) {
  list = new int[size];
  numElements = size;
  for (int ndx = 0; ndx < size; ndx++)
    list[ndx] = 0;
}

/*
 Description: Destructor
 Parameters: None
 Return: None
 Note: This will free the memory allocated by the array constructor.
 */

IntegerList::~IntegerList() { delete[] list; }

/*
 Description: Checks if the input parameter number is a valid index of the
 array. Parameters: element - index to be checked. Return: true if the argument
 is a valid index and false if not.
 */

bool IntegerList::isValid(int element) const {
  bool status = true;

  if (element < 0 || element >= numElements)
    status = false;

  return status;
}

/*
 Description: Stores a value in a specific element of the list. If an
 invalid subscript is passed, the array is unchanged.
 Parameters: element - index to insert.
 value - the value to be placed at the element position in the array.
 Return: None
 */

void IntegerList::setElement(int element, int value) {
  if (isValid(element))
    list[element] = value;
  else {
    cout << "Error: Invalid subscript: No change made. \n";
  }
}

/*
 Description: Gets a value in a specific element of the list. If an
 invalid subscript is passed, the value returned is 0.
 Parameters: element - index to extract.
 Return: Value in the element position if the index is valid and 0 otherwise.
 Note: This is really not the best method for an invalid index. You should not
 return a possibly valid value.  Later in the class we will see better methods
 for handling these types of errors.
 */

int IntegerList::getElement(int element) const {
  if (isValid(element))
    return list[element];
  else {
    cout << "Error: Invalid subscript: Returning 0. \n";
    return 0;
  }
}
