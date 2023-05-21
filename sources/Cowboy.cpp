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
    this->mode = false;

}

// A cowboy is created with six bullets and 11 hit points.
Cowboy::Cowboy(std::string name, Point loc) : Character(name, loc, 110), amountOfBullets(6)
{

}

Cowboy::~Cowboy()
{

}

void Cowboy::shoot(Character* enemy)
{
    if (this == enemy)
    {
        throw std::runtime_error("Self harm (cowboy)");
    }

    if (!enemy->isAlive())
    {
        throw std::runtime_error("Enemy is dead (cowboy)");
    }

    if (!isAlive())
    {
        throw std::runtime_error("Attacker is dead (cowboy)");
    }
    
    
    if(isAlive() && hasboolets()){
        enemy->setHitPoints(enemy->getHitPoints() - 10);
        this->amountOfBullets--;
    }

}

bool Cowboy::hasboolets()
{
    if (amountOfBullets > 0)
    {
        return true;
    }
    return false;
    
}

void Cowboy::reload()
{
    if (!isAlive())
    {
        throw std::runtime_error("Cowboy is dead");
    }

    int bullets = 6 - amountOfBullets;
    this->amountOfBullets += bullets;
}

std::string Cowboy::print() const
{
    std::string output = "C";
    std::string loc = ", (" + std::to_string(location.getX()) +", " + std::to_string(location.getY()) + ").";

    if(this->isAlive()){
        output +=  ", Name: " + name + ", Hit Points: " + std::to_string(hitPoints) + loc;
    }
    else{
        output +=  " (" + name + ")" + loc;
    }
    
    return output;
}

int Cowboy::getBullets(){

    return this->amountOfBullets;
}
