//============================================================================
// Name        : main.cpp
// Author      : Ryan Ellis and Josh Ellis
// Creation Date: 9/11/2024
// Last Update: 9/13/2024
// Description: Main function that includes class header file and implentation
// file and declares 3 spheres and tests built in class functions.
//============================================================================

#include <iostream>
#include "sphere.h"

using namespace std;

int main() {
    
    Sphere s1(2, 3, 4, 1);              //spheres s1, s2, s3 instantiated with given values
    Sphere s2(2.1, 3.5, 3.9, 3);
    Sphere s3(-1, -2, -3, 2);
    
    s1.printSphereInfo();               //function call to print sphere info
    s2.printSphereInfo();
    s3.printSphereInfo();
    
    cout << s1.getX() << " " << s1.getY() << " " << s1.getZ() << " --- ";
    cout << s1.getRadius() << endl;         //cout statement to print s1 sphere info using functions
    
    s1.setCenter(2, 5, 9);          //set center of s1
    s1.setRadius(3.2);              //set radius of s1
    
    cout << s1.getX() << " " << s1.getY() << " " << s1.getZ() << " --- ";
    cout << s1.getRadius() << endl;         //cout statement to print s1 sphere info using functions

    cout << "Sphere 1 Volume: " << s1.volume() << endl;         //calculate sphere volume
    cout << "Sphere 1 Surface Area: " << s1.surfaceArea() << endl;  //calculate sphere surface area

    cout << s1.collide(s2) << endl;         //determine if s1 and s2 collide
    cout << s2.collide(s3) << endl;         //determine if s2 and s3 collide
    cout << s1.collide(s3) << endl;         //determine if s1 and s3 collide
    
    return 0;
    
}
