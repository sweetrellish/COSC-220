//===========================================================================================================================
// Name        : Shape.h
// Author      : Ryan C. Ellis
// Creation Date: 11/6/2024
// Last Update: 11/8/2024
// Description: Header file for Shape parent class structure.
//===========================================================================================================================

#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>
#include <iostream>

using namespace std;

class Shape {
protected:
  string bordercolor;
  string fillcolor;
  int borderwidth;
  double opacity;

public:
  virtual ~Shape();

  string getbordercolor();
  string getfillcolor();
  int getborderwidth();
  double getopacity();
  void setbordercolor(int);
  void setfillcolor(int);
  void setborderwidth(int);
  void setopacity(double);

  virtual int* getBounds();
  virtual void draw();
  virtual string svgcode();
};

#endif /* SHAPE_H_ */

