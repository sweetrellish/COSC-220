//===========================================================================================================================
// Name        : Circle.cpp
// Author      : Ryan C. Ellis
// Creation Date: 11/6/2024
// Last Update: 11/8/2024
// Description:  Implementation file for Circle class structrue.
//===========================================================================================================================

#include "Circle.h"

using namespace std;

//============================================================================
// Description: Constructor for Circle class, takes in parameters for x,y, and radius
// Parameters: int x,y,rad
// Return: Constructed Circle object
// Notes:
//============================================================================
Circle :: Circle(int x, int y, int rad){
    cx = x;
    cy = y;
    radius = rad;
}
//============================================================================
// Description: Desrtructor for Circle class
// Parameters: N/A
// Return: no return
// Notes:
//============================================================================
Circle :: ~Circle(){
    //empty
}
//============================================================================
// Description: Returns x coordinate value
// Parameters: N/A
// Return: int cx
// Notes:
//============================================================================
int Circle :: getx(){
    return cx;
}
//============================================================================
// Description: Returns y coordinate value
// Parameters: N/A
// Return: int cy
// Notes:
//============================================================================
int Circle :: gety(){
    return cy;
}
//============================================================================
// Description: Returns circle radius
// Parameters: N/A
// Return: int radius
// Notes:
//============================================================================
int Circle:: getrad(){
    return radius;
}
//============================================================================
// Description: Sets circle x coordinate
// Parameters: int x
// Return: no return
// Notes:
//============================================================================
void Circle :: setx(int x){
    cx = x;
}
//============================================================================
// Description: Sets circle y coordinate
// Parameters: int y
// Return: no return
// Notes:
//============================================================================
void Circle :: sety(int y){
    cy = y;
}
//============================================================================
// Description: Sets circle radius
// Parameters: int rad
// Return: no return
// Notes:
//============================================================================
void Circle :: setrad(int rad){
    if(rad >= 1)
        radius = rad;
}
//============================================================================
// Description: Child class virtual function for View box boundaries
// Parameters: N/A
// Return: pointer to int array of boundary values.
// Notes:
//============================================================================
int* Circle:: getBounds(){
    int* bounds = new int[4];
    bounds[0] = radius;
    bounds[1] = radius;
    bounds[2] = radius;
    bounds[3] = radius;
    return bounds;
}
//============================================================================
// Description: Child class virutal function to draw information of Rectangle and shape
// Parameters: N/A
// Return: no return
// Notes:
//============================================================================
void Circle :: draw(){
    cout << "Circle Center: ("<<cx<<","<<cy<<") ";
    cout << "Radius: "<<radius;
    Shape :: draw();
}
//============================================================================
// Description: Child class virtual function to return svg code of shape
// Parameters: N/A
// Return: string svg
// Notes:
//============================================================================
string Circle :: svgcode(){
    string shape = Shape ::svgcode();
    string svg = shape + "<circle cx=\""+ to_string(cx) + "\" y=\"" + to_string(cy) + "\" r=\"" + to_string(radius) + "\"  stroke=\"" + bordercolor + "\" fill=\"" + fillcolor + "\" stroke-width=\"" + to_string(borderwidth) + "\" opacity=\"" + to_string(opacity) + "\" />";
    return svg;
}
