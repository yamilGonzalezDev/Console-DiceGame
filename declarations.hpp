#ifndef DECLARATIONS_HPP_INCLUDED
#define DECLARATIONS_HPP_INCLUDED

#include <string>

/// ======================
/// CORE
/// ======================

void game();
void initGame();
void exitMessage();

/// ==========================
/// SCREENS AND GAME MODES
/// ==========================

void singleMode(std::string&, int&, bool);
void versusMode(std::string&, int&, bool);
void laboratoryTest(int);
void displayLeaderboard(int, int, std::string, std::string);

/// ==========================
/// LOGIC AND RULES
/// ==========================

/// @brief Generates a single random die roll.
///
/// @details Uses the standard rand() function to produce a value
/// within the traditional 6-sided die range.
///
/// @return An integer between 1 and 6 inclusive.
/// @note Requires the random seed (srand) to be initialized elsewhere
/// for truly varied results.
int setDice();

/// @brief Manages manual dice input during Simulated Mode.
///
/// @details Displays a prompt to the user and enters a validation loop.
/// It clears the line before each prompt to ensure UI cleanliness.
///
/// @param name The name of the player to be displayed in the prompt.
/// @param isVersus If true, includes the player's name in the message.
/// @return The integer value of the entered die.
///
/// @note Uses rlutil to show/hide the cursor and toInt() for final conversion.
/// @see isNumeric, toInt
int setDevDice(std::string, bool);

/// @brief Evaluates a 6-dice hand and calculates the final score.
///
/// @details Checks for special combinations in a specific hierarchy:
/// 1. Full Set (Straight 1-6).
/// 2. Six of a Kind (All dice equal).
/// 3. Standard sum of all face values.
///
/// @param dices An array of 6 integers representing the dice values.
/// @return The calculated score:
/// - 999: For a Full Set.
/// - 666: For Six of a Kind of 6s.
/// - The value of a single die: For Six of a Kind (1 to 5).
/// - Total sum: If no special combination is met.
///
/// @see isFullSet, isSixOfAKind
int calculateScore(int[]);

/// @brief Determines if the hand is a "Full Set" (all dice are unique).
///
/// @details Uses a nested loop to compare each die against the others.
/// If no duplicates are found in a 6-die hand (values 1-6), it implicitly
/// confirms a straight (1, 2, 3, 4, 5, 6).
///
/// @param dices An array of 6 integers.
/// @return True if all values are unique, false otherwise.
bool isFullSet(int[]);

/// @brief Checks if all dice in the hand have the same value.
///
/// @details Compares every element in the array to the first one.
/// Efficiently returns false at the first discrepancy.
///
/// @param dices An array of 6 integers.
/// @return True if all 6 dice are identical (Six of a Kind).
bool isSixOfAKind(int[]);

/// ==========================
/// UI CORE
/// ==========================

void startInterface(bool, int);
void endInterface();
void renderMessageBox(int, int, int);
void renderHorizontalFrame(std::string, std::string, int, int, int);
int calculateX(int, int);
void center(std::string, int);
void left(std::string, int, int);
int getColor(int);
void pressAnyKey(int, int);

/// ==========================
/// VIEW MANAGER
/// ==========================

void renderMenu();
int getMenuOption(int);
void renderDices(int[], int, int);
void renderScoreboardHeader(std::string);
void renderErrorMessage(std::string, int);
void winningMessage(std::string, int, int, int, bool);
void combinationMessage(std::string, std::string, bool);
void roundSummary(std::string, int, int, int, int, bool);
void versusSummary(std::string, std::string, int , int , int, bool);
void displayHand(std::string, std::string, int, int, int, int, int[], bool);
void tieSummary(std::string, std::string, int, int, int, int);
void tieBreakSummary(std::string, std::string, int, int);
void tieFinalSummary(std::string, std::string, int, int);
void devMessage();
void setDevDiceMessage();
int setRoundsMessage(bool);

/// ==========================
/// HELPERS
/// ==========================

/// @brief Converts a validated numeric string into an integer.
/// @details Reconstructs the number by iterating through the string and applying
/// base-10 positional logic.
/// @param input The numeric string to convert.
/// @return The resulting integer value.
/// @pre The input must be pre-validated by isNumeric() to avoid undefined behavior with non-digit characters.
/// @see getLength, isNumeric
int toInt(std::string);

/// @brief Calculates the number of characters in a string.
/// @param input The string to be measured.
/// @return The total count of characters as an integer.
/// @note Standard utility used across the project to avoid direct dependency on std::string methods in logic loops.
int getLength(std::string);

/// @brief Converts a non-negative integer to a string with zero-padding.
///
/// @details Processes the integer digit by digit using modulo logic.
/// If the resulting string length is less than the specified digits,
/// it prepends '0' characters until the target width is met.
///
/// @param number The non-negative integer to be converted.
/// @param digits The required minimum length of the output string.
/// @return The formatted string, or "ERR" if the input number is negative.
///
/// @note Useful for keeping score alignment (e.g., converting 7 to "007").
/// @see getLength
std::string toString(int, int);

/// @brief Pads a string with spaces to reach a specific width.
/// @param input The original string.
/// @param width The desired total length.
/// @return The string with trailing spaces added.
/// @note Useful for formatting scores in fixed-width UI elements.
/// @see getLength
std::string formatString(std::string, int);

/// @brief Normalizes the player's name to a fixed width for UI consistency.
/// @details Processes the input string to ensure it strictly meets the 4-character requirement.
/// @param name The original name string entered by the player.
/// @return A string exactly 4 characters long.
/// @note If the name is > 4 chars, it's truncated. If < 4, it's padded with trailing spaces.
/// @see getLength
std::string formatPlayerName(std::string);

/// @brief Checks if a string consists exclusively of numeric digits (0-9).
///
/// @details Evaluates each character against the ASCII range for digits.
/// Returns false immediately if an invalid character is found or if the string is empty.
///
/// @param input The string to be validated.
/// @return True if strictly numeric and not empty; false otherwise.
///
/// @note This function is the standard @pre condition for toInt().
/// @see getLength, toInt
bool isNumeric(std::string);

/// @brief Validates if a string consists exclusively of alphabetic characters.
/// @details Iterates through the string to ensure every character is within the A-Z or a-z ASCII range.
/// @param input The string to be checked (usually the raw player input).
/// @return True if the string is not empty and contains only letters; false otherwise.
/// @note Spaces, numbers, and special characters are considered invalid.
/// @see getLength
bool isAlpha(std::string);

/// @brief Manages the player registration flow
/// @details Loops until input is valid letters only
/// @param messageText Text to display (e.g., "Enter Player 1 name: ")
/// @param devMode Flag for Simulated Mode box display
/// @return A 4-character string, normalized by formatPlayerName.
/// @note Name must contain only letters (no spaces/symbols). Forced to 4 chars (padded or truncated)
/// @see isAlpha, formatPlayerName
std::string registerName(std::string, bool);

#endif // DECLARATIONS_HPP_INCLUDED
