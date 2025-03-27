//===========================================================================================================================
// Name        : TLinkedList.h
// Author      : Ryan C. Ellis
// Creation Date: 10/25/2024
// Last Update: 11/7/2024
// Description: Header file with specifications for templated TLinkedList class structure.
//===========================================================================================================================
// A class template for holding a linked list.
// The node type is also a class template.
#ifndef TLINKEDLIST_H
#define TLINKEDLIST_H

#include <iostream>

using namespace std;

//Feedback: Interesting, where you use class on line 562 I would have used typename, as were talking about in lab on 11/13.  I did not think the two were true synonyms.  Code looks good here.

//*********************************************
// TLinkedList class                           *
//*********************************************

template <class T> class TLinkedList {
private:
    // Note: As an inner-class the templating is "inherited" from the LinkedList.
    // Hence the ListNode<T> syntax is replaced with simply ListNode.
    class ListNode {
    public:
        T value;        // Node value
        ListNode *next; // Pointer to the next node
        
        // Constructor
        ListNode(T nodeValue) {
            value = nodeValue;
            next = nullptr;
        }
    };
    
    ListNode *head; // List head pointer
    ListNode *tail; // List tail pointer
    
public:
    // Constructor
    TLinkedList() { head = nullptr; tail = nullptr; }
    TLinkedList(const TLinkedList &);
    
    // Destructor
    ~TLinkedList();
    
    //Overloaded operators
    TLinkedList<T> &operator=(const TLinkedList<T> &);
    
    // Linked list operations
    void push_back(T);
    void push_front(T);
    T pop_front();
    T pop_back();
    T peekHead();
    T peekTail();
    void clear();
    int length();
    T get(int);
    void set(int, T);
    TLinkedList<T> sort();
    void insertNode(T);
    void deleteNode(T);
    void displayList() const;
    
    T& operator[](const int &sub);
    template <class U>
    friend ostream &operator<<(ostream &, const TLinkedList<U>&);
    
};

///============================================================================
// Description: Copy constructor for the templated TLinkedList class structure.
// Parameters: const TLinkedList<T> &list - passed list by reference.
// Return: TLinkedList<T> object
// Notes:
//============================================================================
template <class T>
TLinkedList<T> ::TLinkedList(const TLinkedList<T> &list){
    head = nullptr;
    tail = nullptr;

    ListNode *nodePtr = list.head;

    while(nodePtr != nullptr){
        push_back(nodePtr->value);
        nodePtr = nodePtr->next;
    }

    
}
//============================================================================
// Description: Push back function takes in new value and inserts a new node onto
// the back end of the list structure.
// Parameters: T newValue - new value to be stored.
// Return: void function no return
// Notes:
//============================================================================

template <class T> void TLinkedList<T>::push_back(T newValue) {
    ListNode *newNode; // point to a new node
    ListNode *nodePtr; // To traverse through the list
    
    // create a new node and store newValue there.
    newNode = new ListNode(newValue);
    
    // If there are no nodes in the list
    // make newNode the first node.
    if (!head){
        head = newNode;
        tail = newNode;
    }
    else // Otherwise, insert newNode at end.
    {
        // Initialize nodePtr to head
        nodePtr = head;
        
        // Find the last node
        while (nodePtr->next )
            nodePtr = nodePtr->next;
        
        
        // Insert newNode as the last node.
        nodePtr->next = newNode;
        tail = newNode;
    }
}

//============================================================================
// Description: Push front function takes in new value and inserts a new node onto
// the front end of the list structure.
// Parameters: T newValue - new value to be stored.
// Return: void function no return
// Notes:
//============================================================================

template <class T> void TLinkedList<T>::push_front(T newValue) {
    ListNode *newNode; // To point to a new node
    //ListNode *nodePtr; // To move through the list
    
    // create a new node and store newValue there.
    newNode = new ListNode(newValue);
    
    // If there are no nodes in the list
    // make newNode the first node.
    if (!head){
        head = newNode;
        tail = newNode;
    }
    else // Otherwise, insert newNode at beginning.
    {
        newNode->next = head;
        head = newNode;
        
    }
}
//============================================================================
// Description: Pop front function removes first node from list and returns the
// value that was stored in the node.
// Parameters: N/A
// Return: T value
// Notes:
//============================================================================

template <class T> T TLinkedList<T>::pop_front() {
    ListNode *nodePtr = head; // pointer to head node
    
    string exstring = "Empty List Exception";
    
    if(!head){
        tail = nullptr;
        throw exstring;
    }
    T val = head->value;

    head = head->next;
    delete nodePtr;

    
    return val;
}

//============================================================================
// Description: Pop back function removes last node from list and returns the
// value that was stored in the node.
// Parameters: N/A
// Return: T value
// Notes:
//============================================================================

template <class T> T TLinkedList<T>::pop_back() {
    ListNode *nodePtr = head; // pointer to head node
    
    string exstring = "Empty List Exception";
    
    if(!head){
        throw exstring;
}
    T val = tail->value;
    if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else{

        while(nodePtr->next !=tail){
            nodePtr = nodePtr->next;
        }


        delete tail;
        tail = nodePtr;
        tail->next = nullptr;

    }
    return val;
}

//============================================================================
// Description: Peek head function returns the value of the head node, if it's
// not pointing to null.
// Parameters: N/A
// Return: T value
// Notes:
//============================================================================

template <class T> T TLinkedList<T>::peekHead() {
    
    if(!head){
        string s = "Null Pointer Exception";
        throw s;
    }
    
    return head->value;
}
//============================================================================
// Description: Peek tail function returns the value of the tail node, if it's
// not pointing to null.
// Parameters: N/A
// Return: T value
// Notes:
//============================================================================

template <class T> T TLinkedList<T>::peekTail() {
    
    if(!tail){
        string s = "Null Pointer Exception";
        throw s;
    }
    
    return tail->value;
}

//============================================================================
// Description: Clear function traverses the list and removes every element within
// the list and then sets head and tail to null.
// Parameters: N/A
// Return: void function no return.
// Notes:
//============================================================================

template <class T> void TLinkedList<T>::clear() {
    ListNode *nodePtr = head; // To move through the list
    ListNode *temp;
    
    while(nodePtr != nullptr){
        temp = nodePtr;
        nodePtr = nodePtr->next;
        delete temp;


    }
    head = nullptr;
    tail = nullptr;

}
//============================================================================
// Description: Length will return the int value for the length of the list,
// traversing the list and counting along the way.
// Parameters: N/A
// Return: int value of length
// Notes:
//============================================================================

template <class T> int TLinkedList<T>::length() {
    ListNode *nodePtr;
    int count = 0;
    
    nodePtr = head;
    
    while(nodePtr != nullptr){
        count++;
        nodePtr = nodePtr->next;
    }
        
    return count;
}

//============================================================================
// Description: Get function will take in index value and traverse list, given
// validity checking passes, to find value at given index and return it.
// Parameters: int num - index value
// Return: T value in node
// Notes:
//============================================================================

template <class T> T TLinkedList<T>::get(int num) {
    ListNode *nodePtr = head;
    string exstring = "Empty List Exception";
    string boundstring = "Index Out of Bounds Exception";
    
    nodePtr = head;
    
    if(!head)
        throw exstring;
    if(num < 0 || num >= length())
        throw boundstring;

    for(int i = 0; i < num; i++)
        nodePtr = nodePtr->next;

    return nodePtr->value;


}
//============================================================================
// Description: Set function will take in two parameters, the value to be set,
// and the index of where to set it.
// Parameters: int num - index value
//             T val - value to set
// Return:void function no return.
// Notes:
//============================================================================

template <class T>
void TLinkedList<T>::set(int num, T val) {
    ListNode *nodePtr;
    string exstring = "Empty List Exception";
    string boundstring = "Index Out of Bounds Exception";
    
    nodePtr = head;
    
    if(!head)
        throw exstring;
    if(num < 0 || num > length())
        throw boundstring;
    for(int i = 0; i < num; i++)
        nodePtr = nodePtr->next;

    nodePtr->value = val;
            

}

//============================================================================
// Description: Sort function will sort the nodes by calling the insertNode function
// and will be placed in order of their ascending value.
// Parameters: N/A
// Return:TLinkedList<T>
// Notes:
//============================================================================

template <class T>
TLinkedList<T> TLinkedList<T>::sort() {

    TLinkedList<T> list;
    ListNode *nodePtr = head;

    while(nodePtr != nullptr){
        list.insertNode(nodePtr->value);
        nodePtr = nodePtr->next;
    }

    return list;

}
//============================================================================
// Description: Overloaded indexing operator checks validity of index that is being
// passed into the function, and once it clears through, return the value of the index.
// Parameters: const int &sub - index value (reference)
// Return: &T value
// Notes:
//============================================================================

template <class T>
T& TLinkedList<T>:: operator[](const int &sub){
    ListNode *nodePtr = head;
    string exstring = "Empty List Exception";
    string boundstring = "Index Out of Bounds Exception";     //validity checking, counter for 
                                            //traversing list
    
    //nodePtr = head;
    
    if(!head)
        throw exstring;                         //if list empty throw exception
    if(sub < 0 || sub >= length())        //if out of bounds throw exception
        throw boundstring;

    for(int i = 0; i <sub; i++)                    //range for loop to traverse
        nodePtr = nodePtr->next;                 //if count is sub value return pointer to node
                                                //otherwise continue to travers and increment count
    return nodePtr->value;


}

//============================================================================
// Description: Display List function will traverse list and print horizontally
// every node value in the list.
// Parameters: N/A
// Return: void function no return
// Notes:
//============================================================================

template <class T> void TLinkedList<T>::displayList() const {
    ListNode *nodePtr; // To move through the list
    
    // Position nodePtr at the head of the list.
    nodePtr = head;
    
    //  traverse the list.
    while (nodePtr != nullptr) {
        // Display the value
        cout << nodePtr->value << " ";
        
        // Move to the next node.
        nodePtr = nodePtr->next;
    }
}

//============================================================================
// Description: Insert node function will take in new T value to be inserted in
// list, and each case is assessed of where to insert the node.
// Parameters: T newValue - new value
// Return:void function no return.
// Notes:
//============================================================================

template <class T> void TLinkedList<T>::insertNode(T newValue) {
    ListNode *newNode;                // A new node
    ListNode *nodePtr = head;                // To traverse the list
    ListNode *previousNode = nullptr; // The previous node
    
    // Allocate a new node and store newValue there.
    newNode = new ListNode(newValue);
    
    // If there are no nodes in the list
    // make newNode the first node
    if (!head) {
        head = newNode;
        tail = newNode;
        newNode->next = nullptr;
    } else // Otherwise, insert newNode
    {
        
        // Skip all nodes whose value is less than newValue.
        while (nodePtr != nullptr && nodePtr->value < newValue) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        // If the new node is to be the 1st in the list,
        // insert it before all other nodes.
        if (previousNode == nullptr) {
            newNode->next = head;
            head = newNode;

        } else // Otherwise insert after the previous node.
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
        if(nodePtr == nullptr)
            tail = newNode;
    }
}

//============================================================================
// Description: Deletenode function will take in a search value to delete from
// list structure.
// Parameters: T searchValue - value to delete
// Return:void function, no return.
// Notes:
//============================================================================

template <class T> void TLinkedList<T>::deleteNode(T searchValue) {
    ListNode *nodePtr;      // To traverse the list
    ListNode *previousNode; // To point to the previous node
    
    // If the list is empty, do nothing.
    if (!head)
        return;
    
    // Determine if the first node is the one.
    if (head->value == searchValue) {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
        if(head == nullptr)
            tail = nullptr;
    } else {
        // Initialize nodePtr to head of list
        nodePtr = head;
        
        // Skip all nodes whose value member is
        // not equal to num.
        while (nodePtr != nullptr && nodePtr->value != searchValue) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        // If nodePtr is not at the end of the list,
        // link the previous node to the node after
        // nodePtr, then delete nodePtr.
        if (nodePtr) {
            previousNode->next = nodePtr->next;
            delete nodePtr;

            if(previousNode->next == nullptr)
                tail = previousNode;

        }
    }
    return;
}

//============================================================================
// Description: Destructor function deletes TLinkedList object.
// Parameters: N/A
// Return: destructor function, no return.
// Notes:
//============================================================================

template <class T> TLinkedList<T>::~TLinkedList() {
    ListNode *nodePtr;  // To traverse the list
    ListNode *nextNode; // To point to the next node
    
    // Position nodePtr at the head of the list.
    nodePtr = head;
    
    // While nodePtr is not pointing to null
    while (nodePtr != nullptr) {
        // Save a pointer to the next node.
        nextNode = nodePtr->next;
        
        // Delete the current node.
        delete nodePtr;
        
        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
}

//============================================================================
// Description: Overloaded operator for the assignment operator takes in right hand
// TLinkedList object and assigns values of right to the left.
// Parameters: const TLinkedList<T> &right - TLinkedList object on right hand side.
// Return:TLinkedList<T> object.
// Notes:
//============================================================================
template <class T>
TLinkedList<T>& TLinkedList<T> :: operator=(const TLinkedList<T> &right){

    if(this != &right){
        clear();

        ListNode *nodePtr = right.head;

        while(nodePtr != nullptr){
            push_back(nodePtr->value);
            nodePtr = nodePtr->next;
        }
    }

    return *this;
    
}

//============================================================================
// Description: Overloaded streaming operator will take in TLinkedList<T> object
// and ostream &strm object, and will format how to print TLinkedList to screen.
// Parameters: ostream &strm - stream object
//             const TLinkedList<T> &obj - TLinkedList object
// Return:mostream object
// Notes:
//============================================================================
template <class T>
ostream&  operator<<(ostream &strm, const TLinkedList<T> &obj){

    class TLinkedList<T> ::ListNode *nodePtr = obj.head;


    strm << "[";
    while(nodePtr != nullptr){
        strm << nodePtr->value;
        nodePtr = nodePtr->next;
        if(nodePtr != nullptr)
            strm << ", ";
    }
    strm << "]";
    return strm;

    
}
#endif
