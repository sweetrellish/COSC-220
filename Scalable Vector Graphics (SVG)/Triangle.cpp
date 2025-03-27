//===========================================================================================================================
// Name        : Triangle.cpp
// Author      : Ryan C. Ellis
// Creation Date: 11/7/2024
// Last Update: 11/8/2024
// Description: Implementation file for Triangle class structrue.
//===========================================================================================================================

#include "Triangle.h"
#include <string>

using namespace std;

//============================================================================
// Description: Constructor for Triangle object that takes in pointer to int array
// and sets values equal to list.
// Parameters: int* vert - pointer to int array
// Return: Constructed Triangle object
// Notes:
//============================================================================
Triangle :: Triangle(int* vert){
    list = new int[6];
    list = vert;
}

//============================================================================
// Description: Destructor for Triangle class
// Parameters:N/A
// Return: no return
// Notes:
//============================================================================
Triangle :: ~Triangle(){
    delete [] list;
}
//============================================================================
// Description: Child class virtual function for View box boundaries
// Parameters: N/A
// Return: pointer to int array of boundary values.
// Notes:
//============================================================================
int* Triangle ::getBounds(){
    int* bounds = new int[4];
    //not sure how to get min/max efficiently
    return bounds;
}

//============================================================================
// Description: Child class virutal function to draw information of Triangle
// Parameters: N/A
// Return: no return
// Notes:
//============================================================================
void Triangle :: draw(){
    cout<<"Triangle Points: "<<"("<<list[0]<<","<<list[1]<<")"<<"("<<list[2]<<","<<list[3]<<")"<<"("<<list[4]<<","<<list[5]<<") ";
    Shape :: draw();
}

//============================================================================
// Description: Child class virtual function to return svg code of shape
// Parameters: N/A
// Return: string svg
// Notes:
//============================================================================
string Triangle :: svgcode(){

    string shape = Shape ::svgcode();
    string svg= shape + "<polyline points=\"" + to_string(list[0])+ "," + to_string(list[1]) + "," + to_string(list[2]) + "," + to_string(list[3]) + "," + to_string(list[4]) + "," + to_string(list[5]) + "\" stroke=\"" + bordercolor + "\" fill=\"" + fillcolor +"\" stroke-width=\"" + to_string(borderwidth) + "\" opacity=\"" + to_string(opacity) + "\" />";
    return svg;
}
