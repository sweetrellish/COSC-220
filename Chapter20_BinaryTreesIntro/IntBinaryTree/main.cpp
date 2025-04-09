#include <cstdlib>
#include <ctime>
#include <iostream>

#include "IntBinaryTree.h"

using namespace std;

int main() {
  srand(time(0));

  IntBinaryTree tree;

  cout << "Inserting nodes. ";

  /*
  tree.insertNode(5);
  tree.insertNode(8);
  tree.insertNode(3);
  tree.insertNode(14);
  tree.insertNode(12);
  tree.insertNode(9);
  tree.insertNode(4);
  tree.insertNode(9);
  // */

  tree.insertNode(17);
  tree.insertNode(3);
  tree.insertNode(21);
  tree.insertNode(5);
  tree.insertNode(2);
  tree.insertNode(19);
  tree.insertNode(18);
  tree.insertNode(32);
  tree.insertNode(31);
  tree.insertNode(25);
  tree.insertNode(20);
  tree.insertNode(7);
  tree.insertNode(10);
  tree.insertNode(9);

  //\verb|17, 3, 21, 5, 2, 19, 18, 32, 31, 25, 20, 7, 10, 9

  /*
   for (int i = 0; i < 10; i++)
   tree.insertNode(i + 1);
   // */

  /*
   for (int i = 0; i < 20; i++)
   tree.insertNode(rand() % 100 + 1);
   // */

  cout << "Done.\n\n";

  cout << "Tree:\n";
  tree.PrintTree();

  // Display inorder.
  cout << "Inorder traversal:\n";
  tree.displayInOrder();

  // Display preorder.
  cout << "\nPreorder traversal:\n";
  tree.displayPreOrder();

  // Display postorder.
  cout << "\nPostorder traversal:\n";
  tree.displayPostOrder();

  cout << endl;

  // Search for the value 3.
  if (tree.searchNode(3))
    cout << "3 is found in the tree.\n";
  else
    cout << "3 was not found in the tree.\n";

  // Search for the value 100.
  if (tree.searchNode(100))
    cout << "100 is found in the tree.\n";
  else
    cout << "100 was not found in the tree.\n";

  cout << endl;

  cout << "Tree:\n";
  tree.PrintTree();

  cout << endl;

  // Delete the value 8.
  cout << "Deleting 8...\n";
  tree.remove(8);

  cout << "Tree:\n";
  tree.PrintTree();

  cout << endl;

  // Delete the value 12.
  cout << "Deleting 12...\n";
  tree.remove(12);

  cout << "Tree:\n";
  tree.PrintTree();

  return 0;
}
