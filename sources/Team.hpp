#ifndef TEAM_HPP
#define TEAM_HPP

namespace ariel{}

# include <iostream>
# include <array>
# include <vector>

// # include "Character.hpp"
# include "Cowboy.hpp"
// # include "Ninja.hpp"
# include "YoungNinja.hpp"
# include "TrainedNinja.hpp"
# include "OldNinja.hpp"

enum {
    MAX_MEMBERS = 10,
};

// When a team is created, it gets a pointer to the leader.


// Iterating through  all members of the team (for the purpose of attack, printing, or comparison) will always be done in the following order:
// First of all going over all the cowboys, then going over all the ninjas.
// Within each group, the transition will be made according to the order in which the characters were added.
// The purpose of the requirement to split between cowboys and ninjas in this section is to make it easier for you.
// If you find that the requirement complicates the implementation, think about another implementation.
// When looking for the closest character, and two characters are at the same distance,
// the first character that was checked between them will be selected.


class Team
{

    private:

        Character* leader;

        // 1st option
        // std::array<Character*, MAX_MEMBERS> characterArray;
        // int characters_size;

        // 2nd option
        std::vector<Character*> warriors;

        friend class Team2;
        friend class SmartTeam;

    protected:

        // virtual void replaceLeader();
        void replaceLeader();

        // virtual Character* chooseVictim(Team *enemyTeam);
        Character* chooseVictim(Team *enemyTeam);
    
        int warriors_size() const; // At most 10

        std::vector<Character*> getWarriors();

        std::vector<Character*> getWarriors() const;

        Character* getLeader();

        Character* getLeader() const;


    public:
    
        // Team();

        Team(Character* leader);

        ~Team();

        // Team(const Team&) = delete;
    
        // Team& operator=(const Team&) = delete;

        // Adds a warrior to warriors
        virtual void add(Character* warrior);

        // Returns an integer number of surviving group members.
        // virtual int stillAlive() const;
        int stillAlive() const;


        // Receives a pointer to an enemy team.
        // Attacking the enemy team will be done in the following way:
        // First check if the leader of the attacking group is alive. Otherwise, a new leader must be chosen, who is the closest living character (in terms of location) to the dead leader.
        // Then the group will choose a victim from among the enemy group.
        // The victim is the member of the living enemy group who is closest to the attacking group leader.
        // All living members of the attacking team will attack the chosen victim.
        // Cowboys who have bullets in their guns will shoot the victim, and cowboys who don't have bullets will load their weapons.
        // Ninjas that are less than 1 meter away from the victim will kill the victim, and ninjas that are further away will advance towards the victim.
        // At each stage, if the victim dies a new victim will be chosen (which will be, again, the living enemy character closest to the leader of the attacking team).
        // If there are no living members in the attacking group or the enemy group the attack will end.
        virtual void attack(Team* otherTeam);

        // Iterates through all team characters and prints their details.
        virtual void print() const;

};

#endif
