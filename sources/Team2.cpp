# include "Team2.hpp"
# include "Team.hpp"

using namespace std;


//-------------- Team 2 --------------//

// Team2::Team2() : TeamBase(nullptr){}

Team2::Team2(Character *leader) : Team(leader) {
}

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


void Team2::print() const { // 
    Team::print();
}

void Team2::attack(Team* otherTeam) //
{

    // Check if leader alive
    // If dead replaceLeader()
    // While the 2 teams are alive:
    // chooseVictim();
    // All team members will attack (shoot or slash) the victim:
    // If a cowboy doesnt have bullets left he will reload and then shoot
    // iI a ninja is far from the victim (1) he will move closer and then slash
    // If the victim is dead choose another victim

    if (otherTeam == nullptr)
    {
        throw std::invalid_argument("Other team is a null pointer.");
    }

    // if (otherTeam->stillAlive() == 0)
    // {
    //     throw std::runtime_error("Enemy team is all dead");
    // }

    if(!(leader->isAlive())){
        replaceLeader();
    }

    while (stillAlive() > 0 && otherTeam->stillAlive() > 0)
    {
        Character* victim = chooseVictim(otherTeam);

        for (size_t i = 0; i < warriors_size(); i++) //
        {
            Character* warrior = getWarriors().at(i);

            if (!warrior->isAlive())
            {
                continue;
            }
            

            if (warrior->identifier() == "N")
            {
                if (warrior->distance(victim) > 1) // while?
                {
                    dynamic_cast<Ninja*>(warrior)->move(victim);
                }
                dynamic_cast<Ninja*>(warrior)->slash(victim);

            }
            else if (warrior->identifier() == "C") 
            {
                if (!(dynamic_cast<Cowboy*>(warrior)->hasboolets()))
                {
                    dynamic_cast<Cowboy*>(warrior)->reload();
                }
                dynamic_cast<Cowboy*>(warrior)->shoot(victim);
            }

            if (!victim->isAlive())
            {
                if (victim == otherTeam->getLeader())
                {
                    otherTeam->replaceLeader();
                }
                break;
            }
            
        }
        
    } 


}

void Team2::replaceLeader(){
    // iterate over all team members and choose the one closest to the current (dead) leader
    // leader = new_leader;

    Character* new_leader;
    std::vector<Character*> warriors = getWarriors();

    // To initalize new_leader with a valid warrior
    for (size_t i = 0; i < warriors_size(); i++)
    {
        if (warriors.at(i) != leader && warriors.at(i)->isAlive())
        {
            new_leader = warriors.at(i);
            break;
        }
        
    }
    
    // To choose new_leader who is valid and closest to the (dead) leader
    for (size_t i = 0; i < warriors_size(); i++)
    {
        double dist = warriors.at(i)->distance(leader);
        if (warriors.at(i) != leader && dist < new_leader->distance(leader) && warriors.at(i)->isAlive())
        {
            new_leader = warriors.at(i);
        }
        
    }

}

Character* Team2::chooseVictim(Team *enemyTeam){
    // iterate over all team members and choose the one closest to the current leader
    // the victim has to be alive
    return Team::chooseVictim(enemyTeam);

}

int Team2::stillAlive() const{

    int size = 0;

    for (size_t i = 0; i < getWarriors().size(); i++)
    {
        if (getWarriors().at(i)->isAlive())
        {
            size++;
        }
        
    }
    
    return size;
}

// int Team2::warriors_size(){
//     return this->warriors.size();
// }