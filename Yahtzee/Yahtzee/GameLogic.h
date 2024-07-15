#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "Die.h"
#include <vector>

using namespace std;

class GameLogic {
private:
    vector<Die> dice;
    vector<int> scores;
    void rollDice();
    
public:
    GameLogic();
    void playTurn();
    int getScore();
    vector<Die>& getDice();
    void calculateScore();
    void rerollDice(const vector<int>& diceToReroll);
};

#endif