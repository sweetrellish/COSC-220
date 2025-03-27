//============================================================================
// Name        : shpere.cpp
// Author      : Ryan Ellis and Josh Ellis
// Creation Date: 9/11/2024
// Last Update: 9/13/2024
// Description: Class implementation of Sphere, that lists public functions
// that were previously outlined in the header file.
//============================================================================

#include "sphere.h"
#include <iostream>
#include <cmath>

using namespace std;

//============================================================================
// Description: Function call will construct new Sphere of Sphere data type.
// Parameters: double ix - x value coordinate
//             double iy - y value coordinate
//             double iz - z value coordinate
//             double ir - radius of sphere
// Return: constructor function, no return.
// Notes: N/A
//============================================================================
Sphere::Sphere (double ix, double iy , double iz , double ir ){ //Constructor function for user input
    if (ir < 0)
        rad = 0;                                                //validity checking for negative rad
    x = ix;
    y = iy; 
    z = iz;
    rad = ir;
};
//============================================================================
// Description: Function call will set the center of the sphere with the given
// parameters from user input in main.
// Parameters: double ix - x value coordinate
//             double iy - y value coordinate
//             double iz - z value coordinate
// Return: void function no return.
// Notes: N/A
//============================================================================
void Sphere :: setCenter(double ix, double iy , double iz ){    //function to set center coordinates of sphere
    x = ix;
    y = iy;
    z = iz;
};
//============================================================================
// Description: Function call will set the radius of the sphere with the given
// parameters from user input.
// Parameters: double ir - radius of sphere
// Return: void function no return.
// Notes: N/A
//============================================================================
void Sphere :: setRadius(double ir){                            //function to set radius of sphere
    if (ir < 0)
        rad = 0;                                                //validity checking for negative rad
    else
        rad = ir;
};
//============================================================================
// Description: Function call will return radius value of sphere.
// Parameters: N/A
// Return: double rad - radius of sphere
// Notes: N/A
//============================================================================
double Sphere :: getRadius(){                                   //function to retrieve radius of sphere
    return rad;
}
//============================================================================
// Description: Function call will return x value coordinate of sphere.
// Parameters: N/A
// Return: double x - x value coordinate
// Notes: N/A
//============================================================================
double Sphere :: getX(){                                        //function to get x value of sphere
    return x;
};
//============================================================================
// Description: Function call will return y value coordinate of sphere.
// Parameters: N/A
// Return: double y - y value coordinate
// Notes: N/A
//============================================================================
double Sphere :: getY(){                                        //function to get y value of sphere
    return y;
};
//============================================================================
// Description: Function call will return z value coordinate of sphere.
// Parameters: N/A
// Return: double z - z value coordinate
// Notes: N/A
//============================================================================
double Sphere :: getZ(){                                        //function to get z value of sphere
    return z;
};
//============================================================================
// Description: Function call will calculate surface area of sphere and return
// the calculation.
// Parameters: N/A
// Return: double surface - calculated surface area
// Notes: N/A
//============================================================================
double Sphere :: surfaceArea(){                                 //function to return surface area value of sphere
    double surface = 4*(rad*rad)*PI;
    return surface;
};
//============================================================================
// Description: Function call will calculate volume of sphere and return
// the calculation.
// Parameters: N/A
// Return: double volume - calculated volume
// Notes: N/A
//============================================================================
double Sphere :: volume(){                                      //function to return volume value of sphere
    double volume = (4/3.0)*PI*(rad*rad*rad);
    return volume;
};
//============================================================================
// Description: Function call will test if distance between sphere passed
// through parameter is less than radius of sphere called by function plus
// the sphere passed through parameter. It will then  determine if the spheres
// are colliding and return boolean value true/false.
// Parameters: Sphere s - sphere to compare
// Return: boolean true/false
// Notes: N/A
//============================================================================
bool Sphere :: collide(Sphere s){                               //function to return boolean value to determine if shpere's are colliding based on distance from center
    if((distance(s.x, s.y, s.z)) < (rad + s.getRadius()))       //and radius length
        return true;
    else 
        return false;
};
//============================================================================
// Description: Function call will display information about the sphere.
// Parameters: Sphere s - sphere
// Return: void function no return.
// Notes: N/A
//============================================================================
void Sphere :: printSphereInfo(){                                                       //prints out sphere information
    cout<<"Center : ("<<getX()<<","<<getY()<<","<<getZ()<<")\tRadius : "<<rad<<endl;
};
//============================================================================
// Description: Function call will calculate the distance between sphere passed
// through parameter and sphere called by function and return that value.
// Parameters: double ix - x value coordinate
//             double iy - y value coordinate
//             double iz - z value coordinate
// Return: double distance
// Notes: N/A
//============================================================================
double Sphere :: distance (double ix, double iy, double iz){                            //calculates distance using formula for distance and given input values for 
    double distance = 0;                                                                //
    distance = sqrt(pow((ix - x), 2) + pow((iy - y), 2) + pow((iz - z), 2));
    return distance;
};

