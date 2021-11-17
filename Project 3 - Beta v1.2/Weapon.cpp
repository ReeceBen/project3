//CSCI 1300 
//Authors: Reece Benson, Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class


#include <iomanip>
#include <fstream>
#include <cstring>


#include <array>
#include <iostream>
#include "Weapon.h"

using namespace std;


//default constructor
Weapon::Weapon(){
    weaponName = "default name";
    weaponDamage = 0;
    ammoType = 1;
    weaponAmmo = 0;
    maxAmmo = 69;
}
//paramaterized constructor
Weapon::Weapon(string wn, int wd, int at, int wa, int ma){
    weaponName = wn;
    weaponDamage = wd;
    ammoType = at;
    weaponAmmo = wa;
    maxAmmo = ma;
}


//getters & setters

// Weapon Name
string Weapon::getWeaponName(){
    return weaponName;
}
void Weapon::setWeaponName(string wn){
    weaponName = wn;
}
// Weapon Damage
int Weapon::getWeaponDamage(){
    return weaponDamage;
}
void Weapon::setWeaponDamage(int wd){
    weaponDamage = wd;
}
// Ammo Type
int Weapon::getAmmoType(){
    return ammoType;
}
void Weapon::setAmmoType(int at){
    ammoType = at;
}
// Weapon Ammo
int Weapon::getWeaponAmmo(){
    return weaponAmmo;
}
void Weapon::setWeaponAmmo(int wa){
    weaponAmmo = wa;
}
// Ammo Max
int Weapon::getMaxAmmo(){
    return maxAmmo;
}
void Weapon::setMaxAmmo(int ma){
    maxAmmo = ma;
}


// Use Weapon
//     Applies a damage effect on the zombie it is being used on, 
//     reducing HP by using the set health to be less than the get health by the equivalent damage value
//     *Requires creation of Zombie Class
void Weapon::useWeapon(){
    cout << "awww yea were using this weapon like nobody's buisness" << endl;
}



// Reload Weapon
//     Reduces the amount of ammo type in the player inventory using the player get 
//     and set item number functions and reducing the ammo amount by 1 and refilling 
//     the ammo type to the max for the weapon
void Weapon::reloadWeapon(){
    cout << "yardy know were reloading tf out of this weapon right here" << endl;
}





