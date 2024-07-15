#include "GameLogic.h"
#include <iostream>

using namespace std;

GameLogic::GameLogic() : dice(5), scores(6, 0) {}

void GameLogic::playTurn() {
    rollDice();
}

int GameLogic::getScore() {
    int total = 0;
    for (int score : scores) total += score;
    return total;
}

vector<Die>& GameLogic::getDice() {
    return dice;
}

void GameLogic::rollDice() {
    for (Die& die : dice) die.roll();
}

void GameLogic::rerollDice(const vector<int>& diceToReroll) {
    for (int index : diceToReroll) dice[index].roll();
}


void GameLogic::calculateScore() {
    for (Die& die : dice) scores[die.getFaceValue() - 1] += die.getFaceValue();
}
