# include "Cowboy.hpp"
# include "Character.hpp"


Cowboy::Cowboy(std::string name, Point loc, int hp, int bullets)
        : Character(name, loc, hp)
{
    if (bullets < 0)
    {
        throw std::runtime_error("Negative amount of bullets is impossible");
    }
    
    this->amountOfBullets = bullets;
}

// A cowboy is created with six bullets and 11 hit points.
Cowboy::Cowboy(std::string name, Point loc) : Character(name, loc, 11), amountOfBullets(6)
{

}

Cowboy::~Cowboy()
{

}

void Cowboy::shoot(Character* enemy)
{

}

bool Cowboy::hasboolets()
{
    // if (this->amountOfBullets > 0)
    // {
    //     return true;
    // }
    return false;
    
}

void Cowboy::reload()
{
    // this->amountOfBullets += 6;
}
