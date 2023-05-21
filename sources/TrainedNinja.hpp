#ifndef TNINJA_HPP
#define TNINJA_HPP

# include "Ninja.hpp"



class TrainedNinja : public Ninja
{

    private:

    // int speed;

    public:

        explicit TrainedNinja(std::string name, Point loc);

        ~TrainedNinja() override = default;
        
        // void move(Character* enemy) override;

};

#endif