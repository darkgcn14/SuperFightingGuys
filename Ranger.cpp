//
// Created by BE123 on 11/20/2018.
//

#include "Ranger.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

Ranger::Ranger(string n){
  name = n;
  strength = 8;
  intelligence = 10;
  health = 100;
  resource = 20;
  resourceName = "Stamina";
  weapon = "Bow";
  maxStamina = 40;
  weaponRnd = 9;
  weaponMin = 11;
  armor = 5;
}

bool Ranger::specialAbility(Player& target){
  if (resource >= 20) {
    int random = (rand() % 15);
          if (random == 0){
        cout << "You fail to pull the bow back all the way cause you are weak, this attack does the minimum damage.\n\n";
        }
        else if (random == 14){
          cout << "The winds are with you and your attack does the maximum damage.\n\n";
        }
    int dmg = random + intelligence + strength + 13;
    cout << name << " uses Powered Shot and deals " << dmg << " points of damage.\n\n";
    resource -= 20;

    return target.takeDamage(dmg, *this);
  }
  else {
    cout << "You don't have the energy to pull back your bow and must rest.\n\n";

    return false;
  }
}

bool Ranger::attack(Player& target) {
  resource += 10;
  if (resource > maxStamina){ //sets a maximum to the amount of mana you can have
    resource = maxStamina;
  }
  return Player::attack(target); // This system just calls the attack function from player.cpp
}

void Ranger::takePotion(Player& current){
  resource += 10;
  if (resource > maxStamina){ //sets a maximum to the amount of mana you can have
    resource = maxStamina;
  }

  return Player::takePotion(current);
}

bool Ranger::takeDamage(int dmg, Player& attacker) {
  if (resource == 0){
    dmg = dmg * 2;
    cout << name << " is too tired and receives double damage.\n\n";
  }
  else {
    dmg = dmg;
  }
  
  return Player::takeDamage(dmg, attacker);   
}

void Ranger::defenseAbility(Player& current){
  resource += 20;
  cout << "you gain 20 " << resourceName << ".\n\n";

  cout << name << " || Health: " << health << " Potions: " << potion << " " 
    << resourceName << ": " << resource << "\n\nEnter a new command:\n";
}

void Ranger::defenseAbility2(Player& target){
}