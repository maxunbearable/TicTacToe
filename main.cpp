#include <iostream>
#include <cstring>
#include "gameboard.h"
#include "user.h"
using namespace std;

void playerMakesTurn(Player* player, Gameboard* board);
bool checkForWinners(Player* player1, Player* player2, Gameboard* board);

int main() {
	Gameboard board;
	Player player1;
	Player player2;
	player1.setName();
	player1.setIsX(true);
	player2.setName();
	player2.setIsX(false);

	board.printInfo();

	do {
		playerMakesTurn(&player1, &board);
		if (!checkForWinners(&player1, &player2, &board)) {
			playerMakesTurn(&player2, &board);
		}
	} while (!checkForWinners(&player1, &player2, &board));

	cout << "Game over!";
}

void playerMakesTurn(Player* player, Gameboard* board) {
	cout << player->getName() << " - turn, choose your move: " << endl;
	player->makeTurn(board);
	cout << "Board after " << player->getName() << " turn" << endl;
	board->printInfo();
}

bool checkForWinners(Player* player1, Player* player2, Gameboard* board) {
	int countPlayer1;
	int countPlayer2;
	int countTie = 0;
	for (int i = 0; i < 4; i++)
	{
		countPlayer1 = 0;
		countPlayer2 = 0;
		for (int j = 0; j < 4; j++)
		{
			char currentCell = board->getGameSpace(i, j);
			if (currentCell == player1->getSign().c_str()[0])
			{
				countPlayer1++;
			}
			 else if (currentCell == player2->getSign().c_str()[0])
			{
				countPlayer2++;
			}
			 if (currentCell != '-')
			{
				countTie++;
			}
		}
		if (countPlayer1 == 4) {
			cout << "Player - " << player1->getName() << " WINS!!!" << endl;
			return true;
		}
		else if (countPlayer2 == 4) {
			cout << "Player - " << player2->getName() << " WINS!!!" << endl;
			return true;
		}
		else if (countTie == 16) {
			cout << "It's a tie!" << endl;
			return true;
		}
	}
	return 0;
}