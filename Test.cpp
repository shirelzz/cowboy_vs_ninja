#include "doctest.h"
#include <stdexcept>
#include "sources/Team.hpp"
#include <iostream>

using namespace ariel;
using namespace std;

TEST_CASE("Initalization") {

    Point loc(9,7.2);
    CHECK(loc.getX() == 9);
    CHECK(loc.getY() == 7.2);

    Cowboy *avi = new Cowboy("Avi", loc);
    YoungNinja *shirel = new YoungNinja("Shirel", Point(9, 8));
    OldNinja *jacob = new OldNinja("Jacob", Point(-1.2,0.0));
    TrainedNinja *hodaya = new TrainedNinja("Hodaya", Point(-1,-1.1));

    CHECK(avi->getHitPoints() == 110);
    CHECK(avi->getBullets() == 6);
    CHECK(shirel->getHitPoints() == 100);
    CHECK(shirel->getSpeed() == 14);
    CHECK(jacob->getHitPoints() == 150);
    CHECK(jacob->getSpeed() == 8);   
    CHECK(hodaya->getHitPoints() == 120);
    CHECK(hodaya->getSpeed() == 12);
}

TEST_CASE("Point methods") {

}

TEST_CASE("Character methods") {
    
}

TEST_CASE("Cowboy methods") {
    
}

TEST_CASE("Ninja methods") {
    
}

TEST_CASE("More than 10 team members") {
    
}