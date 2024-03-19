#pragma once
class Gameboard {
private:
    char gameSpace[4][4];

public:
    Gameboard();
    void setGameSpace(int row, int column, char value);
    char getGameSpace(int row, int column);
    int fourInRow();
    void printInfo();
};