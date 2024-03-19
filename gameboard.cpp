#include <iostream>
#include <iomanip> 
using namespace std;

class Gameboard
{
    char gameSpace[4][4];
public:
    Gameboard();
    void setGameSpace(int row, int column, char value);
    char getGameSpace(int row, int column);
    int fourInRow();
    void printInfo();
};

Gameboard::Gameboard()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            gameSpace[i][j] = '-';
        }
}
void Gameboard::setGameSpace(int row, int column, char value)
{
    gameSpace[row][column] = value;
}

char Gameboard::getGameSpace(int row, int column)
{
    return gameSpace[row][column];
}

int Gameboard::fourInRow()
{
    int count;
    for (int i = 0; i < 4; i++)
    {
        count = 0;
        for (int j = 0; j < 4; j++)
        {
            if (gameSpace[i][j] == 'x')
            {
                count++;
            }
        }
        if (count == 4)
            return 1;
    }
    return 0;
}
void Gameboard::printInfo()
{
    cout << std::setw(5);
    cout << "\n";
    cout << " " << 1 << 2 << 3 << 4 << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << i + 1;
        for (int j = 0; j < 4; j++)
        {
            cout << gameSpace[i][j];
        }
        cout << "\n";
    }
}