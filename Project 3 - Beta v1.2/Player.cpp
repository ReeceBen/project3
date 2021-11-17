//CSCI 1300 
//Authors: Reece Benson, Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Player.h"

using namespace std;

Player::Player()
{
    //Default Constructor sets player with empty name to default player states
    playerName = "";
    playerHealth = 10;
    playerStamina = 10;
    playerInvSize = 7;
    playerWepNum = 3;
    playerKeyCount = 0;
    numItems = 0;
    playerWeapons[0].setWeaponName("Pistol");
    playerWeapons[0].setAmmoType(1);
    playerWeapons[0].setWeaponDamage(10);
    playerWeapons[0].setWeaponAmmo(10);
    playerWeapons[0].setMaxAmmo(10);
    playerWeapons[1].setWeaponName("Shotgun");
    playerWeapons[1].setAmmoType(2);
    playerWeapons[1].setWeaponDamage(15);
    playerWeapons[1].setWeaponAmmo(0);
    playerWeapons[1].setMaxAmmo(8);
    playerWeapons[2].setWeaponName("Rifle");
    playerWeapons[2].setAmmoType(3);
    playerWeapons[2].setWeaponDamage(20);
    playerWeapons[2].setWeaponAmmo(0);
    playerWeapons[2].setMaxAmmo(5);
}
Player::Player(string name, int health, int stamina, int inventorySize, int keys)
{
    //Parameterized Constructor
    playerName = name;
    playerHealth = health;
    playerStamina = stamina; 
    playerInvSize = inventorySize;
    playerKeyCount = keys;
    numItems = 0;
    playerWeapons[0].setWeaponName("Pistol");
    playerWeapons[0].setAmmoType(1);
    playerWeapons[0].setWeaponDamage(10);
    playerWeapons[0].setWeaponAmmo(10);
    playerWeapons[0].setMaxAmmo(10);
    playerWeapons[1].setWeaponName("Shotgun");
    playerWeapons[1].setAmmoType(2);
    playerWeapons[1].setWeaponDamage(15);
    playerWeapons[1].setWeaponAmmo(0);
    playerWeapons[1].setMaxAmmo(8);
    playerWeapons[2].setWeaponName("Rifle");
    playerWeapons[2].setAmmoType(3);
    playerWeapons[2].setWeaponDamage(20);
    playerWeapons[2].setWeaponAmmo(0);
    playerWeapons[2].setMaxAmmo(5);
}
//Getters and Setters
string Player::getPlayerName()
{
    return playerName;
}
void Player::setPlayerName(string name)
{
    playerName = name;
}
int Player::getPlayerHealth()
{
    return playerHealth;
}
void Player::setPlayerHealth(int health)
{
    playerHealth = health;
}
int Player::getPlayerStamina()
{
    return playerStamina;
}
void Player::setPlayerStamina(int stamina)
{
    playerStamina = stamina;
}
int Player::getNumItems()
{
    return numItems;   
}
void Player::setNumItems(int numberOfItems)
{
    numItems = numberOfItems;
}
int Player::getPlayerInventorySize()
{
    return playerInvSize;
}
void Player::setPlayerInventorySize(int inventorySize)
{
    playerInvSize = inventorySize;
}
int Player::getPlayerWeaponNum()
{
    return playerWepNum;
}
void Player::setPlayerWeaponNum(int numOfWeapons)
{
    playerWepNum = numOfWeapons;
}
int Player::getPlayerKeyCount()
{
    return playerKeyCount;
}
void Player::setPlayerKeyCount(int keyCount)
{
    playerKeyCount = keyCount;
}
//Displays the player move menu with a loop, returns a value 1-4 depending on which 4 directions the player wants to move
int Player::displayPlayerMoveMenu()
{
    int playerMovementInput = 0;
    while(playerMovementInput == 0)
    {
        cout << "Movement Options:" << endl;
        cout << "1. Up" << endl;
        cout << "2. Down" << endl;
        cout << "3. Left" << endl;
        cout << "4. Right" << endl;
        cin >> playerMovementInput;
        if(playerMovementInput < 1 || playerMovementInput > 4)
        {
            cout << "Invalid input, please choose another option." << endl;
            cout << endl;
        }
    }
    return playerMovementInput;
}
void Player::pickUpItem()
{
    srand(time(0));
    int itemId;
    int randItem = rand() % 1000 + 1;
    if(playerKeyCount  < 3 && playerKeyCount == 0)
    {
        if(randItem > 950)
        {
            if(playerKeyCount < 3)
            {
                playerKeyCount++;
                cout << "Congrats! You Found a Key! " << (3 - playerKeyCount) << " more to go!" << endl;
                cout << endl;
            }
        }
        else if(numItems < playerInvSize)
        {
            if(randItem > 0 && randItem < 330)
            {
                cout << "Nothing was found." << endl;
            }
            else if(randItem > 330 && randItem < 455)
            {
                playerInventory.push_back(Item(1, 1));
                cout << "You found a pistol magazine." << endl;
                cout << endl;
                numItems++;
            }
            else if(randItem > 454 && randItem < 579)
            {   
                playerInventory.push_back(Item(2, 1));
                cout << "You found a box of 6 shotgun shells." << endl;
                cout << endl;
                numItems++;
            }
            else if(randItem > 578 && randItem < 703)
            {
                playerInventory.push_back(Item(3, 1));
                cout << "You found a rifle magazine." << endl;
                cout << endl;
                numItems++;
            }
            else if(randItem > 702 && randItem < 827)
            {
                playerInventory.push_back(Item(4, 1));
                cout << "You found a healing syringe." << endl;
                cout << endl;
                numItems++;
            }
            else if(randItem > 826 && randItem < 950)
            {
                playerInventory.push_back(Item(5, 1));
                cout << "You found a flash grenade." << endl;
                cout << endl;
                numItems++;
            }
        }
        else
        { 
            cout << "Inventory full and no keys found." << endl;
        }
    }
    else if(playerKeyCount  < 3 && playerKeyCount == 1)
    {
        if(randItem > 900)
        {
            if(playerKeyCount < 3)
            {
                playerKeyCount++;
                cout << "Congrats! You Found a Key! " << (3 - playerKeyCount) << " more to go!" << endl;
                cout << endl;
            }
        }
        else if(numItems < playerInvSize)
        {
            if(randItem > 0 && randItem < 330)
            {
                cout << "Nothing was found." << endl;
            }
            else if(randItem > 330 && randItem < 455)
            {
                playerInventory.push_back(Item(1, 1));
                cout << "You found a pistol magazine." << endl;
                cout << endl;
                numItems++;
            }
            else if(randItem > 454 && randItem < 579)
            {   
                playerInventory.push_back(Item(2, 1));
                cout << "You found a box of 6 shotgun shells." << endl;
                cout << endl;
                numItems++;
            }
            else if(randItem > 578 && randItem < 703)
            {
                playerInventory.push_back(Item(3, 1));
                cout << "You found a rifle magazine." << endl;
                cout << endl;
                numItems++;
            }
            else if(randItem > 702 && randItem < 827)
            {
                playerInventory.push_back(Item(4, 1));
                cout << "You found a healing syringe." << endl;
                cout << endl;
                numItems++;
            }
            else if(randItem > 826 && randItem < 899)
            {
                playerInventory.push_back(Item(5, 1));
                cout << "You found a flash grenade." << endl;
                cout << endl;
                numItems++;
            }
        }
        else
        { 
            cout << "Inventory full and no keys found." << endl;
        }
    }
    else if(playerKeyCount  < 3 && playerKeyCount == 2)
    {
        if(randItem > 850)
        {
            if(playerKeyCount < 3)
            {
                playerKeyCount++;
                cout << "Congrats! You Found a Key! " << (3 - playerKeyCount) << " more to go!" << endl;
                cout << endl;
            }
        }
        else if(numItems < playerInvSize)
        {
            if(randItem > 0 && randItem < 330)
            {
                cout << "Nothing was found." << endl;
            }
            else if(randItem > 330 && randItem < 455)
            {
                playerInventory.push_back(Item(1, 1));
                cout << "You found a pistol magazine." << endl;
                cout << endl;
                numItems++;
            }
            else if(randItem > 454 && randItem < 579)
            {   
                playerInventory.push_back(Item(2, 1));
                cout << "You found a box of 6 shotgun shells." << endl;
                cout << endl;
                numItems++;
            }
            else if(randItem > 578 && randItem < 703)
            {
                playerInventory.push_back(Item(3, 1));
                cout << "You found a rifle magazine." << endl;
                cout << endl;
                numItems++;
            }
            else if(randItem > 702 && randItem < 827)
            {
                playerInventory.push_back(Item(4, 1));
                cout << "You found a healing syringe." << endl;
                cout << endl;
                numItems++;
            }
            else if(randItem > 826 && randItem < 849)
            {
                playerInventory.push_back(Item(5, 1));
                cout << "You found a flash grenade." << endl;
                cout << endl;
                numItems++;
            }
        }
        else
        { 
            cout << "Inventory full and no keys found." << endl;
        }   
    }
    else if(playerKeyCount == 3)
    {
        cout << "Congrats! You have found all 3 keys! You must escape through the marked exit on the map now!" << endl;
    }
}
void Player::checkPlayerInventory()
{
    if(playerInventory.empty())
    {
        cout << "Your inventory is currently empty." << endl;
        cout << endl;
    }
    else
    {
        int playerInventoryInput = 0;
        while(playerInventoryInput != playerInventory.size() + 1)
        {
            cout << "Current Inventory: " << endl;
            int displayCounter = 0;
            int itemCounter = 1;
            while(displayCounter < playerInventory.size())
            {
                cout << itemCounter << ": " << playerInventory[displayCounter].getItemName() << endl;
                displayCounter++;
                itemCounter++;
            }
            cout << playerInventory.size() + 1 << ": Quit." << endl;
            cout << "Please select an item: " << endl;
            cin >> playerInventoryInput;
            if(playerInventoryInput < 0 || playerInventoryInput > playerInventory.size() + 1)
            {
                cout << "Invalid Input, Try Again." << endl;
                cout << endl;
            }
            else if(playerInventoryInput == playerInventory.size() + 1)
            {
                cout << "Returning to primary menu" << endl;
            }
            else
            {
                int playerInventoryInput2 = 0;
                while(playerInventoryInput2 != 3)
                {
                    string itemName = playerInventory[playerInventoryInput - 1].getItemName();
                    cout << "What do you want to do with " << itemName << "?" << endl;
                    cout << "1. Use Item." << endl;
                    cout << "2. Drop Item." << endl;
                    cout << "3. Go Back" << endl;
                    cin >> playerInventoryInput2;
                    switch(playerInventoryInput2)
                    {
                        case 1:
                        {
                            cout << "Using " << itemName << "." << endl;
                            if(playerInventory[playerInventoryInput - 1].getItemType() == 1)
                            {
                                playerInventory.erase(playerInventory.begin() + playerInventoryInput);
                                playerInventoryInput2 = 3;
                            }
                            else if(playerInventory[playerInventoryInput - 1].getItemType() == 2)
                            {
                                playerInventory.erase(playerInventory.begin() + playerInventoryInput);
                                playerInventoryInput2 = 3;
                            }
                            else if(playerInventory[playerInventoryInput - 1].getItemType() == 3)
                            {
                                playerInventory.erase(playerInventory.begin() + playerInventoryInput);
                                playerInventoryInput2 = 3;
                            }
                            else if(playerInventory[playerInventoryInput - 1].getItemType() == 4)
                            {
                                if(playerHealth < 100 && playerHealth > 75)
                                {
                                    playerHealth = 100;
                                    numItems--;
                                    playerInventory.erase(playerInventory.begin() + playerInventoryInput);
                                    cout << "Used healing syringe, your health is now full." << endl;
                                    playerInventoryInput2 = 3;
                                }
                                else if(playerHealth < 76 && playerHealth > 0)
                                {
                                    playerHealth += 25;
                                    numItems--;
                                    playerInventory.erase(playerInventory.begin() + playerInventoryInput);
                                    playerInventoryInput2 = 3;
                                    cout << "Used healing syringe, your health is now at " << playerHealth << " HP." << endl;
                                }
                                else if (playerHealth == 100)
                                {
                                    cout << "Health is full, cannot use healing syringe" << endl;
                                    playerInventoryInput2 = 3;
                                }                                     
                            }
                            else if(playerInventory[playerInventoryInput - 1].getItemType() == 5)
                            {
                                cout << "Can only use this item in combat." << endl;
                                playerInventoryInput2 = 3;
                            }
                            break;
                        }
                        case 2:
                        {
                            playerInventory.erase(playerInventory.begin() + playerInventoryInput);
                            numItems--;
                            cout << "Dropped " << itemName << endl;
                            playerInventoryInput2 = 3;
                            break;
                        }
                        case 3: 
                        {
                            cout << "Returning to previous menu." << endl;
                            break;
                        }
                        default:
                        {
                            cout << "Invalid input, please choose another option." << endl;
                            break;
                        }
                    } 
                }
            }
        }   
    }
}
void Player::checkPlayerWeapons()
{
    
    int playerWeaponInput = 0;
    while(playerWeaponInput != 4)
    {
        int weaponNumber = 1;
        cout << "1: Pistol" << endl;
        cout << "2: Shotgun" << endl;
        cout << "3: Rifle" << endl;
        cout << "4: Go Back" << endl;
        cout << "Choose weapon: " << endl;
        cin >> playerWeaponInput;
        if(playerWeaponInput < 1 && playerWeaponInput > 4)
        {
            cout << "Invalid input. Try Again." << endl;
        }
        if(playerWeaponInput == 4)
        {
            cout << "Returning to primary menu." << endl;
        }
        else
        {
            int playerWeaponInput2 = 0;
            while(playerWeaponInput2 != 2)
            {
                cout << "Current ammo: " << playerWeapons[playerWeaponInput - 1].getWeaponAmmo() << "/" << playerWeapons[playerWeaponInput - 1].getMaxAmmo() << endl; 
                cout << "Would you like to reload " << playerWeapons[playerWeaponInput - 1].getWeaponName() << "?" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cin >> playerWeaponInput2;
                if(playerWeaponInput2 < 1 || playerWeaponInput2 > 2)
                {
                    cout << "Invalid option, choose another option" << endl;
                }
                else if(playerWeapons[playerWeaponInput - 1].getWeaponAmmo() == playerWeapons[playerWeaponInput - 1].getMaxAmmo())
                { 
                    cout << "This weapon is already full" << endl;
                    playerWeaponInput2 = 2;
                }
                else if(playerInventory.empty())
                {
                    cout << "Your inventory is empty" << endl;
                }
                else if(playerWeaponInput2 == 1)
                {
                    int currentWeaponAmmoType = playerWeapons[playerWeaponInput - 1].getAmmoType();
                    bool hasMoreAmmo = false;
                    for(int x = 0; x < playerInvSize; x++)
                    {
                        if(playerInventory[x].getItemType() == currentWeaponAmmoType)
                        {
                            hasMoreAmmo = true;
                        }
                    }
                    if(hasMoreAmmo == true)
                    {
                        playerWeapons[playerWeaponInput - 1].reloadWeapon();
                        for(int x = 0; x < playerInvSize; x++)
                        {
                            if(playerInventory[x].getItemType() == currentWeaponAmmoType)
                            {
                                playerInventory.erase(playerInventory.begin() + x);
                            }
                        }
                        cout << "Reloaded " << playerWeapons[playerWeaponInput - 1].getWeaponName() << "." << endl;
                    }
                    else
                    {
                        cout << "You do not have any more ammo for this weapon." << endl;
                    }
                    playerWeaponInput2 = 2;
                }
                else if(playerWeaponInput2 == 2)
                {
                    cout << "Returning to previous menu." << endl;
                }
                else if(playerWeaponInput2 > 3 || playerWeaponInput2 < 1)
                {
                    cout << "Invalid input, choose another option." << endl;
                }
            }
        }
    }
}
void Player::battle(Zombie encounteredZombie)
{
    bool escapedZombie = false;
    while ((playerHealth > 0 && encounteredZombie.getHealth() > 0) || escapedZombie != true)
    {
        int stunGrenadeNum = 0;
        int syringeNum = 0;
        int playerBattleInput = 0;
        cout << "You have encountered a zombie!" << endl;
        cout << endl;
        cout << "Current Player Health: " << playerHealth << " HP" << endl;
        cout << "Current Pistol Ammo: " << playerWeapons[0].getWeaponAmmo() << "/" << playerWeapons[0].getMaxAmmo() << endl;
        cout << "Current Shotgun Ammo: " << playerWeapons[1].getWeaponAmmo() << "/" << playerWeapons[1].getMaxAmmo() << endl;
        cout << "Current Rifle Ammo: " << playerWeapons[2].getWeaponAmmo() << "/" << playerWeapons[2].getMaxAmmo() << endl;
        for(int x = 0; x < playerInventory.size(); x++)
        {
            if(playerInventory[x].getItemType() == 5)
            {
                stunGrenadeNum++;
            }
            else if(playerInventory[x].getItemType() == 4)
            {
                syringeNum++;
            }
        }
        cout << "Amount of stun grenades: " << stunGrenadeNum << endl;
        cout << "Amount of healing syringes: " << syringeNum << endl;
        cout << endl;
        cout << "Current Zombie Health: " << encounteredZombie.getHealth() << " HP" << endl;
        cout << endl;
        cout << "What are you going to do?" << endl;
        cout << "1: Use Weapon" << endl;
        cout << "2: Reload Weapon" << endl;
        cout << "3: Use Healing Item" << endl;
        cout << "4: Run" << endl;
        cin >> playerBattleInput;
        switch(playerBattleInput)
        {
            case 1:
            {
                int playerWeaponInput = 0;
                while(playerWeaponInput != 4)
                {
                    stunGrenadeNum = 0;
                    cout << "Current Player Health: " << playerHealth << " HP" << endl;
                    cout << "Current Pistol Ammo: " << playerWeapons[0].getWeaponAmmo() << "/" << playerWeapons[0].getMaxAmmo() << endl;
                    cout << "Current Shotgun Ammo: " << playerWeapons[1].getWeaponAmmo() << "/" << playerWeapons[1].getMaxAmmo() << endl;
                    cout << "Current Rifle Ammo: " << playerWeapons[2].getWeaponAmmo() << "/" << playerWeapons[2].getMaxAmmo() << endl;
                    for(int x = 0; x < playerInventory.size(); x++)
                    {
                        if(playerInventory[x].getItemType() == 5)
                        {
                            stunGrenadeNum++;
                        }
                    }
                    cout << "Amount of stun grenades: " << stunGrenadeNum;
                    cout << endl;
                    cout << "Current Zombie Health: " << encounteredZombie.getHealth() << " HP" << endl;
                    cout << endl;
                    cout << "Which Weapon are you going to choose? " << endl;
                    cout << "1: Pistol" << endl;
                    cout << "2: Shotgun" << endl;
                    cout << "3: Rifle" << endl;
                    cout << "4: Go Back" << endl;
                    cout << "Choose weapon: " << endl;
                    cin >> playerWeaponInput;
                    switch(playerWeaponInput)
                    {
                        case 1:
                        {
                            if(playerWeapons[0].getWeaponAmmo() == 0)
                            {
                                cout << "You are out of ammo and must reload." << endl;
                                break;
                            }
                            else if(encounteredZombie.getHealth() > 0)
                            {
                                playerWeapons[0].setWeaponAmmo(playerWeapons[0].getWeaponAmmo() - 1);
                                srand(time(0));
                                int hitPercentage = rand() % 100 + 1;
                                if(hitPercentage > 35)
                                {
                                    cout << "The shot hit, the zombie has taken 10 HP of damage." << endl;
                                    encounteredZombie.setHealth(encounteredZombie.getHealth() - 10);
                                }
                                else
                                {
                                    cout << "You missed the zombie." << endl;  
                                }
                                if(encounteredZombie.getHealth() > 0)
                                {
                                    hitPercentage = rand() % 100 + 1;
                                    if(hitPercentage > 25)
                                    {
                                        cout << "The Zombie bit you and you lost " << encounteredZombie.getDamage() << " HP" << endl;
                                        playerHealth = playerHealth - encounteredZombie.getDamage();
                                    }
                                }
                                else
                                {
                                    cout << "The Zombie has be neutralized, Battle sequence is over." << endl;
                                    return;
                                }
                            }
                            else
                            {
                                cout << "The Zombie has be neutralized, Battle sequence is over." << endl;
                                return;
                            }  
                            break;  
                        }
                        case 2:
                        {
                            if(playerWeapons[1].getWeaponAmmo() == 0)
                            {
                                cout << "You are out of ammo and must reload." << endl;
                                break;
                            }
                            else if(encounteredZombie.getHealth() > 0)
                            {
                                playerWeapons[1].setWeaponAmmo(playerWeapons[1].getWeaponAmmo() - 1);
                                srand(time(0));
                                int hitPercentage = rand() % 100 + 1;
                                if(hitPercentage > 5)
                                {
                                    cout << "The shot hit, the Zombie has taken 15 HP of damage." << endl;
                                    encounteredZombie.setHealth(encounteredZombie.getHealth() - 15);
                                }
                                else
                                {
                                    cout << "You missed the zombie." << endl;  
                                }
                                if(encounteredZombie.getHealth() > 0)
                                {
                                    hitPercentage = rand() % 100 + 1;
                                    if(hitPercentage > 25)
                                    {
                                        cout << "The Zombie bit you and you lost " << encounteredZombie.getDamage() << " HP" << endl;
                                        playerHealth = playerHealth - encounteredZombie.getDamage();
                                    }
                                }
                                else
                                {
                                    cout << "The Zombie has be neutralized, Battle sequence is over." << endl;
                                    return;
                                }
                            }
                            else
                            {
                                cout << "The Zombie has be neutralized, Battle sequence is over." << endl;
                                return;
                            }
                            break;    
                        }
                        case 3:
                        {
                            if(playerWeapons[2].getWeaponAmmo() == 0)
                            {
                                cout << "You are out of ammo and must reload." << endl;
                                break;
                            }
                            else if(encounteredZombie.getHealth() > 0)
                            {
                                playerWeapons[2].setWeaponAmmo(playerWeapons[2].getWeaponAmmo() - 1);
                                srand(time(0));
                                int hitPercentage = rand() % 100 + 1;
                                if(hitPercentage > 50)
                                {
                                    cout << "The shot hit, the Zombie has taken 20 HP of damage." << endl;
                                    encounteredZombie.setHealth(encounteredZombie.getHealth() - 20);
                                }
                                else
                                {
                                    cout << "You missed the zombie." << endl;  
                                }
                                if(encounteredZombie.getHealth() > 0)
                                {
                                    hitPercentage = rand() % 100 + 1;
                                    if(hitPercentage > 25)
                                    {
                                        cout << "The Zombie bit you and you lost " << encounteredZombie.getDamage() << " HP" << endl;
                                        playerHealth = playerHealth - encounteredZombie.getDamage();
                                    }
                                }
                                else
                                {
                                    cout << "The Zombie has be neutralized, Battle sequence is over." << endl;
                                    return;
                                }
                            }
                            else
                            {
                                cout << "The Zombie has be neutralized, Battle sequence is over." << endl;
                                return;
                            }
                            break;    
                        }
                        case 4:
                        {
                            cout << "Returning to Previous Menu" << endl;
                            break;
                        }
                        default:
                        {
                            cout << "Invalid Input, please choose something else." << endl; 
                        }
                    }
                }
                break;
            }
            case 2:
            {
                int playerReloadInput;
                while(playerReloadInput != 4)
                {
                    cout << "Which weapon would you like to reload?" << endl;
                    cout << "1. Pistol -  " << playerWeapons[0].getWeaponAmmo() << "/" << playerWeapons[0].getMaxAmmo() << endl;
                    cout << "2. Shotgun -  " << playerWeapons[1].getWeaponAmmo() << "/" << playerWeapons[1].getMaxAmmo() << endl;
                    cout << "3. Rifle -  " << playerWeapons[2].getWeaponAmmo() << "/" << playerWeapons[2].getMaxAmmo() << endl;
                    cout << "4. Go Back" << endl;
                    cin >> playerReloadInput;
                    if(playerReloadInput > 4 || playerReloadInput < 1)
                    {
                        cout << "Invalid Input, please try again" << endl;
                    }
                    else if(playerReloadInput == 4)
                    {
                        break;
                    }
                    else
                    {
                        int currentWeaponAmmoType = playerWeapons[playerReloadInput - 1].getAmmoType();
                        bool hasMoreAmmo = false;
                        for(int x = 0; x < playerInvSize; x++)
                        {
                            if(playerInventory[x].getItemType() == currentWeaponAmmoType)
                            {
                                hasMoreAmmo = true;
                            }
                        }
                        if(hasMoreAmmo == true)
                        {
                            playerWeapons[playerReloadInput - 1].reloadWeapon();
                            for(int x = 0; x < playerInvSize; x++)
                            {
                                if(playerInventory[x].getItemType() == currentWeaponAmmoType)
                                {
                                    playerInventory.erase(playerInventory.begin() + x);
                                }
                            }
                            cout << "Reloaded " << playerWeapons[playerReloadInput - 1].getWeaponName() << "." << endl;
                        }
                        else
                        {
                            cout << "You do not have any more ammo for this weapon." << endl;
                        }
                    }
                }
                break;
            }
            case 3:
            {
                if(syringeNum <= 0)
                {
                    cout << "You are out of healing syringes and cannot heal yourself." << endl;
                    break;
                }
                else
                {
                    int syringeIndex;
                    for(int x = 0; x < playerInventory.size(); x++)
                    {
                        if(playerInventory[x].getItemType() == 4);
                        {
                            syringeIndex = x;
                            break;
                        }
                    }
                    if(playerHealth < 100 && playerHealth > 75)
                    {
                        playerHealth = 100;
                        numItems--;
                        playerInventory.erase(playerInventory.begin() + syringeIndex);
                        cout << "Used healing syringe, your health is now full." << endl;
                    }
                    else if(playerHealth < 76 && playerHealth > 0)
                    {
                        playerHealth += 25;
                        numItems--;
                        playerInventory.erase(playerInventory.begin() - syringeIndex);
                        cout << "Used healing syringe, your health is now at " << playerHealth << " HP." << endl;
                    }
                    else if (playerHealth == 100)
                    {
                        cout << "Health is full, cannot use healing syringe" << endl;
                    }
                }
                break;
            }
            case 4:
            {
                int runInput;
                while(runInput != 1 && runInput != 2 && runInput != 3)
                {
                    cout << "Attempting to run. Do you want to throw a stun grenade to eliminate the large possibility of taking damage?" << endl;
                    cout << "1. Yes." << endl;
                    cout << "2. No." << endl;
                    cout << "3. Don't run, continue fighting." << endl;
                    cin >> runInput;
                    switch(runInput)
                    {
                        case 1:
                        {
                            int flashGrenadeIndex;
                            for(int x = 0; x < playerInventory.size(); x++)
                            {
                                if(playerInventory[x].getItemType() == 4);
                                {
                                    flashGrenadeIndex = x;
                                    break;
                                }
                            }
                            numItems--;
                            playerInventory.erase(playerInventory.begin() + flashGrenadeIndex);
                            cout << "You used a flash grenade and escaped the zombie risk free." << endl;
                            escapedZombie = true;
                            playerStamina = playerStamina - 5;
                            break;
                        }
                        case 2:
                        {
                            srand(time(0));
                            int escapedUnharmed =  rand() % 100 + 1;
                            if (escapedUnharmed > 25)
                            {
                                playerHealth = playerHealth - encounteredZombie.getDamage();
                                cout << "You escaped but unfortunately took " << encounteredZombie.getDamage() << " HP of damage in the process" << endl;
                                escapedZombie = true;
                                playerStamina = playerStamina - 5;
                                break;
                            }
                            else
                            {
                                cout << "Despite the high risk of not using a stun grenade, you managed to escape the zombie without losing damage." << endl;
                                escapedZombie = true;
                                playerStamina = playerStamina - 5;
                                break;
                            }
                        }
                        case 3:
                        {
                            escapedZombie = false;
                            cout << "Returning to previous menu." << endl;
                            break;
                        }  
                    }
                }
            }
            default:
            {
                cout << "Invalid input, please input a valid input." << endl;
            }
        }
    }
}