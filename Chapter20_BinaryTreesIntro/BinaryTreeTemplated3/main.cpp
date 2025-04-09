#include "BinaryTree.h"
#include "FeetInches.h"
#include <iostream>

using namespace std;

const int NUM_NODES = 5;

int main() {
  FeetInches item;

  // Create the binary tree.
  BinaryTree<FeetInches> tree;

  for (int count = 0; count < NUM_NODES; count++) {
    cout << "Enter a distance: ";
    cin >> item;
    tree.insertNode(item);
  }

  // Display the values.
  cout << "\nHere are the values in the tree:\n";
  tree.displayInOrder();

  cout << "\nTree:\n";
  tree.PrintTree(10);

  return 0;
}
