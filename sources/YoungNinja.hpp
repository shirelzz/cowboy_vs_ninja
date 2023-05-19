#ifndef YNINJA_HPP
#define YNINJA_HPP

# include "Ninja.hpp"


class YoungNinja : public Ninja
{

    private:

        int speed;

    public:

        explicit YoungNinja(std::string name, Point loc);

        ~YoungNinja() override = default;

        void move(Character* enemy) override;

};

#endif