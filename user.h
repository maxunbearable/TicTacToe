#include <string>
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