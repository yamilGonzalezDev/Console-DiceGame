#include "declarations.hpp"

void singleMode(std::string& topScoreNameSingle, int& topScoreSingle, bool devMode) {
    bool finishGame = false;
    int dices[6];
    int rounds = 0, totalScore  = 0, totalRolls = 0, limitRolls  = 3, multiplier  = 10;
    std::string combName = "", combDesc = "";

    std::string name    = registerName      ("Enter your name: ", devMode);
    int totalRounds     = setRoundsMessage  (devMode);

    while (!finishGame) {
        rounds++;
        int highestRollInRound = 0;
        if (devMode) {
            setDevDiceMessage();
        }
        for (int rolls = 1; rolls <= limitRolls; rolls++) {
            totalRolls++;
            for (int d = 0; d < 6; d++) {
                if (devMode) {
                    dices[d] = setDevDice(name, false);
                } else {
                    dices[d] = setDice();
                }
            }

            int score = calculateScore(dices);

            if (score == 999) {
                totalScore = score;
                combName = "Full set";
                combDesc = "Instant win!";
                finishGame = true;
            } else if (score == 666) {
                totalScore          = 0;
                highestRollInRound  = 0;
                combName = "The bad [Six] of a kind";
                combDesc = "Total score reset to 0 :(";
            } else if (score >= 1 && score <= 5) {
                score = dices[0] * multiplier;
                combName = "Six of a kind";
                combDesc = "Dice x10!";
            } else {
                combName = "Normal hand";
                combDesc = "";
            }

            if (score == 666 || score == 999) {
                combinationMessage(combName, combDesc, devMode);
            }

            displayHand(name, combName, rolls, score, totalScore, rounds, dices, devMode);

            if (score > highestRollInRound) {
                highestRollInRound = score;
            }

            if (score == 666 || score == 999) {
                break;
            }
        }

        if (!finishGame) {
            totalScore += highestRollInRound;
            roundSummary(name, rounds, totalScore, highestRollInRound, 1, devMode);

            if (totalScore >= 100 || (totalRounds != 0 && rounds >= totalRounds)) {
                finishGame = true;
            }
        }

        if (finishGame) {
            winningMessage(name, totalScore, rounds, totalRolls, devMode);
            if (totalScore > topScoreSingle) {
                topScoreNameSingle    = name;
                topScoreSingle        = totalScore;
            }
            return;
        }
    }
}
