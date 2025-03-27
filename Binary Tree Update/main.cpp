//===========================================================================================================================
// Name        : main.cpp
// Author      : Ryan C. Ellis
// Creation Date: 12/1/2024
// Last Update: 12/5/2024
// Description: Main program will use functions in Binary Tree class structure and test them and manipulate them.
//===========================================================================================================================

#include "BinaryTree.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

template <class T> void TreeInfo(BinaryTree<T> &tree) {
  cout << endl;
  tree.PrintTree(5);
  cout << endl;
  cout << "Number of nodes in the tree = " << tree.numberOfNodes() << endl;
  cout << "Number of leaf nodes in the tree = " << tree.numberOfLeafNodes()
       << endl;
  cout << "Height of the tree = " << tree.height() << endl;
}
template <class T> void TreeInfoBV(BinaryTree<T> tree) {
  cout << "Tree Copy" << endl;
  TreeInfo(tree);
}
void div() { cout << "\n--------------------------\n\n"; }
int main() {
  srand(time(NULL));
  int size = 0;
  BinaryTree<int> tree;
  cout << "Empty Tree";
  TreeInfo(tree);
  cout << endl;
  cout << "Input number of elements to insert: ";
  cin >> size;
  for (int i = 0; i < size; i++)
    tree.insertNode(rand() % 100 + 1);
  TreeInfo(tree);
  div();
  BinaryTree<int> tree2 = tree;
  TreeInfo(tree2);
  div();
  for (int i = 0; i < 10; i++)
    tree.insertNode(rand() % 100 + 1);
  TreeInfo(tree);
  TreeInfo(tree2);
  div();
  BinaryTree<int> tree3;
  tree3 = tree2;
  TreeInfo(tree3);
  div();
  TreeInfoBV(tree2);
  div();
  for (int i = 0; i < 5; i++)
    tree2.insertNode(rand() % 100 + 1);
  tree = tree3 = tree2;
  TreeInfo(tree);
  TreeInfo(tree2);
  TreeInfo(tree3);
  return 0;
}
