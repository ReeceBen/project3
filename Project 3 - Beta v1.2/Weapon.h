//CSCI 1300 
//Authors: Reece Benson, Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class



/*

weapons class

algorithem:

data members: 

Weapon Name
Weapon Damage
Ammo Type
Weapon Ammo
Ammo Max



Member functions:

getters and setters
Get Weapon Name
Set Weapon Name
Get Weapon Damage
Set Weapon Damage
Get Weapon Ammo Type
Set Weapon Ammo Type
Get Weapon Ammo Amount
Set Weapon Ammo Amount
Get Weapon Ammo Max
Set Weapon Ammo Max

Use Weapon
    Applies a damage effect on the zombie it is being used on, 
    reducing HP by using the set health to be less than the get health by the equivalent damage value
    *Requires creation of Zombie Class


Reload Weapon
    Reduces the amount of ammo type in the player inventory using the player get 
    and set item number functions and reducing the ammo amount by 1 and refilling 
    the ammo type to the max for the weapon




*/
//pre proscessor
#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std; 





//weapons class

// algorithem:
class Weapon{
    // data members: 

    
    public:

    //default constructors
    Weapon();
    Weapon(string, int, int, int, int);

    //getters & setters

    // Weapon Name
    string getWeaponName();
    void setWeaponName(string);
    // Weapon Damage
    int getWeaponDamage();
    void setWeaponDamage(int);
    // Ammo Type
    int getAmmoType();
    void setAmmoType(int);
    // Weapon Ammo
    int getWeaponAmmo();
    void setWeaponAmmo(int);
    // Ammo Max
    int getMaxAmmo();
    void setMaxAmmo(int);


    //other

    // Use Weapon
    void useWeapon();
    //     Applies a damage effect on the zombie it is being used on, 
    //     reducing HP by using the set health to be less than the get health by the equivalent damage value
    //     *Requires creation of Zombie Class


    // Reload Weapon
    void reloadWeapon();
    //     Reduces the amount of ammo type in the player inventory using the player get 
    //     and set item number functions and reducing the ammo amount by 1 and refilling 
    //     the ammo type to the max for the weapon
    
    private:
    string weaponName;
    int weaponDamage;
    int ammoType;
    int weaponAmmo;
    int maxAmmo;
};

#endif