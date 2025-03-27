//===========================================================================================================================
// Name        : Square.cpp
// Author      : Ryan C. Ellis
// Creation Date: 11/6/2024
// Last Update: 11/8/2024
// Description: Implementation file for Square class structrue.
//===========================================================================================================================
#include "Square.h"
#include "Rectangle.h"

using namespace std;

//============================================================================
// Description: Constructor for Square class calling Rectangle constructor
// using Parameters.
// Parameters: int x,y,len(width/height)
// Return: Constructed Square
// Notes:
//============================================================================
Square :: Square(int x, int y, int len) : Rectangle(x, y, len, len){
}

//============================================================================
// Description: Destructor for Square class
// Parameters: N/A
// Return: no return
// Notes:
//============================================================================
Square :: ~Square(){
    //empty
}

//============================================================================
// Description: Child class virtual function for View box boundaries
// Parameters: N/A
// Return: pointer to int array of boundary values.
// Notes:
//============================================================================
int* Square::getBounds(){
     int* bounds = new int[4];
    if(getx() < getwidth()){
        bounds[0] = getx();
        bounds[1] = getwidth();
    }
    if(gety() < getheight()){
        bounds[2] = gety();
        bounds[3] = getheight();
    }
    else{
        bounds[0] = getwidth();
        bounds[1] = getx();
        bounds[2] = getheight();
        bounds[3] = gety();
    }
    return bounds;
}

//============================================================================
// Description: Child class virutal function to draw information of Square
// Parameters: N/A
// Return: no return
// Notes:
//============================================================================
void Square :: draw(){
    Rectangle ::draw();
}

//============================================================================
// Description: Child class virtual function to return svg code of shape
// Parameters: N/A
// Return: string svg
// Notes:
//============================================================================
string Square ::svgcode(){
    string shape = Shape ::svgcode();
    return shape + Rectangle ::svgcode();
}
