//===========================================================================================================================
// Name        : main.cpp
// Author      : Ryan C. Ellis
// Creation Date: 11/13/2024
// Last Update: 11/14/2024
// Description: Main program that includes the PriorityQueue class structure, and calls public functions within that and the STL
// for vectors, to manipulate the class strucutre and show its functionality.
//===========================================================================================================================

#include <iostream>
#include "PriorityQueue.h"

using namespace std;

void println(string s = "") { cout << s << endl; }
int main() {
    PriorityQueue<int> queue;
    
    queue.enqueue(7);
    queue.enqueue(5);
    queue.enqueue(15, 3);
    queue.print();
    
    int t = queue.dequeue();
    
    cout << t << endl;
    queue.print();
    t = queue.dequeue();
    cout << t << endl;
    queue.print();
    t = queue.dequeue();
    cout << t << endl;
    queue.print();
    t = queue.dequeue(); // Too Far
    cout << t << endl;
    queue.print();

    for (int i = 0; i < 10; i++)
        queue.enqueue(i, i);

    queue.print();
    cout << queue.size() << endl;
    queue.clear();
    cout << queue.size() << endl;

    for (int i = 0; i < 10; i++)
        queue.enqueue(i, i % 3 + 1);

    queue.print();

    while (!queue.isEmpty()) {
        t = queue.dequeue();
        cout << t << " ";
    }
    println();

    PriorityQueue<string> Squeue;

    Squeue.enqueue("Sam", 2);
    Squeue.enqueue("John");
    Squeue.enqueue("Jack");

    string strarr[] = {"considerable", "substantial", "pronounced",
    "significant", "appreciable", "serious",
    "exceptional", "extraordinary", "tremendous",
    "stupendous", "unlimited", "boundless",
    "cosmic"};

    for (int i = 0; i < 13; i++) {
        Squeue.enqueue(strarr[i], i % 3 + 1);
    }

    Squeue.print();
    println();

    while (!Squeue.isEmpty()) {
        string c = Squeue.dequeue();
        cout << c << " // ";
    }

    println();

    return 0;
}
