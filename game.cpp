#include "declarations.hpp"

void game() {
    initGame();
    std::string topScoreNameSingle = "", topScoreNameVersus = "";
    int topScoreSingle = 0, topScoreVersus = 0;

    while (true) {
        renderMenu();

        int choice = getMenuOption(35);

        switch(choice) {
            case 1: singleMode(topScoreNameSingle, topScoreSingle, false); break;
            case 2: versusMode(topScoreNameVersus, topScoreVersus, false); break;
            case 3: displayLeaderboard(topScoreSingle, topScoreVersus, topScoreNameSingle, topScoreNameVersus); break;
            case 8: singleMode(topScoreNameSingle, topScoreSingle, true); break;
            case 9: versusMode(topScoreNameVersus, topScoreVersus, true); break;
            case 0: exitMessage(); return;
            default: renderErrorMessage("Invalid option", 17); break;
        }
    }
}
