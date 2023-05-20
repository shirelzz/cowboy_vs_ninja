# include "SmartTeam.hpp"
# include "Team.hpp"

using namespace std;

//-------------- Smart Team --------------//

// SmartTeam::SmartTeam() : TeamBase(nullptr){}

SmartTeam::SmartTeam(Character *leader) : Team(leader) {

}

void SmartTeam::print() const{

}

void SmartTeam::attack(Team* otherTeam){

     if (otherTeam == nullptr)
    {
        throw std::invalid_argument("Other team is a null pointer.");
    }
}

void SmartTeam::replaceLeader(){
    // iterate over all team members and choose the one closest to the current (dead) leader
    // leader = new_leader;

}

Character* SmartTeam::chooseVictim(Team *enemyTeam){
    // iterate over all team members and choose the one closest to the current leader
    // the victim has to be alive
    return leader;

}

// int SmartTeam::warriors_size(){
//     return this->warriors.size();
// }