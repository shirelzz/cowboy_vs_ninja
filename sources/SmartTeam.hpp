#ifndef STEAM_HPP
#define STEAM_HPP

# include "Team.hpp"


class SmartTeam : public Team
{

    private:

        Character* leader;

        // 1st option
        std::array<Character*, MAX_MEMBERS> characterArray;
        int characters_size;

        // 2nd option
        // std::vector<Character*> warriors;
        // int warriors_size(); // At most 10

    public:

        // SmartTeam();

        explicit SmartTeam(Character *leader);

        // virtual ~SmartTeam() = default;

        SmartTeam(const SmartTeam&) = delete;
        
        SmartTeam& operator=(const SmartTeam&) = delete;

        void attack(Team* otherTeam) override;
        
        void print() const override;

        // void replaceLeader() override;

        // Character* chooseVictim(Team *enemyTeam) override;

};

#endif