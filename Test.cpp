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

    Point pt1(9,8);
    Point pt2(3,5.4);

    CHECK(pt1.distance(pt2) == 6.53911309);
    CHECK(pt2.distance(pt2) == 0);
    CHECK(pt1.distance(pt2) == pt2.distance(pt1));

    Point src(2,4);
    Point dest(10,10);

    CHECK(src.moveTowards(dest, 2) == Point(3.6, 5.2)); ////// check for normal case, 0 distnce, great dist, 

}

TEST_CASE("Character methods") {

    YoungNinja *tzav = new YoungNinja("Leonardo", Point(7,7));

    tzav->hit(100);

    CHECK(tzav->getHitPoints() == 0);
    CHECK_THROWS(tzav->hit(1));

    Cowboy *shmulik = new Cowboy("Shmulik", Point(1.2,2));
    TrainedNinja *mean_person = new TrainedNinja("Mean Person", Point(1, 1.5));

    CHECK(shmulik->distance(mean_person) == 0.53851648);
    CHECK(shmulik->isAlive() == true);
    
    mean_person->slash(shmulik);
    
    CHECK(shmulik->isAlive() == false);
    
}

TEST_CASE("Cowboy methods") {
    
    Cowboy *midnight = new Cowboy("Midnight", Point(-3,-5));
    Cowboy *boker = new Cowboy("Boker", Point(-3, -4));

    boker->shoot(midnight);
    CHECK(boker->getBullets() == 5);
    CHECK(midnight->getHitPoints() == 100);

    
}

TEST_CASE("Ninja methods") {

    OldNinja *shem = new OldNinja("Shem", Point(13, 20));
    YoungNinja *tzav = new YoungNinja("Donatello", Point(13,19));

    tzav->slash(shem);
    CHECK(shem->getHitPoints() == 110);


    
}

TEST_CASE("More than 10 team members") {

    
}