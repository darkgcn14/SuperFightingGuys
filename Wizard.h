//
// Created by BE123 on 11/15/2018.
//

#ifndef WIZARD_H
#define WIZARD_H

#include "Player.h"
#include <iostream>

using namespace std;

class Wizard : public Player {
private:
    int maxMana;

public:
    Wizard(string n);
    bool specialAbility(Player& target);
    bool attack(Player& target);
    bool takeDamage(int dmg, Player& attacker);
    bool specialAbility2(Player& target);
    void takePotion(Player& current);
    void defenseAbility(Player& current);
    void defenseAbility2(Player& target);
};


#endif