#ifndef COWBOY_HPP
#define COWBOY_HPP

namespace ariel{}

# include <iostream>
# include "Character.hpp"
# include "Ninja.hpp"

class Cowboy : public Character
{

    private:

        int amountOfBullets;
        std::string identifier = "C";

    public:

        Cowboy(std::string name, Point loc, int hit_pts, int bullets);
        Cowboy(std::string name, Point loc);

        Cowboy(const Cowboy& other) = delete;
        Cowboy& operator=(const Cowboy& other) = delete;
        Cowboy(Cowboy&& other) = delete;
        Cowboy& operator=(Cowboy&& other) = delete;

        virtual ~Cowboy() = default;

        // Receives a pointer to the enemy. If the cowboy is not dead and he has bullets left,
        // the cowboy shoots the enemy, subtracts 10 hit points from the enemy - and loses 1 bullet. 
        // Otherwise, no damage will be done to the enemy.
        void shoot(Character* enemy);

        // Checks wether there are any bullets left in this cowboy's gun
        bool hasboolets();

        // Loads the gun with six new bullets
        void reload();

        std::string print() const override;

        int getBullets();


};
#endif