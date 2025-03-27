//===========================================================================================================================
// Name        : Triangle.h
// Author      : Ryan C. Ellis
// Creation Date: 11/6/2024
// Last Update: 11/8/2024
// Description: Header file for Triangle child class structure.
//===========================================================================================================================

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"

class Triangle : public Shape {
private:
  int* list;

public:
  Triangle(int*);
  virtual ~Triangle();

  int* getBounds() ;
  void draw() ;
  string svgcode() ;
};

#endif /* TRIANGLE_H_ */
