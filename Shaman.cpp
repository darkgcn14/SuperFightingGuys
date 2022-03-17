//
// Created by BE123 on 11/20/2018.
//

#include "Shaman.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

Shaman::Shaman(string n){
  name = n;
  strength = 3;
  intelligence = 14;
  health = 100;
  resource = 70;
  resourceName = "Spirit Energy";
  weapon = "Rain Stick";
  weaponRnd = 10;
  weaponMin = 8;
  armor = 0;
}

bool Shaman::specialAbility(Player& target){
  if (resource >= 30) {
    effect* e = new effect("hex", 10, 4);
    effect* h = new effect("heal", 4, 3);
    
    target.addEffect(e);
    addEffect(h);

    cout << name << " places a hex on " << target.getName() << ".\n\n";
    resource -= 30;

    return target.takeDamage(0, *this);
  }
  else {
    cout << "You call to the spirits and all you hear is a faint whisper saying \"git gud\".\n\n";

    return false;
  }
}

bool Shaman::takeDamage(int dmg, Player& attacker) {
  resource += 10;

  return Player::takeDamage(dmg, attacker);
}

void Shaman::defenseAbility(Player& current){
  if (resource >= 30){
    resource -= 30;
    effect* r = new effect("freeResource",30,3);
    addEffect(r);
    cout << "You call to the spirits for their aid, they will answer you for three turns, hope they find favor in you.\n\n" << name << " || Health: " << health << " Potions: " << potion << " " << resourceName << ": " << resource << "\n\n";
  }
  else {
    cout << "not enough " << resourceName << " try again when you have at least 30 " << resourceName << ".\n\n";
  }
  cout << name << " || Health: " << health << " Potions: " << potion << " " 
    << resourceName << ": " << resource << "\n\nEnter a new command:\n";
}


void Shaman::defenseAbility2(Player& target){ 
}
