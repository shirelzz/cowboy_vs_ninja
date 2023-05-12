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
    double distance = src.distance(dest);

    // Check for normal case, 0 distnce, great distance
    CHECK(src.moveTowards(dest, 2) == Point(3.6, 5.2)); 
    CHECK(src.moveTowards(dest, 0) == src);
    CHECK(src.moveTowards(dest, distance) == dest);
}

TEST_CASE("Character methods") {

    YoungNinja *tzav = new YoungNinja("Leonardo", Point(7,7));
    CHECK_THROWS(new TrainedNinja("Zuz", Point(7,7))); // Can't have two characters at the same location

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

    // Cowboys shouldn't attack themselves
    CHECK_THROWS(midnight->shoot(midnight));
    CHECK(boker->getBullets() == 6);

    // Empty gun
    boker->shoot(midnight);
    boker->shoot(midnight);
    boker->shoot(midnight);
    boker->shoot(midnight);
    boker->shoot(midnight);

    CHECK_THROWS(boker->shoot(midnight));
    boker->reload();
    CHECK_NOTHROW(boker->shoot(midnight));


    
}

TEST_CASE("Ninja methods") {

    OldNinja *shem = new OldNinja("Shem", Point(13, 20));
    YoungNinja *tzav = new YoungNinja("Donatello", Point(13,19));
    TrainedNinja *tzav2 = new TrainedNinja("Michelangelo", Point(14,20));

    tzav->slash(shem); // Loses 40 pts
    CHECK(shem->getHitPoints() == 110);

    tzav->slash(tzav2); // Doesn't lose any pts
    CHECK(tzav2->getHitPoints() == 120);

    // Ninjas shouldn't attack themselves
    CHECK_THROWS(tzav->slash(tzav));

    tzav->move(tzav2);
    tzav->slash(tzav2); // Should lose 40 pts
    CHECK(tzav2->getHitPoints() == 80);








    
}

TEST_CASE("Team methods") {

    Cowboy *leader = new Cowboy("Avi", Point(10,10));
    YoungNinja *pargit = new YoungNinja("Yogi", Point(64,57));
    Team tim(leader);

    tim.add(pargit);
    tim.add(new Cowboy("Otis", Point(9,0)));
    tim.add(new YoungNinja("Nin", Point(91,10)));
    tim.add(new TrainedNinja("Train", Point(19,0)));
    tim.add(new OldNinja("Moshe", Point(9,2)));
    tim.add(new Cowboy("Arik", Point(3,7)));
    tim.add(new TrainedNinja("Master", Point(8,10)));
    tim.add(new Cowboy("Mimi", Point(10,6)));
    tim.add(new YoungNinja("Baby", Point(91,70)));

    // More than 10 team members
    CHECK_THROWS(tim.add(new Cowboy("Moo", Point(9,0))));

    Team2 tim2(new OldNinja("Shifu", Point(1,1)));
    tim.attack(&tim2);

    // check with dead leader



}