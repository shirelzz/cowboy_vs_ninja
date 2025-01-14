#include "Point.hpp"
#include <cmath>
#include <iostream>

using namespace std;

// Constructor
Point::Point(double x, double y) : x(x), y(y) {}

// Copy constructor
Point::Point(const Point& other) {
    x = other.x;
    y = other.y;
}

// Move constructor
Point::Point(Point&& other) noexcept : x(other.x), y(other.y) {}

// Move assignment operator
Point& Point:: operator=(Point&& other) noexcept {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

double Point::distance(const Point& pnt) const
{    
    double dist = 0;
    double dx = x - pnt.getX();
    double dy = y - pnt.getY();

    dist = sqrt(dx*dx + dy*dy);

    return dist;
}

void Point::print() const{
    cout << "(" << x << "," << y << ")" << endl; 
}

Point Point::moveTowards(const Point& src, const Point& dest, double dist)
{
    if (dist < 0)
    {
        throw std::invalid_argument("Negative distance");
    }
    
    double src2dest = src.distance(dest);
    if (src2dest == 0 || dist == 0){
        return src;
    }

    if(src2dest <= dist){
        return dest;
    }

    double ratio = dist / src2dest;
    double dx = ratio * (dest.x - src.x);
    double dy = ratio * (dest.y - src.y);

    return Point(src.x + dx, src.y + dy);
}

double Point::getX() const{
    return this->x;
}

double Point::getY() const{
    return this->y;
}


Point& Point::operator=(const Point& other) {
    if (this != &other) { // checks if they are not the same to avoid self-assignment
        x = other.x;
        y = other.y;
    }
    return *this;
}

bool Point::operator==(const Point &other) const
{
    return (x == other.getX()) && (y == other.getY());
}



