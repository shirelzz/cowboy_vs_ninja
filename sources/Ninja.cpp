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



//------------- Young Ninja -------------//


YoungNinja::YoungNinja(std::string name, Point loc) : Ninja(name, loc, 100, 14)
{

}

void YoungNinja::move(Character* enemy) const
{

}

void YoungNinja::slash(Character* enemy) const
{

}



//------------ Trained Ninja ------------//

TrainedNinja::TrainedNinja(std::string name, Point loc) : Ninja(name, loc, 120, 12)
{

}


void TrainedNinja::move(Character* enemy) const
{

}

void TrainedNinja::slash(Character* enemy) const
{

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





