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


bool Character::isAlive()
{
    // if(this->hitPoints > 0){
    //     return true;
    // }
    return false;
}


double Character::distance(Character *other)
{
    return 0;
}

void Character::hit(int hitPoints)
{

}

std::string Character::getName()
{
    return this->name;
}

Point Character::getLocation()
{
    return this->location;
}

int Character:: getHitPoints(){
    return this->hitPoints;
}

void Character::print()
{

}

ostream &operator<<(ostream &output, const Character* character)
{
    Point loc = character.getLocation();
	output << character.getName() << character.getHitPoints() << "(" << loc.getX() << "," << loc.getY();
	return output;
}