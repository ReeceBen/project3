//CSCI 1300 
//Authors: Reece Benson, Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Player.h"
using namespace std;

int main()
{
    //Testing Default Constructor with getters:
    Player player1;
    cout << "Player 1's name is: " << player1.getPlayerName() << endl;
    cout << "Player 1's health is " << player1.getPlayerHealth() << endl;
    cout << "Player 1's stamina is " << player1.getPlayerStamina() << endl;
    cout << "Player 1's inventory size is " << player1.getPlayerInventorySize() << endl;
    cout << "Player 1's number of weapons is " << player1.getPlayerWeaponNum() << endl;
    cout << "Player 1's number of keys is " << player1.getPlayerKeyCount() << endl;

    //Testing Parameterized Constructors: 
    Player player2 = Player("Reece", 20, 15, 6, 2, 1);
    cout << "Player 2's name is: " << player2.getPlayerName() << endl;
    cout << "Player 2's health is " << player2.getPlayerHealth() << endl;
    cout << "Player 2's stamina is " << player2.getPlayerStamina() << endl;
    cout << "Player 2's inventory size is " << player2.getPlayerInventorySize() << endl;
    cout << "Player 2's number of weapons is " << player2.getPlayerWeaponNum() << endl;
    cout << "Player 2's number of keys is " << player2.getPlayerKeyCount() << endl;

    //Testing Setters: 
    player2.setPlayerName("John");
    player2.setPlayerHealth(19);
    player2.setPlayerStamina(10);
    player2.setPlayerInventorySize(4);
    player2.setPlayerWeaponNum(3);
    player2.setPlayerKeyCount(2);
    cout << "Player 2's name is: " << player2.getPlayerName() << endl;
    cout << "Player 2's health is " << player2.getPlayerHealth() << endl;
    cout << "Player 2's stamina is " << player2.getPlayerStamina() << endl;
    cout << "Player 2's inventory size is " << player2.getPlayerInventorySize() << endl;
    cout << "Player 2's number of weapons is " << player2.getPlayerWeaponNum() << endl;
    cout << "Player 2's number of keys is " << player2.getPlayerKeyCount() << endl;

    //Testing the player menu:
    int playerMoveDirection = player2.displayPlayerMoveMenu();
    switch(playerMoveDirection)
    {
    case 1:
        cout << "You are moving north" << endl;
        break;
    case 2:
        cout << "You are moving south" << endl;
        break;
    case 3: 
        cout << "You are moving west" << endl; 
        break;
    case 4: 
        cout << "You are moving east" << endl;
        break;
    }
    return 0;
}