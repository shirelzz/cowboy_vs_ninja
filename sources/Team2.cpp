# include "Team2.hpp"
# include "Team.hpp"

using namespace std;


//-------------- Team 2 --------------//

// Team2::Team2() : TeamBase(nullptr){}

Team2::Team2(Character *leader) : Team(leader) {
    add(leader);
}

void Team2::add(Character *warrior)
{
    if (warriors2.size() >= MAX_MEMBERS)
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

    warriors2.push_back(warrior);

}


void Team2::print() const { // 
    Team::print();
}

void Team2::attack(Team* otherTeam) //
{
    // if (otherTeam == nullptr)
    // {
    //     throw std::invalid_argument("Other team is a null pointer.");
    // }

    Team::attack(otherTeam);

}

void Team2::replaceLeader(){
    // iterate over all team members and choose the one closest to the current (dead) leader
    // leader = new_leader;
    Team::replaceLeader();


}

Character* Team2::chooseVictim(Team *enemyTeam){
    // iterate over all team members and choose the one closest to the current leader
    // the victim has to be alive
    return Team::chooseVictim(enemyTeam);

}

int Team2::stillAlive() const{

    int size = 0;

    for (size_t i = 0; i < warriors2.size(); i++)
    {
        if (warriors2.at(i)->isAlive())
        {
            size++;
        }
        
    }
    
    return size;
}

// int Team2::warriors_size(){
//     return this->warriors.size();
// }