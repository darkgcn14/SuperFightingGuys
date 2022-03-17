//
// Created by BE123 on 11/15/2018.
//

#ifndef NEW_FOLDER_PLAYER_H
#define NEW_FOLDER_PLAYER_H
#include <string>
#include <map>


using namespace std;

struct effect {
  effect(string aType, int aDmg, int aDuration)
    : type(aType),
      dmg(aDmg),
      duration(aDuration),
      id(-1) { }

  string type;
  int dmg;
  int duration;
  int id;
};

class Player {
protected:
  string name = "";
  int strength = 0;
  int intelligence = 0;
  int health = 0;
  int resource = 0;
  string resourceName = "";
  string weapon = "";
  int weaponRnd = 0;
  int weaponMin = 0;
  int armor = 0;
  int potion = 1;
  int effectCounter = 0;
  //int defense = 0;
  map<int, effect*> effects;
  int takeDamageImpl(int dmg, Player& attacker);
  virtual int getDebuffDamage(bool simulate);
  virtual int getBaseDamage(int dmg, Player& attacker, bool simulate);
  virtual void applyDamageReduction(int& dmg);
  virtual void applyEffect(effect* e, int& dmg, bool simulate);

public:
  Player();
  string getName();
  void displayStatus();
  virtual bool isAlive();
  virtual bool attack(Player& target);                     // making this virtual causes the subclass function to be called first
  virtual bool takeDamage(int dmg, Player& attacker);                        
  virtual bool specialAbility(Player& target) = 0;
  virtual void takePotion(Player& current);
  virtual void defenseAbility(Player& current) = 0;
  virtual void defenseAbility2(Player& target) = 0;
  virtual void addEffect(effect* e);
};


#endif