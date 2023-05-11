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
Cowboy::Cowboy(std::string name, Point loc) : Character(name, loc, 110), amountOfBullets(6)
{

}

Cowboy::~Cowboy()
{

}

void Cowboy::shoot(Character* enemy)
{
    if(isAlive() && hasboolets() > 0){
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
    this->amountOfBullets += 6;
}

std::string Cowboy::print() const
{
    
    std::string output = identifier;
    if(this->isAlive()){
        output +=  ", Name: " + name + ", #Hit points: " + std::to_string(hitPoints) + ", Location: "
                   "(" + std::to_string(location.getX()) +", " + std::to_string(location.getY()) + ")";
    }
    else{
        output +=  ", Name: (" + name + ")";
    }
    return output;
}

int Cowboy::getBullets(){

    return this->amountOfBullets;
}
