//===========================================================================================================================
// Name        : Rectangle.h
// Author      : Ryan C. Ellis
// Creation Date: 11/6/2024
// Last Update: 11/8/2024
// Description: Header file for Rectangle child class structure.
//===========================================================================================================================

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle : public Shape {
private:
  int tlx;    //x value
  int tly;    //y value
  int width;  // Width of the rectangle.
  int height; // Height of the rectangle.

public:
  Rectangle();
  Rectangle(int, int, int, int);
  virtual ~Rectangle();

  int getx();
  int gety();
  int getwidth();
  int getheight();
  void setx(int);
  void sety(int);
  void setwidth(int);
  void setheight(int);

  int* getBounds() ;
  void draw() ;
  string svgcode() ;
};

#endif /* RECTANGLE_H_ */
