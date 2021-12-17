#include <iostream>
#include <cmath>
#include <assert.h>

// Define pi
#define PI 3.14159

// Define Line Class
struct LineSegment {
    public:
    // Define protected attribute length
    double length;
};

class Circle {
    public:
    Circle(LineSegment _radius) : radius(_radius){}
    void setRadius(int radius);
    float Area();
    LineSegment radius;
    
}; 

float Circle::Area()
{
    return (PI*(pow(Circle::radius.length,2)));
}
// Define Circle subclass

    // Define public setRadius() and getArea()
    
// Test in main()
int main() 
{
    LineSegment radius {3};
    Circle circle(radius);
    assert(int(circle.Area()) == 28);
}