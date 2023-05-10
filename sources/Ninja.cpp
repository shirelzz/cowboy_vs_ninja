# include "Ninja.hpp"

using namespace std;

//---------------- Ninja ----------------//


Ninja::Ninja(std::string name, Point loc, int hp, int speed): Character(name, loc, hp) ,speed(speed)
{
    if (speed < 0)
    {
        throw std::runtime_error("Negative speed");
    }

    this->speed = speed;
}

int Ninja::getSpeed(){
    return this->speed;
}



//------------- Young Ninja -------------//


YoungNinja::YoungNinja(std::string name, Point loc) : Ninja(name, loc, 100, 14)
{

}

void YoungNinja::move(Character* enemy) const
{
    int stam = enemy->getHitPoints();

}

void YoungNinja::slash(Character* enemy) const
{
    int stam = enemy->getHitPoints();

}

std::string YoungNinja::print() const {
    
    std::string output = "stam";
    // output += this->identifier + ",";
    return output;
}



//------------ Trained Ninja ------------//

TrainedNinja::TrainedNinja(std::string name, Point loc) : Ninja(name, loc, 120, 12)
{

}


void TrainedNinja::move(Character* enemy) const
{
    int stam = enemy->getHitPoints();

}

void TrainedNinja::slash(Character* enemy) const
{
    int stam = enemy->getHitPoints();

}

std::string TrainedNinja::print() const {
    std::string output = "stam";
    // output += this->identifier + ",";
    return output;
}






//-------------- Old Ninja --------------//

OldNinja::OldNinja(std::string name, Point loc) : Ninja(name, loc, 150, 8)
{

}


void OldNinja::move(Character* enemy) const
{

}

void OldNinja::slash(Character* enemy) const
{

}

std::string OldNinja::print() const
{
    std::string output = "";
    // output += this->identifier + ",";
    return output;
}





