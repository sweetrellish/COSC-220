//============================================================================
// Name        : point.cpp
// Author      : Ryan C. Ellis
// Creation Date: 9/27/2024
// Last Update: 10/1/2024
// Description: This is the implementation file for the Matrix class
// structure. This includes the header file and lists all the public functions
// that are defined in that header.
//============================================================================
#include "point.h"
#include <cmath>

//============================================================================
// Description: Default constructor for Point class, when called with no parameters,
// default will set point values to 0.
// Parameters: N/A
// Return: Constructor function, no return.
// Notes:
//============================================================================
Point :: Point(){
    x = 0;
    y = 0;
    z = 0;
}
//============================================================================
// Description: Constructor for Point class given parameter values passed to set
// coordinates of point.
// Parameters: double ix - passed x value
//             double iy - passed y value
//             double iz - passed z value
// Return:Constructor function, no return.
// Notes:
//============================================================================
Point :: Point(double ix, double iy, double iz){
    x = ix;
    y = iy;
    z = iz;
}
//============================================================================
// Description:  Overloaded operator for the addition operator in Point class.
// Temporary point is made and values of called and passed object are added to
// each other and set equal to temp coordinate values, temp is returned.
// Parameters: const Point &p - constant Point of p address.
// Return: Point object.
// Notes:
//============================================================================
Point Point :: operator+(const Point &p){
    Point temp;
    temp.x = x + p.x;
    temp.y = y + p.y;
    temp.z = z + p.z;
    return temp;

}
//============================================================================
// Description: Overloaded operator for the subtraction operator in Point class.
// Temporary point is made and values of called and passed object are subtracted
// and set equal to temp coordinate values, temp is returned.
// Parameters: const Point &p - constant Point of p address.
// Return: Point object.
// Notes:
//============================================================================
Point Point:: operator-(const Point &p){
    Point temp;
    temp.x = x - p.x;
    temp.y = y - p.y;
    temp.z = z - p.z;
    return temp;
}
//============================================================================
// Description: Overloaded operator for the multiplication operator in Point class.
// Temporary point is made and values of called and passed object are multiplied
// and set equal to temp coordinate values, temp is returned.
// Parameters: const Point &p - constant Point of p address.
// Return: Point object.
// Notes:
//============================================================================
double Point :: operator*(const Point &p){
    Point temp;
    temp.x = x * p.x;
    temp.y = y * p.y;
    temp.z = z * p.z;
    return temp.x + temp.y + temp.z;
}
//============================================================================
// Description: Overloaded operator for the multiplication operator in Point class,
// but overloaded again for the scalar multiplication of a double value to a point.
// Two temp points are created and one stores the scalar, and the other stores the
// values of the const p, then they are multiplied, temp point is returned.
// Parameters: double r - scalar double.
// Return: Point object.
// Notes:
//============================================================================
Point Point :: operator*(double r){
    Point temp(r, r, r);
    Point temp2 = *this;
    temp2.x *= temp.x;
    temp2.y *= temp.y;
    temp2.z *= temp.z;
    return temp2;
}
//============================================================================
// Description: Overloaded operator for the division operator in Point class.
// Temporary point is made and values of called and passed object are divided
// and set equal to temp coordinate values, temp is returned.
// Parameters: const Point &p - constant Point of p address.
// Return: Point object.
// Notes:
//============================================================================
Point Point:: operator/(const Point &p){
    Point temp;
    temp.x = x / p.x;
    temp.y = y / p.y;
    temp.z = z / p.z;
    return temp;
}
//============================================================================
// Description: Function call will set size (length) of point equal to the square
// root of each of the coordinates square summation.
// Parameters: N/A
// Return: double size
// Notes:
//============================================================================
double Point :: length(){
    size = sqrt(pow(x,2)+ pow(y, 2)+ pow(z,2));
    return size;
}
//============================================================================
// Description: Function call will take in parameter Point p and will run a
// conditional if all the points are equivalent, then return true, otherwise
// return false.
// Parameters: Point p - point to compare
// Return: boolean value (true/false)
// Notes:
//============================================================================
bool Point :: isEqual(Point p){
    if(x == p.x && y == p.y && z == p.z)
        return true;
    else
        return false;
}

//============================================================================
// Description: Function call will access value of x and return that value.
// Parameters:N/A
// Return: double x
// Notes:
//============================================================================
double Point ::getX(){
    return x;
}

//============================================================================
// Description: Function call will access value of y and return that value.
// Parameters:N/A
// Return: double y
// Notes:
//============================================================================
double Point :: getY(){
    return y;
}

//============================================================================
// Description: Function call will access value of z and return that value.
// Parameters:N/A
// Return: double z
// Notes:
//============================================================================
double Point :: getZ(){
    return z;
}

//============================================================================
// Description: Function call will set value of x to the passed value.
// Parameters:N/A
// Return: Void function, no return.
// Notes:
//============================================================================
void Point :: setX(double ix){
    x = ix;
}

//============================================================================
// Description: Function call will set value of y to the passed value.
// Parameters:N/A
// Return: Void function, no return.
// Notes:
//============================================================================
void Point :: setY(double iy){
    y = iy;
}

//============================================================================
// Description:Function call will set value of z to the passed value.
// Parameters:N/A
// Return: Void function, no return.
// Notes:
//============================================================================
void Point :: setZ(double iz){
    z = iz;
}

//============================================================================
// Description: Function call will set value of x, y, and z to the respective
// passed values.
// Parameters:N/A
// Return: Void function, no return.
// Notes:
//============================================================================
void Point :: setXYZ(double ix, double iy, double iz){
    x = ix;
    y = iy;
    z = iz;
}

//============================================================================
// Description: Overloaded operator for stream operator in Point class. This
// will set the formatting for how the Point object is to be passed through
// an ostream operation.
// Parameters:ostream &strm - ostream object
//            const Point &p - Point object
// Return: ostream return type
// Notes:
//============================================================================
ostream &operator<<(ostream &strm, const Point &p){
    strm << "("<<p.x<<", "<<p.y<<", "<<p.z<<")";
    return strm;
}

//============================================================================
// Description: Overloaded operator for equivalence operator in Point class.
// Conditional if statement will check if all coordinate values are equal
// and if they are return true, and return false otherwise.
// Parameters: const Point &p - constant Point object of p address.
// Return: boolean value (true/false).
// Notes:
//============================================================================
bool Point :: operator==(const Point &p){
    if (x == p.x && y == p.y && z == p.z)
        return true;
    else
        return false;
}

//============================================================================
// Description: Overloaded operator for the multiplication operator in Point class.
// This instance takes in double value and Matrix value to relate on left and right
// side of assignment and multiplies all values in array by scalar.
// Parameters: const Point &p - constant Point of p address.
//             double left - left hand int in expression.
// Return: Point object.
// Notes:
//============================================================================
Point operator*(double left, const Point &p){
    Point temp = p;
    return temp * left;
}

//============================================================================
// Description: Overloaded operator for the multiplication operator in Point class.
// This instance takes in double value and Matrix value to relate on left and right
// side of assignment and multiplies all values in array by scalar.
// Parameters: const Point &p - constant Point of p address.
//             double right - right hand int in expression.
// Return: Point object.
// Notes:
//============================================================================
Point operator*(const Point &p, double right){
    Point temp = p;
    return right * temp;
}

//============================================================================
// Description: Overloaded operator for the division operator in Point class.
// Temporary point is made and values of called and passed object are divided
// and set equal to temp coordinate values, temp is returned.
// Parameters: const Point &p - constant Point of p address.
// Return: Point object.
// Notes:
//============================================================================
Point operator/(const Point &p, double right){
    Point temp(right, right, right);
    Point temp2 = p;
    return temp2 / temp;
}
