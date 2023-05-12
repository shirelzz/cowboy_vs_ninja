# include "Team.hpp"

using namespace std;

//-------------- Team Base --------------//

TeamBase:: TeamBase(Character *leader) : leader(leader)
{
    // if (leader == nullptr)
    // {
    //     throw std::runtime_error("Leader is null");
    // }
    this->leader = leader;
}

// TeamBase::TeamBase() : leader(nullptr){}

void TeamBase::replaceLeader(){
    // iterate over all team members and choose the one closest to the current (dead) leader
    // leader = new_leader;

}

Character& TeamBase::chooseVictim(TeamBase *enemyTeam){
    // iterate over all team members and choose the one closest to the current leader
    // the victim has to be alive
    return *leader;

}

int TeamBase::warriors_size(){
    return this->warriors.size();
}


void TeamBase::add(Character *warrior)
{
    // if (this->warriors_size() > 10)
    // {
    //     throw std::runtime_error("The team is fully populated");
    // }

    // this->warriors.push_back(warrior);
    
}


int TeamBase::stillAlive()
{

    return 0;
}





//-------------- Team --------------//


// Team::Team() : TeamBase(nullptr){}


Team::Team(Character *leader) : TeamBase(leader)
{

}

void Team::attack(TeamBase* otherTeam) const {

    // check if leader alive
    // if dead replaceLeader();
    // while the 2 teams are alive
    // chooseVictim();
    // all team members will attack (shoot or slash) the victim
    // if a cowboy doesnt have bullets left he will reload and then shoot
    // if a ninja is far from the victim (1) he will move closer and then slash
    // if the victim is dead choose another victim

}

void Team::print() const{}





//-------------- Team 2 --------------//

// Team2::Team2() : TeamBase(nullptr){}

Team2::Team2(Character *leader) : TeamBase(leader) {}

void Team2::print() const {

}

void Team2::attack(TeamBase* otherTeam) const
{

}


//-------------- Smart Team --------------//

// SmartTeam::SmartTeam() : TeamBase(nullptr){}

SmartTeam::SmartTeam(Character *leader) : TeamBase(leader) {}

void SmartTeam::print() const{

}

void SmartTeam::attack(TeamBase* otherTeam) const{

}

