/*
 Name          : IntegerList.h
 Author        : Don Spickler
 Creation Date : 1/21/2022
 Last Update   : 1/21/2022
 Description   : Specification file for the IntegerList class.
 Stores a dynamically allocated array of integers and the size of the
 array.  The accessor and mutator functions do not allow access to
 elements outside the array bounds.  This is a feature in other languages
 like Java that are not built into C++.
 */

#ifndef INTEGERLIST_H
#define INTEGERLIST_H

class IntegerList {
private:
  int *list;               // Pointer to the array.
  int numElements;         // Number of elements.
  bool isValid(int) const; // Validates subscripts.

public:
  IntegerList(int); // Constructor
  ~IntegerList();   // Destructor

  void setElement(int, int); // Sets an element to a value
  int getElement(int) const; // Returns an element
};

#endif
