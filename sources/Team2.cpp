# include "Team2.hpp"
# include "Team.hpp"

using namespace std;


Team2::Team2(Character *leader) : Team(leader) {}

void Team2::add(Character *warrior)
{
    if (getWarriors().size() >= MAX_MEMBERS)
    {
        throw std::runtime_error("The team2 is full");
    }

    if (warrior == nullptr)
    {
        throw std::invalid_argument("Warrior is a null pointer");
    }

    if (warrior->inTeam())
    {
        throw std::runtime_error("Warrior is already in a team");
    }

    warriors.push_back(warrior);
    warrior->changeMode();

}

