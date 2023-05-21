# include "SmartTeam.hpp"
# include "Team.hpp"

using namespace std;


SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

void SmartTeam::add(Character *warrior){

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

    if (warriors_size() == 1 || warriors_size() == 0)
    {
        warriors.push_back(warrior);
        warrior->changeMode();
        return;
    }
    
    if (warriors_size() > 1)
    {
        bool flag = false;
        for (std::vector<Character*>::size_type i = 0; i < warriors_size(); i++)
        {
            Character* currWarrior = warriors.at(i);

            if (currWarrior == nullptr)
            {
                continue;
            }
            
            double dist = warrior->distance(leader);
            double curr_warrior_dist = currWarrior->distance(leader);

            if (dist < curr_warrior_dist)
            {
                warriors.insert(warriors.begin() + static_cast<std::vector<Character*>::difference_type>(i), warrior);
                flag = true;
                warrior->changeMode();
                return; 
            }
        }

        if (!flag)
        {
            warriors.push_back(warrior);
            warrior->changeMode();
        }
                
    }

}