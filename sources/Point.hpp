#ifndef POINT_HPP
#define POINT_HPP

namespace ariel{}
#include <iostream>

class Point{

    private:

        double x;
        double y;

    public:

        Point(double x, double y);
        
        Point();

        ~Point();

        double distance(Point pnt);

        void print();

        // Gets a source point, destination point and distance.
        // The function returns the closest point to the destination point,
        // which is at most the given distance from the source point
        Point moveTowards(Point src, Point dest, double dist);

        double getX();

        double getY();








};
#endif