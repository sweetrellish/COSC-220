
//===========================================================================================================================
// Name        : Process.h
// Author      : Ryan C. Ellis
// Creation Date: 11/15/2024
// Last Update: 11/26/2024
// Description: Header file for the Process class structure
//===========================================================================================================================
#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <math.h>

using namespace std;

class Process {
private:
  int exeTime;
  int timeStamp;
  // Execution time of the process.
  // Time stamp of the process creation.

public:
  // Constructors and Destructor
  Process(int time = 1, int stamp = 0);
  Process(const Process &obj);
  ~Process();

  // Acessors and Mutators
  void setExeTime(int);
  int getExeTime();
  void setTimeStamp(int);
  int getTimeStamp();

  // Overloaded operator functions
  friend ostream &operator<<(ostream &, const Process &);
};

#endif
