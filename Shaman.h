//
// Created by BE123 on 11/20/2018.
//

#ifndef SHAMAN_H
#define SHAMAN_H

#include "Player.h"
#include <iostream>

using namespace std;

class Shaman : public Player {
private:

public:
  Shaman(string n);
  bool specialAbility(Player& target);
  bool takeDamage(int dmg, Player& attacker);
  void defenseAbility(Player& current);
  void defenseAbility2(Player& target);
};


#endif