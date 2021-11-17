//CSCI 1300 
//Authors: Reece Benson, Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class
/*
Algorithm:
Data Members:
Item Type
Item Number

Member Function:
Get item number
    Returns the number of a specific Item
Set item number
    Sets the number of a specific item
Get Item type
    Returns the type of a specific item
Set Item type
    Returns the type of a specific item
*/

//pre proscessor
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std; 

class Item
{
    public:
        Item();
        Item(int itType, int itAmount);
        string getItemName();
        void setItemName(string itName);
        int getItemType();
        void setItemType(int itType);
        int getItemAmount();
        void setItemAmount(int itAmount);
    private:
        int type;
        int amount;
        string name;
};


#endif