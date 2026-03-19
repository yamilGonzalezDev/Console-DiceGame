# Console-DiceGame: Full Set

A strategic terminal-based dice game built in **C++**. This project was developed as the final assignment for **Programming I** at University (UTN), focusing on core logic and algorithmic thinking under strict academic constraints.

---

## Project Constraints & Academic Rules

This game was developed under strict regulations, which represented a significant challenge by limiting the use of modern C++ shortcuts. The goal was to demonstrate pure algorithmic logic.

* **No Pointers or References:** (Except for one mandatory implementation in the High Score table).
* **Manual Logic Implementation:** Due to restrictions, several utility functions were built from scratch:
    * **Custom Validations:** Manual functions to verify "Alpha-only" strings for names and "Numeric-only" inputs.
    * **Hand-made Search Algorithms:** Functions to check if an array contains a specific value or to count frequencies of dice faces.
    * **Dynamic UI:** Text centering and frame rendering calculated manually based on console coordinates.
* **Environment:** Developed using `rlutil.h` for color management and cursor positioning.

---

## Game Rules

The game is played with **6 dice**. Each player has up to **3 rolls** per round to achieve the highest possible score.

### Scoring System

| Combination       | Condition                        | Score                     |
| :---------------- | :------------------------------- | :------------------------ |
| **Full Set**      | Straight (1-2-3-4-5-6)           | **999 pts (Instant Win)** |
| **Six of a Kind** | 6 identical dice (faces 1 to 5)  | **Face value x 10**       |
| **The Bad Six**   | 6 identical dice with face **6** | **Score Resets to 0**     |
| **Normal Hand**   | Any other combination            | **Sum of all dice faces** |

### Game Modes
* **Single Player:** Reach 100 points in the fewest rounds to enter the Leaderboard.
* **Versus Mode (1v1):** Local multiplayer with a **Death Stand** tie-breaker.
* **Developer Mode:** Specialized mode to manually input dice values for debugging.

---

## Tech Stack
* **Language:** C++
* **Compiler:** GCC (MinGW-W64) 14.2.0
* **Headers:** `rlutil.h`, `iostream`, `string`.

---

## Installation & Compilation
1.  **Clone the repository:**
      ```
      git clone https://github.com/yamilGonzalezDev/Console-DiceGame.git
      ```
3.  **Compile all source files:**
      ```
      g++ *.cpp -o Console-DiceGame.exe
      ```
4.  **Run the game:**
      ```
      ./Console-DiceGame.exe
      ```

---
*Developed by [Yamil González](https://github.com/yamilGonzalezDev)*
