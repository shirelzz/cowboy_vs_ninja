# include "Team.hpp"

using namespace std;

//-------------- Team Base --------------//

TeamBase:: TeamBase(Character *leader) : leader(leader)
{
    if (leader == nullptr)
    {
        throw std::runtime_error("Character is null");
    }
    this->leader = leader;
}

TeamBase::TeamBase() : leader(nullptr){
    
}

TeamBase:: ~TeamBase(){

}


int TeamBase::warriors_size(){
    return this->warriors.size();
}


void TeamBase::add(Character *warrior)
{
    // if (this->warriors_size() > 10)
    // {
    //     throw std::runtime_error("Full team");
    // }

    // this->warriors.push_back(warrior);
    
}


int TeamBase::stillAlive()
{
    // return this->characters_size;
    // return this->warriors_size();
    return 0;
}

//-------------- Team --------------//


Team::Team() : TeamBase(){

}

Team::Team(Character *leader) : TeamBase(leader)
{

}


Team::~Team()
{

}


void Team::attack(Team *otherTeam) const {}

void Team::print() const{}





//-------------- Team 2 --------------//


void Team2::print() const {

}

void Team2::attack(Team *otherTeam) const
{

}