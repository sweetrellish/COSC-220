//===========================================================================================================================
// Name        : Square.h
// Author      : Ryan C. Ellis
// Creation Date: 11/6/2024
// Last Update: 11/8/2024
// Description: Header file for Square child class structure.
//===========================================================================================================================

#ifndef SQUARE_H_
#define SQUARE_H_

#include "Rectangle.h"

class Square : public Rectangle {

public:
  Square(int, int, int);
  virtual ~Square();

  int* getBounds();
  void draw() ;
  string svgcode()  ;
};

#endif /* SQUARE_H_ */
