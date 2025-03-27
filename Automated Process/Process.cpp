//===========================================================================================================================
// Name        : Process.cpp
// Author      : Ryan C. Ellis
// Creation Date: 11/15/2024
// Last Update: 11/26/2024
// Description: Implementation file for the Process class structure
//===========================================================================================================================

#include "Process.h"

//============================================================================
// Description: Constructor for the Process class
// Parameters: int time - execution time, int stamp - time stamp of creation
// Return: Process object
// Notes:
//============================================================================
Process :: Process(int time, int stamp){
    exeTime = time;
    timeStamp = stamp;
}

//============================================================================
// Description: Copy constructor for the Process class
// Parameters: const Process &obj - passed process by reference
// Return: Process object
// Notes:
//============================================================================
Process :: Process(const Process &obj){
    exeTime = obj.exeTime;
    timeStamp = obj.timeStamp;
}

//============================================================================
// Description: Destructor for the Process class
// Parameters: N/A
// Return: N/A
// Notes:
//============================================================================
Process :: ~Process(){
    //empty destructor
}

//============================================================================
// Description: Function will take in paramter of int time, to set private value
// of exeTime.
// Parameters: int time - execution time
// Return:
// Notes:
//============================================================================
void Process::  setExeTime(int time){
    if(time >= 1)
        exeTime = time;
}

//============================================================================
// Description: Function will return value of execution time.
// Parameters: N/A
// Return: int exeTime
// Notes:
//============================================================================
int Process :: getExeTime(){
    return exeTime;
}

//============================================================================
// Description: Function will take in parameter of int stamp, to set private value
// of timeStamp.
// Parameters: int stamp - time stamp
// Return: N/A
// Notes:
//============================================================================
void Process :: setTimeStamp(int stamp){
    timeStamp = stamp;
}

//============================================================================
// Description: Function will return value of time stamp.
// Parameters: N/A
// Return: int timeStamp
// Notes:
//============================================================================
int Process :: getTimeStamp(){
    return timeStamp;
}

//============================================================================
// Description: Overloaded streaming operator will take in Process object
// and ostream &strm object, and will format how to print Process to screen.
// Parameters: ostream &strm - stream object
//             const Process &obj - Process object
// Return:ostream object
// Notes:
//============================================================================
ostream &operator<<(ostream &strm, const Process &obj){
    strm<<"["<<obj.exeTime << ", "<<obj.timeStamp<<"]";
    return strm;
}
