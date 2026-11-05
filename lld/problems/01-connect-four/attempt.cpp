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

#include <optional>
#include <string>
#include <vector>

enum class Disc { NONE, RED, YELLOW };

class Board {
  int rows_, cols_;
  std::vector<Disc> grid_;

public:
  Board(int rows, int cols)
      : rows_(rows), cols_(cols), grid_(rows * cols, Disc::NONE) {}

  Disc at(int row, int col) { return grid_[row * cols_ + col]; }

  bool canPlace(int col) {
    if (at(0, col) == Disc::NONE)
      return true;
    return false;
  }

  int placeDisc(int col, Disc color) {
    /* Core logic:
     * - find the lowest empty row for that column
     * - place disc
     * - return the row landed in
     *
     * Edge cases:
     * - column index is out of bounds;
     * - column is full;
     */

    if (col < 0 || col >= cols_)
      return -1;
    if (!canPlace(col))
      return -1;

    for (int r = rows_ - 1; r >= 0; --r) {
      if (at(r, col) == Disc::NONE) {
        grid_[r * cols_ + col] = color;
        return r;
      }
    }
    return -1;
  }

  bool isFull() {
    int fulls = 0;
    for (int c = 0; c < cols_; ++c) {
      if (at(0, c) != Disc::NONE)
        ++fulls;
    }
    return fulls == cols_;
  }

  bool checkWin(int row, int col, Disc color) {
    /* Core Logic:
     * - check for four in a row in all four directions
     * - return true if found, false otherwise
     *
     * Edge cases:
     * - row or column out of bounds -> return false
     *   cell at (row, column) doesn't match color -> return false
     */
    if (row < 0 || row >= rows_ || col < 0 || col >= cols_)
      return false;
    if (at(row, col) != color)
      return false;

    constexpr int directions[4][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}};

    for (const auto &[dr, dc] : directions) {
      int count = 1;
      count += countInDirection(row, col, dr, dc, color);
      count += countInDirection(row, col, -dr, -dc, color);
      if (count >= 4)
        return true;
    }
    return false;
  }

private:
  int countInDirection(int row, int col, int dr, int dc, Disc color) {
    int count = 0;
    int r = row + dr;
    int c = col + dc;
    while (r >= 0 && r < rows_ && c >= 0 && c < cols_ && at(r, c) == color) {
      ++count;
      r += dr;
      c += dc;
    }
    return count;
  }
};

class Player {
  std::string name_;
  Disc color_;

public:
  Player(std::string name, Disc color) : name_(name), color_(color) {}

  std::string getName() { return name_; }
  Disc getColor() { return color_; }
  bool operator==(const Player &) const = default;
};

enum class State { IN_PROGRESS, WON, DRAW };

class Game {
  Player player1_;
  Player player2_;
  Player *currentPlayer;
  Player *winner;
  Board board_;
  State state;

public:
  Game(Player player1, Player player2)
      : player1_(player1), player2_(player2), currentPlayer(&player1_),
        winner(nullptr), board_(6, 7), state(State::IN_PROGRESS) {}

  bool makeMove(Player player, int column) {
    /* Core Logic:
     * - placeDisc
     * - checkWin
     * - else if, check for tie
     * - switch turns
     *
     * Edge cases:
     * - game is already over
     * - wrong player turn
     *
     * # this is actually board
     * - column index is out of bounds
     * - column is full
     */
    if (state != State::IN_PROGRESS)
      return false;
    if (*currentPlayer != player)
      return false;

    int row = board_.placeDisc(column, player.getColor());
    if (row == -1)
      return false;

    if (board_.checkWin(row, column, player.getColor())) {
      state = State::WON;
      winner = currentPlayer;
    } else if (board_.isFull()) {
      state = State::DRAW;
      winner = nullptr;
    } else {
      currentPlayer = (player == player1_) ? &player2_ : &player1_;
    }
    return true;
  }

  Player getCurrentPlayer() { return *currentPlayer; }

  State getGameState() { return state; }

  std::optional<Player> getWinner() {
    if (state != State::WON)
      return std::nullopt;
    return *winner;
  }
};

int main() {}
