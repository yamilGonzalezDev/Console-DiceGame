#include <iostream>
#include "rlutil.h"
#include "declarations.hpp"

int calculateScore(int dices[]) {
    if (isFullSet(dices) == true) {
        return 999;
    }

    if (isSixOfAKind(dices)) {
        if (dices[0] == 6) {
            return 666;
        }
        return dices[0];
    }

    int total = 0;
    for (int d = 0; d < 6; d++) {
        total += dices[d];
    }

    return total;
}

bool isFullSet(int dices[]){
    for (int d = 0; d < 6; d++) {
        for (int i = d + 1; i < 6; i++) {
            if (dices[d] == dices[i]) {
                return false;
            }
        }
    }
    return true;
}

bool isSixOfAKind(int dices[]) {
    for (int d = 1; d < 6; d++) {
        if (dices[d] != dices[0]) {
            return false;
        }
    }
    return true;
}

void laboratoryTest(int totalSims) {
    rlutil::hidecursor();
    int cNormal = 0, cSoakPositivo = 0, cSoakSeis = 0, cFullSet = 0;
    int d[6];

    std::cout << "\n\tRunning simulations...\n";

    for (int i = 1; i <= totalSims; i++) {
        for (int j = 0; j < 6; j++) d[j] = (rand() % 6) + 1;

        int score = calculateScore(d);

        if (score == 999) {
            cFullSet++;
        } else if (score == 666) {
            cSoakSeis++;
        } else if (score >= 1 && score <= 5) {
            cSoakPositivo++;
        } else {
            cNormal++;
        }

        if (i % 1000 == 0) {
            int percentage = (i * 100) / totalSims;
            int barWidth = percentage / 5;
            rlutil::locate(1, 4);
            std::cout << "\rProgress: [";
            for (int b = 0; b < 20; b++) {
                if (b < barWidth) {
                    std::cout << "|";
                } else {
                    std::cout << " ";
                }
            }

            std::cout << "] " << percentage << "%";
        }
    }

    std::cout << "\n--- STATS AFTER " << totalSims << " ROLLS ---\n";
    std::cout << "Normal Hands:\t\t" << (cNormal * 100.0) / totalSims << "%\n";
    std::cout << "Six of a Kind (1-5):\t" << (cSoakPositivo * 100.0) / totalSims << "%\n";
    std::cout << "Six of a Kind (6):\t" << (cSoakSeis * 100.0) / totalSims << "%\n";
    std::cout << "Full Set:\t" << (cFullSet * 100.0) / totalSims << "%\n";

    rlutil::anykey();
}

int setDice() {
    return rand() % 6 + 1;
}
