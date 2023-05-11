# include "Character.hpp"
# include "Point.hpp"

using namespace std;


Character::Character(std::string name, Point loc, int hp): name(name), location(loc){

    if (hp < 0)
    {
        throw std::runtime_error("Negative number of hit points is impossible");
    }

    this->hitPoints = hp;
    
}


bool Character::isAlive() const
{
    if(hitPoints > 0){
        return true;
    }
    return false;
}


double Character::distance(const Character *other) const
{
    return location.distance(other->location);
}


void Character::hit(int rdc_hp)
{
    this->hitPoints -= rdc_hp;
}

std::string Character::getName()
{
    return this->name;
}

Point Character::getLocation()
{
    return this->location;
}

void Character::setLocation(Point &loc){
    location = loc;
}

int Character:: getHitPoints(){
    return this->hitPoints;
}

void Character::setHitPoints(int new_hp){
    this->hitPoints = new_hp;
}
