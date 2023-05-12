#ifndef CHARACTER_HPP
#define CHARACTER_HPP

namespace ariel{}

# include <iostream>
# include "Point.hpp"


class Character{

    private:

        std::string name;
        int hitPoints;
        Point location;

        friend class Cowboy;
        friend class Ninja;

    protected:


        void setHitPoints(int new_hp);

        void setLocation(Point& loc);

        Character(std::string name, Point loc, int hit_pts);


    public:


        // Checks if the character has more than zero hit points
        bool isAlive() const;

        // Gets a pointer to another character and returns the distance between the characters
        double distance(const Character* other) const;

        // Gets an integer. Subtracts the appropriate amount of hit points from the character. returns nothing.
        void hit(int rdc_hp);

        std::string getName();

        Point getLocation();

        int getHitPoints();

        // Prints the name of the character, the number of its hit points, and the point where the character is.
        // If the character dies the number of its hit points will not be printed, and the character's name will appear in parentheses.
        // Before the name will appear a letter indicating the type of character: N for ninja and C for cowboy
        virtual std::string print() const = 0;


};

#endif