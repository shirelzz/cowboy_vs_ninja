#ifndef POINT_HPP
#define POINT_HPP

namespace ariel{}
#include <iostream>

class Point{

    private:

        double x;
        double y;

    public:

        Point(double pt_x, double pt_y);
        
        Point();

        Point(const Point& other);

        ~Point();

        double distance(const Point& pnt) const;

        void print() const;

        // Gets a source point, destination point and distance.
        // The function returns the closest point to the destination point,
        // which is at most the given distance from the source point
        Point moveTowards(const Point& dest, int dist) const;

        double getX() const;

        double getY() const;

        Point& operator=(const Point& other);

        bool operator==(const Point& other) const;









};
#endif