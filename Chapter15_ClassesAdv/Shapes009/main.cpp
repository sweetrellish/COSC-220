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
  // Shape shape1;  // Cannot instantiate a Shape object, pure virtual.

  Shape *shapes[3] = {new Triangle(3, 4, 5, "Green"),
                      new Rectangle(3, 4, "Blue"), new Square(5, "Light Gray")};

  for (int i = 0; i < 3; i++)
    shapes[i]->draw();

  for (int i = 0; i < 3; i++)
    cout << shapes[i]->Area() << endl;

  for (int i = 0; i < 3; i++)
    printArea(*(shapes[i]));

  Rectangle r(2, 17);
  printArea(r);

  Triangle t(7, 5, 10);
  printArea(t);

  for (int i = 0; i < 3; i++)
    delete shapes[i];

  return 0;
}

void printArea(Shape &s) { cout << "Area: " << s.Area() << endl; }
