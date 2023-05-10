#include "Point.hpp"
#include <cmath>
#include <iostream>

using namespace std;

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point() : x(0.0), y(0.0) {}

Point::~Point()
{
    // delete this;
}

double Point::distance(Point pnt)
{    
    double dist;
    // dist = pow((this->x - pnt.x), 2) + pow((this->y - pnt.x), 2);
    // dist = sqrt(dist);
    return dist;
}

void Point::print(){
    // cout << "(" << this->x << "," << this->y << ")" << endl; 
}

Point Point::moveTowards(Point src, Point dest, double dist)
{
    Point closest(0,0);

    return closest;
}

double Point::getX(){
    return this->x;
}

double Point::getY(){
    return this->y;
}



