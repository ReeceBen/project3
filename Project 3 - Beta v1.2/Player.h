//CSCI 1300 
//Authors: Reece Benson, Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class
/*
Algorithm:
Data Members:
Health
Stamina 
Inventory Size - Size of the array that holds Item Objects
Weapons
Ammo
Amount of Keys

Member Functions:
Move
    Print out a menu giving 4 movement directions
    If the player chooses up or down
        Update the row the player is on
    If the player chooses left or right
        Update the column the player is on
    Return the players new position
Check Inventory 
    Print out a menu of the current item the players hold 
    Let the player input a number corresponding to the item in their inventory
    If the number does not correspond to the number of items in their inventory
        Tell them its an invalid input
    Else
        Give the player another menu of options they would like to do with the item
        Options Include:
            Drop Item
            Use Item
            Go back
Check Weapons
    Print out a menu of the current weapons that the player holds
    Let the player input a number corresponding to the weapon they hold
    If the number does not correspond to the number of weapons they hold
        Tell them its an invalid input
    Else
        Give the player another menu of options they would like to do with the weapon
        Options Include:
            Drop Weapon
            Reload Weapon
Check amount of Keys
    Prints the amount of keys you've found out
Battle
    Prints out a menu of options if the player battles a zombie
    Options include:
        Choose weapon
        Reload weapon
        Use healing item
        Run
*/

//pre proscessor
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Item.h"
#include "Weapon.h"
#include "Zombie.h"
using namespace std; 

class Player
{
    public:
        Player();
        Player(string name, int health, int stamina, int inventorySize, int keys);
        string getPlayerName();
        void setPlayerName(string name);
        int getPlayerHealth(); 
        void setPlayerHealth(int health);
        int getPlayerStamina();
        void setPlayerStamina(int stamina);
        int getNumItems();
        void setNumItems(int numberOfItems);
        int getPlayerInventorySize();
        void setPlayerInventorySize(int inventorySize);
        int getPlayerWeaponNum();
        void setPlayerWeaponNum(int numOfWeapons);
        int getPlayerKeyCount();
        void setPlayerKeyCount(int keyCount);
        int displayPlayerMoveMenu();
        void pickUpItem();
        void checkPlayerInventory();
        void checkPlayerWeapons();
        void battle(Zombie encounteredZombie);
    private:
        string playerName;
        int playerHealth;
        int playerStamina;
        int playerInvSize;
        int playerWepNum;
        int playerKeyCount;
        int numItems;
        vector<Item> playerInventory;
        Weapon playerWeapons[3];
};

#endif