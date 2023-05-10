#ifndef CHARACTER_HPP
#define CHARACTER_HPP

namespace ariel{}

# include <iostream>
# include "Point.hpp"


class Character{

    private:

        std::string name;

        friend class Cowboy;
        friend class Ninja;

    protected:

        Point location;
        int hitPoints;

        void setHitPoints(int new_hp);

    public:

        Character(std::string name, Point loc, int hp);

        // Checks if the character has more than zero hit points
        bool isAlive();

        // Gets a pointer to another character and returns the distance between the characters
        double distance(Character* other);

        // Gets an integer. Subtracts the appropriate amount of hit points from the character. returns nothing.
        void hit(int hitPoints);

        std::string getName();

        Point getLocation();

        int getHitPoints();

        // Prints the name of the character, the number of its hit points, and the point where the character is.
        // If the character dies the number of its hit points will not be printed, and the character's name will appear in parentheses.
        // Before the name will appear a letter indicating the type of character: N for ninja and C for cowboy
        virtual std::string print() const = 0;


};

#endif