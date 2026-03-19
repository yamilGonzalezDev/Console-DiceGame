#include <iostream>
#include "rlutil.h"
#include "declarations.hpp"

void initGame() {
    srand(time(0));
    rlutil::cls();
    rlutil::setColor(rlutil::WHITE);
    if(rlutil::saveDefaultColor() < 0) {
        renderErrorMessage("Error to initialize the game: Couldn't set the color", 9);
        rlutil::anykey();
        return;
    }
    rlutil::showcursor();
}

void startInterface(bool devMode, int width) {
    rlutil::resetColor();
    if (devMode) {
        devMessage();
    }
    renderMessageBox(9, width, 3);
    rlutil::showcursor();
}

void endInterface() {
    rlutil::hidecursor();
    rlutil::cls();
    rlutil::resetColor();
}

void renderHorizontalFrame(std::string pattern, std::string midPattern, int y, int width, int height) {
    int lastTop = -1, lastBot = -1, lastMid = -1;

    int x = calculateX((width * 2), 0);

    for (int i = 0; i < width; i++) {
        int topColor = getColor(lastTop);
        rlutil::setColor(topColor);
        rlutil::locate(x + (i * 2), y);
        std::cout << pattern;
        lastTop = topColor;

        if (midPattern != "") {
            int midColor = getColor(lastMid);
            rlutil::setColor(midColor);
            rlutil::locate(x + (i * 2), y + 2);
            std::cout << midPattern;
            lastMid = midColor;
        }

        int botColor = getColor(lastBot);
        rlutil::setColor(botColor);
        rlutil::locate(x + (i * 2), y + height);
        std::cout << pattern;
        lastBot = botColor;
    }

    rlutil::resetColor();
}

void renderMessageBox(int y, int width, int height) {
    int tw = width - 2;
    int ty = y + 1;

    std::string separator   = "+";
    std::string whiteSpace  = "|";

    for (int i = 0; i < tw; i++) {
        separator += "-";
    }
    separator += "+";

    for (int j = 0; j < tw; j++) {
        whiteSpace += " ";
    }
    whiteSpace += "|";

    center(separator, y);
    for (int k = 0; k < height; k++) {
        center(whiteSpace, ty + k);
    }
    center(separator, ty + height);
}

void center(std::string line, int y) {
    int x = calculateX(getLength(line), 0);
    rlutil::locate(x, y);
    std::cout << line;
}

void left(std::string t, int width, int y) {
    int x = calculateX(width, 2);
    rlutil::locate(x, y);
    std::cout << t;
}

int calculateX(int width, int offset) {
    return ((rlutil::tcols() - width) / 2) + offset;
}

void renderDices(int dices[], int x, int y) {
    int lastColor = -1;
    int random;
    rlutil::locate(x - 1, y);
    std::cout << "[";
    for (int d = 0; d < 6; d++) {
        random = getColor(lastColor);
        rlutil::setColor(random);
        rlutil::locate(x, y);
        std::cout << dices[d];
        if (d != 5) {
           std::cout << ",";
        }
        x += 3;
        lastColor = random;
    }
    std::cout << "]";
}

int getColor(int lastColor) {
    int colors[3] = {rlutil::LIGHTCYAN, rlutil::LIGHTMAGENTA, rlutil::LIGHTBLUE};
    int other;

    do {
        other = colors[rand() % 3];
    } while (other == lastColor);

    return other;
}

void pressAnyKey(int y, int width) {
    renderHorizontalFrame("==", "--", y, width, 2);
    rlutil::resetColor();
    center("Press any key to continue", y + 1);
    rlutil::anykey();
    rlutil::cls();
}
