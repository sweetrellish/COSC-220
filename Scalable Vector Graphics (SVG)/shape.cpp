//===========================================================================================================================
// Name        : shape.cpp
// Author      : Ryan C. Ellis
// Creation Date: 11/6/2024
// Last Update: 11/7/2024
// Description: Implementation file for Shape class structrue.
//===========================================================================================================================
#include "Shape.h"

using namespace std;

//============================================================================
// Description: Destructor of Shape objects.
// Parameters: N/A
// Return: no return
// Notes:
//============================================================================
Shape :: ~Shape(){
  //empty
}

//============================================================================
// Description: Returns border color
// Parameters:N/A
// Return: string bordercolor
// Notes:
//============================================================================
string Shape :: getbordercolor(){
  return bordercolor;
  }

//============================================================================
// Description: Returns fill color
// Parameters:N/A
// Return: string fillcolor
// Notes:
//============================================================================
string Shape ::  getfillcolor(){
  return fillcolor;
}

//============================================================================
// Description: Returns border width
// Parameters:N/A
// Return: int borderwidth
// Notes:
//============================================================================
int Shape :: getborderwidth(){
  return borderwidth;
}

//============================================================================
// Description: Returns opacity
// Parameters:N/A
// Return: double borderwidth
// Notes:
//============================================================================
double Shape :: getopacity(){
  return opacity;
}

//============================================================================
// Description: Sets border color based off integer value input from user,
// a switch-case structure determines which selection corresponds to which color.
// Parameters: int border - border color selection integer
// Return: void function no return
// Notes:
//============================================================================
void Shape :: setbordercolor(int border){
    switch(border){
                case 1: bordercolor ="black"; break;
                case 2: bordercolor = "blue"; break;
                case 3: bordercolor = "brown"; break;
                case 4: bordercolor = "cyan"; break;
                case 5: bordercolor = "darkblue"; break;
                case 6: bordercolor = "darkcyan"; break;
                case 7: bordercolor = "darkgray"; break;
                case 8: bordercolor = "darkgreen"; break;
                case 9: bordercolor = "darkorange"; break;
                case 10: bordercolor = "darkred"; break;
                case 11: bordercolor = "gold"; break;
                case 12: bordercolor = "gray"; break;
                case 13: bordercolor = "green"; break;
                case 14: bordercolor = "lightcyan"; break;
                case 15: bordercolor = "lightgray"; break;
                case 16: bordercolor = "lightgreen"; break;
                case 17: bordercolor = "magenta"; break;
                case 18: bordercolor = "maroon"; break;
                case 19: bordercolor = "navy"; break;
                case 20: bordercolor = "orange"; break;
                case 21: bordercolor = "purple"; break;
                case 22: bordercolor = "red"; break;
                case 23: bordercolor = "violet"; break;
                case 24: bordercolor = "yellow"; break;
                case 25: bordercolor = "transparent"; break;
            }

}

//============================================================================
// Description: Sets fill color based off integer value input from user,
// a switch-case structure determines which selection corresponds to which color.
// Parameters: int fill - fill color selection integer
// Return: void function no return
// Notes:
//============================================================================
void Shape :: setfillcolor(int fill){
    switch(fill){
                case 1: fillcolor ="black"; break;
                case 2: fillcolor = "blue"; break;
                case 3: fillcolor = "brown"; break;
                case 4: fillcolor = "cyan"; break;
                case 5: fillcolor = "darkblue"; break;
                case 6: fillcolor = "darkcyan"; break;
                case 7: fillcolor = "darkgray"; break;
                case 8: fillcolor = "darkgreen"; break;
                case 9: fillcolor = "darkorange"; break;
                case 10: fillcolor = "darkred"; break;
                case 11: fillcolor = "gold"; break;
                case 12: fillcolor = "gray"; break;
                case 13: fillcolor = "green"; break;
                case 14: fillcolor = "lightcyan"; break;
                case 15: fillcolor = "lightgray"; break;
                case 16: fillcolor = "lightgreen"; break;
                case 17: fillcolor = "magenta"; break;
                case 18: fillcolor = "maroon"; break;
                case 19: fillcolor = "navy"; break;
                case 20: fillcolor = "orange"; break;
                case 21: fillcolor = "purple"; break;
                case 22: fillcolor = "red"; break;
                case 23: fillcolor = "violet"; break;
                case 24: fillcolor = "yellow"; break;
                case 25: fillcolor = "transparent"; break;
            }
}

//============================================================================
// Description: Sets border width with validity checking in the function with a
// throw exception.
// Parameters: int width - width of border
// Return: void function no return
// Notes:
//============================================================================
void Shape :: setborderwidth(int width){
  string exstring = "Enter valid input";
    if(width >= 1 && width <= 100)
        borderwidth = width;
    else
        throw exstring;
}

//============================================================================
// Description: Sets opacity with validity checking in the function with a
// throw exception.
// Parameters: double op - opacity
// Return: void function no return
// Notes:
//============================================================================
void Shape :: setopacity(double op){
  string exstring = "Enter valid input";
  if(op >= 0 && op <= 1)
    opacity = op;
  else
      throw exstring;
}

//============================================================================
// Description: Parent class virtual function for View box boundaries
// Parameters: N/A
// Return: pointer to int array of boundary values.
// Notes:
//============================================================================
int* Shape ::  getBounds() {
    int* bounds = new int[4]{1000};
    return bounds;
}

//============================================================================
// Description: Parent class virutal function to draw information of shape
// Parameters: N/A
// Return: no return
// Notes:
//============================================================================
void Shape :: draw(){
  cout<<"Border: "<< bordercolor<< " ";
  cout<<"Fill: "<<fillcolor<< " ";
  cout<<"Border Width: "<<borderwidth<<" ";
  cout<<"Opacity: "<<opacity<<" ";
}

//============================================================================
// Description: Parent class virtual function to return svg code of shape
// Parameters: N/A
// Return: string svg
// Notes: not sure why it's not going through inheritance and printing child values
//============================================================================
string Shape ::svgcode(){
  return "<svg xmlns=\"http://www.w3.org/2000/svg\">";
}
