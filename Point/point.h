//===========================================================================================================================
// Name        : point.h
// Author      : Ryan C. Ellis
// Creation Date: 9/27/2024
// Last Update: 10/1/2024
// Description: This header file outlines the Point class structure where in private values of the x, y, and z coordinate are defined,
// along with the length of the point (denoted : size). Public functions outlined are for the constructor and a default constructor,
// with functions used to access and mutate the point object. Overloaded operators are defined for the computation and comparison of point // objects.
//===========================================================================================================================
#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point {

private:
    double x;
    double y;
    double z;
    double size;

public:
    Point();
    Point(double ,double ,double );
    double length();
    bool isEqual(Point);
    double multiply(Point);
    double getX();
    double getY();
    double getZ();
    void setX(double);
    void setY(double);
    void setZ(double);
    void setXYZ(double, double, double);

    Point operator+(const Point &);
    Point operator-(const Point &);
    double operator*(const Point &);
    Point operator*(double);
    Point operator/(const Point &);
    bool operator ==(const Point &);

    friend ostream &operator<<(ostream &, const Point &);
    friend Point operator*(double, const Point &);
    friend Point operator*(const Point &, double );
    friend Point operator/(const Point &, double );
};

#endif
