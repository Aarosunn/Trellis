"""Writes hidden .in files to tests/ next to this script. Outputs come from ref.cpp."""
import os
import random

R = random.Random(2026)
OUT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "tests")
ROWS, COLS = 6, 7


class Sim:
    """Just enough game logic to search for draw / last-move-win sequences."""

    def __init__(self):
        self.g = [[None] * COLS for _ in range(ROWS)]
        self.h = [0] * COLS
        self.n = 0

    def drop(self, col, p):
        r = self.h[col]
        self.g[r][col] = p
        self.h[col] += 1
        self.n += 1
        return r

    def wins(self, r, c):
        p = self.g[r][c]
        for dr, dc in ((0, 1), (1, 0), (1, 1), (1, -1)):
            k = 1
            for s in (1, -1):
                rr, cc = r + s * dr, c + s * dc
                while 0 <= rr < ROWS and 0 <= cc < COLS and self.g[rr][cc] == p:
                    k += 1
                    rr += s * dr
                    cc += s * dc
            if k >= 4:
                return True
        return False


def random_game():
    """Returns (moves, outcome) for a random legal game played to the end."""
    s, p, moves = Sim(), "R", []
    while True:
        col = R.choice([c for c in range(COLS) if s.h[c] < ROWS])
        r = s.drop(col, p)
        moves.append((p, col + 1))
        if s.wins(r, col):
            return moves, ("win_full" if s.n == ROWS * COLS else "win")
        if s.n == ROWS * COLS:
            return moves, "draw"
        p = "Y" if p == "R" else "R"


def find_game(outcome):
    while True:
        moves, o = random_game()
        if o == outcome:
            return moves


def drops(moves):
    return [f"DROP {p} {c}" for p, c in moves]


def write(name, lines):
    with open(os.path.join(OUT, name + ".in"), "w") as f:
        f.write("\n".join(lines) + "\n")


def main():
    os.makedirs(OUT, exist_ok=True)

    write("01-malformed", [
        "BOARD", "STATUS", "drop R 1", "DROP", "DROP R", "DROP R 1 1", "DROP r 1", "DROP RY 1",
        "DROP R 1.5", "DROP R x", "DROP R 99999999999999999999", "BOARD 1", "STATUS now",
        "", "   ", "FOO", "DROP R 3", "STATUS", "BOARD",
    ])

    write("02-game-over", drops([("R", 1), ("Y", 2), ("R", 1), ("Y", 2), ("R", 1), ("Y", 2), ("R", 1)]) + [
        "DROP Y 3", "DROP R 3", "DROP Y 9", "DROP Y 0", "STATUS", "BOARD", "DROP R x",
    ])

    write("03-out-of-turn", [
        "DROP Y 1", "DROP Y 1", "DROP R 1", "DROP R 2", "DROP Y 2", "DROP Y 3", "STATUS", "DROP R 3", "BOARD",
    ])

    write("04-column-range", [
        "DROP R 0", "DROP R 8", "DROP R -1", "DROP R -9223372036854775808", "DROP R 9223372036854775807",
        "DROP R 7", "DROP Y 1", "STATUS", "BOARD",
    ])

    full_col = drops([("R", 3), ("Y", 3)] * 3)
    write("05-column-full", full_col + ["DROP R 3", "DROP Y 3", "STATUS", "DROP R 4", "BOARD"])

    write("06-horizontal", drops([("R", 1), ("Y", 1), ("R", 2), ("Y", 2), ("R", 3), ("Y", 3), ("R", 4)])
          + ["STATUS", "BOARD"])

    # R builds a rising diagonal (1,1)(2,2)(3,3)(4,4)
    write("07-diagonal-up", drops([
        ("R", 1), ("Y", 2), ("R", 2), ("Y", 3), ("R", 4), ("Y", 3), ("R", 3),
        ("Y", 4), ("R", 5), ("Y", 4), ("R", 4),
    ]) + ["STATUS", "BOARD"])

    # mirror image: falling diagonal (7,1)(6,2)(5,3)(4,4)
    write("08-diagonal-down", drops([
        ("R", 7), ("Y", 6), ("R", 6), ("Y", 5), ("R", 4), ("Y", 5), ("R", 5),
        ("Y", 4), ("R", 3), ("Y", 4), ("R", 4),
    ]) + ["STATUS", "BOARD"])

    draw = find_game("draw")
    write("09-draw", ["STATUS"] + drops(draw) + ["STATUS", "BOARD", "DROP R 1", "DROP Y 1"])

    last = find_game("win_full")
    write("10-win-on-last-move", drops(last) + ["STATUS", "BOARD", "DROP R 1"])

    write("11-precedence", [
        "DROP Y 0",      # wrong turn + bad column -> E3
        "DROP Y x",      # malformed beats everything -> E1
        "DROP R 8",      # E4
    ] + drops([("R", 1), ("Y", 1)] * 3) + [
        "DROP Y 1",      # wrong turn + full column -> E3
        "DROP R 1",      # E5
        "DROP R 0",      # E4
    ] + drops([("R", 2), ("Y", 3), ("R", 2), ("Y", 3), ("R", 2), ("Y", 3), ("R", 2)]) + [
        "DROP R 1",      # over + wrong turn + full -> E2
        "DROP Y 0",      # over + bad column -> E2
        "DROP Q 1",      # E1 even after game over
        "STATUS",
    ])

    # random game with noise and queries after every move
    moves, _ = random_game()
    lines = []
    for p, c in moves:
        other = "Y" if p == "R" else "R"
        lines += R.sample([f"DROP {other} {c}", f"DROP {p} 0", "STATUS", "BOARD", "FOO", ""], 2)
        lines.append(f"DROP {p} {c}")
    write("12-random-noisy", lines + ["STATUS", "BOARD"])

    moves, _ = random_game()
    lines = []
    pool = ["STATUS", "BOARD", "DROP R 4", "DROP Y 4", "DROP R 0", "DROP Y 12", "BAD", "DROP R"]
    for p, c in moves:
        lines += [R.choice(pool) for _ in range(500)]
        lines.append(f"DROP {p} {c}")
    while len(lines) < 100000:
        lines.append(R.choice(pool))
    write("13-large", lines)


if __name__ == "__main__":
    main()
