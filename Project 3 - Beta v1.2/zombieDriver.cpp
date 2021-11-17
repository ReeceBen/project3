//CSCI 1300 
//Authors: Reece Benson, Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Zombie.h"
#include "Zombie.cpp"
using namespace std;



int main(){

    Zombie zombie54(3,5,2,6);
    //Zombie zombie54;

    zombie54.setDamage(99);
    zombie54.setHealth(420);
    zombie54.setX(1);
    zombie54.setY(1);


    int response = 3;
    zombie54.setAllStatsRandom();

    while(response > 2){
        cout << "enter a number greater than 2 to move randomly.....";
        cin >> response;

        
        zombie54.moveRandomly();

        cout << "zombie x: " << zombie54.getX() << endl;
        cout << "zombie y: " << zombie54.getY() << endl;
    }
    


    //zombie54.setAllStatsRandom();

    cout << "zombie damage: " << zombie54.getDamage() << endl;
    cout << "zombie health: " << zombie54.getHealth() << endl;
    cout << "zombie x: " << zombie54.getX() << endl;
    cout << "zombie y: " << zombie54.getY() << endl;

    return 0;
}