//CSCI 1300 
//Authors: Reece Benson, Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Map.h"
using namespace std;



int main(){

    Map map69;

    map69.setPlayerX(26);
    cout << "player X:" << map69.getPlayerX() << endl;
    map69.setPlayerY(0);
    cout << "player Y:" << map69.getPlayerY() << endl;

    //map69.setZombiesArrAt(1,2, 9);
    //cout << "zombies arr at 3,2 is: " << map69.getZombiesArrAtIndex(3,2) << endl;

    cout << "lets display the map" << endl;
    map69.displayMap();


    return 0;
}