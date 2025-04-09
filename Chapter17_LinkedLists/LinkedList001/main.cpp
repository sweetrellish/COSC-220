// This program demonstrates the deleteNode member function.

#include <iostream>

#include "NumberList.h"

using namespace std;

int main() {
  // Define a NumberList object.
  NumberList list;

  // Build the list with some values.
  list.appendNode(2.5);
  list.appendNode(7.9);
  list.appendNode(12.6);

  // Display the list.
  cout << "Here are the initial values:\n";
  list.displayList();
  cout << endl;

  // Delete the middle node.
  cout << "Now deleting the node in the middle.\n";
  list.deleteNode(7.9);

  // Display the list.
  cout << "Here are the nodes left.\n";
  list.displayList();
  cout << endl;

  list.appendNode(3.4);
  list.appendNode(-5.3);
  list.appendNode(6.7);

  cout << "Here are the nodes left.\n";
  list.displayList();
  cout << endl;

  // Delete the last node.
  cout << "Now deleting the last node.\n";
  list.deleteNode(6.7);

  // Display the list.
  cout << "Here are the nodes left.\n";
  list.displayList();
  cout << "List Length: " << list.length() << endl;
  cout << endl;

  // Delete 2.5
  cout << "Now deleting 2.5.\n";
  list.deleteNode(2.5);

  // Display the list.
  cout << "Here are the nodes left.\n";
  list.displayList();
  cout << endl;

  // Delete the list.
  cout << "Delete entire list.\n";
  list.deleteList();
  cout << "List Length: " << list.length() << endl;

  // Display the list.
  cout << "Here are the nodes left.\n";
  list.displayList();

  list.insertNode(4.5);
  list.displayList();
  list.insertNode(2.1);
  list.displayList();
  list.insertNode(5.7);
  list.displayList();
  list.insertNode(3.3);
  list.displayList();
  list.insertNode(2.9);
  list.displayList();
  list.insertNode(6);
  list.displayList();

  return 0;
}
