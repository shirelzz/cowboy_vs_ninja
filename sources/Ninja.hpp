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
        virtual ~Ninja() = default;

        std::string getIdentifier();



    public:

        // Receives a pointer to the enemy and goes towards the enemy. The ninja goes a distance equal to its speed
        virtual void move(Character* enemy) = 0;

        virtual std::string print() const = 0;

        // Receives a pointer to the enemy.
        // If the ninja is alive and the enemy is less than 1 meter away, the ninja will cause a damage of 40 hit points to the enemy.
        // Otherwise, no damage will be done to the enemy.
        void slash(Character* enemy) const;

        int getSpeed();

};


class YoungNinja : public Ninja
{

    private:

        int speed;

    public:

        explicit YoungNinja(std::string name, Point loc);

        ~YoungNinja() override = default;

        void move(Character* enemy) override;

        std::string print() const override;


};

class TrainedNinja : public Ninja
{

    private:

        int speed;

    public:

        explicit TrainedNinja(std::string name, Point loc);

        ~TrainedNinja() override = default;
        
        void move(Character* enemy) override;

        std::string print() const override;

};

class OldNinja : public Ninja
{   

    private:

        int speed;

    public:

        explicit OldNinja(std::string name, Point loc);

        ~OldNinja() override = default;

        void move(Character* enemy) override;

        std::string print() const override;


};

#endif