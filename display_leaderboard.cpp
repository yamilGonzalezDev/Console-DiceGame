#include "declarations.hpp"

void displayLeaderboard(int topScoreSingle, int topScoreVersus, std::string topScoreNameSingle, std::string topScoreNameVersus) {
    int fullSet = 999;
    std::string noPlayers = "Player:  N/A  - Score: N/A", singlePlayerDisplay = "", versusDisplay = "";

    if (topScoreSingle == 0) {
        singlePlayerDisplay = noPlayers;
    } else {
        singlePlayerDisplay = "Player: " + topScoreNameSingle + " - Score: ";
        if (topScoreSingle == fullSet) {
            singlePlayerDisplay += "Full set";
        } else {
            singlePlayerDisplay += toString(topScoreSingle, 3);
        }
    }

    if (topScoreVersus == 0) {
        versusDisplay = noPlayers;
    } else {
        versusDisplay = "Player: " + topScoreNameVersus + " - Score: ";
        if (topScoreVersus == fullSet) {
            versusDisplay += "Full set";
        } else {
            versusDisplay += toString(topScoreVersus, 3);
        }
    }

    renderScoreboardHeader(".:Scoreboard:.");
    center("Highest score - Single Mode:", 11);
    center(singlePlayerDisplay, 12);
    center("Highest score - Versus Mode:", 14);
    center(versusDisplay, 15);
    pressAnyKey(17, 17);
}
