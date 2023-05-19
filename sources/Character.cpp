# include "Character.hpp"
# include "Point.hpp"

using namespace std;


Character::Character(std::string name, Point loc, int hp): name(name), location(loc){

    if (hp < 0)
    {
        throw std::invalid_argument("Negative number of hit points is impossible");
    }
    
    this->mode = false;
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
    if (rdc_hp < 0){
        throw std::invalid_argument("Number of hit points to deduct is negative");
    }
    this->hitPoints -= rdc_hp;
}

std::string Character::getName() const
{
    return this->name;
}

Point Character::getLocation() const
{
    return this->location;
}

void Character::setLocation(Point &loc){
    location = loc;
}

int Character:: getHitPoints() const
{
    return this->hitPoints;
}

void Character::setHitPoints(int new_hp){
    this->hitPoints = new_hp;
}

std::string Character::identifier() const
{
    if (this->print()[0] == 'N')
    {
        return "N";
    }
    else if (this->print()[0] == 'C')
    {
        return "C";
    }
    else{
        return "No id";
    }
}

bool Character::inTeam()
{
    return mode;
}

void Character::changeMode()
{
    this->mode = !mode;
}
