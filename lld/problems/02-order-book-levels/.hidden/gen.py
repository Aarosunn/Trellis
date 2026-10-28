#!/usr/bin/env python3
"""Writes hidden .in files to tests/ next to this script. Outputs come from ref.cpp."""
import random
from pathlib import Path

OUT = Path(__file__).parent / "tests"
OUT.mkdir(exist_ok=True)
R = random.Random(2026)
BIG = 10**9


def write(name, lines):
    (OUT / f"{name}.in").write_text("\n".join(lines) + "\n")


write("01-malformed", [
    "FOO 1",
    "add 1 B 10 10",
    "ADD 1 B 10",
    "ADD 1 B 10 10 5",
    "ADD 1 b 10 10",
    "ADD 1 BUY 10 10",
    "ADD x B 10 10",
    "ADD 1 B 10.5 10",
    "ADD 1 B +10 10",
    "ADD 1 B 10 99999999999999999999",
    "ADD 1 B 10 1e3",
    "CANCEL",
    "CANCEL 1 2",
    "MODIFY 1",
    "BEST now",
    "DEPTH",
    "DEPTH two",
    "",
    "   ",
    "  ADD   1   B   10   10  ",
    "BEST",
    "\tDEPTH\t1",
])

write("02-invalid-values", [
    "ADD 0 B 10 10",
    "ADD -1 B 10 10",
    "ADD 1000000000000000001 B 10 10",
    "ADD 1000000000000000000 B 10 10",
    "ADD 2 B 0 10",
    "ADD 3 S -5 10",
    "ADD 4 B 1000000001 10",
    "ADD 5 S 1000000000 10",
    "ADD 6 B 1 0",
    "ADD 7 B 1 1000000001",
    "ADD 8 B 1 1000000000",
    "MODIFY 8 0",
    "MODIFY 8 -3",
    "MODIFY 0 5",
    "CANCEL 0",
    "CANCEL -7",
    "DEPTH 0",
    "DEPTH -1",
    "DEPTH 1000000001",
    "DEPTH 1000000000",
    "BEST",
])

write("03-unknown-id", [
    "CANCEL 1",
    "MODIFY 1 5",
    "ADD 1 B 100 5",
    "CANCEL 1",
    "CANCEL 1",
    "MODIFY 1 5",
    "ADD 2 S 200 5",
    "MODIFY 3 5",
    "CANCEL 999999999999999999",
    "DEPTH 3",
])

write("04-duplicate-id", [
    "ADD 5 B 100 1",
    "ADD 5 B 100 1",
    "ADD 5 S 300 1",
    "CANCEL 5",
    "ADD 5 B 100 1",
    "ADD 6 S 50 1",
    "ADD 7 S 150 1",
    "ADD 8 B 150 1",
    "ADD 8 B 149 1",
    "ADD 8 B 148 1",
    "ADD 0 B 100 1",
    "ADD 9 B 0 1",
    "ADD 9 B 1 1",
    "DEPTH 10",
])

write("05-crossing", [
    "ADD 1 B 100 1",
    "ADD 2 S 100 1",
    "ADD 3 S 99 1",
    "ADD 4 S 101 1",
    "ADD 5 B 101 1",
    "ADD 6 B 102 1",
    "ADD 7 B 100 1",
    "ADD 8 S 101 1",
    "CANCEL 4",
    "CANCEL 8",
    "ADD 9 B 500 1",
    "ADD 10 S 500 1",
    "CANCEL 1",
    "CANCEL 7",
    "CANCEL 9",
    "ADD 11 S 1 1",
    "ADD 12 B 1000000000 1",
    "BEST",
])

write("06-empty-book", [
    "BEST",
    "DEPTH 1",
    "DEPTH 1000000000",
    "ADD 1 B 10 3",
    "BEST",
    "DEPTH 2",
    "CANCEL 1",
    "BEST",
    "DEPTH 2",
    "ADD 2 S 20 4",
    "BEST",
    "DEPTH 2",
    "CANCEL 2",
    "BEST",
])

write("07-level-lifecycle", [
    "ADD 1 B 100 10",
    "ADD 2 B 100 20",
    "ADD 3 B 100 30",
    "ADD 4 B 98 5",
    "ADD 5 S 105 7",
    "ADD 6 S 105 8",
    "DEPTH 5",
    "CANCEL 2",
    "DEPTH 5",
    "CANCEL 1",
    "CANCEL 3",
    "BEST",
    "DEPTH 5",
    "CANCEL 5",
    "DEPTH 5",
    "CANCEL 6",
    "BEST",
    "ADD 7 B 100 1",
    "DEPTH 5",
])

write("08-modify", [
    "ADD 1 B 100 10",
    "ADD 2 B 100 20",
    "MODIFY 1 10",
    "DEPTH 1",
    "MODIFY 1 1",
    "DEPTH 1",
    "MODIFY 2 1000000000",
    "DEPTH 1",
    "CANCEL 2",
    "DEPTH 1",
    "ADD 3 S 200 5",
    "MODIFY 3 6",
    "MODIFY 3 6",
    "BEST",
    "CANCEL 3",
    "MODIFY 3 6",
    "DEPTH 1",
])

write("09-precedence", [
    "ADD 1 B 100 1",
    "ADD 2 S 200 1",
    "ADD 1 X 0 0",
    "ADD 1 B 0 1",
    "ADD 1 S 50 1",
    "ADD 3 S 50 0",
    "ADD 2 B 300 1",
    "MODIFY 99 0",
    "MODIFY 99 x",
    "CANCEL 0",
    "DEPTH 0 1",
    "BEST",
])

overflow = [f"ADD {i} S 777 {BIG}" for i in range(1, 6001)]
overflow += ["BEST", "DEPTH 1"]
overflow += [f"MODIFY {i} 1" for i in range(1, 3001)]
overflow += ["DEPTH 1"] + [f"ADD {i} B 776 {BIG}" for i in range(6001, 9001)] + ["BEST"]
write("10-overflow", overflow)


def random_session(n, max_depth, id_space):
    live, used, lines = [], set(), []
    for _ in range(n):
        r = R.random()
        if r < 0.45 or not live:
            oid = R.randint(1, id_space)
            side = R.choice("BS")
            price = R.randint(900, 1060) if side == "B" else R.randint(1040, 1200)
            lines.append(f"ADD {oid} {side} {price} {R.randint(1, BIG)}")
            live.append(oid)
            used.add(oid)
        elif r < 0.65:
            oid = R.choice(live) if R.random() < 0.9 else R.randint(1, id_space)
            lines.append(f"CANCEL {oid}")
        elif r < 0.8:
            oid = R.choice(live) if R.random() < 0.9 else R.randint(1, id_space)
            lines.append(f"MODIFY {oid} {R.randint(1, BIG)}")
        elif r < 0.9:
            lines.append("BEST")
        elif r < 0.98:
            lines.append(f"DEPTH {R.randint(1, max_depth)}")
        else:
            lines.append(R.choice(["ADD 1 B", "CANCEL 0", "MODIFY 1 0", "PING", "DEPTH 0"]))
    return lines


write("11-random-medium", random_session(3000, 8, 4000))
write("12-large", random_session(100000, 5, 10**18))
