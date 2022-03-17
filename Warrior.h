//
// Created by BE123 on 11/15/2018.
//

#ifndef WARRIOR_H
#define WARRIOR_H

#include "Player.h"
#include <iostream>

using namespace std;

class Warrior : public Player {
private:

public:
  Warrior(string n);
  bool specialAbility(Player& target);
  bool attack(Player& target);
  bool takeDamage(int dmg, Player& attacker);
  void defenseAbility(Player& current);
  void defenseAbility2(Player& target);
};


#endif 
