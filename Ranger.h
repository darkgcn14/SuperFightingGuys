//
// Created by BE123 on 11/20/2018.
//

#ifndef RANGER_H
#define RANGER_H

#include "Player.h"
#include <iostream>

using namespace std;

class Ranger: public Player {
private:
  int maxStamina;

public:
  Ranger(string n);
  bool specialAbility(Player& target);
  bool attack(Player& target);
  bool takeDamage(int dmg, Player& attacker);
  void takePotion(Player& current);
  void defenseAbility(Player& current);
  void defenseAbility2(Player& target);
};


#endif