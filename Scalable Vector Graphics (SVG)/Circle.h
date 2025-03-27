//===========================================================================================================================
// Name        : Circle.h
// Author      : Ryan C. Ellis
// Creation Date: 11/6/2024
// Last Update: 11/8/2024
// Description: Header file for Circle child class structure.
//===========================================================================================================================

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
protected:
  int cx;
  int cy;
  int radius;

public:
  Circle(int, int, int);
  virtual ~Circle();

  int getx();
  int gety();
  int getrad();
  void setx(int);
  void sety(int);
  void setrad(int);

  int* getBounds() ;
  void draw() ;
  string svgcode();
};

#endif /* CIRCLE_H */
