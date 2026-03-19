#include <iostream>
#include "rlutil.h"
#include "declarations.hpp"

void renderMenu() {
    int width = 35;
    int x = calculateX(width, 21);

    renderMessageBox(5, width, 1);
    renderMessageBox(7, width, 8);

    center(".: FULL  SET :.", 6);
    left("1. Single Player Mode"    , width,  9);
    left("2. Versus Mode (PvP)"     , width, 10);
    left("3. Leaderboard"           , width, 11);
    left("0. Exit Game"             , width, 12);
    left(" Select an option:"       , width, 14);
    rlutil::locate(x, 14);
}

int getMenuOption(int width) {
    std::string option = "";
    std::cin >> option;

    while (!isNumeric(option)) {
        renderErrorMessage("Invalid format", 17);
        renderMenu();
        std::cin >> option;
    }

    rlutil::hidecursor();
    return toInt(option);
}

void renderErrorMessage(std::string errorText, int y) {
    int width = 35, height = 1;
    std::string line = "";
    rlutil::hidecursor();
    rlutil::setColor(rlutil::RED);
    renderMessageBox(y, width, height);
    center(errorText, y + 1);
    rlutil::anykey();
    for (int i = 0; i < width; i++) {
        line += " ";
    }
    for (int j = 0; j < (height + 2); j++) {
        center(line, y + j);
    }
    rlutil::setColor(rlutil::WHITE);
    rlutil::showcursor();
}

void renderScoreboardHeader(std::string headerText) {
    rlutil::hidecursor();
    rlutil::resetColor();
    rlutil::cls();
    renderHorizontalFrame("**", "", 7, 17, 2);
    center(headerText, 8);
}

void combinationMessage(std::string combName, std::string combDesc, bool devMode) {
    renderHorizontalFrame("==", "--", 9, 24, 4);
    if (devMode) {
        devMessage();
    }
    rlutil::resetColor();
    center(combName + "!", 10);
    center(combDesc, 12);
    rlutil::anykey();
    rlutil::cls();
}

void winningMessage(std::string name, int score, int rounds, int totalRolls, bool devMode) {
    if (devMode) {
        devMessage();
    }

    int fullSet = 999;

    renderHorizontalFrame("==", "--", 9, 31, 5);
    rlutil::resetColor();
    if (score == fullSet) {
        center("Congrats, " + name + "! Full Set achieved! You win the game!", 10);
        center("Final score: Full Set", 12);
    } else {
        center("Congrats, " + name + "! Goal achieved! You win the game!", 10);
        center("Final score: " + toString(score, 3), 12);
    }

    center("With " + toString(totalRolls, 2) + " rolls in " + toString(rounds, 2) + " rounds", 13);

    rlutil::resetColor();
    rlutil::anykey();
    rlutil::cls();
}

void roundSummary(std::string name, int round, int totalScore, int highestRoll, int players, bool devMode) {
    int y = 7, width = 36;

    if (devMode) {
        devMessage();
    }

    rlutil::setColor(rlutil::YELLOW);
    renderMessageBox(y, width, 7);

    if (players == 2) {
        center("End of " + name + " turn", y + 2);
    }

    if (players == 1) {
        center("End of round " + toString(round, 2), y + 2);
    }

    center("Highest roll: " + toString(highestRoll, 2), y + 4);
    center("Total " + name + "'s score: " + toString(totalScore, 2), y + 6);

    rlutil::resetColor();
    rlutil::anykey();
    rlutil::cls();
}

void versusSummary(std::string nameP1, std::string nameP2, int round, int totalScoreP1, int totalScoreP2, bool roundEnd) {
    rlutil::setColor(rlutil::YELLOW);
    renderMessageBox(7, 36, 7);

    center("END OF ROUND N " + toString(round, 2), 9);
    center(nameP1 + " total score: " + toString(totalScoreP1, 3), 11);
    center(nameP2 + " total score: " + toString(totalScoreP2, 3), 13);

    rlutil::resetColor();
    rlutil::anykey();
    rlutil::cls();
}

void tieSummary(std::string nameP1, std::string nameP2, int p1TotalScore, int p2TotalScore, int p1Rolls, int p2Rolls) {
    renderMessageBox(9, 35, 7);
    center("Death stand!!", 9);
    center("Tie in points and rolls", 11);
    center(nameP1 + " score: " + toString(p1TotalScore, 3) + " in " + toString(p1Rolls, 2) + " rolls", 13);
    center(nameP2 + " score: " + toString(p2TotalScore, 3) + " in " + toString(p2Rolls, 2) + " rolls", 15);
    rlutil::anykey();
    rlutil::cls();
}

void tieBreakSummary(std::string nameP1, std::string nameP2, int diceRollP1, int diceRollP2) {
    renderMessageBox(9, 35, 7);
    center("Tie roll!", 11);
    center(nameP1 + " roll: " + toString(diceRollP1, 1), 13);
    center(nameP2 + " roll: " + toString(diceRollP2, 1), 15);
    rlutil::anykey();
    rlutil::cls();
}

void tieFinalSummary(std::string winnerName, std::string secondPlaceName, int winnerScore, int secondPlaceScore) {
    renderMessageBox(9, 35, 7);
    center(winnerName + " wins!",11);
    center(winnerName + " score: " + toString(winnerScore, 3), 13);
    center(secondPlaceName + " score: " + toString(secondPlaceScore, 3), 15);
    rlutil::anykey();
    rlutil::cls();
}

void devMessage() {
    char c = 219;
    std::string aux = "";
    std::string line = "";
    aux = c;
    for (int i = 0; i < 17; i++) line += c;
    rlutil::setColor(rlutil::LIGHTCYAN);
    center(line, 1);
    center(line, 4);
    center(aux + aux + "  DEV  MODE  " + aux + aux, 2);
    center(aux + aux + "  ACTIVATED  " + aux + aux, 3);
    rlutil::resetColor();
}

void setDevDiceMessage() {
    int width = 35;
    devMessage();
    renderMessageBox(9, width, 3);
}

void exitMessage() {
    rlutil::cls();
    rlutil::hidecursor();
    renderMessageBox(9, 35, 1);
    center("Thanks for playing the game", 10);
    rlutil::anykey();
    rlutil::cls();
}

void displayHand(std::string name, std::string combName, int rolls, int rollScore, int totalScore, int round, int dices[], bool devMode) {
    rlutil::setColor(rlutil::LIGHTCYAN);
    if (devMode) {
        devMessage();
    }
    int y = 5, width = 50;
    renderMessageBox(y, width, 1);
    renderMessageBox(y + 2, width, 7);
    std::string header  = "Jugador: "           + formatString(name, 4);
                header += " | Ronda "           + toString(round, 2);
                header += " | Puntaje Total: "  + toString(totalScore, 3);
    left(header, width, y + 1);
    left("Roll " + toString(rolls, 2) + ": ", width, y + 4);
    left("Combination: " + combName, width, y + 6);
    left("Roll score: " + toString(rollScore, 2), width, y + 8);

    renderDices(dices, 47, 9);

    pressAnyKey(y + 11, 24);
    rlutil::cls();
    rlutil::resetColor();
}

std::string registerName(std::string messageText, bool devMode) {
    rlutil::cls();
    int width = 35;
    std::string name = "";
    startInterface(devMode, width);

    while (!isAlpha(name)) {
        left("                               ", width, 11);
        left(messageText, width, 11);
        std::cin >> name;

        if (!isAlpha(name)) {
            renderErrorMessage("Invalid format", 14);
        }
    }

    endInterface();
    return formatPlayerName(name);
}

int setRoundsMessage(bool devMode) {
    int width = 35;
    std::string roundsNumber = "";
    startInterface(devMode, width);

    while (!isNumeric(roundsNumber)) {
        left("                               ", width, 11);
        left("Set rounds (0 for endless): ", width, 11);
        std::cin >> roundsNumber;

        if (!isNumeric(roundsNumber)) {
            renderErrorMessage("Invalid format", 14);
        }
    }

    rlutil::hidecursor();
    rlutil::cls();
    rlutil::resetColor();
    rlutil::saveDefaultColor();
    return toInt(roundsNumber);
}

int setDevDice(std::string name, bool isVersus) {
    int width = 35;
    std::string input = "";
    rlutil::showcursor();

    while (!isNumeric(input)) {
        left("                               ", width, 11);
        if(isVersus) {
            left("Set " + name + " dice: ", width, 11);
        } else {
            left("Set dice: ", width, 11);
        }
        std::cin >> input;

        if (!isNumeric(input)) {
            renderErrorMessage("Invalid format", 14);
        }
    }

    rlutil::hidecursor();
    return toInt(input);
}
