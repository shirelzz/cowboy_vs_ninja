# include "Team.hpp"
// # include "Team2.hpp"
// # include "SmartTeam.hpp"

using namespace std;

//-------------- Team --------------//

Team::Team(Character *leader) : leader(leader)
{
    if (leader->inTeam())
    {
        throw std::runtime_error("The leader is already in a different team");
    }
    // cout<< "building" << endl;

    
    add(leader);
    // cout<< "added" << endl;

    // leader->changeMode();
}

void Team::add(Character *warrior){

    // cout<< "adding" << endl;

    if (warriors_size() >= MAX_MEMBERS)
    {
        throw std::runtime_error("The team is full");
    }
    // cout<< "1 if" << endl;


    if (warrior == nullptr)
    {
        throw std::invalid_argument("Warrior is a null pointer");
    }
    // cout<< "2 if" << endl;


    if (warrior->inTeam())
    {
        throw std::runtime_error("Warrior is already in a team");
    }
    // cout<< "3 if" << endl;

    

    if (warrior->identifier() == "C")
    {
        warriors.insert(warriors.begin(), warrior);
    }
    else if (warrior->identifier() == "N")
    {
        warriors.push_back(warrior);
    }
    // cout<< "end if" << endl;

    warrior->changeMode();

    // cout<< "finish" << endl;

}

int Team::stillAlive() const
{
    int size = 0;

    for (size_t i = 0; i < warriors_size(); i++)
    {
        if (warriors.at(i)->isAlive())
        {
            size++;
        }
        
    }
    
    return size;
}

void Team::attack(Team* otherTeam) {

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

        for (size_t i = 0; i < warriors_size(); i++)
        {
            Character* warrior = warriors.at(i);

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
                if (victim == otherTeam->leader)
                {
                    otherTeam->replaceLeader();
                }
                break;
            }
            
        }
        
    } 

}

void Team::print() const{

    std::string output = "";

    for (size_t i = 0; i < warriors_size(); i++)
    {
        output += warriors.at(i)->print();
    }

    cout << output << endl;
}

void Team::replaceLeader(){
    // iterate over all team members and choose the one closest to the current (dead) leader
    // leader = new_leader;

    Character* new_leader;

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

Character* Team::chooseVictim(Team *enemyTeam){

    // iterate over all enemyTeam members and choose the one closest to this current leader
    // the victim has to be alive

    if (enemyTeam->stillAlive() == 0)
    {
        throw std::runtime_error("Enemy team is all dead");
    }
    

    Character* victim;

    // To initalize victim with a valid warrior
    for (size_t i = 0; i < enemyTeam->warriors_size(); i++)
    {
        if (enemyTeam->warriors.at(i)->isAlive())
        {
            victim = enemyTeam->warriors.at(i);
            break;
        }
        
    }
    
    // To choose  a victim who is valid and closest to the (dead) leader
    for (size_t i = 0; i < enemyTeam->warriors_size(); i++)
    {
        double dist = enemyTeam->warriors.at(i)->distance(leader);
        if (dist < victim->distance(leader) && enemyTeam->warriors.at(i)->isAlive())
        {
            victim = enemyTeam->warriors.at(i);
        }
        
    }
    return victim;

}

int Team::warriors_size() const{
    return this->warriors.size();
}

std::vector<Character *> Team::getWarriors()
{
    return warriors;
}

std::vector<Character *> Team::getWarriors()const 
{
    return warriors;
}

Character *Team::getLeader() {
    return leader;
}

Character *Team::getLeader() const{
    return leader;
}

