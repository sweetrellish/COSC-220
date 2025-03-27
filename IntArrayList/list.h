//============================================================================
// Name        : list.h
// Author      : Ryan Ellis
// Creation Date: 9/13/2024
// Last Update: 9/13/2024
// Description: Class definition of IntArrayList, that has private values  of
// int pointer array list and int size. Public functions declared  that will
// manipulate and configure array list.
//============================================================================
//============================================================================

#ifndef LIST_H
#define LIST_H

class IntArrayList {
private:
  int *list;
  int size;

public:
  IntArrayList();
  ~IntArrayList();
  IntArrayList(int *list, int size);
  void duplicate(IntArrayList &);
  void display(bool vert = false);
  void displayAddress();
  void sort();
  bool sorted();
  void add(int);
  void concat(const IntArrayList &);
  void remove(int, int);
  void shuffle();
  void sub(int, int);
  void insert(const IntArrayList &, int);
  void insert(int, int);
  int get(int);
  void set(int, int);
  void resize(int);
  int length();
};

#endif
