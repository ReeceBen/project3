//CSCI 1300 
//Authors: Reece Benson, Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class


//Map class

//summery
//the map class keeps track of the player's location, keeping their coordinates as variables x and y
//the map class also keeps track of the zombies locations, storing them
//the map class, in general, keeps track of the locations of everything that can be displayed
//at its core it will be creating an "image" of the map that can be printed out
//the map will have dimentions 5x9
//the map's grid will be displayed how it will be printed, from top to bottom and left to right, meaning:
// 0,0 corosponds to the top left, and 0,1 would be the top row, one move to the right





//order of things to get done:
//
//make it so the player can move around within the 5x9 grid, and they can't go outside the boundries of the grid
//
//make it so the player can go to the edge of the displayed map and go into another "chamber"
//      with this make it so the player can't go through walls
//      idea on how to make that work: make a 2D array with 0s and 1s, 0s they can walk through, 1s they cant
//
//add zombies and get their movement and stuff working
//
//add anything else





//pseudo code
/*

data members:

playerX
playerY
zombiesArrRow
zombiesArrCol
zombiesArray, has zombie positions, 2s for no zombies 3s for zombies



member functions:

displayMap
    prints out the current map
    displays where the player is
    if we have to include more things then display those too

    in total the map has a size of 15 rows and 27 columns
    so we will need to display only a section of the map
    do this by checking if the players x and y is within some specified ranges
    and if its inside some specific ranges then we can display the part of the map that corosponds to this ranges


*/








//pre proscessor
#ifndef MAP_H
#define MAP_H

#include <cstring>
#include <iostream>
using namespace std;



class Map{

    public:

    //default constructor
    Map();

    //getters
    int getPlayerX();
    int getPlayerY();
    int getZombiesArrRow();
    int getZombiesArrCol();

    int getZombiesArrAtIndex(int, int);

    //setters

    void setPlayerX(int);
    void setPlayerY(int);
    void setZombiesArrAt(int, int, int);

    //other

    void displayMap();
    

    private:

    int playerX;
    int playerY;
    static const int zombiesArrRow = 15;
    static const int zombiesArrCol = 27;
    int zombiesArr[15][27];

    static const int mapRow = 15;
    static const int mapCol = 27;

};


#endif