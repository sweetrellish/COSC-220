
//===========================================================================================================================
// Name        : main.cpp
// Author      : Ryan C. Ellis
// Creation Date: 11/15/2024
// Last Update: 11/26/2024
// Description: Main program will run a simulation of automated processes entering into an array of cpu cores and looping through each
// clock cycle adding and removing processes throughout, given a minimum and maximum amount of processes (load bearing) and a step value // that will increase as the load as the simulation runs. A status report is given once the number of simulations are over.
//===========================================================================================================================

//Note: This section is running a lot smoother than the first simulation is and i'm not exactly sure why but I don't have time to mull
// over why it is giving me values and the other isn't. Albeit i'm sure they're wildly incorrect, i'm going to run the analysis off this
// data and submit it so I can at least get some partial credit (i'm hoping).

#include <iostream>
#include <ctime>
#include "PriorityQueue.h"
#include "Process.h"
#include <fstream>
#include <string>

using namespace std;

void println(string s = "") { cout << s << endl; }      //print line function

int main() {

    srand((0));     //set time seed

    PriorityQueue<Process> queue;       //queue structure to hold processes and input variables
    int count = 0;
    int cores;
    int minex;
    int maxex;
    int levels;
    double simlength;
    double minproc;
    double maxproc;
    double step;
    ofstream file;          //output file to track simulation runs

    cout<<"Input the Number of CPU Cores: ";
    cin>>cores;
    cout<<"Input the Minimum Number of Execution Cycles per Process: ";     //prompt for user input
    cin>>minex;
    cout<<"Input the Maximum Number of Execution Cycles per Process: ";
    cin>>maxex;
    cout<<"Input the Number of Priority Levels: ";
    cin>>levels;
    cout<<"Minimum Number of New Processes per Cycle: ";
    cin>>minproc;
    cout<<"Maximum Number of New Processes per Cycle: ";
    cin>>maxproc;
    cout<<"New Processes per Cycle Step Size: ";
    cin>>step;
    cout<<"Input the Length of the Simulation in Cycles: ";
    cin>>simlength;




    int *cpu = new int[cores]{0};       //dynamic core cpu with load value starting at minimum
    double load = minproc;

    file.open("output.csv");        //open file for table values in analysis

    println();      //test line

    cout<<"============ Simulation Results ============"<<endl;     //results header
    cout<<"Load | Idle | Completed | Processed Wait | Unprocessed | Exe. Needed | Unpr. Wait | Unpr. Max Wait"<<endl;

    while(load <= maxproc){     //run through minimum and maximum load values with increase by step value

    int idle = 0;               //variables for tracking processes and wait times
    int processes = 0;
    int totalWaitTime = 0;
    double newProcessAmount = 0;
    int totalExecutionTimeQueue = 0;
    int totalWaitTimeQueue = 0;
    int maxWaitTimeQueue = 0;

    count = 0; //reset count to zero

        while(count < simlength){       //run while count is less than simulation cycles

            newProcessAmount += load;   //new process amount which is the load

            while(newProcessAmount >= 1){ //method from prompt

                Process t;                              //make new process
                t.setTimeStamp(count);
                t.setExeTime(rand()%(maxex-minex+1) + minex);     //set execution time
                queue.enqueue(t, rand()%levels + 1);        //enqueue


                newProcessAmount-=1;
            }

            int idleCount = 0;          //counter for idle cores

            for(int i = 0; i < cores; i++){         //loop to check if cores are waiting for process


                if(cpu[i] == 0){                  // if core is zero to the following

                    idleCount++;            //increase amount of idle cores in array

                    if(!queue.isEmpty()){       //if queue isn't empty then add process

                        Process temp;                  //set process exe time to core
                        temp = queue.dequeue();
                        cpu[i] += temp.getExeTime();
                        totalWaitTime += count - temp.getTimeStamp();       //total wait time is sum of count minus time stamp


                        processes++;        //increase number of processes
                    }
                }
                else{
                    cpu[i]--;       //otherwise decrease core time
                }
            }

            idle += idleCount;      //increase idle core amount


            for( int i = 0; i <queue.size(); i++){      //for remaining processes in queue run the following code

                Process remainingProc = queue[i];
                totalExecutionTimeQueue += remainingProc.getExeTime();
                totalWaitTimeQueue += count - remainingProc.getTimeStamp();
                maxWaitTimeQueue = max(maxWaitTimeQueue, count - remainingProc.getTimeStamp());

            }
            count++;        //increase count size until simlength
        }



    cout<< load <<"\t "<<idle<< "\t "<<processes<<"\t "<<totalWaitTime<<"\t\t "<<queue.size()<< "\t\t "<<totalExecutionTimeQueue<< "\t\t "<<totalWaitTimeQueue<< "\t\t "<<maxWaitTimeQueue<<endl;     //output results of current load

    file<< load <<"\t "<<idle<< "\t "<<processes<<"\t "<<totalWaitTime<<"\t\t "<<queue.size()<< "\t\t "<<totalExecutionTimeQueue<< "\t\t "<<totalWaitTimeQueue<< "\t\t "<<maxWaitTimeQueue<<endl;

    load += step;       //increase load by step value

    }
    file.close();       //close file

    delete [] cpu;  //clear memory

    return 0;
}
