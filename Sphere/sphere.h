//============================================================================
// Name        : shpere.h
// Author      : Ryan Ellis and Josh Ellis
// Creation Date: 9/11/2024
// Last Update: 9/13/2024
// Description: Class definition of Sphere, that has private values of the
// (x,y,z) coordinates for the center of the sphere, a private function distance
// to calculate distance from the center, and a constant to represent Pi.
//============================================================================

#ifndef SPHERE_H
#define SPHERE_H

using namespace std;

class Sphere {                              //class declaration with private variables
    private:                                    //holds (x,y,z) position of sphere with radiusiu
        double x;                               //private distance variable holds distance of center
        double y;
        double z;
        double rad;
        double distance(double, double, double);
        double const PI = 3.141592653589793;    //constant approx. variable for pi 
        
public:
    Sphere(double ix = 0, double iy = 0, double iz = 0, double ir = 1);
    void setCenter(double ix = 0, double iy = 0, double iz = 0);
    void setRadius(double ir = 1);
    double getRadius();
    double getX();
    double getY();
    double getZ();
    double surfaceArea();
    double volume();
    bool collide(Sphere s);
    void printSphereInfo();
    
    
};

#endif
