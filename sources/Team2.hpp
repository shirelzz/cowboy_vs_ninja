#ifndef TEAM2_HPP
#define TEAM2_HPP

# include "Team.hpp"


// The same as team, but the iterating through the characters will be 
// according to the order of addition without distinguishing cowboys or ninjas

class Team2 : public Team
{

    public:

        explicit Team2(Character *leader);

        void add(Character* warrior) override;

};

#endif