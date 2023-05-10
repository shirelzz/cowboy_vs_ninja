#ifndef NINJA_HPP
#define NINJA_HPP

namespace ariel{}

#include <iostream>
#include "Character.hpp"

class Ninja : public Character 
{

   private:


   protected:

        int speed;

        Ninja(std::string name, Point loc, int hp, int speed);
        virtual ~Ninja() {}



    public:

        // Receives a pointer to the enemy and goes towards the enemy. The ninja goes a distance equal to its speed
        virtual void move(Character* enemy) const = 0;


        // Receives a pointer to the enemy.
        // If the ninja is alive and the enemy is less than 1 meter away, the ninja will cause a damage of 31 hit points to the enemy.
        // Otherwise, no damage will be done to the enemy.
        virtual void slash(Character* enemy) const = 0;


};


class YoungNinja : public Ninja
{

    private:


    public:

        // YoungNinja(std::string name, Point loc, int hp, int speed);

        YoungNinja(std::string name, Point loc);


        virtual void move(Character* enemy) const override;

        virtual void slash(Character* enemy) const override;




};

class TrainedNinja : public Ninja
{

    private:


    public:

        TrainedNinja(std::string name, Point loc, int hp, int speed);

        TrainedNinja(std::string name, Point loc);

        
        virtual void move(Character* enemy) const override;

        virtual void slash(Character* enemy) const override;


};

class OldNinja : public Ninja
{

    private:


    public:

        // OldNinja(std::string name, Point loc, int hp, int speed);

        OldNinja(std::string name, Point loc);

        virtual void move(Character* enemy) const override;

        virtual void slash(Character* enemy) const override;


};






#endif