//============================================================================
// Name        : main.cpp
// Author      : Ryan C. Ellis
// Creation Date: 9/17/2024
// Last Update: 9/19/2024
// Description: This program reads in data from external files and applies
// said data to StateData objects and manipulates this data using the public
// functions define in the header file.
//============================================================================


#include "data.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getInteger(string , int , int );
int getValueInList(string, const int *, int);

int main() {


  ifstream file;                    //input file name
  string filename = "";              //string for file name user chooses

  cout << "Input the filename: ";
  cin >> filename;

                                        // Open the file.
  file.open(filename);

                                    // If the files were successfully opened continue.
  if (!file) {
    cerr << "Error opening the file."<<endl;
    cerr << "File : " << filename <<" does not exist."<< endl;
    return 1;
    }

  //Find the number of years

  int pos = 0;                  //position variable
  int yearcount = 0;            //counter for number of years
  string line = "";             //initialized line to store line in file

  getline(file, line);          //gets first line of file to get year count

  while (pos != string :: npos){    //while position isn't equal to unsigned long value
    pos = line.find(',', pos + 1);  //position equals where line finds year after delimiter
    yearcount++;                    //increase year count
  }
  yearcount--;                      //decrease by one

  //Find the number of states

  int statecount = 0;             //counter variable for states
  while(getline(file, line)){     //while the file reads in lines
    statecount++;                 //increment state count
  }

  StateData *array = new StateData[statecount];  //2D array database of StateData

  file.clear();                 //clears error bits
  file.seekg(0L, ios :: beg);   //moves file pointer to position in beginning

  int *years = new int[yearcount];  //new array to hold years

  getline(file, line);              //gets first line of file for years
  pos = line.find(',', 0);
  int old = pos;
  int index = 0;

  while(pos != string ::npos){      //while position isn't equal to unsigned long value
    pos = line.find(',', old + 1);
    string year = line.substr(old + 1, pos - old -1);  //sets string year to substring found
    years[index] = stoi(year);
    index++;
    old = pos;
  }

  int stateindex = 0;         //index to count states

  while (getline(file, line)){    //parse through file to find number of states
    pos = line.find(',', 0);      //starting at position 0
    string state = line.substr(0, pos);   //string to hold state name

    int yearindex = 0;                      //index for year array
    array[stateindex].setStateName(state);    //set name state to StateData array
    array[stateindex].add(years[yearindex]);  //add double years to index

    int oldpos = pos;         //old position is new position
    int index = 0;
    while (pos != string:: npos){     //while position isn't equal to unsigned long value
      pos = line.find(',', oldpos + 1);
      string val = line.substr(oldpos + 1, pos - oldpos -1);  //sets val to substring found
      array[index].add(stod(val));
      index++;
      oldpos = pos;
    }
    stateindex++;
    yearindex++;
  }

   file.close();

  //Do searches

  cout << "Select a State" << endl;                 //State Selection for user prompt
  for (int i = 0; i < yearcount; i++){
    cout<< (i + 1) << ". "<< array[i].getStateName() << endl;
  }
  int stateselection;
  cin>>stateselection;

  cout << endl;
  cout << "Enter a Year"<<endl;                //Year Selection for user prompt
  for (int i = 0; i < yearcount; i++)
    cout << (i + 1) << ". "<<years[i] << endl;

  int yearselection;
  cin>>yearselection;

  int yearindex = 0;
  for(int i = 0; i < yearcount; i++){
    if (years[i] == yearselection)
      yearindex = i;
  }
  cout << endl;                                                 //output results from search
  cout << "The energy-related carbon dioxide emissions for ";
  cout<< array[stateselection - 1].getStateName();
  cout<< " in millions of metric tons in the year "<< years[yearindex];
  cout<< " was "<< array[stateselection - 1].get(yearindex)<<"."<<endl;

  //free all the data

  delete[] array;
  delete[] years;

  return 0;
}


