//===========================================================================================================================
// Name        : BinaryTree.h
// Author      : Ryan C. Ellis
// Creation Date: 12/5/2024
// Last Update: 12/5/2024
// Description: Header file for the Binary Tree class structure with added functions.
//===========================================================================================================================
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;

// Stack template
template <class T> class BinaryTree {
private:
  class TreeNode {
  public:
    T value;         // The value in the node
    TreeNode *left;  // Pointer to left child node
    TreeNode *right; // Pointer to right child node
                     // TreeNode *parent;

    TreeNode() {
      left = nullptr;
      right = nullptr;
    }
  };

  TreeNode *root; // Pointer to the root node

  // Private member functions
  void insert(TreeNode *&, TreeNode *&);
  void destroySubTree(TreeNode *);
  void deleteNode(T, TreeNode *&);
  void makeDeletion(TreeNode *&);
  void displayInOrder(TreeNode *) const;
  void displayPreOrder(TreeNode *) const;
  void displayPostOrder(TreeNode *) const;
  void IndentBlock(int);
  void PrintTree(TreeNode *, int, int);
  void loadInOrderRec (TreeNode *, T [], int &);
  void loadInOrder(T []);
  int numberOfNodesRec(TreeNode *);
  int numberOfLeafNodesRec(TreeNode *);
  int heightRec(TreeNode *);
  void treeCopyRec(TreeNode *&, TreeNode *);

public:
  // Constructor
  BinaryTree() { root = nullptr; }
  BinaryTree (const BinaryTree &);

  // Destructor
  ~BinaryTree() { destroySubTree(root); }

  // Binary tree operations
  void insertNode(T);
  bool searchNode(T);
  void remove(T);

  void displayInOrder() const { displayInOrder(root); }
  void displayPreOrder() const { displayPreOrder(root); }
  void displayPostOrder() const { displayPostOrder(root); }
  void PrintTree(int Indent = 4, int Level = 0);
  int numberOfNodes();
  int numberOfLeafNodes();
  int height();
  void clear();

  BinaryTree<T> &operator=(const BinaryTree<T> &);

};

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************
template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
  if (nodePtr == nullptr)
    nodePtr = newNode; // Insert the node.
  else if (newNode->value < nodePtr->value)
    insert(nodePtr->left, newNode); // Search the left branch
  else
    insert(nodePtr->right, newNode); // Search the right branch
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************
template <class T> void BinaryTree<T>::insertNode(T item) {
  TreeNode *newNode = nullptr; // Pointer to a new node.

  // Create a new node and store num in it.
  newNode = new TreeNode;
  newNode->value = item;
  newNode->left = newNode->right = nullptr;

  // Insert the node.
  insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************
template <class T> void BinaryTree<T>::destroySubTree(TreeNode *nodePtr) {
  if (nodePtr) {
    if (nodePtr->left)
      destroySubTree(nodePtr->left);
    if (nodePtr->right)
      destroySubTree(nodePtr->right);
    delete nodePtr;
  }
}

//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************
template <class T> bool BinaryTree<T>::searchNode(T item) {
  TreeNode *nodePtr = root;

  while (nodePtr) {
    if (nodePtr->value == item)
      return true;
    else if (item < nodePtr->value)
      nodePtr = nodePtr->left;
    else
      nodePtr = nodePtr->right;
  }
  return false;
}

//**********************************************
// remove calls deleteNode to delete the       *
// node whose value member is the same as num. *
//**********************************************
template <class T> void BinaryTree<T>::remove(T item) {
  deleteNode(item, root);
}

//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num.                *
//********************************************
template <class T> void BinaryTree<T>::deleteNode(T item, TreeNode *&nodePtr) {
  //fix in class to avoid seg fault? if node value isn't found
  if (!nodePtr)
    return;

  if (item < nodePtr->value)
    deleteNode(item, nodePtr->left);
  else if (item > nodePtr->value)
    deleteNode(item, nodePtr->right);
  else
    //return? to avoid seg fault
    makeDeletion(nodePtr);
}

//***********************************************************
// makeDeletion takes a reference to a pointer to the node  *
// that is to be deleted. The node is removed and the       *
// branches of the tree below the node are reattached.      *
//***********************************************************
template <class T> void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr) {
  // Define a temporary pointer to use in reattaching
  // the left subtree.
  TreeNode *tempNodePtr = nullptr;

  if (nodePtr == nullptr)
    cout << "Cannot delete empty node.\n";
  else if (nodePtr->right == nullptr) {
    tempNodePtr = nodePtr;
    nodePtr = nodePtr->left; // Reattach the left child
    delete tempNodePtr;
  } else if (nodePtr->left == nullptr) {
    tempNodePtr = nodePtr;
    nodePtr = nodePtr->right; // Reattach the right child
    delete tempNodePtr;
  }
  // If the node has two children.
  else {
    // Move one node the right.
    tempNodePtr = nodePtr->right;
    // Go to the end left node.
    while (tempNodePtr->left)
      tempNodePtr = tempNodePtr->left;
    // Reattach the left subtree.
    tempNodePtr->left = nodePtr->left;
    tempNodePtr = nodePtr;
    // Reattach the right subtree.
    nodePtr = nodePtr->right;
    delete tempNodePtr;
  }
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************
template <class T> void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const {
  if (nodePtr) {
    displayInOrder(nodePtr->left);
    cout << nodePtr->value << endl;
    displayInOrder(nodePtr->right);
  }
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************
template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const {
  if (nodePtr) {
    cout << nodePtr->value << endl;
    displayPreOrder(nodePtr->left);
    displayPreOrder(nodePtr->right);
  }
}

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************
template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const {
  if (nodePtr) {
    displayPostOrder(nodePtr->left);
    displayPostOrder(nodePtr->right);
    cout << nodePtr->value << endl;
  }
}

//****************************************************************
// Simple helper function to do the indentations for the tree
// printing algorithm.
//****************************************************************

template <class T> void BinaryTree<T>::IndentBlock(int num) {
  for (int i = 0; i < num; i++)
    cout << " ";
}

//****************************************************************
// This function recursively prints the tree contents to the
// console using a reverse inorder traversal with indenting.
//****************************************************************

template <class T>
void BinaryTree<T>::PrintTree(TreeNode *t, int Indent, int Level) {
  if (t != NULL) {
    PrintTree(t->right, Indent, Level + 1);
    IndentBlock(Indent * Level);
    cout << t->value << "\n";
    PrintTree(t->left, Indent, Level + 1);
  }
}

//****************************************************************
// This function initiates the recursive printing function to
// print the contents of the tree in tree form sideways with the
// root at the far left.
//****************************************************************

template <class T> void BinaryTree<T>::PrintTree(int Indent, int Level) {
  if (root != NULL)
    PrintTree(root, Indent, Level);
}

//============================================================================
// Description:Recursive function to load elements into next position of array from an in order traversal of tree.
// Parameters: Treenode *nodePtr - pointer to traverse tree
//             T A[]- array of type T
//             int &pos - position of array by reference
// Return:void no return
// Notes:
//============================================================================
template <class T>
void BinaryTree<T> :: loadInOrderRec(TreeNode *nodePtr, T A[], int &pos){
  if(nodePtr){
    loadInOrderRec(nodePtr->left, A, pos);
    A[pos++] = nodePtr ->value;
    loadInOrderRec(nodePtr->right, A, pos);
  }

}

//============================================================================
// Description:Function call will implement recursive function to the root of the tree.
// Parameters: T A[] - array of type T
// Return: void no return
// Notes:
//============================================================================
template <class T>
void BinaryTree<T> :: loadInOrder(T A[]){
  int pos = 0;
  loadInOrderRec(root, A, pos);
}

//============================================================================
// Description:Function call will implement recursive function to the root of the tree.
// Parameters: N/A
// Return: int recursive function call
// Notes:
//============================================================================
template <class T>
int BinaryTree<T> :: numberOfNodes(){
  return numberOfNodesRec(root);

}

//============================================================================
// Description: Recursive function that counts the number of nodes in the tree and returns that value.
// Parameters: TreeNode *nodePtr - pointer to traverse tree
// Return: int - number of nodes
// Notes:
//============================================================================
template <class T>
int BinaryTree<T> :: numberOfNodesRec(TreeNode *nodePtr){
  if(!nodePtr)
    return 0;
  return 1 + numberOfNodesRec(nodePtr->left) + numberOfNodesRec(nodePtr->right);
}
//============================================================================
// Description:Function call will implement recursive function to the root of the tree.
// Parameters: N/A
// Return: int recursive function call
// Notes:
//============================================================================
template <class T>
int BinaryTree<T> :: numberOfLeafNodes(){
  return numberOfLeafNodesRec(root);
}

//============================================================================
// Description:Recursive function that counts the number of leaf nodes in the tree and returns that value.
// Parameters: TreeNode *nodePtr - pointer to traverse tree
// Return: int - number of leaf nodes
// Notes:
//============================================================================
template <class T>
int BinaryTree<T> ::numberOfLeafNodesRec(TreeNode *nodePtr){

  if(!nodePtr)
    return 0;

  int leafcount = numberOfLeafNodesRec(nodePtr->left);

  if(nodePtr->left == nullptr && nodePtr->right == nullptr)
    leafcount++;
  leafcount += numberOfLeafNodesRec(nodePtr->right);

  return leafcount;

  return numberOfLeafNodesRec(nodePtr->left) + numberOfLeafNodesRec(nodePtr->right);
}
//============================================================================
// Description:Function call will implement recursive function to the root of the tree.
// Parameters: N/A
// Return: int recursive function call
// Notes:
//============================================================================
template <class T>
int BinaryTree<T> ::height(){
  return heightRec(root);
}

//============================================================================
// Description:Recursive function that counts the height of the tree and returns that value.
// Parameters: TreeNode *nodePtr - pointer to traverse tree
// Return: int - height of tree
// Notes:
//============================================================================
template <class T>
int BinaryTree<T> :: heightRec(TreeNode *nodePtr){
  if(!nodePtr)
    return 0;
  int left = heightRec(nodePtr->left);
  int right = heightRec(nodePtr->right);
  return 1 + max(left, right);
}

//============================================================================
// Description: Function call will use recursive function to delete all subtrees from root in tree.
// Parameters: N/A
// Return: void no return
// Notes:
//============================================================================
template <class T>
void BinaryTree<T> :: clear(){
  destroySubTree(root);
  root = nullptr;
}

//============================================================================
// Description: Copy constructor for Binary Tree class structure, using recursive function to do a deep copy.
// Parameters: const BinaryTree<T> &obj - Binary Tree object
// Return: Binary Tree object
// Notes:
//============================================================================
template <class T>
BinaryTree<T> :: BinaryTree(const BinaryTree<T> &obj){
  root = nullptr;
  if(obj.root != nullptr)
    treeCopyRec(root, obj.root );
}

//============================================================================
// Description: Recursive function that determines if tree is empty and if not, traverses through tree and sets values of each node to new tree.
// Parameters: TreeNode *node1, *node2 - called object and pass object.
// Return: void no return
// Notes:
//============================================================================
template <class T>
void BinaryTree<T> :: treeCopyRec(TreeNode *&node1, TreeNode *node2){
  if(node2 != nullptr){
    node1 = new TreeNode;
    node1->value = node2->value;
    treeCopyRec(node1->left,node2->left );
    treeCopyRec(node1->right,node2->right );
  }
}

//============================================================================
// Description: Overloaded assignment operator for Binary Tree class. If it is not equivalent then it clears the current tree and calls recursive function to set values of passed tree to called tree.
// Parameters: const BinaryTree<T> &obj - Binary Tree object
// Return: Binary Tree object
// Notes:
//============================================================================
template <class T>
BinaryTree<T>& BinaryTree<T> :: operator=(const BinaryTree<T> &obj){
  if(this != &obj){
    destroySubTree(root);
    root = nullptr;
  }
  if(obj.root != nullptr)
    treeCopyRec(root, obj.root);
  return *this;

}

#endif
