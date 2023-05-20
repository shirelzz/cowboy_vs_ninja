#ifndef TEAM2_HPP
#define TEAM2_HPP

# include "Team.hpp"


// The same as team, but the iterating through the characters will be 
// according to the order of addition without distinguishing cowboys or ninjas
class Team2 : public Team
{

    private:

        Character* leader;

        // 1st option
        // std::array<Character*, MAX_MEMBERS> characterArray;
        // int characters_size;

        // 2nd option
        // std::vector<Character*> warriors2;

    public:

        // Team2();

        explicit Team2(Character *leader);

        // virtual ~Team2() = default;

        // Team2(const Team&) = delete;
        
        // Team2& operator=(const Team2&) = delete;

        void add(Character* warrior) override;

        void attack(Team* otherTeam) override;

        void print() const override;

        void replaceLeader() override;

        Character* chooseVictim(Team *enemyTeam) override;

        // Returns an integer number of surviving group members.
        int stillAlive() const override;



};

#endif