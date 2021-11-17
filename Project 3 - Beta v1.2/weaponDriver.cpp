//CSCI 1300 
//Authors: Reece Benson, Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Weapon.h"
#include "Weapon.cpp"
using namespace std;



int main(){

    //Weapon blackHammer;
    Weapon blackHammer("Thorn", 69, "primary", 53, 420);

    blackHammer.setWeaponName("Ash Factory");
    blackHammer.setWeaponDamage(355);
    blackHammer.setAmmoType("heavy ammo");
    blackHammer.setWeaponAmmo(3);
    blackHammer.setMaxAmmo(8);

    cout << "weapon name: " << blackHammer.getWeaponName() << endl;
    cout << "weapon damage: " << blackHammer.getWeaponDamage() << endl;
    cout << "weapon ammo type: " << blackHammer.getAmmoType() << endl;
    cout << "weapon ammo: " << blackHammer.getWeaponAmmo() << endl;
    cout << "max ammo: " << blackHammer.getMaxAmmo() << endl;

    blackHammer.useWeapon();
    blackHammer.reloadWeapon();
    

    return 0;
}