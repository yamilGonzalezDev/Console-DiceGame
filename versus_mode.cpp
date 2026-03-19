#include "declarations.hpp"

void versusMode(std::string& topScoreNameVersus, int& topScoreVersus, bool devMode) {
    bool finishGame = false, event = false;
    int dices[6];
    int rounds = 0, p1TotalScore = 0, p2TotalScore = 0, p1Rolls = 0, p2Rolls = 0, score = 0, limitRolls = 3, multiplier = 10;
    std::string combName = "", combDesc = "";

    std::string nameP1 = registerName("Enter Player 1 name: ", devMode);
    std::string nameP2 = registerName("Enter Player 2 name: ", devMode);
    int totalRounds = setRoundsMessage(devMode);

    while (!finishGame) {
        rounds++;
        score = 0;
        int p1HighestRoll = 0, p2HighestRoll = 0, lan;
        if (devMode) {
            setDevDiceMessage();
        }
        for (lan = 1; lan <= limitRolls; lan++) {
            event = false;
            p1Rolls++;
            for (int d = 0; d < 6; d++) {
                if (devMode) {
                    dices[d] = setDevDice(nameP1, true);
                } else {
                    dices[d] = setDice();
                }
            }

            score = calculateScore(dices);

            if (score == 999) {
                event = true;
                p1HighestRoll = 0;
                p1TotalScore = score;
                combName = "Full set";
                combDesc = "Instant win!";
            } else if (score == 666) {
                event = true;
                p1HighestRoll = 0;
                p1TotalScore  = 0;
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

            if (event) {
                combinationMessage(combName, combDesc, devMode);
            }

            if (score > p1HighestRoll) {
                p1HighestRoll = score;
            }

            displayHand(nameP1, combName, lan, score, p1TotalScore, rounds, dices, devMode);

            if (event) {
                break;
            }
        }

        p1TotalScore += p1HighestRoll;
        roundSummary(nameP1, rounds, p1TotalScore, p1HighestRoll, 2, devMode);

        event = false;

        for (lan = 1; lan <= limitRolls; lan++) {
            event = false;
            p2Rolls++;
            if (devMode) {
                setDevDiceMessage();
            }
            for (int d = 0; d < 6; d++) {
                if (devMode) {
                    dices[d] = setDevDice(nameP2, true);
                } else {
                    dices[d] = setDice();
                }
            }

            score = calculateScore(dices);

            if (score == 999) {
                event = true;
                p2HighestRoll = 0;
                p2TotalScore = 999;
                combName = "Full set";
                combDesc = "Instant win!";
            } else if (score == 666) {
                event = true;
                p2HighestRoll = 0;
                p2TotalScore  = 0;
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

            if (event) {
                combinationMessage(combName, combDesc, devMode);
            }

            if (score > p2HighestRoll) {
                p2HighestRoll = score;
            }

            displayHand(nameP2, combName, lan, score, p2TotalScore, rounds, dices, devMode);

            if (event) {
                break;
            }
        }

        p2TotalScore += p2HighestRoll;
        roundSummary(nameP2, rounds, p2TotalScore, p2HighestRoll, 2, devMode);

        versusSummary(nameP1, nameP2, rounds, p1TotalScore, p2TotalScore, true);

        if (p1TotalScore >= 100  || p2TotalScore >= 100  ||
            p1HighestRoll == 999 || p2HighestRoll == 999 ||
            (totalRounds != 0 && rounds >= totalRounds)) {
            finishGame = true;
        }
    }

    std::string winnerName = "", secondPlaceName = "";
    int winnerScore = 0, secondPlaceScore = 0, winnerRolls = 0;

    if (p1TotalScore > p2TotalScore) {
        winnerName = nameP1;
        winnerScore = p1TotalScore;
        winnerRolls = p1Rolls;
    } else if (p2TotalScore > p1TotalScore) {
        winnerName = nameP2;
        winnerScore = p2TotalScore;
        winnerRolls = p2Rolls;
    } else if (p1Rolls < p2Rolls) {
        winnerName = nameP1;
        winnerScore = p1TotalScore;
        winnerRolls = p1Rolls;
    } else if (p2Rolls < p1Rolls) {
        winnerName = nameP2;
        winnerScore = p2TotalScore;
        winnerRolls = p2Rolls;
    } else {
        while (p1TotalScore == p2TotalScore) {
            tieSummary(nameP1, nameP2, p1TotalScore, p2TotalScore, p1Rolls, p2Rolls);

            int p1DeathStandRoll = setDice();
            int p2DeathStandRoll = setDice();

            p1Rolls++;
            p2Rolls++;
            p1TotalScore += p1DeathStandRoll;
            p2TotalScore += p2DeathStandRoll;

            tieBreakSummary(nameP1, nameP2, p1DeathStandRoll, p2DeathStandRoll);
        }

        if (p1TotalScore > p2TotalScore) {
           winnerName = nameP1;
           winnerScore = p1TotalScore;
           winnerRolls = p1Rolls;

           secondPlaceName = nameP2;
           secondPlaceScore = p2TotalScore;
        } else {
            winnerName = nameP2;
            winnerScore = p2TotalScore;
            winnerRolls = p2Rolls;

            secondPlaceName = nameP1;
            secondPlaceScore = p1TotalScore;
        }

        tieFinalSummary(winnerName, secondPlaceName, winnerScore, secondPlaceScore);
    }

    winningMessage(winnerName, winnerScore, rounds, winnerRolls, devMode);
    if (winnerScore > topScoreVersus) {
        topScoreNameVersus = winnerName;
        topScoreVersus = winnerScore;
    }
}
