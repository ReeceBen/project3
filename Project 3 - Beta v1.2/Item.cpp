//CSCI 1300 
//Authors: Reece Benson, Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Item.h"
using namespace std;

Item::Item()
{
    name = "";
    type = 0;
    amount = 0;
}
Item::Item(int itType, int itAmount)
{
    amount = itAmount;
    type = itType;
    if(type == 1)
    {
        name = "Pistol Magazine";
    }
    else if(type == 2)
    {
        name = "Box of 6 Shotgun Shells";
    }
    else if(type == 3)
    {
        name = "Rifle Magazine";
    }
    else if(type == 4)
    {
        name = "Healing Syringe";
    }
    else if (type == 5)
    {
        name = "Stun Grenade";
    }
}
string Item::getItemName()
{
    return name;
}
void Item::setItemName(string itName)
{
    name = itName;
}
int Item::getItemType()
{
    return type;
}
void Item::setItemType(int itType)
{
    type = itType;
}
int Item::getItemAmount()
{
    return amount;
}
void Item::setItemAmount(int itAmount)
{
    amount = itAmount;
}