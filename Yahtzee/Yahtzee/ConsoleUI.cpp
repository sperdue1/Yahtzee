#include "ConsoleUI.h"
#include "GameLogic.h"
#include <iostream>
#include <string>

using namespace std;

ConsoleUI::ConsoleUI() : game() {}

void ConsoleUI::startGame() {
    cout << "Welcome to Yahtzee!\n";
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j) {
            game.playTurn();
            displayDice();
            if (j < 2) {
                vector<int> diceToReroll = selectDice();
                game.rerollDice(diceToReroll);
                displayDice();
            }
        }
        game.calculateScore();
        displayScore();
    }
    cout << "Final score: " << game.getScore() << "\n";
}

void ConsoleUI::displayDice() {
    vector<Die>& dice = game.getDice();
    cout << "You rolled: ";
    for (Die& die : dice) cout << die.getFaceValue() << " ";
    cout << "\n";
}

void ConsoleUI::displayScore() {
    cout << "Score: " << game.getScore() << "\n";
}

vector<int> ConsoleUI::selectDice() {
    int numOfDie;
    int input;
    vector<int> index;
    cout << "How many die would you like to reroll?\n";
    cin >> numOfDie;
    for (int i = 0; i < numOfDie; i++) {
        cout << "Enter index for die #" << i + 1 << ": ";
        cin >> input;
        index.push_back(input);
    }

    //cout << "Enter the indices of the dice you want to reroll (0-4, separated by spaces), or -1 to keep all dice.\n";
    vector<int> diceToReroll;
    GameLogic game;
    vector<Die> dice = game.getDice();
    vector<int> originaldice;
    Die die;
    for (int i = 0; dice[i].getFaceValue(); i++) {
        originaldice.push_back(dice[i].getFaceValue());
    }
    for (int i = 0; index[i]; i++) {
        for (int i = 0; i < 5; i++) {
            if (i == index[i]) {
                die.roll();
                /*diceToReroll[index[i]] = die.getFaceValue();*/
                diceToReroll(index[i])
            }
            else {
                diceToReroll[i] = originaldice[i];
            }
        }
    }
    // testing
    cout << "Original dice: " << endl;
    for (int i = 0; originaldice[i]; i++) {
        cout << originaldice[i];
    }

    cout << "New dice: " << endl;
    for (int i = 0; diceToReroll[i]; i++) {
        cout << diceToReroll[i];
    }

    return diceToReroll;
}

