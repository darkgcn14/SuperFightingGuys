#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include "Wizard.h"
#include "Player.h"
#include "Shaman.h"
#include "Ranger.h"
#include "Warrior.h"
#include "Shadow.h"

using namespace std;

/*
// Should deal with pass by reference + need to deal
void PlayerTurn(string& s) {
  // Also should use switches.
  bool endTurn = false;
  do {
	if (s == "1"){
	  endGame = currentPlayer->attack(*targetPlayer);
	  endTurn = true;
	}
	else if (s == "2"){
	  endGame = currentPlayer->specialAbility(*targetPlayer);
	  endTurn = true;
	}
	else if (s == "3"){
	  currentPlayer->takePotion(*currentPlayer);
	  endTurn = true;
	}
	else if (s == "4"){
	  //currentplayer->defenseAbility(*cu)
	  endTurn = false;
	  cout << "Please enter another option. \n\n";
	  getline(cin, s);
	}
	else {
	  cout << "You trip and fall, lose a turn\n\n";
	  endTurn = true;
	}
  } while (!endTurn);
}
*/

Player* promptPlayer(string playerId) {
	cout << playerId << " enter your name: ";
	
	string playerName;
	getline(cin, playerName);
	cout << "\n";

	cout << playerName << " select your fighter: \n 1. Warrior \n 2. Ranger \n 3. Shaman \n 4. Wizard \n 5. Shadow \n 6. Random \n *Random will be chosen if input is invalid\n\n";

	int choice;
	try {
		string input;
		getline(cin, input);
		choice = stoi(input);
	}
	catch (...) {
		choice = 6;
	}

	if (choice < 1 or choice > 5) {
		choice = (rand() % 5) + 1;
	}

	//I want to eventually build an array of strings to return a random value
	//string selectA[]{"1","2","3","4","5","6"};

	Player* player;

	if (choice == 1) player = new Warrior(playerName);
	else if (choice == 2) player = new Ranger(playerName);
	else if (choice == 3) player = new Shaman(playerName);
	else if (choice == 4) player = new Wizard(playerName);
	else if (choice == 5) player = new Shadow(playerName);
	else assert(false);
	
	return player;
}

int main() {
	bool playGame = false;
	while (!playGame) {
		string option = "";
		cout << "====================\n"
			<< "Main Menu\n"
			<< "====================\n"
			<< "1. Play Game\n"
			<< "2. Fighter Info\n"
			<< "3. Credits\n"
			<< "====================\n"
			<< "Enter Choice: ";
		getline(cin, option);
		cout << endl;

		if (option == "1") {
			srand(time(NULL));

			bool endGame2 = false;
			while (!endGame2) {
				// Create Characters

				Player* playerOne = promptPlayer("Player 1");

				Player* playerTwo = promptPlayer("Player 2");

				Player* currentPlayer;
				Player* targetPlayer;
				Player* temp;

				//Player 1 goes first
				currentPlayer = playerOne;
				targetPlayer = playerTwo;

				//Coin Flip to determine who goes first
/*
				int coin = (rand() % 2);
				if (coin == 0) {
				  currentPlayer = playerOne;
				  targetPlayer = playerTwo;
				}
				else {
				  currentPlayer = playerTwo;
				  targetPlayer =  playerOne;            //Rounds of fighting
				}
*/
				bool endGame = false;

				int turn = 1;
				while (!endGame) {
					cout << "Turn: " << turn << endl;
					cout << "=========================\n"
						<< currentPlayer->getName() << " Take your turn\n"
						<< "=========================\n";
					currentPlayer->displayStatus();
					targetPlayer->displayStatus();
					cout << "=========================\n"
						<< "1. Attack (ends turn)\n"
						<< "2. Special Ability (ends turn)\n"
						<< "3. Take Potion (ends turn)\n"
						<< "4. Defense Ability (doesn't end turn)\n"
						<< "=========================\n"
						<< "Enter choice: " << endl;
					string s = "";
					getline(cin, s);
					//int choice = stoi(s);
					cout << endl;

					//PlayerTurn (s);

					bool endTurn = false;
					while (!endTurn) {
						if (s == "1") {
							endGame = currentPlayer->attack(*targetPlayer);
							endTurn = true;
						}
						else if (s == "2") {
							endGame = currentPlayer->specialAbility(*targetPlayer);
							endTurn = true;
						}
						else if (s == "3") {
							currentPlayer->takePotion(*currentPlayer);
							endTurn = true;
						}
						else if (s == "4") {
							currentPlayer->defenseAbility(*currentPlayer);
							currentPlayer->defenseAbility2(*targetPlayer);
  
							endTurn = false;
							//cout << "You used a defensive ability so your turn did not end. Please enter another option. \n\n";
							getline(cin, s);
						}
						else {
							cout << "You trip and fall, lose a turn\n\n";
							endTurn = true;
						}
					}



					//Switch player's turn
					temp = currentPlayer;
					currentPlayer = targetPlayer;
					targetPlayer = temp;
					turn++;
				}
				//Asks if player wants to play again and closes game if they elect no.
				string cont = "";
				bool cont2 = false;
				while (!cont2) {
					cout << "Would you like to play again?\n   1. Yes\n   2. No\n   3. Main Menu" << endl;
					getline(cin, cont);

					if (cont == "2") {
						endGame2 = true;
						playGame = true;
						cont2 = true;
					}
					else if (cont == "1") {
						endGame2 = false;
						cont2 = true;
					}
					else if (cont == "3") {
						endGame2 = true;
						playGame = false;
						cont2 = true;
						break;
					}
					else {
						cout << "Invalid Input, try again." << endl << endl;
						cont2 = false;
					}
					//cin.ignore();
				}
				//cin.ignore();
			}
		}
		else if (option == "2") {
			bool mainScreen = false;
			while (!mainScreen) {
				string character = "";
				cout << "=========================\n"
					<< "Fighters\n"
					<< "=========================\n"
					<< " 1. Warrior \n 2. Ranger \n 3. Shaman \n 4. Wizard \n 5. Shadow \n 6. Main Menu\n"
					<< "=========================\n";
				getline(cin, character);

				if (character == "1") {
					cout << "This is a paragraph about the warrior\n\n";
				}
				else if (character == "2") {
					cout << "This is a paragraph about the Ranger\n\n";
				}
				else if (character == "3") {
					cout << "This is a paragraph about the Shaman\n\n";
				}
				else if (character == "4") {
					cout << "This is a paragraph about the Wizard\n\n";
				}
				else if (character == "5") {
					cout << "This is a paragraph about the Shadow\n\n";
				}
				else if (character == "6") {
					cout << endl << endl << endl;
					mainScreen = true;
					break;
				}
				else {
					cout << "Invalid input: Please respond with 1, 2, 3, 4, 5 or 6.\n\n";
				}
			}
		}
		else if (option == "3") {
			cout << "Creator: DarkDarkington\n"
				<< "Co-Creator: Brian Baker\n"
				<< "Play tester: MrFailology\n"
				<< "Dude with good ideas: MrFailology\n"
				<< "Costume Design: HazardousMonkey\n"
				<< "Bug Finder: KFTalentScout\n"
				<< "Fixer of jank code: Peelz\n"
				<< endl << endl;
		}
		else {
			cout << "invalid input: Please respond with a 1, 2 or 3.\n\n";

		}
	}
}