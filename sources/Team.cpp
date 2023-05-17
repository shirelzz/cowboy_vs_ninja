# include "Team.hpp"
# include "Team2.hpp"
# include "SmartTeam.hpp"

using namespace std;

//-------------- Team --------------//


// Team::Team() : TeamBase(nullptr){}


Team::Team(Character *leader) : leader(leader)
{

}

void Team::add(Character *warrior){

}

int Team::stillAlive(){
    return 0;
}

void Team::attack(Team* otherTeam) const {

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

void Team::replaceLeader(){
    // iterate over all team members and choose the one closest to the current (dead) leader
    // leader = new_leader;

}

Character& Team::chooseVictim(Team *enemyTeam){
    // iterate over all team members and choose the one closest to the current leader
    // the victim has to be alive
    return *leader;

}

int Team::warriors_size(){
    return this->warriors.size();
}

//-------------- Team 2 --------------//

// Team2::Team2() : TeamBase(nullptr){}

Team2::Team2(Character *leader) : Team(leader) {}

void Team2::print() const {

}

void Team2::attack(Team* otherTeam) const
{

}

void Team2::replaceLeader(){
    // iterate over all team members and choose the one closest to the current (dead) leader
    // leader = new_leader;

}

Character& Team2::chooseVictim(Team *enemyTeam){
    // iterate over all team members and choose the one closest to the current leader
    // the victim has to be alive
    return *leader;

}

int Team2::warriors_size(){
    return this->warriors.size();
}


//-------------- Smart Team --------------//

// SmartTeam::SmartTeam() : TeamBase(nullptr){}

SmartTeam::SmartTeam(Character *leader) : Team(leader) {

}

void SmartTeam::print() const{

}

void SmartTeam::attack(Team* otherTeam) const{

}

void SmartTeam::replaceLeader(){
    // iterate over all team members and choose the one closest to the current (dead) leader
    // leader = new_leader;

}

Character& SmartTeam::chooseVictim(Team *enemyTeam){
    // iterate over all team members and choose the one closest to the current leader
    // the victim has to be alive
    return *leader;

}

int SmartTeam::warriors_size(){
    return this->warriors.size();
}

