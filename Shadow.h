#ifndef SHADOW_H
#define SHADOW_H

#include "Player.h"
#include <iostream>

using namespace std;

class Shadow : public Player {
private:
  bool dodge100{};
protected:
  void applyDamageReduction(int& dmg);

public:
  Shadow(string n);
  bool specialAbility(Player& target);
  bool attack(Player& target);
  bool takeDamage(int dmg, Player& attacker);
  void defenseAbility(Player& current);
  void defenseAbility2(Player& target);
};


#endif