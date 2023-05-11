#include "Point.hpp"
#include <cmath>
#include <iostream>

using namespace std;

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point() : x(0.0), y(0.0) {}

Point::Point(const Point& other) {
    x = other.x;
    y = other.y;
}


Point::~Point()
{
    // delete this;
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

Point Point::moveTowards(Point src, Point dest, double dist) const
{
    Point closest(0,0);
    double src2dest_dist = src.distance(dest);
    if(src2dest_dist <= dist){
        return src;
    }

    double slope = (dest.getY() - this->y) / (dest.getX() - this->x);

    return closest;
}

double Point::getX() const{
    return this->x;
}

double Point::getY() const{
    return this->y;
}


Point& Point::operator=(const Point& other) {
    if (this != &other) {
        // clear();
        x = other.x;
        y = other.y;
    }
    return *this;
}



