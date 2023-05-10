#ifndef COWBOY_HPP
#define COWBOY_HPP

namespace ariel{}

# include <iostream>
# include "Character.hpp"

class Cowboy : public Character
{

    private:

        int amountOfBullets;

    public:

        Cowboy(std::string name, Point loc, int hp, int bullets);
        Cowboy(std::string name, Point loc);


        ~Cowboy();

        //receives a pointer to the enemy. If the morning is not dead and he has bullets left,
        //the cowboy shoots the enemy, subtracts 01 hit points from the enemy - and loses 1 bullet. 
        //Otherwise, no damage will be done to the enemy.
        void shoot(Character* enemy);

        // Checks wether there are any bullets left in this cowboy's gun
        bool hasboolets();

        // Loads the gun with six new bullets
        void reload();



};
#endif