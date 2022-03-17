//
// Created by BE123 on 11/15/2018.
//

#include "Player.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

static string lines[] = {
  "%3$s dealt %2$d damage to %1$s.\n\n",
  "Blah blah blah, %3$s damaged %1$s for %2$d.\n\n",
  "%3$s 360 no-scoped %1$s for %2$d damage.\n\n"
};

Player::Player(){
  name = "";
  strength = 0;
  intelligence = 0;
  health = 0;
  resource = 0;
  resourceName = "";
  weapon = "";
  weaponRnd = 0;
  weaponMin = 0;
  armor = 0;
  potion = 1;
  //defense = 0;
}

void Player::displayStatus(){
  cout << name << " || Health: " << health << " Potions: " << potion << " " << resourceName << ": " << resource << 
  //" Defense Abilities: " << defense << 
  endl;
}

bool Player::attack(Player& target) {
  int random = (rand() % weaponRnd);
  int dmg = random + weaponMin + strength;
  if (random == 0) {
    cout << "Your attack is incredibly weak and does the minimum damage.\n\n";
  }
  else if (random == (weaponRnd - 1)) {
    cout << "You max rolled like a boss and dealt as much damage as possible.\n\n";
  }
  cout << name << " attacks " << target.name << " with his " << weapon << " and does " << dmg << " points of damage.\n\n";

  return target.takeDamage(dmg, *this);
}

// Effects

void Player::addEffect(effect* e) {
  e->id = effectCounter;
  effects.insert(pair<int, effect*>(effectCounter, e));
  effectCounter++;
}

void Player::applyEffect(effect* e, int& dmg, bool simulate) {
  if (e->type == "hex") {
    dmg += e->dmg;

    if (!simulate) {
      cout << name << " takes " << e->dmg << " points of damage from a hex.\n\n";
      e->duration--;
    }

    //cout << "CHECKING HEX #" << e->id << " - duration: " << e->duration << endl << endl;
    if (!simulate && e->duration <= 0) {
      //cout << ">>>>>>>>>>>>>>>>>>>>attempting to delete effect #" << e->id << endl << endl;
      effects.erase(e->id); //cycles through all the effects and disables them as they expire
    }
  }
  else if (e->type == "fire") {
    dmg += e->dmg;

    if (!simulate) {
      cout << name << " takes " << e->dmg << " points of damage from fire.\n\n";
      e->duration--;
    }

    if (!simulate && e->duration <= 0) {
      effects.erase(e->id); //cycles through all the effects and disables them as they expire
    }
  }
  else if (e->type == "heal") {
    if (!simulate) {
      health += e->dmg;
      cout << name << " receives healing from the life spirits for " << e->dmg << " points of health.\n\n";
    }

    e->duration--;
    if (!simulate && e->duration <= 0) {
      effects.erase(e->id); //cycles through all the effects and disables them as they expire
    }
  }
  else if (e->type == "armor") {
    if (!simulate) {
      int armor2 = 8;
      armor = armor2 + e->dmg;
      cout << this->name << " has 4 additional armor from enchantment.\n\n";
    }

    e->duration--;
    if (!simulate && e->duration <= 0) {
      effects.erase(e->id);
      cout << this->name << "'s armor is no longer enchanted.\n\n";
      armor = armor - e->dmg;
    }
  }
  else if (e->type == "lifeSteal"){
    if (!simulate) {
      health += e->dmg;
    }
    e->duration--;
    if (!simulate && e->duration <= 0) {
      effects.erase(e->id);
    }
  }
  else if (e->type == "lifeSteal2"){  
    if (!simulate) {
      dmg += e->dmg;
    }
    e->duration--;
    if (!simulate && e->duration <= 0) {
      effects.erase(e->id);
    }
  }
  else if (e->type == "freeResource"){
    if (!simulate) {
      int chance = (rand() % 3);

      cout << endl << endl;
      cout << chance << endl << endl;
      
      if (chance <= 1){
        cout << "Your call to the spirits has been unanswered this turn.\n\n";
      }
      else if (chance == 2){
        resource += e->dmg;
        cout << "The spirits have answered your call this turn and have granted 30 Spirit Energy\n\n";
      }
    }
    e->duration--;
    if (!simulate && e->duration <= 0) {
      effects.erase(e->id);
      cout << this->name << "The spirits will no longer attempt to answer your calls\n\n";
    }
  }
}

int Player::getDebuffDamage(bool simulate) {
  int dmg = 0;

  for (pair<int, effect*> element : effects) {
    applyEffect(element.second, dmg, simulate);
  }

  return dmg;
}

int Player::getBaseDamage(int dmg, Player& attacker, bool simulate) {
  return getDebuffDamage(simulate) + dmg;
}

void Player::applyDamageReduction(int& dmg) {
  if (dmg - armor > 0) {
    dmg -= armor;
    cout << this->name << "'s armor has blocked " << armor << " points of damage.\n\n";
  }
  else if (dmg - armor <= 0) {
    dmg = 1;
  }
}

// This returns the damage taken by the player
int Player::takeDamageImpl(int dmg, Player& attacker) {
  dmg = getBaseDamage(dmg, attacker, false);
  
  // Direct Attack
  applyDamageReduction(dmg);

  if (dmg == 1) {
    cout << this->name << " takes the minimum damage.\n\n";
  } else if (dmg > 0) {
    // Print a random line similar to "PlayerX dealt damage to PlayerY"
    int lineCount = sizeof(lines)/sizeof(string);
    string line = lines[rand() % lineCount];
    printf(line.c_str(), this->name.c_str(), dmg, attacker.name.c_str());
  }

  //cout << "Total damage received: " << dmg << endl << endl;
  health -= dmg;

  if (!isAlive()) {
    cout << name << " got rekt like a noob" << endl;
  }

  return dmg;
}

bool Player::takeDamage(int dmg, Player& attacker) {
  takeDamageImpl(dmg, attacker);
  // Return true if we should end the game
  return !isAlive();
}

string Player::getName() {
  return name;
}

bool Player::isAlive() {
  return health > 0;
}

void Player::takePotion(Player& current){
  if (potion >= 1 && health <= 60){
    health += 40;
    potion--;
    cout << name << " takes a health potion and heals for 40 HP." << endl << endl;
  }
  else if (potion >= 1 && health > 60 && health < 100){
    potion--;
    cout << name << " uses their health potion like a wanker and receives " << 100 - health << " HP." << endl << endl;
    health = 100;
  }
  else if (potion >= 1 && health == 100){
    potion--;
    cout << name << " takes their health potion and throws it on the ground like a boss. Nice." << endl << endl;
  }
  else if (potion < 1){
    cout << "You search your pockets for a health potion but none is available, your bumbling around gave your enemy time to attack." << endl << endl;
  }
}

