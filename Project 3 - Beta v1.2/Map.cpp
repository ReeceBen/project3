//CSCI 1300 
//Authors: Reece Benson, Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class

#include <iomanip>
#include <fstream>
#include <cstring>


#include <array>
#include <iostream>
#include "Map.h"

using namespace std;



//default constructor
//this sets the player in the starting position
//creates a zombiesArr grid with no zombies
//      maybe makes a weapons grid with no werapons?
Map::Map(){
    playerX = 0;
    playerY = 0;

    //static const int zombiesArrRow = 15;
    //static const int zombiesArrCol = 27;

    //this sets up the zombies array with no zombies in it
    for(int i = 0; i < zombiesArrRow; i++){
        for(int k = 0; k < zombiesArrCol; k++){
            zombiesArr[i][k] = 2;
        }
    }
}

//getters
int Map::getPlayerX(){
    return playerX;
}
int Map::getPlayerY(){
    return playerY;
}
int Map::getZombiesArrRow(){
    return zombiesArrRow;
}
int Map::getZombiesArrCol(){
    return zombiesArrCol;
}

int Map::getZombiesArrAtIndex(int r, int c){
    //cout << "aight well figure this out sometime" << endl;
    return zombiesArr[r][c];
}






//setters

void Map::setPlayerX(int r){
    playerX = r;
}
void Map::setPlayerY(int r){
    playerY = r;
}
void Map::setZombiesArrAt(int row, int col, int value){
    zombiesArr[row][col] = value;
}




//other

//this prints out the map, where the player is in, as a 5 row 9 column grid
//the player is diplayed with some kind of character, a "P" for instance
//note the map is actually 15x27, so the function first finds where the player is and then
// outlines that specific section of map
void Map::displayMap(){
    

    //first find the player and find out what "room" they're in
    //keep in mind the map in total has a size of 15 rows and 27 columns

    //then we will set the bounds on what to display



    //we will use these guys to indicate the start and end points
    // of the values we want to display in the rows and columns
    int rowStart = 0;
    int rowEnd = 0;
    int colStart = 0;
    int colEnd = 0;

    //this sets up our rows starting and ending
    if(playerY >= 0 && playerY < (mapRow/3)){
        //cout << "first 3rd" << endl;
        //in first 3rd of map's columns
        rowStart = 0; rowEnd = (mapRow/3);
    }else if(playerY >= ((mapRow/3)) && playerY < ((mapRow/3)*2)){
        //cout << "second 3rd" << endl;
        rowStart = ((mapRow/3)); rowEnd = ((mapRow/3)*2);
    }else{
        //cout << "third 3rd" << endl;
        rowStart = ((mapRow/3)*2); rowEnd = mapRow;
    }


    //this sets up our cols starting and ending
    if(playerX >= 0 && playerX < (mapCol/3)){
        //cout << "first 3rd" << endl;
        //in first 3rd of map's columns
        colStart = 0; colEnd = (mapCol/3);
    }else if(playerX >= ((mapCol/3)) && playerX < ((mapCol/3)*2)){
        //cout << "second 3rd" << endl;
        colStart = ((mapCol/3)); colEnd = ((mapCol/3)*2);
    }else{
        //cout << "third 3rd" << endl;
        colStart = ((mapCol/3)*2); colEnd = mapCol;
    }





    for(int i = rowStart; i < rowEnd; i++){
        for(int k = colStart; k < colEnd; k++){

            //lets check if the player is located here
            //if they are do a "P" instead of an "_"
            ////        *if we want to add another thing, for instance a shop, we just need to check for its x and y*
            if(playerX == k && playerY == i){
                cout << "P";
            }else{
                cout << "_";
            }
        }
        //cout << "we're on row numbe: " << i << endl;
        cout << endl;
    }
}
