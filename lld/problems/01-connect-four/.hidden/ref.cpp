#include <array>
#include <iostream>
#include <sstream>
#include <string>

enum class Disc { None, Red, Yellow };

char symbol(Disc d) {
    switch (d) {
    case Disc::Red: return 'R';
    case Disc::Yellow: return 'Y';
    default: return '.';
    }
}

class Board {
public:
    static constexpr int kRows = 6;
    static constexpr int kCols = 7;

    bool columnFull(int col) const { return heights_[col] == kRows; }
    bool full() const { return placed_ == kRows * kCols; }
    Disc at(int row, int col) const { return grid_[row][col]; }

    // Returns the 0-based row the disc landed in. Caller checks columnFull first.
    int drop(int col, Disc d) {
        int row = heights_[col]++;
        grid_[row][col] = d;
        ++placed_;
        return row;
    }

    bool completesLine(int row, int col) const {
        static constexpr std::array<std::array<int, 2>, 4> kDirs{{{0, 1}, {1, 0}, {1, 1}, {1, -1}}};
        Disc d = grid_[row][col];
        for (auto [dr, dc] : kDirs) {
            int count = 1 + run(row, col, dr, dc, d) + run(row, col, -dr, -dc, d);
            if (count >= 4) return true;
        }
        return false;
    }

private:
    int run(int row, int col, int dr, int dc, Disc d) const {
        int n = 0;
        for (int r = row + dr, c = col + dc; r >= 0 && r < kRows && c >= 0 && c < kCols && grid_[r][c] == d;
             r += dr, c += dc)
            ++n;
        return n;
    }

    std::array<std::array<Disc, kCols>, kRows> grid_{};
    std::array<int, kCols> heights_{};
    int placed_ = 0;
};

enum class Status { InProgress, Won, Draw };
enum class MoveError { None, GameOver, OutOfTurn, BadColumn, ColumnFull };

struct MoveResult {
    MoveError error = MoveError::None;
    int row = 0;  // 1-based, valid when error == None
};

class Game {
public:
    MoveResult drop(Disc player, long long column) {
        if (status_ != Status::InProgress) return {MoveError::GameOver};
        if (player != turn_) return {MoveError::OutOfTurn};
        if (column < 1 || column > Board::kCols) return {MoveError::BadColumn};
        int col = static_cast<int>(column) - 1;
        if (board_.columnFull(col)) return {MoveError::ColumnFull};

        int row = board_.drop(col, player);
        if (board_.completesLine(row, col))
            status_ = Status::Won;
        else if (board_.full())
            status_ = Status::Draw;
        else
            turn_ = (turn_ == Disc::Red) ? Disc::Yellow : Disc::Red;
        return {MoveError::None, row + 1};
    }

    Status status() const { return status_; }
    Disc turn() const { return turn_; }  // after a win: the winner
    const Board& board() const { return board_; }

private:
    Board board_;
    Disc turn_ = Disc::Red;
    Status status_ = Status::InProgress;
};

int main() {
    std::ios::sync_with_stdio(false);
    Game game;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream in(line);
        std::string cmd, extra;
        if (!(in >> cmd)) continue;

        if (cmd == "DROP") {
            std::string who;
            long long column;
            if (!(in >> who >> column) || (in >> extra) || (who != "R" && who != "Y")) {
                std::cout << "E1\n";
                continue;
            }
            MoveResult r = game.drop(who == "R" ? Disc::Red : Disc::Yellow, column);
            switch (r.error) {
            case MoveError::GameOver: std::cout << "E2\n"; break;
            case MoveError::OutOfTurn: std::cout << "E3\n"; break;
            case MoveError::BadColumn: std::cout << "E4\n"; break;
            case MoveError::ColumnFull: std::cout << "E5\n"; break;
            case MoveError::None:
                if (game.status() == Status::Won)
                    std::cout << "WIN " << who << '\n';
                else if (game.status() == Status::Draw)
                    std::cout << "DRAW\n";
                else
                    std::cout << "OK " << r.row << '\n';
            }
        } else if (cmd == "BOARD" && !(in >> extra)) {
            for (int row = Board::kRows - 1; row >= 0; --row) {
                std::string out;
                for (int col = 0; col < Board::kCols; ++col) out += symbol(game.board().at(row, col));
                std::cout << out << '\n';
            }
        } else if (cmd == "STATUS" && !(in >> extra)) {
            switch (game.status()) {
            case Status::InProgress: std::cout << "TURN " << symbol(game.turn()) << '\n'; break;
            case Status::Won: std::cout << "WINNER " << symbol(game.turn()) << '\n'; break;
            case Status::Draw: std::cout << "DRAW\n"; break;
            }
        } else {
            std::cout << "E1\n";
        }
    }
}
