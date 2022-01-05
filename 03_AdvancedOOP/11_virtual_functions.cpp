// Example solution for Shape inheritance
#include <assert.h>
#include <cmath>
#include <iostream>

// TODO: Define pi
#define PI 3.141592653

// TODO: Define the abstract class Shape
class Shape {
public:
  // TODO: Define public virtual functions Area() and Perimeter()
    virtual double Area() const= 0;
    virtual double Perimeter() const= 0;
  // TODO: Append the declarations with = 0 to specify pure virtual functions  
};
  
// TODO: Define Rectangle to inherit publicly from Shape
  // TODO: Declare public constructor
  // TODO: Override virtual base class functions Area() and Perimeter()
  // TODO: Declare private attributes width and height
class Rectangle : public Shape {
public:
    Rectangle(int h, int w)
        : height(h),width(w)
    {}
    
    double Area() const override
    {
        return height*width;
    }

    double Perimeter() const override
    {
        return(2*width + 2*height);
    }
    
private:
    int width;
    int height;
};


// TODO: Define Circle to inherit from Shape
  // TODO: Declare public constructor
  // TODO: Override virtual base class functions Area() and Perimeter()
  // TODO: Declare private member variable radius
class Circle : public Shape {
public:
    Circle(double r)
        : radius(r)
    {}
    
    double Area() const override
    {
        return (pow(radius, 2) * PI);
    }

    double Perimeter() const override
    {
        return(2*PI*radius);
    }
    
private:
    double radius;
    
};

// Test in main()
int main() {
  double epsilon = 0.1; // useful for floating point equality

  // Test circle
  Circle circle(12.31);
    std::cout << circle.Perimeter() << std::endl;
  assert(abs(circle.Perimeter() - 77.35) < epsilon);
  assert(abs(circle.Area() - 476.06) < epsilon);

  // Test rectangle
  Rectangle rectangle(10, 6);
  assert(rectangle.Perimeter() == 32);
  assert(rectangle.Area() == 60);
}