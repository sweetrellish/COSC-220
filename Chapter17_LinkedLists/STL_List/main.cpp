// This program demonstrates the STL list container.
#include <iostream>
#include <list>

using namespace std;

template <class T> void displayList(list<T> L);

int main() {
  // Define an empty list.
  list<int> myList;
  list<double> myListD;

  // Add some values to the list.
  for (int x = 0; x < 100; x += 10)
    myList.push_back(x);

  // Use an iterator to display the values.
  for (auto it = myList.begin(); it != myList.end(); it++)
    cout << *it << " ";
  cout << endl;

  // Now reverse the order of the elements.
  myList.reverse();

  // Display the values again, with a range-based for loop
  for (auto element : myList)
    cout << element << " ";
  cout << endl;

  displayList(myList);

  for (double x = 0; x < 100; x += 7.1)
    myListD.push_front(x);

  displayList(myListD);

  list<int>::iterator myListIter;
  myListIter = myList.begin();

  cout << *myListIter << endl;

  myListIter++;
  cout << *myListIter << endl;

  myListIter++;
  myListIter++;
  myListIter++;
  cout << *myListIter << endl;

  myListIter--;
  cout << *myListIter << endl;

  displayList(myListD);

  myListD.pop_front();
  displayList(myListD);

  myListD.pop_back();
  displayList(myListD);

  cout << "Length = " << myListD.size() << endl;

  return 0;
}

template <class T> void displayList(list<T> L) {
  for (auto element : L)
    cout << element << " ";
  cout << endl;
}
