# Connect Four

Time limit: 90 minutes.

## Background

Two players, `R` (red) and `Y` (yellow), take turns dropping discs into a vertical
board of **7 columns** and **6 rows**. A disc falls to the lowest empty row of the chosen
column. The first player to get **four or more** of their discs in a line — horizontal,
vertical, or diagonal — wins. If the board fills with no winner, the game is a draw.

Your program receives one game as a stream of commands on standard input and must print
the result of each command on standard output.

## Rules

1. `R` always moves first. After every successful move the turn passes to the other player.
2. Columns are numbered `1` to `7`, left to right. Rows are numbered `1` (bottom) to `6` (top).
3. A move is checked for a win using the disc just placed. If that move both wins and fills
   the board, it is a win, not a draw.
4. Once the game is won or drawn, no further moves are accepted. Queries still work.
5. A rejected move changes nothing: same board, same player to move.

## Input format

One command per line. Tokens are separated by one or more spaces. Blank lines are ignored
and produce no output.

| Command | Meaning |
|---|---|
| `DROP <player> <column>` | `<player>` drops a disc into `<column>` |
| `BOARD` | print the board |
| `STATUS` | print the game status |

## Output format

Exactly one line per command, except `BOARD`, which prints six lines.

**`DROP`**, on success:
- `WIN <player>` if the move wins the game
- `DRAW` if the move fills the board without a win
- otherwise `OK <row>`, where `<row>` is the row the disc landed in

**`BOARD`**: six lines, top row (row 6) first. Each line has exactly 7 characters, one per
column left to right: `R`, `Y`, or `.` for empty.

**`STATUS`**:
- `TURN <player>` while the game is in progress (the player to move next)
- `WINNER <player>` after a win
- `DRAW` after a draw

## Error codes

When a command is rejected, print only its error code. If several apply, print the
**first** one in this list:

| Code | Condition |
|---|---|
| `E1` | Malformed command: unknown command word, wrong number of tokens, `<player>` not exactly `R` or `Y`, or `<column>` not an integer |
| `E2` | `DROP` after the game is over |
| `E3` | `DROP` by the player whose turn it is not |
| `E4` | `<column>` is an integer outside `1`–`7` |
| `E5` | `<column>` is full |

`BOARD` and `STATUS` can only fail with `E1` (for example, `BOARD 3`).

## Constraints

- Up to `100000` lines of input.
- Each line is at most 100 characters.
- An integer `<column>` fits in a signed 64-bit integer; anything that does not is not an integer (`E1`).

## Example 1

Input:
```
STATUS
DROP R 4
DROP Y 5
DROP R 4
DROP Y 5
DROP R 4
DROP Y 5
DROP R 4
BOARD
STATUS
DROP Y 1
```

Output:
```
TURN R
OK 1
OK 1
OK 2
OK 2
OK 3
OK 3
WIN R
.......
.......
...R...
...RY..
...RY..
...RY..
WINNER R
E2
```

## Example 2

Input:
```
DROP Y 1
DROP R 0
DROP R 1 2
JUMP R 1
DROP R x
DROP R 1
STATUS
```

Output:
```
E3
E4
E1
E1
E1
OK 1
TURN Y
```
