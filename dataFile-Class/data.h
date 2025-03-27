//============================================================================
// Name        : data.h
// Author      : Ryan Ellis
// Creation Date: 9/13/2024
// Last Update: 9/19/2024
// Description: Class definition of StateData, that has private values of
// a string to hold the state name, a double pointer for array data, and an
// int for the size of the array. Public functions declared that will construct
// and destruct class structure StateData, and manipulate data within the class.
//============================================================================

#ifndef DATA_H
#define DATA_H

#include <string>

using namespace std;

class StateData {
	private:
		string StateName;
		double *data;
		int size;
public:
	StateData();
	~StateData();

	void setStateName(string);
	string getStateName();
	void add(double);
	double get(int);
};

#endif
