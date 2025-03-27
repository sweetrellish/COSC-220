//===========================================================================================================================
// Name        : Rectangle.cpp
// Author      : Ryan C. Ellis
// Creation Date: 11/6/2024
// Last Update: 11/8/2024
// Description: Implementation file for Rectangle class structrue.
//===========================================================================================================================

#include "Rectangle.h"
#include <string>

using namespace std;

//============================================================================
// Description: Constructor for Rectangle taking in four parameters for x,y,
// width, height.
// Parameters: int x,y,w,h
// Return: Constructed Rectangle object
// Notes:
//============================================================================
Rectangle :: Rectangle(int x, int y, int w, int h){
    tlx = x;
    tly = y;
    width = w;
    height = h;
}
//============================================================================
// Description: Destructor for Rectangle class
// Parameters: N/A
// Return: no return
// Notes:
//============================================================================
Rectangle:: ~Rectangle(){
    //empty
}
//============================================================================
// Description: Return x value
// Parameters: N/A
// Return: int tlx
// Notes:
//============================================================================
int Rectangle::  getx(){
    return tlx;
}
//============================================================================
// Description: Return y value
// Parameters: N/A
// Return: int tly
// Notes:
//============================================================================
int Rectangle :: gety(){
    return tly;
}
//============================================================================
// Description: Return width
// Parameters: N/A
// Return: int width
// Notes:
//============================================================================
int Rectangle:: getwidth(){
    return width;
}
//============================================================================
// Description: Return height
// Parameters: N/A
// Return: int height
// Notes:
//============================================================================
int Rectangle:: getheight(){
    return height;
}
//============================================================================
//  Description: Set x value
// Parameters: int x
// Return: void function
// Notes:
//============================================================================
void Rectangle::  setx(int x){
    tlx = x;
}
//============================================================================
// Description: Set y value
// Parameters: int y
// Return: void function
// Notes:
//============================================================================
void Rectangle :: sety(int y){
    tly = y;
}
//============================================================================
// Description: Set width
// Parameters: int w
// Return: void function
// Notes:
//============================================================================
void Rectangle :: setwidth(int w){
    if(w >= 1 && w<= 1000)
        width = w;
}
//============================================================================
// Description: Set height
// Parameters: int h
// Return: void function
// Notes:
//============================================================================
void Rectangle :: setheight(int h){
    if(h >= 1 && h <=1000)
        height = h;
}

//============================================================================
// Description: Child class virtual function for View box boundaries
// Parameters: N/A
// Return: pointer to int array of boundary values.
// Notes:
//============================================================================
int* Rectangle :: getBounds(){
    int* bounds = new int[4];
    if(tlx < width){
        bounds[0] = tlx;
        bounds[1] = width;
    }
    if(tly <height){
        bounds[2] = tly;
        bounds[3] = height;
    }
    else{
        bounds[0] = width;
        bounds[1] = tlx;
        bounds[2] = height;
        bounds[3] = tly;
    }
    return bounds;

}

//============================================================================
// Description: Child class virutal function to draw information of Rectangle and shape
// Parameters: N/A
// Return: no return
// Notes:
//============================================================================
void Rectangle:: draw() {
    cout<<"Rectangle  Anchor Point: ("<<tlx<<","<<tly<<") ";
    cout<<"Width: "<<width<<" ";
    cout<<"Height: "<<height<<" ";
    Shape ::draw();
}

//============================================================================
// Description: Child class virtual function to return svg code of shape
// Parameters: N/A
// Return: string svg
// Notes:
//============================================================================
string Rectangle::svgcode() {
    string svg = "<rect x=\"" + to_string(tlx) + "\" y=\"" + to_string(tly) +
                 "\" width=\"" + to_string(width) + "\" height=\"" + to_string(height) +
                 "\" stroke=\"" + bordercolor + "\" fill=\"" + fillcolor +
                 "\" stroke-width=\"" + to_string(borderwidth) + "\" opacity=\"" + to_string(opacity) + "\" />";
    return svg;
}
