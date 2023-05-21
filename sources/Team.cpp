# include "Team.hpp"

using namespace std;


Team::Team(Character *leader) : leader(leader)
{
    if (leader->inTeam())
    {
        throw std::runtime_error("The leader is already in a different team");
    }
    
    add(leader);
}

Team::~Team()
{
    for (size_t i = 0; i < warriors_size(); i++)
    {
        Character* warrior = warriors.at(i);

        if (warrior == nullptr)
        {
            continue;
        }

        if (warrior->identifier() == "N")
        {
            delete dynamic_cast<Ninja*>(warrior);
        }
        else if (warrior->identifier() == "C")
        {
            delete dynamic_cast<Cowboy*>(warrior);
        }
        
    }

    leader = nullptr;
    warriors.clear();
    
}

void Team::add(Character *warrior){

    if (warriors_size() >= MAX_MEMBERS)
    {
        throw std::runtime_error("The team is full");
    }

    if (warrior == nullptr)
    {
        throw std::invalid_argument("Warrior is a null pointer");
    }

    if (warrior->inTeam())
    {
        throw std::runtime_error("Warrior is already in a team");
    }

    if (warrior->identifier() == "C")
    {
        warriors.insert(warriors.begin(), warrior);
    }
    else if (warrior->identifier() == "N")
    {
        warriors.push_back(warrior);
    }

    warrior->changeMode();

}

int Team::stillAlive() const
{
    int size = 0;

    if (warriors_size() == 0)
    {
        return 0;
    }

    for (size_t i = 0; i < warriors_size(); i++)
    {
        Character* warrior = warriors.at(i);

        if (warrior == nullptr)
        {
            continue;
        }

        if (warrior->isAlive())
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

    if (this == otherTeam)
    {
        throw std::invalid_argument("Self attack (Team).");
    }

    if (otherTeam->stillAlive() == 0)
    {
        throw std::runtime_error("Enemy team is dead (Team:attack)");
    }

    if (stillAlive() == 0)
    {
        return;
    }

    if(!(leader->isAlive())){
        replaceLeader();

        if (leader == nullptr)
        {
            return;
        }
        
    }


    Character* victim = chooseVictim(otherTeam);

    if (victim == nullptr)
    {
        return;
    }
        
    for (size_t i = 0; i < warriors_size(); i++)
    {
        Character* warrior = warriors.at(i);

        if (!warrior->isAlive() || warrior == nullptr)
        {
            continue;
        }

        if (warrior->identifier() == "N")
        {
            if (warrior->distance(victim) >= 1)
            {
                dynamic_cast<Ninja*>(warrior)->move(victim);
                warrior->getLocation().print();
            }
            else
            {
                dynamic_cast<Ninja*>(warrior)->slash(victim);
            }

        }

        else if (warrior->identifier() == "C") 
        {
            if (!(dynamic_cast<Cowboy*>(warrior)->hasboolets()))
            {
                dynamic_cast<Cowboy*>(warrior)->reload();
            }
            else
            {
                dynamic_cast<Cowboy*>(warrior)->shoot(victim);
            }
        }

        if (!victim->isAlive())
        {
            victim = chooseVictim(otherTeam);

            if (victim == nullptr)
            {
                return;
            }
        }            
    }        
} 


void Team::replaceLeader(){

    // iterate over all team members and choose the one closest to the current (dead) leader
    // leader = new_leader;

    if (stillAlive() == 0)
    {
        cout << "Dead team" << endl;
        return;
    }
    
    Character* new_leader = nullptr;

    // To initalize new_leader with a valid warrior
    for (size_t i = 0; i < warriors_size(); i++)
    {
        if (warriors.at(i) != leader && warriors.at(i)->isAlive())
        {
            new_leader = warriors.at(i);
            break;
        }
        
    }

    if(new_leader == nullptr){
        cout << "fail. couldn't find a valid warrior (Team: replace leader)" << endl;
        leader = new_leader;
        return;
    }

    // To choose new_leader who is valid and closest to the (dead) leader
    for (size_t i = 0; i < warriors_size(); i++)
    {
        Character* warrior = warriors.at(i);

        if (warrior == nullptr)
        {
            continue;
        }

        double dist = warrior->distance(leader);

        if (warrior != leader && dist < new_leader->distance(leader) && warrior->isAlive())
        {
            new_leader = warrior;
        }
        
    }

    leader = new_leader;
    
}

Character* Team::chooseVictim(Team *enemyTeam){

    // iterate over all enemyTeam members and choose the one closest to this current leader
    // the victim has to be alive

    if (enemyTeam == nullptr)
    {
        return nullptr;
    }
    
    if (enemyTeam->stillAlive() == 0)
    {
        return nullptr;
    } 

    Character* victim = nullptr;

    // To initalize victim with a valid warrior
    for (size_t i = 0; i < enemyTeam->warriors_size(); i++)
    {
        Character* enemyWarrior = enemyTeam->warriors.at(i);

        if (enemyWarrior == nullptr)
        {
            continue;
        }
        
        if (enemyWarrior->isAlive())
        {
            victim = enemyWarrior;
            break;
        }
        
    }
    
    // To choose a victim who is valid and closest to the (dead) leader
    for (size_t i = 0; i < enemyTeam->warriors_size(); i++)
    {
        Character* enemyWarrior = enemyTeam->warriors.at(i);

        if (enemyWarrior == nullptr)
        {
            continue;
        }

        double dist = enemyWarrior->distance(leader);

        if (dist < victim->distance(leader) && enemyWarrior->isAlive())
        {
            victim = enemyWarrior;
        }
        
    }
    return victim;

}

int Team::warriors_size() const
{
    return this->warriors.size();
}

void Team::print() const{

    std::string output = "";

    for (size_t i = 0; i < warriors_size(); i++)
    {
        Character* warrior = warriors.at(i);

        if (warrior == nullptr)
        {
            continue;
        }
        
        output += warrior->print() + "\n";
    }

    cout << output << endl;
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

