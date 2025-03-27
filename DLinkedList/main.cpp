//===========================================================================================================================
// Name        : main.cpp
// Author      : Ryan C. Ellis
// Creation Date: 10/25/2024
// Last Update:11/7/2024
// Description: Main function to implement DLinkedList class structure and manipulate data using public member functions.
//===========================================================================================================================
#include <ctime>
#include <iostream>

#include "DLinkedList.h"

using namespace std;

template <class T> void displayHeadTail(DLinkedList<T> &);
void div(string s = "") {
  cout << "\n" << s << "----------------------------------\n\n";
}
int main() {

  srand(time(0));
  DLinkedList<int> lst;
  div("Push back and delete tests ");
  lst.push_back(12);
  lst.push_back(4);
  lst.push_back(54);
  lst.push_back(10);
  lst.displayList();
  cout << endl;
  displayHeadTail(lst);
  lst.push_back(101);
  lst.push_back(17);
  lst.push_back(21);
  lst.displayList();
  cout << endl;
  displayHeadTail(lst);
  lst.deleteNode(12);
  lst.displayList();
  cout << endl;
  displayHeadTail(lst);
  lst.deleteNode(101);
  lst.displayList();
  cout << endl;
  displayHeadTail(lst);
  lst.deleteNode(1234);
  lst.displayList();
  cout << endl;
  displayHeadTail(lst);
  lst.deleteNode(21);
  lst.displayList();
  cout << endl;
  displayHeadTail(lst);
  lst.push_back(112);
  lst.push_back(14);
  lst.push_back(154);
  lst.push_back(110);
  lst.displayList();
  cout << endl;
  displayHeadTail(lst);
  div("Print reversed ");
  lst.displayList();
  cout << endl;
  lst.displayList(false, true);
  cout << endl;
  div("Insert Tests ");
  lst.clear();
  displayHeadTail(lst);
  lst.clear();
  lst.insertNode(45);
  lst.displayList();
  cout << endl;
  displayHeadTail(lst);
  lst.insertNode(21);
  lst.displayList();
  cout << endl;
  displayHeadTail(lst);
  lst.insertNode(57);
  lst.displayList();
  cout << endl;
  displayHeadTail(lst);
  for (int i = 0; i < 10; i++)
    lst.insertNode(rand() % 100);
  lst.displayList();
  cout << endl;
  displayHeadTail(lst);
  div("Push front tests ");
  lst.clear();
  lst.push_front(12);
  lst.displayList();
  cout << endl;
  displayHeadTail(lst);
  lst.push_front(15);
  lst.displayList();
  cout << endl;
  displayHeadTail(lst);
  lst.push_front(25);
  lst.displayList();
  cout << endl;
  displayHeadTail(lst);
  for (int i = 0; i < 10; i++)
    lst.push_front(rand() % 100);
  lst.displayList();
  cout << endl;
  displayHeadTail(lst);
  div("Pop front and back with indexing tests ");
  try {
    cout << lst.pop_front() << endl;
    lst.displayList();
    cout << endl;
    displayHeadTail(lst);
    cout << lst.pop_front() << endl;
    lst.displayList();
    cout << endl;
    displayHeadTail(lst);
    cout << lst.pop_front() << endl;
    lst.displayList();
    cout << endl;
    displayHeadTail(lst);
    cout << lst.pop_front() << endl;
    lst.displayList();
    cout << endl;
    displayHeadTail(lst);
    cout << lst.pop_back() << endl;
    lst.displayList();
    cout << endl;
    displayHeadTail(lst);
    cout << lst.pop_back() << endl;
    lst.displayList();
    cout << endl;
    displayHeadTail(lst);
    cout << lst.pop_back() << endl;
    lst.displayList();
    cout << endl;
    displayHeadTail(lst);
  } catch (string err) {
    cout << err << endl;
  }
  try {
    cout << lst[5] << endl;
    cout << lst[2] << endl;
    cout << lst[6] << endl;
    cout << lst[21] << endl;
  } catch (string err) {
    cout << err << endl;
  }
  lst.displayList();
  cout << endl;
  try {
    lst[5] = 17;
    lst[1] = 29;
    lst[3] = 11;
    lst[52] = 7;
  } catch (string err) {
    cout << err << endl;
  }
  lst.displayList();
  cout << endl;
  displayHeadTail(lst);
  try {
    lst.set(5, -17);
    lst.set(1, -29);
    lst.set(3, -11);
    lst.set(52, -7);
  } catch (string err) {cout << err << endl;
  }
  lst.displayList();
  cout << endl;
  displayHeadTail(lst);
  div("CC and = tests ");
  DLinkedList<int> L1;
  for (int i = 0; i < 5; i++)
    L1.push_back(rand() % 10000 + 1);
  DLinkedList<int> L2 = L1;
  DLinkedList<int> L3(L1);
  L1.displayList();
  cout << endl;
  L2.displayList();
  cout << endl << endl;
  L3.displayList();
  cout << endl;
  L1[3] = 1234567;
  L3[3] = 7654321;
  L1.displayList();
  cout << endl;
  L2.displayList();
  cout << endl;
  L3.displayList();
  cout << endl << endl;
  L3 = L2 = L1;
  L1.displayList();
  cout << endl;
  L2.displayList();
  cout << endl;
  L3.displayList();
  cout << endl << endl;
  L1[3] = 987654321;
  L2[1] = -25;
  L1.displayList();
  cout << endl;
  L2.displayList();
  cout << endl;
  L3.displayList();
  cout << endl << endl;
  L1 = L1;
  cout << L1 << endl;
  cout << endl;
  div("Reverse tests ");
  L2 = L1.reverse();
  cout << L1 << endl;
  cout << L2 << endl;
  cout << endl;
  L2.pop_front();
  L2.pop_back();
  cout << L1 << endl;
  cout << L2 << endl;
  cout << endl;
  div("Sort tests ");
  L2 = L1.sort();
  cout << L1 << endl;
  cout << L2 << endl;
  cout << endl;
  L1 = L1.sort();
  cout << L1 << endl;
  cout << endl;
  return 0;
}
template <class T> void displayHeadTail(DLinkedList<T> &L) {
  cout << "Head: ";
  try {
    cout << L.peekHead() << endl;
  } catch (string s) {
    cout << s << endl;
  }
  cout << "Tail: ";
  try {
    cout << L.peekTail() << endl;
  } catch (string s) {
    cout << s << endl;
  }
}
