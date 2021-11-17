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

int main()
{
    //Testing the constructors
    Item item1 = Item();
    Item item2 = Item(1, 2);
    cout << item1.getItemName() << endl;
    cout << item1.getItemAmount() << endl;
    cout << item1.getItemType() << endl;
    cout << endl;
    cout << item2.getItemName() << endl;
    cout << item2.getItemAmount() << endl;
    cout << item2.getItemType() << endl;
    cout << endl;
    //Testing getters and setters
    item1.setItemName("Rifle Magazine");
    item1.setItemAmount(4);
    item1.setItemType(3);
    cout << item1.getItemName() << endl;
    cout << item1.getItemAmount() << endl;
    cout << item1.getItemType() << endl;
}