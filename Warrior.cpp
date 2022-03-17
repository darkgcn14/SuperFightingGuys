//
// Created by BE123 on 11/15/2018.
//

#include "Warrior.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

Warrior::Warrior(string n){
  name = n;
  strength = 12;
  intelligence = 0;
  health = 100;
  resource = 0;
  resourceName = "Rage";
  weapon = "Sword";
  weaponRnd = 12;
  weaponMin = 8;
  armor = 8;
  //defense = resource;
}
bool Warrior::specialAbility(Player& target){
  if (resource >= 40) {
    effect* f = new effect("fire", 5, 3);
    int dmg = (rand() % weaponRnd) + weaponMin + strength;

    if (dmg == 20){
      cout << "This attack does the minimum damage.\n\n";
    }
    else if (dmg == 31){
      cout << "this attack does the maximum damage.\n\n";
    }
    cout << name << " Uses their rage to light their " 
          << weapon << " ablaze and does " << dmg 
          << " points of damage to " << target.getName() 
          << endl << endl;

    target.addEffect(f);

    cout << name << " does fire damage to " 
         << target.getName() << ". " << endl << endl;
    resource -= 40;

    return target.takeDamage(dmg, *this);
  }
  else {
    cout << "You attempt to light your sword but do not have enough hate in your heart. Try again later.\n\n";

    return false;
  }
}

bool Warrior::attack(Player& target) {
  return Player::attack(target);
}

bool Warrior::takeDamage(int dmg, Player& attacker){
  int baseDmg = getBaseDamage(dmg, attacker, true);
  takeDamageImpl(dmg, attacker);
  int rageProduced = (baseDmg-armor) / 2;
  if (rageProduced <= 1){
    resource += 1;
  }
  else{
    resource += rageProduced;
  }
  return !isAlive();
}

void Warrior::defenseAbility(Player& current){
  if (resource >= 20){
    resource -= 20;
    effect* a = new effect("armor", 4, 6);
    addEffect(a);
    cout << this->name << " enchants their armor adding 4 additional armor.\n\n" << name << " || Health: " << health << " Potions: " << potion << " " << resourceName << ": " << resource << "\n\nEnter a new command:\n";
  
  }
  else {
    cout << "not enough rage try again when you have at least 20 rage.\n\nEnter another command.";
  }
}

void Warrior::defenseAbility2(Player& target){
}

