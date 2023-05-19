# include "Ninja.hpp"
# include "YoungNinja.hpp"
# include "TrainedNinja.hpp"
# include "OldNinja.hpp"
# include "Point.hpp"

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

// Ninja::~Ninja()
// {}

int Ninja::getSpeed(){
    return this->speed;
}

void Ninja::slash(Character* enemy) const
{
    if (this == enemy)
    {
        throw std::runtime_error("Self harm (ninja)");
    }

    if (!enemy->isAlive())
    {
        throw std::runtime_error("Enemy is dead (ninja)");
    }

    if (!isAlive())
    {
        throw std::runtime_error("Attacker is dead (ninja)");
    }
    
    if(isAlive() && distance(enemy) < 1){
        enemy->hit(40);
    }
}

std::string Ninja::getIdentifier(){
    return this->identifier;
}

std::string Ninja::print() const {

    std::string output = "N";
    std::string loc = "(" + std::to_string(this->getLocation().getX()) +", " + std::to_string(this->getLocation().getY()) + ")";

    if(this->isAlive()){
        output +=  ", Name: " + this->getName() + ", Hit Points: " + std::to_string(this->getHitPoints()) + loc;
    }
    else{
        output +=  " (" + name + ")" + loc;
    }
    
    return output;
}



//------------- Young Ninja -------------//


YoungNinja::YoungNinja(std::string name, Point loc) : Ninja(name, loc, 100, 14) {}

void YoungNinja::move(Character* enemy)
{
    Point new_loc = Point::moveTowards(getLocation(), enemy->getLocation(), speed);
    this->setLocation(new_loc);
}

// YoungNinja::~YoungNinja(){}




//------------ Trained Ninja ------------//

TrainedNinja::TrainedNinja(std::string name, Point loc) : Ninja(name, loc, 120, 12) {}

// TrainedNinja::~TrainedNinja(){}

void TrainedNinja::move(Character* enemy)
{
    Point new_loc = Point::moveTowards(this->getLocation(), enemy->getLocation(), speed);
    this->setLocation(new_loc);

}






//-------------- Old Ninja --------------//

OldNinja::OldNinja(std::string name, Point loc) : Ninja(name, loc, 150, 8) {}

// OldNinja::~OldNinja(){}

void OldNinja::move(Character* enemy)
{
    Point new_loc = Point::moveTowards(getLocation(), enemy->getLocation(), speed);
    this->setLocation(new_loc);
}





