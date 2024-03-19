#include <iostream>
#include <string>
#include "gameboard.h"
using namespace std;

class Player
{
    bool isX;
    string name;
public:
    void setName();
    string getName();
    void setIsX(bool inIsX);
    string getSign();
    void makeTurn(Gameboard* board);
};

void Player::makeTurn(Gameboard* board) {
    int col;
    int row;
    cout << "Enter col: ";
    cin >> col;
    cout << "Enter row: ";
    cin >> row;
    char sign = getSign().c_str()[0];
    while (board->getGameSpace(row - 1, col - 1) != '-') {
        cout << "Please enter valid game cell" << endl;
        cout << "Enter col: ";
        cin >> col;
        cout << "Enter row: ";
        cin >> row;
    }
    board->setGameSpace(row - 1, col - 1, sign);
}

void Player::setName()
{
    string inName;
    cout << "Set player name: ";
    cin >> inName;
    name = inName;
}

string Player::getName()
{
    return name;
}

void Player::setIsX(bool inIsX)
{
    isX = inIsX;
}

string Player::getSign()
{
    if (isX) {
        return "x";
    }
    else {
        return "o";
    }
}