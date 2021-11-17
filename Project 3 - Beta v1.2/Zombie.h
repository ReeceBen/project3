//CSCI 1300 
//Authors: Reece Benson, Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class


/*

zombie class

summery:
zombies will be stored in an array
but each zombie will have some stats:
damage
health
X
Y

many (if not all) of these stats will be randomized


Algorithm:
Data Members:

zombieDamage
zombieHealth
zombieX
zombieY
maxZombieDamage
maxZombieHealth

Member Functions:

moveRandomly()
setAllStatsRandom()

then literally just getters and setters for the stats above

*/


//pre proscessor
#ifndef ZOMBIE_H
#define ZOMBIE_H


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std; 




class Zombie{

    public:
    Zombie();
    Zombie(int, int, int, int);

    int getDamage();
    int getHealth();
    int getX();
    int getY();
    
    int getMaxDamage();
    int getMaxHealth();

    void setDamage(int);
    void setHealth(int);
    void setX(int);
    void setY(int);

    void moveRandomly();
    void setAllStatsRandom();

    private:
    int zombieDamage;
    int zombieHealth;
    int zombieX;
    int zombieY;
    static const int maxZombieDamage = 17;
    static const int maxZombieHealth = 20;

};

#endif