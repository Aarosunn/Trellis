/*
 *
 * 1. primary capabilities
 * 2. error handling
 * 3. scope boundaries
 *
 * 1. Two players take turns dropping discs in a 7x6 bourd
 * 2. A disc falls to the lowest available row in the column
 * 3. The game ends when:
 *    - A player gets four discs in a row (vertical, horizontal, or diagonal).
 * They win.
 *    - The board is full. It's a draw.
 * 4. Invalid moves should be rejected clearly:
 *    - Dropping in a full column.
 *    - Moving out of turn.
 *    - Moving after the game is over.
 *
 * Out of scope:
 *    - UI support
 *    - Concurrent games
 *
 * Requirements -> Entities -> Class Design -> Implementation
 * -> Extensibility
 *
 *  Entities:
 *  - Game
 *  - Board
 *  - Player
 *  - Disc?
 *
 *  Single Responsibility Principle
 *
 *  Implementation
 *  1. Defining the core logic
 *  2. Consider the edge class
 *
 *  Game.makeMove
 *  board.placeDisc
 *  board.checkWin
 *
 */

#include <cstdint>
#include <string>
#include <vector>

enum class Disc { NONE, RED, YELLOW };

class Board {
  uint8_t rows_, cols_;
  std::vector<Disc> grid_;

public:
  Board(uint8_t rows, uint8_t cols)
      : rows_(rows), cols_(cols), grid_(rows * cols, Disc::NONE) {}

  Disc at(uint8_t row, uint8_t col) { return grid_[row * cols_ + col]; }

  bool canPlace(uint8_t col) {}
  uint8_t placeDisc(uint8_t col, Disc color) {}
  bool isFull() {}
  bool checkWin(uint8_t row, uint8_t col, Disc color) {}
};

class Player {
  std::string name_;
  Disc color_;

public:
  Player(std::string name, Disc color) : name_(name), color_(color) {}

  std::string getName() { return name_; }
  Disc getColor() { return color_; }
};

enum class State { IN_PROGRESS, WON, DRAW };

class Game {
  Player player1_;
  Player player2_;
  Player *currentPlayer_;
  Board board_;

public:
  Game(Player player1, Player player2)
      : player1_(player1), player2_(player2), board_(6, 7) {}

  bool makeMove(Player player, uint8_t column) {
    /* Core Logic:
     * - placeDisc
     * - checkWin
     * - else if, check for tie
     * - switch turns
     *
     * Edge cases:
     * - game is already over
     * - wrong player turn
     * - column index is out of bounds
     * -
     *
     *
     */
  }

  Player getCurrentPlayer() {}

  State getGameState() {}

  Player getWinner() {}
};

int main() {}
