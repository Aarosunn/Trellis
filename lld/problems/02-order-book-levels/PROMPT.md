# Order Book Price Levels

**Time limit:** 90 minutes · **Language:** C++20

## Background

An exchange keeps a *limit order book* for one instrument. Traders rest buy orders
(bids) and sell orders (asks) at integer prices measured in ticks. Downstream systems
don't care about individual orders — they want the book **aggregated by price level**:
for each price, the total resting quantity and how many orders make it up.

You will build the component that maintains the book and answers level queries.
This component does **not** match orders: an order that would trade against the
opposite side is rejected instead (see `E5`).

## Input

Commands arrive on standard input, one per line, until end of input. Tokens are
separated by one or more whitespace characters; leading/trailing whitespace is
ignored. A line with no tokens is skipped and produces **no** output. Command names
and the side token are case-sensitive.

| Command | Meaning |
|---|---|
| `ADD <id> <side> <price> <qty>` | Rest a new order. `<side>` is `B` (buy) or `S` (sell). |
| `CANCEL <id>` | Remove a resting order. |
| `MODIFY <id> <qty>` | Replace a resting order's quantity with `<qty>`. Side and price are unchanged. |
| `BEST` | Report the best bid and best ask level. |
| `DEPTH <k>` | Report up to `k` best levels on each side. |

Every numeric token must be a decimal integer (an optional leading `-` followed by
digits only) that fits in a signed 64-bit integer.

## Rules

1. `<id>` identifies an order for the whole session. An id that was successfully
   added can **never** be added again — not while the order rests, and not after it
   has been cancelled. An `ADD` that fails (any error) does not use up its id.
2. The **best bid** is the highest bid price; the **best ask** is the lowest ask price.
3. A buy order *crosses* if an ask level exists and `price >= best ask`. A sell order
   crosses if a bid level exists and `price <= best bid`. A crossing `ADD` is rejected
   with `E5` and the book is unchanged. Adding to an empty opposite side never crosses.
4. A price level exists only while at least one order rests at it. When the last order
   at a price is cancelled, that level disappears.
5. `MODIFY` changes the level's total quantity by the difference; the order count at
   the level does not change. Modifying to the same quantity is valid.
6. Quantities to aggregate can exceed 32-bit range.

## Valid values

| Field | Valid range |
|---|---|
| `<id>` | 1 ≤ id ≤ 10^18 |
| `<price>` | 1 ≤ price ≤ 10^9 |
| `<qty>` | 1 ≤ qty ≤ 10^9 |
| `<k>` | 1 ≤ k ≤ 10^9 |

## Output

Every non-blank command prints exactly **one result** (`DEPTH` prints two lines; all
others print one).

- `ADD`, `CANCEL`, `MODIFY` on success: `OK`
- `BEST`: `BEST <bid> <ask>` where each side is `<price>x<totalQty>` of its best level,
  or `-` if that side is empty.
- `DEPTH <k>`: two lines.
  - `BID` followed by up to `k` levels, best first (highest price first), each as
    ` <price>:<totalQty>:<orderCount>`; or `BID -` if there are no bids.
  - `ASK` likewise, best first (lowest price first); or `ASK -`.
- On error: the error code alone, e.g. `E3`. The book is unchanged.

## Error codes

| Code | Meaning |
|---|---|
| `E1` | Malformed command: unknown command name, wrong number of tokens, side not `B`/`S`, or a numeric token that is not a valid 64-bit decimal integer. |
| `E2` | Invalid value: a well-formed number outside its valid range. |
| `E3` | Unknown id: `CANCEL`/`MODIFY` of an id that is not currently resting. |
| `E4` | Duplicate id: `ADD` with an id that was previously added successfully. |
| `E5` | Would cross: `ADD` that crosses the opposite side (rule 3). |

If more than one error applies, print the **lowest-numbered** one.

## Constraints

- At most 2 × 10^5 input lines.
- The total number of levels printed by all `DEPTH` commands is at most 10^6.
- Every operation should run in O(log n) or better (excluding output size).

## Example 1

Input:
```
ADD 1 B 100 10
ADD 2 B 100 5
ADD 3 B 99 7
ADD 4 S 102 4
ADD 5 S 101 6
BEST
DEPTH 2
CANCEL 2
MODIFY 3 20
DEPTH 5
```

Output:
```
OK
OK
OK
OK
OK
BEST 100x15 101x6
BID 100:15:2 99:7:1
ASK 101:6:1 102:4:1
OK
OK
BID 100:10:1 99:20:1
ASK 101:6:1 102:4:1
```

## Example 2

Input:
```
BEST
ADD 1 S 50 10
ADD 2 B 50 3
ADD 1 B 40 3
CANCEL 1
ADD 1 B 40 3
MODIFY 7 5
ADD 3 B 0 5
ADD 4 X 45 5
cancel 3
DEPTH 3
```

Output:
```
BEST - -
OK
E5
E4
OK
E4
E3
E2
E1
E1
BID -
ASK -
```

Explanation: `ADD 2 B 50 3` would buy at 50 while an ask rests at 50 → `E5`.
`ADD 1 B 40 3` reuses resting id 1 → `E4`. After `CANCEL 1`, id 1 still can't be
reused → `E4`. Price 0 is out of range → `E2`. Side `X` → `E1`. Lowercase `cancel`
is not a command → `E1`.
