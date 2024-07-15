#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "GameLogic.h"

using namespace std;

class ConsoleUI {
private:
    GameLogic game;
    void displayDice();
    void displayScore();
    vector<int> selectDice();
public:
    ConsoleUI();
    void startGame();
};

#endif