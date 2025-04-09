/*
 Author: Don Spickler
 Creation Date: 1/26/2022
 Last Update: 1/26/2022
 Description: Testing program for inheritance.
 User Interface: None
 */

#include <iostream>

#include "Rectangle.h"
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"

using namespace std;

void printArea(Shape &s);

int main() {
  cout << "Create Triangle, Rectangle, Square" << endl;
  Shape *shapes[3] = {new Triangle(3, 4, 5, "Green"),
                      new Rectangle(3, 4, "Blue"), new Square(5, "Light Gray")};

  cout << endl;
  cout << "Create Rectangle" << endl;
  Rectangle r(2, 17);

  cout << endl;
  cout << "Create Triangle" << endl;
  Triangle t(7, 5, 10);

  cout << endl;
  cout << "Delete Pointer Array" << endl;
  for (int i = 0; i < 3; i++)
    delete shapes[i];

  cout << endl;
  cout << "Ending the Program" << endl;

  return 0;
}

void printArea(Shape &s) { cout << "Area: " << s.Area() << endl; }
