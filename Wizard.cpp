//
// Created by BE123 on 11/15/2018.
//

#include "Wizard.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

Wizard::Wizard(string n){
    name = n;
    strength = 1;
    intelligence = 22;
    health = 100;
    resource = 150;
    maxMana = 200;
    resourceName = "Mana";
    weapon = "Wand";
    weaponRnd = 7;
    weaponMin = 8;
    armor = 2;
}

bool Wizard::specialAbility(Player& target){
  if (resource >= 40) {
    int dmg = (rand() % 16) + intelligence + 5;
      if (dmg == 27){
        cout << "This attack does the minimum damage.\n\n";
      }
      else if (dmg == 42){
        cout << "This attack does the max damage.\n\n";
      }
    cout << name << " moves their wand like a weirdo and shoots lightning from the sky which does " << dmg << " points of damage to " << target.getName() << "\n\n";
    resource -= 40;

    return target.takeDamage(dmg, *this);
  }
  else {
    cout << "A puff of smoke emits from your wand which does nothing.\n\n";

    return false;
  }
}

/*void Wizard::applyEffect(effect e, int& dmg, bool simulate) {
  if (e.type == "fire") {
    effect.dmg = 0;
    effect.duration = 0;
  }

  Player::applyEffect(e, dmg, simulate);
}*/

bool Wizard::attack(Player& target) {
  resource += 30;
  if (resource > maxMana) { //sets a maximum to the amount of mana you can have
      resource = maxMana;
  }

  return Player::attack(target); // This system just calls the attack function from player.cpp
}

bool Wizard::takeDamage(int dmg, Player& attacker) {
  resource += 10;
  return Player::takeDamage(dmg, attacker);
}

//void Wizard::takePotion(Player& current) {
 // cout << "Would you like to restore"
//}
void Wizard::defenseAbility(Player& current){

  if (health <= 70 && resource >= 60){
    resource -= 60;
    health += 30;
    cout << "you use 60 " << resourceName << " and recover 30 HP. Your turn does not end.\n\n";
    
  }
  else if (resource < 60){
    cout << "you do not have enough mana to use this, do something else. Idiot.\n\n" << endl;
  }
  
  else if (health > 70 && resource >= 60){
    resource -= 60;
    health = 100;
    cout << name << " uses 60 " << resourceName << " and only heals for " << 100 - health << " because they used their ability like a nerd. Try again when below 70 HP next time.\n\n";
  }
  cout << name << " || Health: " << health << " Potions: " << potion << " " 
    << resourceName << ": " << resource << "\n\nEnter a new command:\n";
}

void Wizard::takePotion(Player& current){
  if (potion >= 1 && resource < 160){
    resource += 40;
    potion--;
    cout << name << " takes a mana potion and restores 40 mana." << endl << endl;
  }
  else if (potion >= 1 && resource > 160 && resource < 200){
    potion--;
    cout << name << " uses their mana potion like a wanker and receives " << 200 - resource << " mana." << endl << endl;
    resource = 200;
  }
  else if (potion >= 1 && resource == 200){
    potion--;
    cout << name << " takes their mana potion and throws it on the ground like a boss. Nice." << endl << endl;
  }
  else if (potion < 1){
    cout << "You search your pockets for a health potion but none is available, your bumbling around gave your enemy time to attack." << endl << endl;
  }
}

void Wizard::defenseAbility2(Player& target){
}

