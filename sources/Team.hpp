#ifndef TEAM_HPP
#define TEAM_HPP

namespace ariel{}

#include <iostream>
#include <vector>
#include "Character.hpp"
# include "Ninja.hpp"
# include "Cowboy.hpp"


//---------------- Team Base ----------------//

// When a team is created, it gets a pointer to the leader.

class TeamBase{

    private:

    protected:

        Character* leader;

        // 1st option
        Character* characters[10];
        int characters_size;

        // 2nd option
        std::vector<Character*> warriors;
        int warriors_size(); // At most 10

    public:

        TeamBase();

        TeamBase(Character *leader);

        ~TeamBase();

        // Adds a warrior to warriors
        void add(Character* warrior);

        // Returns an integer number of surviving group members.
        int stillAlive();

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
        virtual void attack(Team* otherTeam) const = 0;


        // Iterates through all team characters and prints their details.
        virtual void print() const = 0;



};

// Iterating through  all members of the team (for the purpose of attack, printing, or comparison) will always be done in the following order:
// First of all going over all the cowboys, then going over all the ninjas.
// Within each group, the transition will be made according to the order in which the characters were added.
// The purpose of the requirement to split between cowboys and ninjas in this section is to make it easier for you.
// If you find that the requirement complicates the implementation, think about another implementation.
// When looking for the closest character, and two characters are at the same distance,
// the first character that was checked between them will be selected.


class Team: public TeamBase
{

    private:

    
    public:
    
        Team();

        Team(Character* leader);


        // Frees the memory allocated to all characters in the team.
        ~Team();

        virtual void attack(Team* otherTeam) const override;

        virtual void print() const override;

};



// The same as team, but the transition to the characters will be according to the order of addition without distinguishing cowboys or ninjas
class Team2 : public TeamBase
{


    public:

        virtual void print() const override;

        virtual void attack(Team* otherTeam) const override;




};

#endif
