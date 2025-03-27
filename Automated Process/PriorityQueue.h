//===========================================================================================================================
// Name        : PriorityQueue.h
// Author      : Ryan C. Ellis
// Creation Date: 11/13/2024
// Last Update: 11/26/2024
// Description: Header file for the templated PQNode and PriorityQueue class structure.
//===========================================================================================================================

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T> 
class PQNode {
public:
    T data;
    int priority;
    PQNode(T Data) {
        data = Data;
        priority = 1;
    }
    PQNode(T Data, int Priority) {
        data = Data;
        if (Priority < 1)
            Priority = 1;
        priority = Priority;
    }
};

template <class T> 
class PriorityQueue {
private:
    vector<PQNode<T>> queue;
public:
    // Constructors and Destructor
    PriorityQueue();
    PriorityQueue(const PriorityQueue &obj);
    ~PriorityQueue();
    // Acessors and Mutators
    void enqueue(T Data, int Priority = 1);
    T dequeue();
    // Other Functions
    void print();
    bool isEmpty();
    void clear();
    int size();

    T& operator[](const int &sub);
};

//============================================================================
// Description: Default constructor for the PriorityQueue class.
// Parameters: N/A
// Return: Constructor
// Notes:
//============================================================================
template <class T> 
PriorityQueue<T> :: PriorityQueue(){
    //default constructor
}

//============================================================================
// Description: Copy constructor for the PriorityQueue class.
// Parameters: const PriorityQueue &obj - PriorityQueue object
// Return: PriorityQueue object
// Notes:
//============================================================================
template <class T>
PriorityQueue<T> :: PriorityQueue(const PriorityQueue &obj){

    PriorityQueue temp;
    for(int i = 0; i < obj.size(); i++){
            temp.queue[i].data = obj.queue[i].data;
            temp.queue[i].priority = obj.queue[i].priority;
    }

}

//============================================================================
// Description: Destructor for the PriorityQueue class.
// Parameters: N/A
// Return: Destructor, no return
// Notes:
//============================================================================
template <class T>
PriorityQueue<T> :: ~PriorityQueue(){
    
}

//============================================================================
// Description: Function will take in parameters for PQNode data and priority level,
// which will be set to a temp node and pushed back onto the queue.
// Parameters: T Data - Data of type T
//             int level - priority level
// Return: void function no return.
// Notes:
//============================================================================
template <class T> 
void PriorityQueue<T> :: enqueue(T Data, int level){
    PQNode<T> temp(Data, level);
    queue.push_back(temp);
}

//============================================================================
// Description: Function will parse through queue and find first instance of highest
// priority node and return data that is in node to be erased from queue.
// Parameters: N/A
// Return: T temp
// Notes:
//============================================================================
template <class T>
T PriorityQueue<T> :: dequeue(){

    if(queue.empty())
        return T();

    T temp = queue[0].data;
    int index = 0;

    for(unsigned int i = 0; i <queue.size(); i++){
        if(queue[index].priority < queue[i].priority){
            index = i;
            temp = queue[i].data;
        }
    }
    queue.erase(queue.begin() + index);
   
   return temp;

}

//============================================================================
// Description: Function will print out queue and data/priority for each node.
// Parameters: N/A
// Return: void function, no return.
// Notes:
//============================================================================
template <class T> 
void PriorityQueue<T> :: print(){

    for(unsigned int i = 0; i <queue.size(); i++){
        
        cout<< queue[i].data << " --- "<< queue[i].priority<<endl;
    }
}

//============================================================================
// Description: Function will check if queue is empty and return boolean value.
// Parameters: N/A
// Return: boolean true/false.
// Notes:
//============================================================================
template <class T>
bool PriorityQueue<T> :: isEmpty(){
    if(queue.empty()) return true;
    else return false;
}

//============================================================================
// Description: Function will clear queue of all nodes.
// Parameters: N/A
// Return: void function no return.
// Notes:
//============================================================================
template <class T>
void PriorityQueue<T> :: clear(){
    queue.clear();
        
}

//============================================================================
// Description: Function will return size of queue.
// Parameters: N/A
// Return: int (size of queue).
// Notes:
//============================================================================
template <class T>
int PriorityQueue<T> :: size(){
    return queue.size();
}

//============================================================================
// Description:Overloaded indexing operator checks validity of index that is being
// passed into the function, and once it clears through, return the value of the index.
// Parameters: const int &sub - index value (reference)
// Return: &T value
// Notes:
//============================================================================
template <class T>
T& PriorityQueue<T> :: operator[](const int &sub){
    return queue[sub].data;
}

#endif
