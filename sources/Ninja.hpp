#ifndef NINJA_HPP
#define NINJA_HPP

namespace ariel{}

#include <iostream>
#include "Character.hpp"

class Ninja : public Character 
{

    private:

        std::string identifier = "N";
        int speed;

    protected:
   
        Ninja(std::string name, Point loc, int hit_pts, int speed);

        Ninja(const Ninja& other) = delete;
        Ninja& operator=(const Ninja& other) = delete;
        Ninja(Ninja&& other) = delete;
        Ninja& operator=(Ninja&& other) = delete;
        
        std::string getIdentifier();


    public:

        virtual ~Ninja() = default;

        // Receives a pointer to the enemy and goes towards the enemy. The ninja goes a distance equal to its speed
        // virtual void move(Character* enemy) = 0;
        void move(Character* enemy);

        std::string print() const override;
        // Receives a pointer to the enemy.
        // If the ninja is alive and the enemy is less than 1 meter away, the ninja will cause a damage of 40 hit points to the enemy.
        // Otherwise, no damage will be done to the enemy.
        void slash(Character* enemy) const;

        int getSpeed();

};

#endif