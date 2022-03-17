/*

#include <iostream>
#include <string>
#include <ctime>
#include "Wizard.h"
#include <cstdlib>
#include "Player.h"
#include "Shaman.h"
#include "Ranger.h"
#include "Warrior.h"
#include "Shadow.h"

using namespace std;


int main() {
  srand(time(NULL));
  bool endGame2 = false;
  while(!endGame2){
  //Create Characters
  string name1 = "";
  string name2 = "";
  string s1 = "";
  string s2 = "";

  cout << "Player 1 enter your name: ";
  getline(cin,name1);

  cout << "\nPlayer 1 select your fighter: \n 1. Warrior \n 2. Ranger \n 3. Shaman \n 4. Wizard \n 5. Shadow \n 6. Random \n *Random will be chosen if input is invalid\n\n";
  getline(cin,s1);
  int select1 = stoi(s1);

  Player *playerOne;
    if (select1 < 1 or select1 > 5){
      select1 = (rand() % 5) + 1;
    }
    
    if (select1 == 1){
      playerOne = new Warrior(name1);
    }
    else if (select1 == 2){
      playerOne = new Ranger(name1);
    }
    else if (select1 == 3){
      playerOne = new Shaman(name1);
    }
    else if (select1 == 4){
      playerOne = new Wizard(name1);
    }
    else if (select1 == 5){
      playerOne = new Shadow(name1);
    }
    else {
      playerOne = new Warrior(name1);
    }

  cout << "Player 2 enter your name: ";
  getline(cin,name2);

  cout << "\nPlayer 2 select your fighter: \n 1. Warrior \n 2. Ranger \n 3. Shaman \n 4. Wizard \n 5. Shadow \n 6. Random \n *Random will be chosen if input is invalid\n\n";
  getline(cin,s2);
  int select2 = stoi(s2);

  Player *playerTwo;
    if (select2 < 1 or select2 > 5){
        select2 = (rand() % 5) + 1;
    }

    if (select2 == 1){
      playerTwo = new Warrior(name2);
    }
    else if (select2 == 2){
      playerTwo = new Ranger(name2);
    }
    else if (select2 == 3){
      playerTwo = new Shaman(name2);
    }
    else if (select2 == 4){
      playerTwo = new Wizard(name2);
    }
    else if (select2 == 5){
      playerTwo = new Shadow(name2);
    }
    else {
      playerTwo = new Warrior(name2);
    }
    
  //Coin Flip to determine who goes first
  // use * to get the reference to the player, not make a copy of Player
    
  Player *currentPlayer;             
  Player *targetPlayer;
  Player *temp;

  int coin = (rand() % 2);
    if (coin == 0) {
      currentPlayer = playerOne;
      targetPlayer = playerTwo;
    }
    else if (coin == 1) {
    currentPlayer = playerTwo;
    targetPlayer = playerOne;
    }
    
    //Rounds of fighting

    bool endGame = false;

  int turn = 1;
  while(!endGame){
    cout << "Turn: " << turn << endl;
    cout << "=========================\n"
         << currentPlayer -> getName()  << " Take your turn\n"
         << "=========================\n";
    currentPlayer->displayStatus();
    targetPlayer->displayStatus();
    cout << "=========================\n"
         << "1. Attack\n"
         << "2. Special Ability\n"
         << "3. Take Potion\n"
         << "=========================\n"
         << "Enter choice: " << endl;
    string s = "";
    getline(cin, s);
    //int choice = stoi(s);
    cout << endl;

    if (s == "1"){
      endGame = currentPlayer->attack(*targetPlayer);
    }
    else if (s == "2"){
      endGame = currentPlayer->specialAbility(*targetPlayer);
    }
    else if (s == "3"){
      currentPlayer->takePotion(*currentPlayer);
    }
    else {
      cout << "You trip and fall, lose a turn\n\n";
    }
        
  //Switch player's turn
  temp = currentPlayer;
  currentPlayer = targetPlayer;
  targetPlayer = temp;
  turn++;
  }
  //Asks if player wants to play again and closes game if they elect no.
  int cont = 0;
  while (cont < 1 || cont > 2){
    cout << "Would you like to play again?\n   1. Yes\n   2. No" << endl;
    cin >> cont;

      if (cont == 2) {
        endGame2 = true;
      }
      else if (cont == 1){
        endGame2 = false;
      }
      else {
        cout << "Invalid Input, try again." << endl << endl;
      }
  }
  cin.ignore();   
  }
}
*/