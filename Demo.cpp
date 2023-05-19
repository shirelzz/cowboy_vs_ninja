/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes
#include "sources/Team2.hpp" // for my demo


using namespace ariel;


int main() {
    Point a(32.3,44),b(1.3,3.5);
    assert(a.distance(b) == b.distance(a));
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    tom->shoot(sushi);
    cout << tom->print() <<endl;

    sushi->move(tom);
    cout << "1" << endl;
    sushi->slash(tom);
      cout << "2" << endl;


    Team team_A(tom); 
   cout << "3" << endl;

    team_A.add(new YoungNinja("Yogi", Point(64,57)));
        cout << "4" << endl;


    // Team b(tom); should throw tom is already in team a

     Team team_B(sushi);
         cout << "5" << endl;

     team_B.add(new TrainedNinja("Hikari", Point(12,81)));
         cout << "6" << endl;



     while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
        team_A.attack(&team_B);
        team_B.attack(&team_A);
        team_A.print();
        team_B.print();
     }

     if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
     else cout << "winner is team_B" << endl;



     // my

    Point p1{1, 1};
    Point p2{2, 3};

    double distance = p1.distance(p2);
    double half_p = distance / 2;
    double third_p = distance / 3;

    Point p3{Point::moveTowards(p1, p2, half_p)};
    cout << "p3 to p2: " << p3.distance(p2) << endl;

    Point p4{Point::moveTowards(p1, p2, third_p)};
    cout << "p4 to p2: " << p4.distance(p2) << endl;

    // ------------------//

    Ninja* nin = new OldNinja("Moshe", Point(0,0));
    Cowboy* cow = new Cowboy("Otis", Point(0.5, 0.5));

    cout << "Nin alive? " << nin->isAlive() << ", Cow alive? " << cow->isAlive() << endl; // true

    Team team1(nin);
    Team2 team2(cow);
    cout << "team1 alive? " << team1.stillAlive() << ", team2 alive? " << team2.stillAlive() << endl; // true

    team1.add(new TrainedNinja("l", Point(0,1)));
    team2.add(new Cowboy("c", Point(8,9)));
    cout << "team1 alive? " << team1.stillAlive() << ", team2 alive? " << team2.stillAlive() << endl; // true

    team1.add(new Cowboy("lr", Point(1,1)));
    team2.add(new YoungNinja("cn", Point(0,9)));
    cout << "team1 alive? " << team1.stillAlive() << ", team2 alive? " << team2.stillAlive() << endl; // true





    return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}
