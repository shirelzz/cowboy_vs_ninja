#ifndef STEAM_HPP
#define STEAM_HPP

# include "Team.hpp"

// The same as team, but the iterating through the characters will be 
// according to the proximity to the leader without distinguishing cowboys or ninjas

class SmartTeam : public Team
{

    public:

        explicit SmartTeam(Character *leader);

        void add(Character* warrior) override;

};

#endif