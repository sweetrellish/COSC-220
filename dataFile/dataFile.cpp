//============================================================================
// Name        : dataFile.cpp
// Author      : Ryan C. Ellis
// Creation Date: 9/12/2024
// Last Update: 9/12/2024
// Description: This program reads in data from external files and applies
// said data to structures 'StateData' and its public values.
//============================================================================
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct StateData{
public:
    string StateName = "";
    double *data = nullptr;

};

void setData(StateData *&, int ,ifstream);
void setState(StateData *&, int, ifstream);

int main() {
  ifstream file;                    //input file name
  string filename;                  //string for file name user chooses
  int numstates = -1;               // var to contain num of states, minus header



  cout << "Input the filename: ";
  cin >> filename;

                                        // Open the file.
  file.open(filename);

                                    // If the files were successfully opened continue.
  if (file) {
    string line;
    cout << endl;
    while(getline(file, line)){
        cout << line << endl;
        numstates++;
    }
                                        // Close the file.
    file.close();
  } else {
                                        // Display an error message if file wasn't opened
    cerr << "Error opening the file.\n";
    return 1;
  }


  cout << endl;
  cout << "The file contained " << numstates << " states." << endl; //display how many states there are

  StateData *dat;
  dat.data = new double[numstates + 1];                 //dynamically create new StateData set to number of states

  setData(dat, numstates, file);

  delete[] dat;                                 //delete StateData
  return 0;
}
//============================================================================
// Description: Function call will take in values for StateData type and its
// size along with the file to be read. A copy of data is made and a for loop
// will read in values from file.
// Parameters: StateData *& data - StateData type passed by reference
//             int size - size of pointer array
//             ifstream file - file to be read
// Return: void function no return.
// Notes: N/A
//============================================================================
void setData(StateData *&data,  int size, ifstream file){
    string str;
    StateData *arr;
    arr = new StateData[size];

    for(int i = 0; i <size; i++){
        arr[i] = getline(file, str);
    }
};
//============================================================================
// Description: Function call will take in values for StateData type and its
// size along with the file to be read. A copy of data is made and a for loop
// will read in values from file for State string data.
// Parameters: StateData *& data - StateData type passed by reference
//             int size - size of pointer array
//             ifstream file - file to be read
// Return: void function no return.
// Notes: N/A
//============================================================================
void setstate(StateData *&data, int size, ifstream file){
    string str;
    StateData *arr;
    arr = new StateData[size];

    string state;
    for(int i = 0; i <size; i++){
        state = getline(file, str, ',');
        arr->StateName[i] = state;

    }
    data = arr;

};
