
//===========================================================================================================================
// Name        : main.cpp
// Author      : Ryan C. Ellis
// Creation Date: 11/15/2024
// Last Update: 11/26/2024
// Description: Main program will run a simulation of processes entering into an array of cpu cores and looping through each clock
// cycle adding and removing processes throughout, and will give a status report once the number of simulations are over.
//===========================================================================================================================

//Note: This program isn't running up to standards, I have implemented the output file to track what is occurring when each process
// is enqueued/dequeued and the array values. I'm having difficulty with the logic of the prompt method of adding processes
// because the time stamp is always the same as the clock cycle and it's not giving me a correct wait time, which throws off the whole
// thing. Also the queue is always empty so the final results are also blank.


//Feedback: t.setExeTime(rand()%(maxex-minex+1) + minex);     //set execution time
// You only want to increment the idle time if the core is ready and there is nothing in the queue.
// The remaining processes should be taken care of outside the simulation loop. This is for processes that are still in the queue after all simulation cycles are done.
// int data for the accumulators is probably too small, use unsigned longs or even long long data types.

#include <iostream>
#include <ctime>
#include "PriorityQueue.h"
#include "Process.h"
#include <fstream>
#include <string>

using namespace std;

void println(string s = "") { cout << s << endl; }      //print line function

int main() {

    srand((0));         //set time seed

    PriorityQueue<Process> queue;       //queue structure to hold processes and varialbes to store input values
    int count = 0;
    int cores;
    int minex;
    int maxex;
    int levels;
    double newproc;
    double simlength;
    ofstream file;              // output file to test simulation runs and see where values are stored

    cout<<"Input the Number of CPU Cores: ";
    cin>>cores;
    cout<<"Input the Minimum Number of Execution Cycles per Process: ";
    cin>>minex;
    cout<<"Input the Maximum Number of Execution Cycles per Process: ";
    cin>>maxex;
    cout<<"Input the Number of Priority Levels: ";
    cin>>levels;
    cout<<"Input the Number of New Processes per Cycle: ";
    cin>>newproc;
    cout<<"Input the Length of the Simulation in Cycles: ";             //prompts for user input
    cin>>simlength;




    int *cpu = new int[cores]{0};       //dynamic cpu core with additional variables for tracking wait times and processes
    int idle = 0;
    int processes = 0;
    int totalWaitTime = 0;
    double newProcessAmount = 0;
    int totalExecutionTimeQueue = 0;
    int totalWaitTimeQueue = 0;
    int maxWaitTimeQueue = 0;


    //make output file to check whats going on
    file.open("output.txt");
    //trying a while loop with a for loop nested
    while(count < simlength){

        newProcessAmount += newproc;

        while(newProcessAmount >= 1){ //method from prompt

            file<<"running new proc at time : "<<count<<endl;

            Process t;                              //make new process
            t.setTimeStamp(count);
            t.setExeTime(rand()%(maxex-minex+1) + minex);     //set execution time
            queue.enqueue(t, rand()%levels + 1);        //enqueue

            file<<"Process : "<<"Exe time " << t.getExeTime()<<endl<<"Time Stamp "<< t.getTimeStamp()<<endl;

            newProcessAmount-=1;
        }


        int idleCount = 0;      //counter for idle cores

        for(int i = 0; i < cores; i++){         //loop to check if cores are waiting for process

            file<<cpu[i]<< " ";

            if(cpu[i] == 0){            //if core is zero do the following

                idleCount++;            //increase amount of idle cpus in array

                if(!queue.isEmpty()){           //if queue isn't empty add process time to core

                    Process temp;
                    temp = queue.dequeue();
                    cpu[i] += temp.getExeTime();
                    totalWaitTime += count - temp.getTimeStamp();       //total wait time is the sum of clock cycle minus time stamp

                    file<<"Temp exe : "<<temp.getExeTime()<<"Temp time stamp: "<<temp.getTimeStamp()<<endl;
                    file<< "Total Wait Time : "<<totalWaitTime<<endl;

                    processes++;        //increase number of processes
                }
            }
            else{           //otherwise decrement core time
                cpu[i]--;
            }
        }

        file<<endl;
        idle += idleCount;              //increase idle core amount


        for( int i = 0; i <queue.size(); i++){      //for remaining processes in queue run the following code

            Process remainingProc = queue[i];
            totalExecutionTimeQueue += remainingProc.getExeTime();
            totalWaitTimeQueue += count - remainingProc.getTimeStamp();
            maxWaitTimeQueue = max(maxWaitTimeQueue, count - remainingProc.getTimeStamp());
            file<< "Total Execution Time Queue : "<<totalExecutionTimeQueue<<endl;
            file<< "Total Wait Time Queue : "<<totalWaitTimeQueue<<endl;
            file<< "Max Wait Time Queue : "<<maxWaitTimeQueue<<endl;
        }
        count++;    //increase loop count until sim length is reached
    }

    file.close(); //close output file

    println();      //test line
    cout<<"============ Simulation Results ============"<<endl;         //display results
    cout<<"Idle Time = "<< idle<<endl;;
    cout<<"Processes Completed = "<< processes<<endl;
    cout<<"Total Wait Time of Completed Processes = "<< totalWaitTime<<endl;
    cout<< "Processes Remaining in Queue = "<< queue.size()<<endl;
    cout<< "Total Execution Time of Remaining Processes = "<< totalExecutionTimeQueue<<endl;
    cout<< "Total Wait Time of Remaining Processes = "<< totalWaitTimeQueue<<endl;
    cout<< "Maximum Wait Time of Remaining Processes = "<< maxWaitTimeQueue<<endl;


    delete [] cpu;      //clean up memory

    return 0;
}
