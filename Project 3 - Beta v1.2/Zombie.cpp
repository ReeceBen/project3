//CSCI 1300 
//Authors: Reece Benson, Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class


#include <iomanip>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <time.h>

#include <array>
#include <iostream>
#include "Zombie.h"

using namespace std;



//default constructor
//this sets the player in the starting position
//creates a zombiesArr grid with no zombies
//      maybe makes a weapons grid with no werapons?
Zombie::Zombie(){
    zombieDamage = 1;
    zombieHealth = 1;
    zombieX = 3;
    zombieY = 3;
}
Zombie::Zombie(int q, int w, int e, int r){
    zombieDamage = q;
    zombieHealth = w;
    zombieX = e;
    zombieY = r;
}


//getters
    
int Zombie::getDamage(){
    return zombieDamage;
}
int Zombie::getHealth(){
    return zombieHealth;
}
int Zombie::getX(){
    return zombieX;
}
int Zombie::getY(){
    return zombieY;
}

int Zombie::getMaxDamage(){
    return maxZombieDamage;
}
int Zombie::getMaxHealth(){
    return maxZombieDamage;
}


//setters

void Zombie::setDamage(int d){
    zombieDamage = d;
}
void Zombie::setHealth(int h){
    zombieHealth = h;
}
void Zombie::setX(int x){
    zombieX = x;
}
void Zombie::setY(int y){
    zombieY = y;
}
    



//other

//this makes it so zombies can wander around the map randomly
//changes either the x or y coordinates by +/- 1. Will not move off the edge of the map
void Zombie::moveRandomly(){
    //cout << "move randomly n shit lmao" << endl;
    //moves in a random direction
    //doesnt move through the edge of the map

    //these are used to prevent the zombie from picking the same number repededly
    bool picked1 = 0;
    bool picked2 = 0;
    bool picked3 = 0;
    bool picked4 = 0;


    //if we picked a direction that does not push you off the edge of the map
    // we'll change this to a 1 and break the wile loop
    bool validDirection = 0;
    




    //all this makes a random seed generated on nano seconds!
    struct timespec ts;

    clock_gettime(CLOCK_MONOTONIC, &ts);

    //we'll use nano-seconds instead of seconds
    srand((time_t)ts.tv_nsec);

    //printf ("Random fast seeded: %d\n", rand()%10);
    
    





    //srand(time(NULL));
    int r = rand();

    //this will be 1 2 3 or 4 corosponding to up down left or right
    int moveDirection = (r%4) + 1;

    //cout << "move direction is: " << moveDirection << endl;


    //lets have while loop that checks for the the direction is valid
    //it basically just rotates the zombie around in a circle,
    // and each time it chacks if they can move in that direction. If they can't then keep rotating
    while(validDirection == 0){
        
        //check each direction, if they can move in that direction, break the loop, they're good to go
        //if they can't move in that direction, add 1 to the moveDirection and keep looping!
        if(moveDirection == 1){
            //up 
            if(zombieY != 0){
                validDirection = 1;
            }else{
                moveDirection++;
                //cout << "well we cant move up" << endl;
            }
        }else if(moveDirection == 2){
            //down
            if(zombieY != 14){
                validDirection = 1;
            }else{
                moveDirection++;
                //cout << "well we cant move down" << endl;
            }
        }else if(moveDirection == 3){
            //left
            if(zombieX != 0){
                validDirection = 1;
            }else{
                moveDirection++;
                //cout << "well we cant move left" << endl;
            }
        }else{
            //right
            if(zombieX != 26){
                validDirection = 1;
            }else{
                moveDirection = 1;
                //cout << "well we cant move right" << endl;
            }
        }
    }


    //cool we got a valid move direction, now lets move!!!
    if(moveDirection == 1){
        //up
        zombieY--;
    }else if(moveDirection == 2){
        //down
        zombieY++;
    }else if(moveDirection == 3){
        //left
        zombieX--;
    }else{
        //right
        zombieX++;
    }

}




//this sets all the zombies stats to random values within a specified range
//this enables us to create many zombies with randomized stats easily
void Zombie::setAllStatsRandom(){
    //cout << "ayyy set them stats random as fuck lmao" << endl;
    //sets stats between 0 and maxDamage & maxHealth



    
    //all this makes a random seed generated on nano seconds!
    struct timespec ts;

    clock_gettime(CLOCK_MONOTONIC, &ts);

    //we'll use nano-seconds instead of seconds
    srand((time_t)ts.tv_nsec);

    //printf ("Random fast seeded: %d\n", rand()%10);
    


    

    //srand(time(NULL));
    int r = rand();
    zombieDamage = r%maxZombieDamage;
    zombieHealth = r%maxZombieHealth;

    //the +3 s here make sure a zombie doesnt spawn within 3 squares for the player
    zombieX = (r%23) + 3;
    zombieY = (r%11) + 3;


}