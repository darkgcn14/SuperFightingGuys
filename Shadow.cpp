#include "Shadow.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

Shadow::Shadow(string n){
  name = n;
  strength = 6;
  intelligence = 12;
  health = 100;
  resource = 10;
  resourceName = "Shadow Magic";
  weapon = "Knife";
  weaponRnd = 6;
  weaponMin = 11;
  armor = 2;
}

bool Shadow::specialAbility(Player& target) {

  if (resource >= 30) {
    int dmg = ((rand() % 10) + weaponMin + strength + intelligence - 4);

    if (dmg == 25){
        cout << "You dealt the minimum damage.\n\n";
      }
      else if (dmg == 34){
        cout << "This is a maximum damage attack, good job.\n\n";
      }

    cout << name << " Calls upon the shadows and strikes twice with their " << weapon << " and does " << dmg << " points of damage to " << target.getName() << "." << endl << endl;
    resource -= 30;
      

    return target.takeDamage(dmg, *this);
  }
  else {
    cout << "The shadows have abandoned you, try again when you are stronger.\n\n";

    return false;
  }
}    

bool Shadow::attack(Player& target) {
  return Player::attack(target);
}

void Shadow::applyDamageReduction(int& dmg) {
  // Direct Attack
  int dodge = (rand() % 3);
  bool dodgeSuccess = dodge > 1;

  
  if (dodge100 == 1){
    dodgeSuccess = 1;
  }

  else if (dodge100 == 0){
    dodgeSuccess = dodge > 1;
  }
  
  
  if (dmg - armor > 0 && !dodgeSuccess) {
    dmg -= armor;
    resource += 15;
    cout << this->name << "'s armor has blocked " << armor << " points of damage.\n\n";
  }
  else if (dmg - armor > 0 && dodgeSuccess && resource >= 10) {
    dmg = 0;
    resource -= 10;
    cout << this->name << " dodges the attack and receives 0 damage." << endl << endl;
  }
  else if (dmg-armor > 0 && dodgeSuccess && resource < 10) {
    cout << this->name << " would have dodged this attack but magic was too low, that's too bad.\n\n";
    dmg -= armor;
    resource += 15;
  }
  else if (dmg - armor <= 0 && !dodgeSuccess) {
    dmg = 1;
    resource += 15;
  }
  else if (dmg - armor <= 0 && dodgeSuccess && resource >= 10) {
    dmg = 0;
    resource -= 10;
    cout << this->name << " dodges the attack and receives 0 damage." << endl << endl;
  }
  else if (dmg-armor <= 0 && dodgeSuccess && resource < 10) {
    cout << this->name << " would have dodged this attack but magic was too low, that's too bad.\n\n";
    dmg -=armor;
    resource += 15;
  }

}

bool Shadow::takeDamage(int dmg, Player& attacker) {

  return Player::takeDamage(dmg, attacker);
}


void Shadow::defenseAbility(Player& current){
  health -= 8;
  resource -= 10;
  cout << "you should dodge the next attack assuming you're pro " << resourceName << ".\n\n";
  cout << name << " || Health: " << health << " Potions: " << potion << " " 
    << resourceName << ": " << resource << "\n\nEnter a new command:\n";
}


//void Shadow::defenseAbility(Player& current){
//}

void Shadow::defenseAbility2(Player& target){
}

/*
inline bool Shadow::defenseAbility3(Player& current){
  health -= 8;
  resource -= 10;
  dodge100 = 1;
  cout << "you should dodge the next attack assuming you're pro " << resourceName << ".\n\n";
  cout << name << " || Health: " << health << " Potions: " << potion << " " 
    << resourceName << ": " << resource << "\n\nEnter a new command:\n";
}
*/