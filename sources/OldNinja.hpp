#ifndef ONINJA_HPP
#define ONINJA_HPP

# include "Ninja.hpp"

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