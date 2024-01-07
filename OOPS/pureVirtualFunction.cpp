/*  Write a program in C++ calculate area of triangle, rectangle, and circle using 
pure virtual function. */

#include <iostream>
using namespace std;

class Shape {
public:
    virtual float area() const = 0;
};

class Triangle : public Shape {
private:
    float base;
    float height;
public:
    Triangle(float b, float h) : base(b), height(h) {}
    float area() const {
        return 0.5 * base * height;
    }
};

class Rectangle : public Shape {
private:
    float length;
    float width;
public:
    Rectangle(float l, float w) : length(l), width(w) {}
    float area() const {
        return length * width;
    }
};

class Circle : public Shape {
private:
    float radius;
public:
    Circle(float r) : radius(r) {}
    float area() const {
        return 3.14159 * radius * radius;
    }
};

int main() {
    Triangle triangle(4.0, 6.0);
    Rectangle rectangle(5.0, 7.0);
    Circle circle(3.5);

    Shape* shapes[] = { &triangle, &rectangle, &circle };

    for (int i = 0; i < 3; i++) {
        cout << "Area of shape " << i + 1 << ": " << shapes[i]->area() << endl;
    }

    return 0;
}